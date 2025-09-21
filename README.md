# Danos Firewall Manager

![Logo Danos Firewall Manager](https://github.com/DanielPereiraSilva-linux/danos-firewall/blob/main/Gemini_Generated_Image_qpzwjsqpzwjsqpzw.png?raw=true){: .img-responsive width="200px"}

---

## 🛡️ Visão Geral

O **Danos Firewall Manager** é uma ferramenta de linha de comando robusta, intuitiva e de código aberto, escrita em C. Sua missão primordial é simplificar e otimizar a administração de tarefas essenciais de segurança e manutenção em sistemas Linux. Desenvolvido para administradores de sistemas, entusiastas e qualquer pessoa que busque um controle granular sobre seu ambiente, o Danos oferece uma interface unificada para gerenciar o firewall, monitorar e controlar **serviços**, realizar **atualizações** de sistema e administrar **usuários** de forma eficiente e segura.

> **Compatibilidade:** O Danos Firewall Manager foi extensivamente testado e é **garantido para funcionar em distribuições baseadas em Debian, como Ubuntu e Debian.**
>
> **Privilégios:** A maioria das funcionalidades deste script exige **permissões de superusuário (root)** para serem executadas com sucesso. Isso é fundamental para operações que alteram as regras do firewall, modificam configurações do sistema ou gerenciam contas de usuário.

---

## ✨ Principais Funcionalidades

O Danos Firewall Manager agrupa um conjunto poderoso de ferramentas para gerenciamento de sistema:

-   **Controle Abrangente de Firewall:**
    -   **Visualização:** Exiba as regras ativas para um monitoramento transparente da sua segurança de rede.
    -   **Gerenciamento de Portas:** Adicione ou remova portas específicas para controlar o tráfego de rede de entrada, crucial para hospedar serviços ou proteger seu sistema.
-   **Manutenção e Atualização do Sistema Simplificada:**
    -   **Atualização de Repositórios:** Mantenha seus índices de pacotes atualizados para acesso às últimas versões de software.
    -   **Upgrade Completo:** Atualize todos os pacotes instalados no sistema para garantir segurança e acesso a novas funcionalidades.
-   **Supervisão de Serviços:**
    -   **Listagem:** Obtenha uma visão rápida e clara dos serviços do sistema que estão ativamente em execução, auxiliando na depuração e monitoramento.
-   **Backup e Recuperação de Configurações:**
    -   **Criação de Backup:** Salve suas configurações de firewall em um arquivo seguro, permitindo a recuperação rápida em caso de erros ou necessidades de rollback.
    -   **Restauração:** Restaure as regras do firewall a partir de um backup, garantindo a consistência das suas políticas de segurança.
-   **Configuração Avançada de DNS:**
    -   **Gerenciamento de Servidores:** Adicione ou remova servidores DNS dinamicamente, otimizando a resolução de nomes de domínio e a privacidade da navegação.
-   **Gerenciamento Simplificado de Usuários:**
    -   **Bloqueio e Desbloqueio:** Controle o acesso de usuários ao sistema, bloqueando ou reativando contas conforme a necessidade de segurança.

---

## 🚀 Instalação Rápida

A instalação do Danos Firewall Manager é simplificada para que você possa começar a usar a ferramenta em segundos. Certifique-se de ter o `git` instalado em seu sistema. Se não tiver, instale-o com:

```bash
sudo apt update && sudo apt install git -y
```

Em seguida, execute o comando abaixo no seu terminal. Ele irá clonar o repositório, conceder permissões de execução ao executável `danos`, movê-lo para o diretório `/bin` (tornando-o acessível globalmente) e, finalmente, remover os arquivos temporários da instalação.

```bash
sudo git clone [https://github.com/DanielPereiraSilva-linux/danos-firewall.git](https://github.com/DanielPereiraSilva-linux/danos-firewall.git) /tmp/danos-install && sudo chmod +x /tmp/danos-install/danos && sudo mv /tmp/danos-install/danos /bin/ && sudo rm -rf /tmp/danos-install
```

Após a execução bem-sucedida deste comando, o `danos` estará instalado e pronto para ser utilizado em qualquer diretório do seu terminal.

---

## 📖 Guia de Uso Detalhado

O Danos Firewall Manager utiliza um formato de comando intuitivo:

```bash
danos [opcao] [comando] [argumentos]
```

### Opções Globais do Script

Estas opções são utilizadas para obter informações fundamentais sobre o próprio Danos Firewall Manager.

-   **`-h` | `--help` (Ajuda):**
    -   **Descrição:** Este comando é a sua porta de entrada para o Danos. Ele exibe uma lista completa e detalhada de todas as opções e comandos disponíveis na ferramenta, incluindo seus respectivos usos, argumentos esperados e exemplos práticos. Essencial para novos usuários ou para refrescar a memória sobre qualquer funcionalidade.
    -   **Parâmetros:** Nenhum.
    -   **Requisitos:** Nenhum.
    -   **Exemplo de Uso:**
        ```bash
        danos -h
        ```

-   **`-v` | `--version` (Versão):**
    -   **Descrição:** Fornece a versão atual do Danos Firewall Manager. Útil para verificar se você está utilizando a versão mais recente, para fins de depuração ou para relatar a versão ao buscar suporte.
    -   **Parâmetros:** Nenhum.
    -   **Requisitos:** Nenhum.
    -   **Exemplo de Uso:**
        ```bash
        danos -v
        ```

### Comandos de Gerenciamento e Seus Parâmetros

Aqui, detalhamos cada comando específico que o Danos Firewall Manager pode executar, com explicações sobre seus propósitos, parâmetros e exemplos.

#### 1. `regras`

-   **Descrição:** Um comando vital para a segurança de rede. Ele lista todas as regras ativas do firewall no sistema. Isso permite uma visão abrangente das políticas de filtragem de pacotes configuradas para tráfego de entrada, saída e encaminhamento.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos regras
    ```

#### 2. `addport <numero_porta> <protocolo>`

-   **Descrição:** Adiciona uma nova regra ao firewall para permitir o tráfego de entrada em uma porta específica através de um determinado protocolo. Este comando é fundamental para expor serviços (como servidores web, SSH, bancos de dados) à rede externa ou local, garantindo que as conexões legítimas sejam aceitas.
-   **Parâmetros:**
    -   `<numero_porta>` (obrigatório): Um número inteiro que representa a porta que você deseja abrir (ex: `80` para HTTP, `22` para SSH, `443` para HTTPS).
    -   `<protocolo>` (obrigatório): O protocolo de rede associado à porta. Aceita `tcp` (Transmission Control Protocol) para serviços orientados a conexão ou `udp` (User Datagram Protocol) para serviços sem conexão.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplos de Uso:**
    -   Para permitir conexões SSH na porta 22 (TCP):
        ```bash
        sudo danos addport 22 tcp
        ```
    -   Para permitir consultas DNS na porta 53 (UDP):
        ```bash
        sudo danos addport 53 udp
        ```

#### 3. `removeport <numero_porta> <protocolo>`

-   **Descrição:** Remove uma regra previamente adicionada que permitia o tráfego de entrada em uma porta e protocolo específicos. Este comando é crucial para fechar portas que não são mais utilizadas, minimizando a superfície de ataque e aumentando a segurança do sistema ao bloquear acessos desnecessários.
-   **Parâmetros:**
    -   `<numero_porta>` (obrigatório): O número da porta que você deseja fechar.
    -   `<protocolo>` (obrigatório): O protocolo de rede associado à porta (`tcp` ou `udp`).
-   **Requisitos:** Permissões de `sudo`. **Importante:** A regra a ser removida deve corresponder exatamente a uma regra existente no firewall para ser efetivamente removida.
-   **Exemplos de Uso:**
    -   Para remover a permissão para a porta 80 (HTTP) TCP:
        ```bash
        sudo danos removeport 80 tcp
        ```
    -   Para remover a permissão para a porta 123 (NTP) UDP:
        ```bash
        sudo danos removeport 123 udp
        ```

#### 4. `services`

-   **Descrição:** Fornece uma lista concisa dos serviços do sistema que estão atualmente em um estado de execução (`running`). Este comando é uma ferramenta valiosa para monitorar o estado dos processos em segundo plano, verificar se um serviço esperado está ativo ou identificar serviços não essenciais que consomem recursos.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Não requer `sudo`, mas informações mais detalhadas ou sobre serviços restritos podem ser exibidas se executado com privilégios.
-   **Exemplo de Uso:**
    ```bash
    danos services
    ```

#### 5. `update`

-   **Descrição:** Atualiza a lista de pacotes disponíveis dos repositórios configurados no sistema. Este é o primeiro passo e uma prática recomendada antes de qualquer instalação ou atualização de software, garantindo que o gerenciador de pacotes tenha as informações mais recentes sobre os softwares disponíveis.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos update
    ```

#### 6. `upgrade`

-   **Descrição:** Realiza o upgrade de todos os pacotes instalados no sistema para suas versões mais recentes, com base nas informações obtidas pelo comando `update`. Este processo garante que seu sistema esteja com as últimas correções de segurança, melhorias de desempenho e novas funcionalidades. A operação é não-interativa.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos upgrade
    ```

#### 7. `backup`

-   **Descrição:** Cria um backup das regras atuais do firewall. As configurações são salvas em um arquivo chamado `/tmp/iptables-backup.conf`. Este backup é essencial para a recuperação de desastres, para testar novas regras com a possibilidade de reverter rapidamente para uma configuração funcional ou para migrar configurações entre sistemas.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos backup
    ```

#### 8. `restore`

-   **Descrição:** Restaura as regras do firewall a partir de um arquivo de backup previamente criado (espera-se que esteja em `/tmp/iptables-backup.conf`). Este comando substitui as regras ativas no momento pelas regras salvas no backup, sendo uma ferramenta crítica para restaurar a segurança de rede após configurações incorretas ou falhas.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos restore
    ```

#### 9. `dns <acao> <endereco_dns>`

-   **Descrição:** Gerencia os servidores DNS configurados no arquivo `/etc/resolv.conf`. Permite adicionar um novo servidor DNS para melhorar a resolução de nomes ou remover um existente para solucionar problemas ou alterar provedores de DNS.
-   **Parâmetros:**
    -   `<acao>` (obrigatório): A ação a ser realizada. Aceita `add` para incluir um servidor DNS na lista ou `remove` para retirar um.
    -   `<endereco_dns>` (obrigatório): O endereço IP do servidor DNS (ex: `8.8.8.8` para Google DNS, `1.1.1.1` para Cloudflare DNS).
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplos de Uso:**
    -   Para adicionar o DNS público do Google:
        ```bash
        sudo danos dns add 8.8.8.8
        ```
    -   Para remover o DNS público do Google:
        ```bash
        sudo danos dns remove 8.8.8.8
        ```

#### 10. `block-user <nome_usuario>`

-   **Descrição:** Bloqueia um usuário específico do sistema, impedindo-o de fazer login. Este comando modifica o status da conta do usuário, travando sua senha. É uma medida de segurança eficaz para contas comprometidas ou temporariamente suspensas.
-   **Parâmetros:**
    -   `<nome_usuario>` (obrigatório): O nome de usuário da conta a ser bloqueada.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos block-user joao
    ```

#### 11. `allow-user <nome_usuario>`

-   **Descrição:** Permite que um usuário previamente bloqueado volte a fazer login no sistema. Este comando reativa a conta do usuário, destravando sua senha e restaurando seu acesso normal.
-   **Parâmetros:**
    -   `<nome_usuario>` (obrigatório): O nome de usuário da conta a ser reativada.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos allow-user joao
    ```

---

## 🤝 Contribuições

Sua colaboração é imensamente valiosa para o aprimoramento contínuo do Danos Firewall Manager! Se você deseja contribuir com o projeto, encontrou um bug, tem uma sugestão de nova funcionalidade ou uma ideia para melhorias, por favor:

-   **Abra uma [Issue](https://github.com/DanielPereiraSilva-linux/danos-firewall/issues)**: Para relatar bugs, propor novas ideias ou discutir funcionalidades.
-   **Envie um [Pull Request](https://github.com/DanielPereiraSilva-linux/danos-firewall/pulls)**: Com suas implementações de código, correções de bugs ou melhorias de documentação.

Agradecemos o seu interesse e apoio!

---
