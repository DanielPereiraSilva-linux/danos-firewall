#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Para getuid() e sleep()

// --- Definições de Cores para o Terminal ---
#define RESET   "\x1b[0m"
#define VERMELHO "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARELO "\x1b[33m"
#define AZUL    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CIANO   "\x1b[36m"
#define BRANCO  "\x1b[37m"

// --- Protótipos das Funções ---

// Funções Auxiliares e de Verificação
void verificar_dependencias();
void verificar_root();
void limpar_tela();
void pressione_enter_para_continuar();
void exibir_menu();
void executar_comando(const char* comando, int silencioso);

// Funções de Firewall Padrão
void exibir_regras();
void adicionar_porta();
void remover_porta();
void definir_politica_padrao();
void limpar_todas_regras();
void salvar_regras();
void restaurar_regras();

// Funções de Segurança Avançada
void configurar_porta_armadilha();
void atualizar_lista_ameacas();
void ativar_protecao_ssh();

// --- Função Principal ---
int main() {
    verificar_dependencias();
    verificar_root(); 
    int opcao = -1;

    while (opcao != 0) {
        limpar_tela();
        exibir_menu();
        printf(CIANO "Escolha uma opção: " RESET);
        
        if (scanf("%d", &opcao) != 1) {
            while (getchar() != '\n'); 
            opcao = -1;
        }

        switch (opcao) {
            case 1:  exibir_regras(); break;
            case 2:  adicionar_porta(); break;
            case 3:  remover_porta(); break;
            case 4:  definir_politica_padrao(); break;
            case 5:  salvar_regras(); break;
            case 6:  restaurar_regras(); break;
            
            case 10: configurar_porta_armadilha(); break;
            case 11: atualizar_lista_ameacas(); break;
            case 12: ativar_protecao_ssh(); break;

            case 99: limpar_todas_regras(); break;
            case 0:  printf(AMARELO "\nSaindo do Danos Firewall Manager. Até logo!\n\n" RESET); break;
            default: printf(VERMELHO "\nOpção inválida! Tente novamente.\n" RESET); break;
        }

        if (opcao != 0) {
            pressione_enter_para_continuar();
        }
    }
    return 0;
}

// --- Implementação das Funções de Verificação e Auxiliares ---

void verificar_dependencias() {
    printf(CIANO "Verificando integridade do sistema e dependências...\n" RESET);
    int erro = 0;
    
    const char* dependencias[][2] = {
        {"iptables", "iptables"},
        {"ipset", "ipset"},
        {"curl", "curl"}
    };
    
    char comando_verificacao[100];
    char pacotes_faltando[200] = "";

    for (int i = 0; i < 3; i++) {
        snprintf(comando_verificacao, sizeof(comando_verificacao), "command -v %s > /dev/null 2>&1", dependencias[i][0]);
        if (system(comando_verificacao) != 0) {
            erro = 1;
            strcat(pacotes_faltando, dependencias[i][1]);
            strcat(pacotes_faltando, " ");
        }
    }

    if (erro) {
        printf(VERMELHO "\n--- ERRO: DEPENDÊNCIAS FALTANDO ---\n" RESET);
        printf(AMARELO "Para funcionar, esta ferramenta precisa dos seguintes pacotes: %s\n", pacotes_faltando);
        printf(AMARELO "Eles não parecem estar instalados no seu sistema.\n\n");
        printf(CIANO "Por favor, execute o seguinte comando para instalá-los:\n" RESET);
        printf(VERDE "\nsudo apt-get update && sudo apt-get install %s\n\n", pacotes_faltando);
        printf(VERMELHO "O programa será encerrado.\n" RESET);
        exit(EXIT_FAILURE);
    }
    
    printf(VERDE "Dependências verificadas. Sistema pronto.\n" RESET);
    sleep(1); 
}


void verificar_root() {
    if (getuid() != 0) {
        limpar_tela();
        printf(VERMELHO "Erro fatal: Privilégios de superusuário são necessários para gerenciar o firewall.\n" RESET);
        printf(AMARELO "Use: sudo ./danos-firewall\n" RESET);
        exit(EXIT_FAILURE);
    }
}

void limpar_tela() {
    system("clear");
}

void pressione_enter_para_continuar() {
    printf(AMARELO "\n\nPressione Enter para continuar..." RESET);
    while (getchar() != '\n'); 
    getchar(); 
}

void executar_comando(const char* comando, int silencioso) {
    if (!silencioso) {
        printf(AZUL "Executando comando no sistema... " RESET);
    }
    int status = system(comando);
    if (status == 0) {
        if (!silencioso) printf(VERDE "OK.\n" RESET);
    } else {
        if (!silencioso) printf(VERMELHO "FALHA.\n" RESET);
    }
}

void exibir_menu() {
    printf(CIANO "############################################################\n");
    printf(CIANO "#" VERDE "      DDDD      A      N   N    OOO     SSSSS           " CIANO "#\n");
    printf(CIANO "#" VERDE "      D   D    A A     NN  N   O   O   S                " CIANO "#\n");
    printf(CIANO "#" VERDE "      D   D   AAAAA    N N N   O   O    SSSSS           " CIANO "#\n");
    printf(CIANO "#" VERDE "      D   D  A     A   N  NN   O   O         S          " CIANO "#\n");
    printf(CIANO "#" VERDE "      DDDD  A       A  N   N    OOO     SSSSS           " CIANO "#\n");
    printf(CIANO "#                                                          #\n");
    printf(CIANO "#" MAGENTA "            Danos Firewall Manager v0.10.1             " CIANO "#\n");
    printf(CIANO "############################################################\n\n");
    printf(BRANCO "--- Gerenciamento Básico de Regras ---\n" RESET);
    printf(VERDE "  [ 1] " RESET "Verificar Status do Firewall (Listar Regras)\n");
    printf(VERDE "  [ 2] " RESET "Permitir Tráfego em uma Porta\n");
    printf(VERDE "  [ 3] " RESET "Bloquear Regra de uma Porta\n");
    printf(VERDE "  [ 4] " RESET "Definir Política Padrão (ACCEPT/DROP)\n");
    printf(VERDE "  [ 5] " RESET "Salvar Configuração Atual de Regras\n");
    printf(AMARELO "  [ 6] " RESET "Restaurar Última Configuração Salva\n");
    printf(BRANCO "\n--- Módulos Avançados de Segurança ---\n" RESET);
    printf(MAGENTA "  [10] " RESET "Ativar Porta Armadilha (Honeypot)\n");
    printf(MAGENTA "  [11] " RESET "Sincronizar com Lista de Ameaças Global\n");
    printf(MAGENTA "  [12] " RESET "Ativar Proteção SSH (Anti-Força Bruta)\n");
    printf(AZUL "  --------------------------------------------------------\n");
    printf(VERMELHO "  [99] " RESET "Resetar Firewall (Remover Todas as Regras)\n");
    printf(VERMELHO "  [ 0] " RESET "Sair\n\n");
}


// --- Implementação das Funções de Firewall Padrão ---

void exibir_regras() {
    printf(CIANO "\n--- Status Atual das Regras do Firewall ---\n\n" RESET);
    executar_comando("iptables -L -v -n --line-numbers", 1); 
}

void adicionar_porta() {
    int porta;
    char protocolo[5];
    char comando[256];
    printf(CIANO "Digite a porta que deseja permitir: " RESET);
    scanf("%d", &porta);
    printf(CIANO "Digite o protocolo (tcp ou udp): " RESET);
    scanf("%s", protocolo);
    snprintf(comando, sizeof(comando), "iptables -A INPUT -p %s --dport %d -j ACCEPT > /dev/null 2>&1", protocolo, porta);
    executar_comando(comando, 0);
}

void remover_porta() {
    int porta;
    char protocolo[5];
    char comando[256];
    printf(CIANO "Digite a porta da regra que deseja remover: " RESET);
    scanf("%d", &porta);
    printf(CIANO "Digite o protocolo (tcp ou udp) da regra: " RESET);
    scanf("%s", protocolo);
    snprintf(comando, sizeof(comando), "iptables -D INPUT -p %s --dport %d -j ACCEPT > /dev/null 2>&1", protocolo, porta);
    executar_comando(comando, 0);
}

void definir_politica_padrao(){
    char chain[10], politica[10], comando[256];
    printf(CIANO "Digite a chain (INPUT, OUTPUT, FORWARD): " RESET);
    scanf("%s", chain);
    printf(CIANO "Digite a política padrão (ACCEPT ou DROP): " RESET);
    scanf("%s", politica);
    snprintf(comando, sizeof(comando), "iptables -P %s %s > /dev/null 2>&1", chain, politica);
    executar_comando(comando, 0);
}

void salvar_regras() {
    printf(CIANO "\nSalvando configuração de regras...\n" RESET);
    executar_comando("mkdir -p /etc/iptables", 1);
    executar_comando("iptables-save > /etc/iptables/rules.v4", 1);
    printf(VERDE "Configuração salva com sucesso em /etc/iptables/rules.v4\n" RESET);
}

void restaurar_regras() {
    printf(CIANO "\nRestaurando configuração de regras...\n" RESET);
    executar_comando("iptables-restore < /etc/iptables/rules.v4", 0);
}

void limpar_todas_regras() {
    char confirmacao[5];
    printf(VERMELHO "!!! ATENÇÃO !!!\n");
    printf(AMARELO "Esta ação irá remover TODAS as regras e deixar o sistema completamente aberto.\n");
    printf(CIANO "Confirmar? (sim/nao): " RESET);
    scanf("%s", confirmacao);
    if (strcmp(confirmacao, "sim") == 0) {
        printf(VERMELHO "\nResetando firewall...\n" RESET);
        executar_comando("ipset flush blacklist > /dev/null 2>&1", 1);
        executar_comando("iptables -F && iptables -X && iptables -Z", 1);
        executar_comando("iptables -P INPUT ACCEPT && iptables -P OUTPUT ACCEPT && iptables -P FORWARD ACCEPT", 1);
        printf(VERDE "Firewall resetado. Todas as regras foram removidas.\n" RESET);
    } else {
        printf(VERDE "\nOperação cancelada. As regras permanecem inalteradas.\n" RESET);
    }
}


// --- Implementação dos Módulos Avançados de Segurança ---

void configurar_porta_armadilha() {
    int porta;
    char comando[256];
    printf(VERMELHO "--- Módulo H.O.N.E.Y.P.O.T ---\n" RESET);
    printf(AMARELO "Este módulo criará uma porta falsa. Qualquer IP que tentar acessá-la será banido.\n" RESET);
    printf(CIANO "Escolha uma porta para a armadilha (ex: 23 para Telnet, 3307 para um falso MySQL): " RESET);
    scanf("%d", &porta);

    printf(CIANO "Armando o sistema...\n" RESET);
    executar_comando("ipset create blacklist hash:ip timeout 86400 -exist", 1);
    executar_comando("iptables -N HONEYPOT_TRAP > /dev/null 2>&1", 1);
    snprintf(comando, sizeof(comando), "iptables -F HONEYPOT_TRAP > /dev/null 2>&1");
    executar_comando(comando, 1);
    snprintf(comando, sizeof(comando), "iptables -A HONEYPOT_TRAP -j SET --add-set blacklist src --exist");
    executar_comando(comando, 1);
    executar_comando("iptables -A HONEYPOT_TRAP -j DROP", 1);
    snprintf(comando, sizeof(comando), "iptables -A INPUT -p tcp --dport %d -j HONEYPOT_TRAP", porta);
    executar_comando(comando, 1);
    executar_comando("iptables -I INPUT 1 -m set --match-set blacklist src -j DROP", 1);
    
    printf(VERDE "Armadilha na porta %d ativada. O sistema agora caça ativamente por ameaças.\n" RESET, porta);
}


void atualizar_lista_ameacas() {
    printf(CIANO "\n--- Módulo de Inteligência Global ---\n" RESET);
    printf(AMARELO "Conectando a fontes de ameaças para baixar lista de IPs maliciosos conhecidos...\n" RESET);

    const char* url_blocklist = "https://raw.githubusercontent.com/firehol/firehol_level1/master/firehol_level1.netset";
    const char* arquivo_temp = "/tmp/blocklist.txt";
    char comando[512];
    snprintf(comando, sizeof(comando), "curl -s --connect-timeout 10 -o %s %s", arquivo_temp, url_blocklist);
    
    int status = system(comando);
    if (status != 0) {
        printf(VERMELHO "Falha ao baixar a lista de ameaças. Verifique a conexão com a internet.\n" RESET);
        return;
    }
    
    printf(VERDE "Lista de ameaças baixada. Processando e aplicando...\n" RESET);
    
    executar_comando("ipset create blacklist hash:ip timeout 86400 -exist", 1);
    executar_comando("ipset flush blacklist", 1);

    FILE* fp = fopen(arquivo_temp, "r");
    if (fp == NULL) {
        printf(VERMELHO "Não foi possível abrir o arquivo da lista de ameaças.\n" RESET);
        return;
    }

    char linha[256];
    int contador = 0;
    while (fgets(linha, sizeof(linha), fp)) {
        if (linha[0] == '#' || linha[0] == '\n') continue;
        linha[strcspn(linha, "\n")] = 0;
        snprintf(comando, sizeof(comando), "ipset add blacklist %s > /dev/null 2>&1", linha);
        executar_comando(comando, 1);
        contador++;
    }
    fclose(fp);
    remove(arquivo_temp); 

    executar_comando("iptables -I INPUT 1 -m set --match-set blacklist src -j DROP > /dev/null 2>&1", 1);

    printf(VERDE "Sincronização concluída! %d ameaças globais foram neutralizadas.\n" RESET, contador);
}


void ativar_protecao_ssh() {
    char comando[512];
    printf(CIANO "\n--- Módulo Proteção SSH ---\n" RESET);
    printf(AMARELO "Ativando detecção e bloqueio automático de ataques de força bruta na porta 22 (SSH).\n" RESET);
    
    snprintf(comando, sizeof(comando), "iptables -A INPUT -p tcp --dport 22 -m conntrack --ctstate NEW -m recent --set --name SSH --rsource");
    executar_comando(comando, 1);

    snprintf(comando, sizeof(comando), "iptables -A INPUT -p tcp --dport 22 -m conntrack --ctstate NEW -m recent --update --seconds 60 --hitcount 4 --name SSH --rsource -j DROP");
    executar_comando(comando, 1);

    printf(VERDE "Proteção SSH ativada. Conexões suspeitas serão bloqueadas automaticamente.\n" RESET);
}
