# Danos Firewall Manager

![Logo Danos Firewall Manager](https://github.com/DanielPereiraSilva-linux/danos-firewall/blob/main/logo_danos_firewall.png?raw=true)
O **Danos Firewall Manager** é uma ferramenta de linha de comando robusta e intuitiva, desenvolvida em C, projetada para simplificar a administração de tarefas essenciais do sistema em ambientes Linux. **Atualmente, este script foi rigorosamente testado e tem seu funcionamento garantido em distribuições baseadas em Debian, como o Ubuntu.** Sua principal missão é otimizar e centralizar o gerenciamento do **firewall** (`iptables`), a supervisão e controle de **serviços**, a execução de **atualizações** do sistema e a administração de **usuários** de maneira ágil, eficiente e segura.

> **Atenção:** A maioria das funcionalidades deste script requer permissões de superusuário (root) para serem executadas com sucesso. Isso inclui operações como modificação das regras do firewall, instalação de atualizações do sistema e gerenciamento de usuários.

---

## Funcionalidades Detalhadas

O Danos Firewall Manager oferece uma suíte de funcionalidades que cobre aspectos cruciais da administração de sistemas:

-   **Gerenciamento de Firewall (`iptables`):** Permite visualizar as regras ativas, além de adicionar ou remover portas específicas para controle de tráfego de rede.
-   **Atualização do Sistema:** Facilita a manutenção do sistema, atualizando a lista de pacotes e realizando upgrades completos com comandos simplificados.
-   **Supervisão de Serviços:** Oferece uma visão rápida dos serviços que estão atualmente em execução no sistema.
-   **Backup e Restauração de Firewall:** Garante a segurança das suas configurações de firewall, possibilitando criar backups e restaurá-los em caso de necessidade.
-   **Configuração de DNS:** Simplifica a adição ou remoção de servidores DNS, afetando a resolução de nomes de domínio do sistema.
-   **Gerenciamento de Usuários:** Fornece ferramentas para bloquear ou reativar o acesso de usuários ao sistema.

---

## Instalação

Para instalar e começar a usar o `danos` em seu sistema, execute o comando abaixo em seu terminal. Este comando automatiza o processo de clonar o repositório, conceder permissões de execução ao executável e movê-lo para um diretório do sistema (`/bin`), garantindo que o `danos` possa ser invocado de qualquer lugar.

```bash
sudo git clone [https://github.com/DanielPereiraSilva-linux/danos-firewall.git](https://github.com/DanielPereiraSilva-linux/danos-firewall.git) /tmp/danos-install && sudo chmod +x /tmp/danos-install/danos && sudo mv /tmp/danos-install/danos /bin/ && sudo rm -rf /tmp/danos-install
```

Após a execução bem-sucedida, o comando `danos` estará disponível globalmente no seu terminal.

---

## Uso

O formato geral para utilizar o `danos` é:

```bash
danos [opcao] [comando] [argumentos]
```

### Opções Globais

As opções globais são utilizadas para obter informações sobre o próprio script:

-   **`-h` (Ajuda):**
    -   **Descrição:** Exibe uma lista completa de todas as opções e comandos disponíveis no Danos Firewall Manager, incluindo seus respectivos usos e argumentos. É o ponto de partida ideal para qualquer usuário novo.
    -   **Exemplo de Uso:**
        ```bash
        danos -h
        ```

-   **`-v` (Versão):**
    -   **Descrição:** Mostra a versão atual do script Danos Firewall Manager, útil para verificar se você está usando a versão mais recente ou para fins de depuração.
    -   **Exemplo de Uso:**
        ```bash
        danos -v
        ```

### Comandos Disponíveis e Seus Parâmetros

Os comandos são as ações específicas que o Danos Firewall Manager pode executar. Abaixo, detalhamos cada um:

#### 1. `regras`

-   **Descrição:** Lista todas as regras ativas do firewall `iptables` no sistema. Permite uma visão geral das políticas de filtragem de pacotes configuradas, mostrando as cadeias INPUT, FORWARD e OUTPUT.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos regras
    ```

#### 2. `addport <numero_porta> <protocolo>`

-   **Descrição:** Adiciona uma nova regra ao firewall para permitir o tráfego de entrada (INPUT) em uma porta específica para um determinado protocolo. Isso é essencial para permitir que serviços externos acessem sua máquina.
-   **Parâmetros:**
    -   `<numero_porta>`: O número da porta que você deseja abrir (e.g., `80` para HTTP, `22` para SSH, `443` para HTTPS).
    -   `<protocolo>`: O protocolo de rede associado à porta. Aceita `tcp` (Transmission Control Protocol) ou `udp` (User Datagram Protocol).
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    -   Para abrir a porta 80 (HTTP) usando TCP:
        ```bash
        sudo danos addport 80 tcp
        ```
    -   Para abrir a porta 53 (DNS) usando UDP:
        ```bash
        sudo danos addport 53 udp
        ```

#### 3. `removeport <numero_porta> <protocolo>`

-   **Descrição:** Remove uma regra existente do firewall que permite o tráfego de entrada em uma porta específica para um determinado protocolo. Este comando é crucial para fechar portas que não são mais necessárias, aumentando a segurança do sistema.
-   **Parâmetros:**
    -   `<numero_porta>`: O número da porta que você deseja fechar.
    -   `<protocolo>`: O protocolo de rede associado à porta. Aceita `tcp` ou `udp`.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    -   Para fechar a porta 80 (HTTP) usando TCP:
        ```bash
        sudo danos removeport 80 tcp
        ```
    -   Para fechar a porta 53 (DNS) usando UDP:
        ```bash
        sudo danos removeport 53 udp
        ```

#### 4. `services`

-   **Descrição:** Exibe uma lista dos serviços do sistema que estão atualmente em execução. Este comando utiliza `systemctl` (padrão em sistemas Systemd como Ubuntu e Debian) para listar units do tipo `service` com estado `running`, útil para monitorar o estado dos processos em segundo plano.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Não requer `sudo`, mas pode listar mais detalhes com ele.
-   **Exemplo de Uso:**
    ```bash
    danos services
    ```

#### 5. `update`

-   **Descrição:** Atualiza os índices de pacotes dos repositórios configurados no sistema. Este é o primeiro passo para garantir que você esteja baixando as informações mais recentes sobre os pacotes disponíveis. Equivale a `sudo apt-get update`.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos update
    ```

#### 6. `upgrade`

-   **Descrição:** Atualiza todos os pacotes instalados no sistema para suas versões mais recentes, conforme os índices de pacotes atualizados. Este comando pode exigir confirmação do usuário (`-y` é adicionado para aceitar automaticamente). Equivale a `sudo apt-get upgrade -y`.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos upgrade
    ```

#### 7. `backup`

-   **Descrição:** Cria um backup das regras atuais do firewall `iptables`. As regras são salvas em um arquivo `/tmp/iptables-backup.conf`, que pode ser usado posteriormente para restaurar a configuração.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos backup
    ```

#### 8. `restore`

-   **Descrição:** Restaura as regras do firewall `iptables` a partir de um arquivo de backup previamente criado (espera-se que esteja em `/tmp/iptables-backup.conf`). Use este comando para reverter o firewall para um estado anterior.
-   **Parâmetros:** Nenhum.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos restore
    ```

#### 9. `dns <acao> <endereco_dns>`

-   **Descrição:** Gerencia os servidores DNS configurados no arquivo `/etc/resolv.conf`. Permite adicionar um novo servidor DNS ou remover um existente.
-   **Parâmetros:**
    -   `<acao>`: A ação a ser realizada. Aceita `add` para adicionar um servidor DNS ou `remove` para remover um.
    -   `<endereco_dns>`: O endereço IP do servidor DNS (e.g., `8.8.8.8` para Google DNS, `1.1.1.1` para Cloudflare DNS).
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    -   Para adicionar o DNS do Google:
        ```bash
        sudo danos dns add 8.8.8.8
        ```
    -   Para remover o DNS do Google:
        ```bash
        sudo danos dns remove 8.8.8.8
        ```

#### 10. `block-user <nome_usuario>`

-   **Descrição:** Bloqueia um usuário específico do sistema, impedindo que ele faça login. Isso é feito travando a senha do usuário (`usermod -L`). O usuário não poderá mais acessar o sistema até ser reativado.
-   **Parâmetros:**
    -   `<nome_usuario>`: O nome de usuário da conta a ser bloqueada.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos block-user joao
    ```

#### 11. `allow-user <nome_usuario>`

-   **Descrição:** Permite que um usuário previamente bloqueado volte a fazer login no sistema. Isso é feito destravando a senha do usuário (`usermod -U`).
-   **Parâmetros:**
    -   `<nome_usuario>`: O nome de usuário da conta a ser reativada.
-   **Requisitos:** Permissões de `sudo`.
-   **Exemplo de Uso:**
    ```bash
    sudo danos allow-user joao
    ```

---

## Contribuições

Sua colaboração é muito bem-vinda! Se você deseja contribuir com o projeto, encontrou um bug, tem uma sugestão de nova funcionalidade ou melhoria, por favor:
- Abra uma **Issue** para relatar bugs ou sugerir novas ideias.
- Envie um **Pull Request** com suas implementações e melhorias.

---
