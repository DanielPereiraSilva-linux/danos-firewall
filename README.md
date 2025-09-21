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

Para instalar e usar o `danos` no seu sistema, basta executar o seguinte comando no terminal. Ele irá clonar o repositório, dar permissão de execução ao arquivo e movê-lo para o diretório de comandos do sistema, limpando a pasta temporária em seguida.

```bash
sudo git clone [https://github.com/DanielPereiraSilva-linux/danos-firewall.git](https://github.com/DanielPereiraSilva-linux/danos-firewall.git) /tmp/danos-install && sudo chmod +x /tmp/danos-install/danos && sudo mv /tmp/danos-install/danos /bin/ && sudo rm -rf /tmp/danos-install
