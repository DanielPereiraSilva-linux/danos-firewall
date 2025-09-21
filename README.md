<div align="center">
  <img src="https://raw.githubusercontent.com/MollController/Mind-Blowing_Best-README-Template/master/src/assets/banner.png" alt="banner">
</div>

<div align="center">
  
# 🛡️ Danos Firewall Manager v0.10.1 🛡️

### _Sua primeira linha de defesa inteligente, forjada em C._

</div>

**Danos Firewall Manager** não é apenas um script, é um sentinela para o seu sistema Linux. Escrito em C puro para ser ridiculamente rápido e leve, ele transforma o complexo `iptables` em um centro de comando interativo e poderoso no seu terminal. Gerencie regras, automatize defesas e cace ameaças ativamente.

<div align="center">

```
############################################################
#      DDDD      A      N   N    OOO     SSSSS           #
#      D   D    A A     NN  N   O   O   S                #
#      D   D   AAAAA    N N N   O   O    SSSSS           #
#      D   D  A     A   N  NN   O   O         S          #
#      DDDD  A       A  N   N    OOO     SSSSS           #
#                                                          #
#            Danos Firewall Manager v0.10.1             #
############################################################

--- Gerenciamento Básico de Regras ---
  [ 1] Verificar Status do Firewall (Listar Regras)
  [ 2] Permitir Tráfego em uma Porta
  [ 3] Bloquear Regra de uma Porta
  [ 4] Definir Política Padrão (ACCEPT/DROP)
  [ 5] Salvar Configuração Atual de Regras
  [ 6] Restaurar Última Configuração Salva

--- Módulos Avançados de Segurança ---
  [10] Ativar Porta Armadilha (Honeypot)
  [11] Sincronizar com Lista de Ameaças Global
  [12] Ativar Proteção SSH (Anti-Força Bruta)
  --------------------------------------------------------
  [99] Resetar Firewall (Remover Todas as Regras)
  [ 0] Sair

Escolha uma opção:
```

</div>

---

## 💥 Arsenal de Features

* **Interface Interativa:** Chega de decorar comandos. Um menu simples e colorido guia você.
* **Gerenciamento Completo:** Adicione e remova regras, defina políticas padrão e persista suas configurações.
* **🍯 Honeypot Ativo:** Crie portas-armadilha que banem automaticamente qualquer IP que tentar escaneá-las.
* **🌐 Inteligência de Ameaças:** Sincronize com blocklists globais e neutralize milhares de IPs maliciosos conhecidos.
* **🔒 Guardião SSH:** Proteja seu servidor contra ataques de força bruta, banindo IPs com múltiplas falhas de login.
* **Zero Dependências Pesadas:** Escrito em C, precisa apenas de ferramentas padrão do sistema (`curl`, `ipset`).
* **Verificação Automática:** O programa checa se as dependências existem antes de rodar, e te avisa como instalar.

---

## 🚀 Instalação & Compilação

Para forjar sua própria cópia do Danos Firewall Manager, siga estes passos.

### 1. 🌐 Pré-requisitos

O programa precisa de algumas ferramentas essenciais para operar seus módulos avançados. Em sistemas baseados em Debian/Ubuntu, instale tudo com um único comando:

```bash
sudo apt-get update && sudo apt-get install build-essential curl ipset
```
* `build-essential`: Fornece o compilador `gcc` e outras ferramentas para criar o programa.
* `curl`: Usado pelo módulo de Inteligência de Ameaças para baixar as listas de IPs.
* `ipset`: A ferramenta secreta para gerenciar e bloquear milhares de IPs de forma ultra eficiente.

### 2. ⚙️ Compilação

Com os pré-requisitos instalados, compile o código-fonte (`danos-firewall.c`) para criar o executável.

```bash
gcc danos-firewall.c -o danos-firewall
```
Se tudo correr bem, você terá um novo arquivo chamado `danos-firewall` no mesmo diretório.

---

## 🏃 Execução

Para controlar o firewall do sistema, o programa precisa de privilégios de root. Sempre execute-o com `sudo`.

```bash
sudo ./danos-firewall
```

---

## 📖 Guia de Operações

Cada opção no menu é uma arma no seu arsenal. Saiba como usá-las.

### Gerenciamento Básico de Regras

* **`[1] Verificar Status do Firewall`**: Mostra a configuração atual do `iptables` de forma detalhada, incluindo contadores de pacotes, regras e políticas padrão. Essencial para ter consciência situacional.
* **`[2] Permitir Tráfego em uma Porta`**: Abre uma porta para o mundo exterior. Você especificará a porta (ex: `80`) e o protocolo (`tcp` ou `udp`).
* **`[3] Bloquear Regra de uma Porta`**: Remove uma regra de `ACCEPT` que você criou anteriormente. Essencial para fechar acessos que não são mais necessários.
* **`[4] Definir Política Padrão`**: Configura a estratégia principal do seu firewall. `DROP` é a mais segura (negar tudo, exceto o permitido). `ACCEPT` é mais permissiva (permitir tudo, exceto o proibido).
* **`[5] Salvar Configuração`**: Grava suas regras `iptables` atuais em `/etc/iptables/rules.v4`. Isso **NÃO** salva os IPs bloqueados pelos módulos avançados, apenas as regras estáticas.
* **`[6] Restaurar Configuração`**: Carrega as regras do arquivo salvo, substituindo a configuração atual.

### Módulos Avançados de Segurança

Estes são os módulos proativos que transformam seu firewall de uma parede estática em um sistema de defesa ativo.

#### `[10] 🍯 Ativar Porta Armadilha (Honeypot)`
* **O que é?** Uma armadilha. Você escolhe uma porta que não está em uso. Qualquer scanner, bot ou atacante que "tocar" nessa porta terá seu IP instantaneamente adicionado a uma blacklist permanente.
* **Como funciona?** O tráfego para a porta escolhida é redirecionado para uma lógica que usa `ipset` para registrar e bloquear o IP de origem.
* **Uso Prático:** Use portas comumente atacadas por bots, como `23` (Telnet), `3389` (RDP), ou portas altas aleatórias.
* **⚠️ Aviso!** **NUNCA** use uma porta que é necessária para um serviço legítimo em seu servidor (ex: porta `80` se você tem um site, ou `22` se você usa SSH).

#### `[11] 🌐 Sincronizar com Lista de Ameaças Global`
* **O que é?** Seu firewall baixa uma lista de IPs conhecidos por atividades maliciosas (ataques, spam, botnets) de fontes confiáveis na internet (atualmente, a lista `firehol_level1`).
* **Como funciona?** `curl` baixa a lista, e o programa usa `ipset` para carregar dezenas de milhares de IPs em uma blacklist de forma extremamente rápida e eficiente em termos de memória.
* **Uso Prático:** Execute esta opção uma vez por semana ou mês para manter seu firewall atualizado contra as ameaças mais recentes.

#### `[12] 🔒 Ativar Proteção SSH (Anti-Força Bruta)`
* **O que é?** Um sentinela para sua porta SSH (22). Ele monitora tentativas de login falhas.
* **Como funciona?** Usando o módulo `recent` do `iptables`, ele conta as tentativas de conexão de cada IP. Se um IP exceder o limite (atualmente 4 tentativas em 60 segundos), ele é temporariamente bloqueado.
* **💀 AVISO DE MORTE!** Este módulo é poderoso e pode te bloquear. Se você errar sua própria senha de SSH várias vezes, **SEU IP SERÁ BANIDO**. Tenha sempre uma forma de acesso de emergência ao seu servidor (console web, acesso físico) antes de ativar esta proteção.

### Opções de Emergência

* **`[99] 💥 Resetar Firewall`**: O botão de pânico. Esta opção apaga **TODAS** as regras, zera as blacklists e define a política padrão de tudo para `ACCEPT`. Seu sistema ficará completamente aberto, mas isso pode ser sua única saída se você se trancou para fora.

---

## 📜 Licença

Este projeto é de código aberto e está sob a [Licença MIT](LICENSE). Sinta-se livre para usar, modificar e distribuir.
