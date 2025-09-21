#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para exibir a ajuda sobre os comandos disponíveis
void exibir_ajuda() {
    printf("Uso: danos [opcao] [comando] [argumentos]\n");
    printf("Opcoes disponíveis:\n");
    printf("  -h        Exibe esta ajuda\n");
    printf("  -v        Exibe a versão do script\n");
    printf("Comandos disponíveis:\n");
    printf("  regras    Exibe as regras do firewall\n");
    printf("  addport   Adiciona uma porta ao firewall\n");
    printf("  removeport Remove uma porta do firewall\n");
    printf("  services  Lista os serviços em execução\n");
    printf("  update    Atualiza o sistema\n");
    printf("  upgrade   Atualiza todos os pacotes do sistema\n");
    printf("  backup    Cria um backup das regras do firewall\n");
    printf("  restore   Restaura o backup das regras do firewall\n");
    printf("  dns       Configura servidores DNS\n");
    printf("  block-user Bloqueia um usuário\n");
    printf("  allow-user Permite um usuário\n");
}

// Função para exibir a versão do script
void exibir_versao() {
    printf("Danos Firewall Manager - Versão 1.0\n");
}

// Função para exibir as regras do firewall
void exibir_regras() {
    printf("Exibindo as regras do firewall...\n");
    system("iptables -L");
}

// Função para adicionar uma porta ao firewall
void adicionar_porta(int porta, char *protocolo) {
    char comando[100];
    snprintf(comando, sizeof(comando), "iptables -A INPUT -p %s --dport %d -j ACCEPT", protocolo, porta);
    system(comando);
    printf("Porta %d %s adicionada ao firewall.\n", porta, protocolo);
}

// Função para remover uma porta do firewall
void remover_porta(int porta, char *protocolo) {
    char comando[100];
    snprintf(comando, sizeof(comando), "iptables -D INPUT -p %s --dport %d -j ACCEPT", protocolo, porta);
    system(comando);
    printf("Porta %d %s removida do firewall.\n", porta, protocolo);
}

// Função para listar os serviços em execução
void listar_servicos() {
    printf("Exibindo os serviços em execução...\n");
    system("systemctl list-units --type=service --state=running");
}

// Função para atualizar o sistema
void atualizar_sistema() {
    printf("Atualizando repositórios...\n");
    system("sudo apt-get update");
    printf("Sistema atualizado.\n");
}

// Função para atualizar todos os pacotes
void atualizar_pacotes() {
    printf("Atualizando todos os pacotes...\n");
    system("sudo apt-get upgrade -y");
    printf("Todos os pacotes foram atualizados.\n");
}

// Função para criar um backup das regras do firewall
void criar_backup() {
    printf("Criando backup das regras do firewall...\n");
    system("iptables-save > /tmp/iptables-backup.conf");
    printf("Backup das regras criado em /tmp/iptables-backup.conf\n");
}

// Função para restaurar o backup do firewall
void restaurar_backup() {
    printf("Restaurando backup do firewall...\n");
    system("iptables-restore < /tmp/iptables-backup.conf");
    printf("Backup restaurado.\n");
}

// Função para configurar o DNS
void configurar_dns(char *acao, char *dns) {
    if (strcmp(acao, "add") == 0) {
        printf("Adicionando o DNS %s...\n", dns);
        char comando[100];
        snprintf(comando, sizeof(comando), "echo 'nameserver %s' | sudo tee -a /etc/resolv.conf", dns);
        system(comando);
    } else if (strcmp(acao, "remove") == 0) {
        printf("Removendo o DNS %s...\n", dns);
        char comando[100];
        snprintf(comando, sizeof(comando), "sudo sed -i '/nameserver %s/d' /etc/resolv.conf", dns);
        system(comando);
    } else {
        printf("Ação desconhecida. Use 'add' ou 'remove'.\n");
    }
}

// Função para bloquear um usuário
void bloquear_usuario(char *usuario) {
    char comando[100];
    snprintf(comando, sizeof(comando), "sudo usermod -L %s", usuario);
    system(comando);
    printf("Usuário %s bloqueado.\n", usuario);
}

// Função para permitir um usuário
void permitir_usuario(char *usuario) {
    char comando[100];
    snprintf(comando, sizeof(comando), "sudo usermod -U %s", usuario);
    system(comando);
    printf("Usuário %s permitido.\n", usuario);
}

// Função principal - processa os argumentos e executa as funções apropriadas
int main(int argc, char *argv[]) {
    if (argc < 2) {
        exibir_ajuda();
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0) {
        exibir_ajuda();
    } else if (strcmp(argv[1], "-v") == 0) {
        exibir_versao();
    } else if (strcmp(argv[1], "regras") == 0) {
        exibir_regras();
    } else if (strcmp(argv[1], "addport") == 0 && argc == 4) {
        int porta = atoi(argv[2]);
        adicionar_porta(porta, argv[3]);
    } else if (strcmp(argv[1], "removeport") == 0 && argc == 4) {
        int porta = atoi(argv[2]);
        remover_porta(porta, argv[3]);
    } else if (strcmp(argv[1], "services") == 0) {
        listar_servicos();
    } else if (strcmp(argv[1], "update") == 0) {
        atualizar_sistema();
    } else if (strcmp(argv[1], "upgrade") == 0) {
        atualizar_pacotes();
    } else if (strcmp(argv[1], "backup") == 0) {
        criar_backup();
    } else if (strcmp(argv[1], "restore") == 0) {
        restaurar_backup();
    } else if (strcmp(argv[1], "dns") == 0 && argc == 4) {
        configurar_dns(argv[2], argv[3]);
    } else if (strcmp(argv[1], "block-user") == 0 && argc == 3) {
        bloquear_usuario(argv[2]);
    } else if (strcmp(argv[1], "allow-user") == 0 && argc == 3) {
        permitir_usuario(argv[2]);
    } else {
        printf("Comando desconhecido. Use -h para ajuda.\n");
    }

    return 0;
}
