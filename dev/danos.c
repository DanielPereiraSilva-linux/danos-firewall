#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define C_RESET   "\x1b[0m"
#define C_BRIGHT  "\x1b[1m"
#define C_RED     "\x1b[31m"
#define C_GREEN   "\x1b[32m"
#define C_YELLOW  "\x1b[33m"
#define C_CYAN    "\x1b[36m"
#define C_MAGENTA "\x1b[35m"

// --- Protótipos ---
void limpar_tela();
void pressione_enter();
int executar_comando(const char* comando);
void menu_gerenciar_chain(const char* tabela);

// --- Funções de Ajuda e UI ---

void limpar_tela() { system("clear"); }
void pressione_enter() {
    printf(C_YELLOW "\n\nPressione Enter para continuar..." C_RESET);
    while (getchar() != '\n');
    getchar();
}

int executar_comando(const char* comando) {
    printf(C_CYAN "\nExecutando: %s\n" C_RESET, comando);
    return system(comando);
}

// Limpa o buffer de entrada para evitar problemas com scanf/fgets
void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Pega uma entrada do usuário de forma segura
void obter_input(const char* prompt, char* buffer, size_t tamanho) {
    printf(C_CYAN "%s" C_RESET, prompt);
    limpar_buffer_entrada(); // Limpa antes de ler
    fgets(buffer, tamanho, stdin);
    buffer[strcspn(buffer, "\n")] = 0; // Remove a nova linha
}


// --- Funções de Gerenciamento de Regras ---

void listar_regras(const char* tabela, const char* chain) {
    char comando[256];
    snprintf(comando, sizeof(comando), "sudo iptables -t %s -L %s -v -n --line-numbers", tabela, chain);
    executar_comando(comando);
}

void apagar_regra(const char* tabela, const char* chain) {
    int num_regra;
    char comando[256];
    printf(C_CYAN "Digite o número da regra a ser apagada: " C_RESET);
    scanf("%d", &num_regra);
    snprintf(comando, sizeof(comando), "sudo iptables -t %s -D %s %d", tabela, chain, num_regra);
    executar_comando(comando);
}

void inserir_regra(const char* tabela, const char* chain, const char* regra) {
    char comando[1024];
    snprintf(comando, sizeof(comando), "sudo iptables -t %s -I %s 1 %s", tabela, chain, regra);
    executar_comando(comando);
}

// O CONSTRUTOR DE REGRAS GUIADO
void adicionar_regra_guiada(const char* tabela, const char* chain) {
    char regra[1024] = "";
    char buffer[100];

    printf(C_GREEN "\n--- Construtor de Regra Guiado ---\n" C_RESET);
    printf("Deixe em branco e pressione Enter para ignorar uma condição.\n");

    // Protocolo
    obter_input("Protocolo (tcp, udp, icmp, all): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-p %s ", buffer); }

    // Origem
    obter_input("IP/Rede de Origem (ex: 192.168.1.100 ou 192.168.1.0/24): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-s %s ", buffer); }

    // Porta de Origem
    obter_input("Porta de Origem (ex: 8080): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "--sport %s ", buffer); }
    
    // Destino
    obter_input("IP/Rede de Destino: ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-d %s ", buffer); }

    // Porta de Destino
    obter_input("Porta de Destino: ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "--dport %s ", buffer); }

    // Interface de Entrada
    obter_input("Interface de Entrada (ex: eth0): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-i %s ", buffer); }

    // Interface de Saída
    obter_input("Interface de Saída (ex: eth1): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-o %s ", buffer); }

    // Estado da Conexão
    obter_input("Estado da Conexão (NEW, ESTABLISHED, RELATED): ", buffer, sizeof(buffer));
    if (strlen(buffer) > 0) { sprintf(regra + strlen(regra), "-m conntrack --ctstate %s ", buffer); }

    // Ação (Target)
    printf(C_YELLOW "\nEscolha a Ação (Target):\n" C_RESET);
    printf("  1. ACCEPT (Permitir)\n");
    printf("  2. DROP (Descartar silenciosamente)\n");
    printf("  3. REJECT (Rejeitar com resposta)\n");
    printf("  4. LOG (Registrar no log do sistema)\n");
    obter_input("Opção: ", buffer, sizeof(buffer));
    int acao = atoi(buffer);
    switch(acao) {
        case 1: sprintf(regra + strlen(regra), "-j ACCEPT"); break;
        case 2: sprintf(regra + strlen(regra), "-j DROP"); break;
        case 3: sprintf(regra + strlen(regra), "-j REJECT"); break;
        case 4: sprintf(regra + strlen(regra), "-j LOG --log-prefix \"[DANOS_LOG] \""); break;
        default: printf(C_RED "Ação inválida. Regra não adicionada.\n" C_RESET); return;
    }
    
    inserir_regra(tabela, chain, regra);
}

// --- Funções de Gerenciamento de NAT ---

void configurar_nat_masquerade() {
    char if_saida[100];
    char comando[512];
    
    printf(C_GREEN "\n--- Compartilhar Conexão de Internet (MASQUERADE) ---\n" C_RESET);
    obter_input("Digite a interface de SAÍDA (a que tem internet, ex: eth0): ", if_saida, sizeof(if_saida));

    if (strlen(if_saida) == 0) {
        printf(C_RED "Interface inválida.\n" C_RESET);
        return;
    }

    // Habilita o encaminhamento de pacotes no kernel
    executar_comando("echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward");
    
    // Adiciona a regra de MASQUERADE na tabela NAT
    snprintf(comando, sizeof(comando), "sudo iptables -t nat -A POSTROUTING -o %s -j MASQUERADE", if_saida);
    executar_comando(comando);
    
    printf(C_GREEN "Regra de MASQUERADE para a interface %s adicionada.\n" C_RESET, if_saida);
}

void configurar_nat_dnat() {
    char if_entrada[100], protocolo[10], porta_externa[10], ip_interno[20], porta_interna[10];
    char comando[512];

    printf(C_GREEN "\n--- Redirecionamento de Porta (DNAT) ---\n" C_RESET);
    obter_input("Interface de ENTRADA (onde a conexão chega, ex: eth0): ", if_entrada, sizeof(if_entrada));
    obter_input("Protocolo (tcp/udp): ", protocolo, sizeof(protocolo));
    obter_input("Porta Externa (a ser acessada da internet): ", porta_externa, sizeof(porta_externa));
    obter_input("IP Interno (para onde redirecionar): ", ip_interno, sizeof(ip_interno));
    obter_input("Porta Interna (se for diferente da externa, senão deixe em branco): ", porta_interna, sizeof(porta_interna));
    
    if (strlen(porta_interna) == 0) {
        strcpy(porta_interna, porta_externa);
    }

    // Habilita o encaminhamento de pacotes no kernel
    executar_comando("echo 1 | sudo tee /proc/sys/net/ipv4/ip_forward");
    
    // Regra de DNAT (PREROUTING)
    snprintf(comando, sizeof(comando), "sudo iptables -t nat -A PREROUTING -i %s -p %s --dport %s -j DNAT --to-destination %s:%s",
        if_entrada, protocolo, porta_externa, ip_interno, porta_interna);
    executar_comando(comando);
    
    // Regra de FORWARD para permitir o tráfego
    snprintf(comando, sizeof(comando), "sudo iptables -A FORWARD -i %s -p %s -d %s --dport %s -j ACCEPT",
        if_entrada, protocolo, ip_interno, porta_interna);
    executar_comando(comando);

    printf(C_GREEN "Redirecionamento da porta %s para %s:%s configurado.\n" C_RESET, porta_externa, ip_interno, porta_interna);
}


// --- Menus da Interface ---

void menu_gerenciar_chain(const char* tabela) {
    char chain[20];
    int opcao = -1;

    limpar_tela();
    printf(C_GREEN "Tabela selecionada: [%s]\n" C_RESET, tabela);
    obter_input("Digite o nome da Chain a gerenciar (ex: INPUT, FORWARD): ", chain, sizeof(chain));

    if (strlen(chain) == 0) return;

    while (opcao != 0) {
        limpar_tela();
        printf(C_GREEN "Gerenciando: Tabela [%s] -> Chain [%s]\n\n" C_RESET, tabela, chain);
        listar_regras(tabela, chain);
        
        printf("\nOpções para a chain '%s':\n", chain);
        printf("  1. Adicionar nova regra (Assistente Guiado)\n");
        printf("  2. Apagar uma regra (pelo número)\n");
        printf("  0. Voltar ao menu de tabelas\n");
        printf(C_CYAN "Escolha uma opção: " C_RESET);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: adicionar_regra_guiada(tabela, chain); break;
            case 2: apagar_regra(tabela, chain); break;
            case 0: break;
            default: printf(C_RED "Opção inválida.\n" C_RESET); break;
        }
        if (opcao != 0) pressione_enter();
    }
}

void menu_nat() {
    int opcao = -1;
    while(opcao != 0) {
        limpar_tela();
        printf(C_GREEN "--- Gerenciamento de NAT ---\n\n" C_RESET);
        printf("  1. Compartilhar Internet (MASQUERADE)\n");
        printf("  2. Redirecionar Porta (DNAT)\n");
        printf("  3. Listar regras da tabela NAT\n");
        printf("  0. Voltar ao menu principal\n");
        printf(C_CYAN "Escolha uma opção: " C_RESET);
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: configurar_nat_masquerade(); break;
            case 2: configurar_nat_dnat(); break;
            case 3: 
                limpar_tela();
                executar_comando("sudo iptables -t nat -L -v -n --line-numbers"); 
                break;
            case 0: break;
            default: printf(C_RED "Opção inválida.\n" C_RESET); break;
        }
        if (opcao != 0) pressione_enter();
    }
}


int main() {
    if (getuid() != 0) {
        fprintf(stderr, C_RED "Erro: Este programa precisa ser executado com privilégios de root.\n" C_RESET);
        return 1;
    }

    int opcao = -1;
    while (opcao != 0) {
        limpar_tela();
        printf(C_BRIGHT C_GREEN "========================================\n");
        printf("         DANOS FIREWALL PRO         \n");
        printf("========================================\n\n" C_RESET);
        printf(C_YELLOW "--- MENU PRINCIPAL ---\n" C_RESET);
        printf("  1. Gerenciar Tabela 'filter' (Padrão: bloquear/permitir pacotes)\n");
        printf("  2. Gerenciar Tabela 'nat' (Redirecionamento, compartilhar internet)\n");
        printf("  3. Gerenciar Tabela 'mangle' (Modificação avançada de pacotes)\n");
        printf("\n  4. Funções Rápidas de NAT\n");
        printf("\n  9. Salvar todas as regras permanentemente\n");
        printf("  0. Sair\n");
        printf(C_CYAN "Escolha uma opção: " C_RESET);
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: menu_gerenciar_chain("filter"); break;
            case 2: menu_gerenciar_chain("nat"); break;
            case 3: menu_gerenciar_chain("mangle"); break;
            case 4: menu_nat(); break;
            case 9: 
                executar_comando("sudo iptables-save > /etc/iptables/rules.v4");
                printf(C_GREEN "Regras salvas em /etc/iptables/rules.v4. Instale 'iptables-persistent' para carregar no boot.\n" C_RESET);
                break;
            case 0: break;
            default: printf(C_RED "Opção inválida.\n" C_RESET); break;
        }
        if (opcao != 0 && opcao < 9) pressione_enter();
    }
    
    printf(C_GREEN "\nSaindo do Danos Firewall Pro.\n" C_RESET);
    return 0;
}
