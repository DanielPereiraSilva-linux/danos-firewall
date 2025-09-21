# Danos Firewall Manager

O **Danos Firewall Manager** é uma ferramenta de linha de comando simples e eficaz, escrita em C, para gerenciar tarefas comuns de administração de sistema. **Atualmente, o script foi testado e é garantido que funcione em distribuições baseadas em Debian, como o Ubuntu.** Ele simplifica o controle do **firewall** (`iptables`), a gestão de **serviços**, a **atualização** do sistema e o **gerenciamento de usuários** de forma rápida e segura.

> **Atenção:** Este script deve ser executado com permissões de superusuário (root) para a maioria de suas funções, como a modificação das regras do firewall e atualizações do sistema.

---

## Funcionalidades

- **Gerenciamento de Firewall:** Adicione, remova e visualize regras `iptables`.
- **Atualização do Sistema:** Execute `apt-get update` e `apt-get upgrade` com um único comando.
- **Serviços:** Liste os serviços do sistema em execução.
- **Backup e Restauração:** Crie e restaure backups das regras do firewall.
- **Configuração de DNS:** Adicione ou remova servidores DNS.
- **Gerenciamento de Usuários:** Bloqueie ou desbloqueie usuários do sistema.

---

## Instalação

Para instalar e usar o `danos` no seu sistema, siga estes passos simples:

1.  **Baixe o executável `danos` para o seu computador.**
    (Adicione o link para o download aqui, por exemplo: `[danos](https://github.com/seuperfil/seurepositorio/releases/download/v1.0/danos)`)

2.  **Mova o arquivo para o diretório de comandos do sistema:**
    ```bash
    sudo mv danos /bin/
    ```

3.  **Dê permissões de execução para o arquivo:**
    ```bash
    sudo chmod +x /bin/danos
    ```

Agora você pode usar o comando `danos` de qualquer diretório no seu terminal.

---

## Uso

O formato de uso geral do comando é:
`danos [opção] [comando] [argumentos]`

### Opções Disponíveis

-   `danos -h`: Exibe a ajuda com todos os comandos e opções disponíveis.
-   `danos -v`: Exibe a versão atual do script.

### Comandos e Exemplos

| Comando | Descrição | Exemplo de Uso |
| :--- | :--- | :--- |
| `regras` | Exibe as regras do firewall (iptables). | `sudo danos regras` |
| `addport` | Adiciona uma porta ao firewall. | `sudo danos addport 22 tcp` |
| `removeport` | Remove uma porta do firewall. | `sudo danos removeport 80 tcp` |
| `services` | Lista os serviços em execução no sistema. | `danos services` |
| `update` | Atualiza os repositórios do sistema (`apt-get update`). | `sudo danos update` |
| `upgrade` | Atualiza todos os pacotes instalados (`apt-get upgrade`). | `sudo danos upgrade` |
| `backup` | Cria um backup das regras do firewall em `/tmp/iptables-backup.conf`. | `sudo danos backup` |
| `restore` | Restaura as regras do firewall a partir do arquivo de backup. | `sudo danos restore` |
| `dns` | Adiciona ou remove um servidor DNS. | `sudo danos dns add 8.8.8.8`<br>`sudo danos dns remove 8.8.8.8`|
| `block-user` | Bloqueia um usuário, impedindo o login. | `sudo danos block-user joao` |
| `allow-user` | Permite o login de um usuário bloqueado. | `sudo danos allow-user joao` |

---

## Contribuições

Se você quiser contribuir, encontrou um bug ou tem uma ideia de nova funcionalidade, sinta-se à vontade para abrir uma **issue** ou enviar um **pull request**.
