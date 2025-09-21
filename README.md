<div align="center">
  <img src="https://raw.githubusercontent.com/MollController/Mind-Blowing_Best-README-Template/master/src/assets/banner.png" alt="banner">
</div>

<div align="center">

# 🛡️ Danos Firewall Pro 🛡️

### _O poder bruto do `iptables`, a simplicidade de um assistente._

</div>

O `iptables` é o guardião supremo do kernel Linux, uma muralha de poder inigualável. Mas seu poder vem com uma complexidade intimidadora e uma sintaxe arcana. Erros de digitação podem expor seu sistema ou trancá-lo para fora.

**Danos Firewall Pro** resolve isso. Ele encapsula a complexidade do `iptables` em uma interface de terminal interativa, bonita e em português. Ele não esconde o poder; ele o canaliza, guiando você na criação de regras simples e complexas com segurança e velocidade. De um iniciante a um administrador de sistemas experiente, Danos Pro é seu centro de comando para as defesas da rede.

<div align="center">

```
========================================
         DANOS FIREWALL PRO         
========================================

--- MENU PRINCIPAL ---
  1. Gerenciar Tabela 'filter' (Padrão: bloquear/permitir pacotes)
  2. Gerenciar Tabela 'nat' (Redirecionamento, compartilhar internet)
  3. Gerenciar Tabela 'mangle' (Modificação avançada de pacotes)

  4. Funções Rápidas de NAT

  9. Salvar todas as regras permanentemente
  0. Sair
Escolha uma opção:
```

</div>

---

## 💥 Arsenal de Features

* **Controle Total:** Gerencie as tabelas `filter`, `nat` e `mangle` e todas as suas chains (`INPUT`, `OUTPUT`, `FORWARD`, etc.).
* **🧙 Construtor de Regras Guiado:** Um assistente passo a passo para forjar regras complexas sem precisar memorizar a sintaxe do `iptables`.
* **🚀 Funções de NAT Simplificadas:** Configure o compartilhamento de internet (Masquerade) e o redirecionamento de portas (DNAT) através de menus simples.
* **Interface Hierárquica:** Navegue de forma lógica entre tabelas e chains para aplicar regras exatamente onde você precisa.
* **Gerenciamento Intuitivo:** Liste regras com numeração clara e apague-as por seu número, sem erros.
* **Seguro e Leve:** Escrito em C, é rápido, leve e não requer dependências complexas.

---

## 🚀 Instalação

A instalação é simples, exigindo apenas as ferramentas de compilação padrão.

### 1. Pré-requisitos

Seu sistema precisa do compilador `gcc` e do `iptables`. Em sistemas baseados em Debian/Ubuntu:
```bash
sudo apt-get update && sudo apt-get install build-essential
```

### 2. Compilação

Salve o código-fonte como `danos-pro.c` e execute o seguinte comando para compilar:
```bash
gcc danos-pro.c -o danos-pro
```
Você terá um executável chamado `danos-pro` pronto para a ação.

---

## ⚡ Execução

O programa precisa de privilégios de root para manipular as regras do kernel. Sempre execute-o com `sudo`.

```bash
sudo ./danos-pro
```

---

## 📖 Guia de Operações: Dominando o Netfilter

### Navegação Principal: As Tabelas do Poder

O menu principal permite que você escolha em qual "dimensão" do firewall você quer trabalhar. Cada tabela tem um propósito específico:

* **`[1] Tabela 'filter'`**: A mais comum. É o seu guarda da portaria. Suas chains (`INPUT`, `OUTPUT`, `FORWARD`) decidem se um pacote pode entrar, sair ou passar através do seu sistema. **Use esta tabela para bloquear e permitir acessos.**
* **`[2] Tabela 'nat'`**: O operador de telefonia. Ela reescreve os endereços de origem e destino dos pacotes. **Use esta tabela para redirecionar portas (DNAT) e compartilhar sua conexão de internet (SNAT/Masquerade).**
* **`[3] Tabela 'mangle'`**: O agente especial. É usada para modificações avançadas e esotéricas nos cabeçalhos dos pacotes, como alterar o TTL ou o ToS. Para usuários avançados.

### Gerenciando uma Chain

Após escolher uma tabela, o programa pedirá o nome da **chain** que você deseja gerenciar.

Exemplo: se você escolheu a tabela `filter`, pode digitar `INPUT` para gerenciar as regras de tráfego que chega ao seu computador.

Uma vez dentro de uma chain, você tem duas opções principais:

* **`[1] Adicionar nova regra (Assistente Guiado)`**: A função mais poderosa do Danos Pro.
* **`[2] Apagar uma regra (pelo número)`**: As regras são listadas com um número na primeira coluna. Basta digitar o número para remover a regra correspondente.

### 🧙 O Construtor de Regras Guiado

Este é o coração do Danos Pro. Ele te fará uma série de perguntas para construir o comando `iptables` perfeito. Deixe a resposta em branco e pressione `Enter` para não incluir uma condição.

* **`Protocolo`**: `tcp`, `udp`, `icmp` ou `all`. Define o tipo de tráfego.
* **`IP/Rede de Origem`**: De onde o pacote está vindo. Pode ser um único IP (`1.2.3.4`) ou uma rede em formato CIDR (`192.168.1.0/24`).
* **`Porta de Origem`**: A porta que o pacote usou na máquina de origem.
* **`IP/Rede de Destino`**: Para onde o pacote está indo.
* **`Porta de Destino`**: A porta que o pacote quer alcançar na máquina de destino (ex: `80` para web, `22` para SSH).
* **`Interface de Entrada/Saída`**: A placa de rede pela qual o pacote entra (`-i eth0`) ou sai (`-o eth1`).
* **`Estado da Conexão`**: Uma das funcionalidades mais poderosas. Permite criar regras baseadas no estado do rastreamento de conexão (`conntrack`).
    * `NEW`: Um novo pacote tentando iniciar uma conexão.
    * `ESTABLISHED`: Pacotes que fazem parte de uma conexão já existente e permitida.
    * `RELATED`: Pacotes relacionados a uma conexão existente (ex: FTP).
* **`Ação (Target)`**: O que fazer com o pacote que corresponde a todas as condições.
    * `ACCEPT`: Permitir a passagem.
    * `DROP`: Descartar o pacote silenciosamente. O remetente não recebe resposta.
    * `REJECT`: Rejeitar o pacote, enviando uma resposta de erro.
    * `LOG`: Cria um registro do pacote nos logs do sistema (visível com `dmesg`). É ótimo para depuração.

### 🚀 Funções Rápidas de NAT

O menu `[4]` oferece atalhos para as tarefas de NAT mais comuns, evitando que você precise construir as regras manualmente.

* **`[1] Compartilhar Internet (MASQUERADE)`**: Perfeito para transformar seu computador Linux em um roteador. Ele pega todo o tráfego da sua rede interna, "mascara" com o IP da sua interface de internet e envia para o mundo.
* **`[2] Redirecionar Porta (DNAT)`**: Essencial para expor um serviço interno. Se você tem um servidor web rodando em uma máquina na sua rede local (`192.168.1.50` na porta `80`), você pode usar o DNAT para que qualquer tráfego que chegue na porta `80` do seu firewall seja automaticamente encaminhado para esse servidor interno.

###💾 Salvando as Regras

A opção `[9]` usa o comando `iptables-save` para despejar a configuração atual da memória para um arquivo (`/etc/iptables/rules.v4`).

> **IMPORTANTE:** Por padrão, essas regras **NÃO** sobrevivem a uma reinicialização. Para que elas sejam carregadas automaticamente no boot, você precisa de um pacote adicional. Em sistemas Debian/Ubuntu, instale-o com:
> ```bash
> sudo apt-get install iptables-persistent
> ```
> Durante a instalação, ele perguntará se você deseja salvar as regras atuais. Diga sim.

---

## 📜 Licença

Este projeto está sob a [Licença MIT](LICENSE). Sinta-se livre para usar, modificar e distribuir.
