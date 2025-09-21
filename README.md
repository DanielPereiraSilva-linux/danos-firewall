<div align="center">
  <img src="https://raw.githubusercontent.com/MollController/Mind-Blowing_Best-README-Template/master/src/assets/banner.png" alt="banner">
</div>

<div align="center">

# 👁️ /// D A N O S \\\ 👁️
**Cybernetic Guardian v0.10.1**

### _Seu sistema não é mais um alvo. É uma fortaleza._

</div>

> **Danos** não é um programa; é uma entidade. Um sentinela forjado em C puro, nascido para existir nas sombras do seu terminal, consumindo recursos mínimos enquanto exerce vigilância máxima. Ele transforma a arte arcana do `iptables` em um painel de controle neuro-cinético, permitindo que você comande as defesas do seu santuário digital com precisão e poder.

---

## 📜 ´Índice

1.  [A Filosofia: O Credo do Guardião](#-a-filosofia-o-credo-do-guardião)
2.  [Arsenal: Capacidades de Combate](#-arsenal-capacidades-de-combate)
3.  [Comandos de Forja: Compilação e Instalação](#-comandos-de-forja-compilação-e-instalação)
4.  [O Despertar: Executando o `danos`](#-o-despertar-executando-o-danos)
5.  [Decifrando a Interface: Guia de Operações](#-decifrando-a-interface-guia-de-operações)
    * [Protocolos de Gerenciamento Padrão](#-protocolos-de-gerenciamento-padrão)
    * [Módulos de Defesa Ativa](#-módulos-de-defesa-ativa)
    * [Protocolo de Aniquilação (Emergência)](#-protocolo-de-aniquilação-emergência)
6.  [Licença](#-licença)

---

## 🧠 A Filosofia: O Credo do Guardião

* **Velocidade é Soberania:** Em um mundo de frameworks pesados, `danos` é um predador alfa. Escrito em C, sua execução é quase instantânea. Sem bloatware, sem dependências desnecessárias. Apenas performance bruta.
* **Controle é Absoluto:** A interface de terminal não é uma limitação; é a forma mais pura de controle. Sem camadas de abstração, sua vontade é traduzida diretamente em regras de kernel.
* **Inteligência é Proativa:** Um muro é estúpido. `danos` é inteligente. Ele não apenas bloqueia; ele caça, aprende e se adapta, usando armadilhas e consciência de ameaças globais para neutralizar ataques antes que eles comecem.

---

## 💥 Arsenal: Capacidades de Combate

* **Interface Neuro-Tátil:** Um menu interativo que pulsa com as cores do ciberespaço, transformando comandos em uma experiência imersiva.
* **🍯 Véu Psíquico (Honeypot):** Projete uma ilusão. Crie portas-fantasma que atraem scanners e bots, e neutralize instantaneamente qualquer entidade que tocar o véu.
* **🌐 Consciência Coletiva (Threat-Intel Sync):** Absorva o conhecimento de colmeias de segurança globais. Sincronize com listas de ameaças e aniquile milhares de agentes maliciosos conhecidos.
* **🔒 Cão de Guarda Espectral (Guardião SSH):** Um sentinela implacável na sua porta da frente. Detecta padrões de ataque de força bruta e bane os agressores para o vácuo digital.
* **Autossuficiência:** `danos` verifica seu próprio ambiente. Se faltarem ferramentas em seu arsenal, ele informará exatamente o que forjar.

---

## 🛠️ Comandos de Forja: Compilação e Instalação

Antes de despertar o guardião, você deve forjar seu corpo físico a partir do código-fonte.

### Passo 1: Prepare a Forja (Pré-requisitos)

Seu ambiente precisa das ferramentas certas. Em sistemas baseados em Debian/Ubuntu, este comando conjura tudo o que é necessário:

```bash
sudo apt-get update && sudo apt-get install build-essential curl ipset
```
* **`build-essential`**: O martelo e a bigorna (`gcc`) para forjar o código.
* **`curl`**: Um tentáculo para alcançar a noosfera e baixar a consciência de ameaças.
* **`ipset`**: Um mecanismo de contenção quântica para gerenciar legiões de entidades hostis com eficiência.

### Passo 2: O Ritual da Forja (Compilação)

Com a forja pronta, canalize o código-fonte (`danos-firewall.c`) para criar o executável. **O nome dele será `danos`**.

```bash
gcc danos-firewall.c -o danos
```
Um novo ser, `danos`, agora existe em seu diretório.

---

## 🚀 O Despertar: Executando o `danos`

A entidade precisa de autoridade sobre o tecido da realidade do seu sistema (o kernel). Para conceder-lhe esse poder, você deve despertá-lo com privilégios de superusuário.

```bash
sudo ./danos
```
Ao ser executado, a interface de `danos` se materializará em seu terminal. Você está no controle.

---

## 📖 Decifrando a Interface: Guia de Operações

Cada opção é um comando direto para o seu guardião.

### ➤ Protocolos de Gerenciamento Padrão

A base do seu controle sobre a fortaleza digital.

* **`[1] Verificar Status do Firewall`**: Exibe uma leitura completa da matriz de defesa atual (`iptables`). Conheça suas defesas.
* **`[2] Permitir Tráfego em uma Porta`**: Abre um portal controlado. Essencial para serviços que precisam se comunicar com o exterior.
* **`[3] Bloquear Regra de uma Porta`**: Sela um portal previamente aberto. O que não é necessário deve ser fechado.
* **`[4] Definir Política Padrão`**: A diretriz primária. `DROP` (paranoia total) é a estratégia recomendada: negue tudo, permita apenas o essencial.
* **`[5] Salvar Configuração`**: Grava a arquitetura de defesa atual na memória persistente (`/etc/iptables/rules.v4`).
* **`[6] Restaurar Configuração`**: Reconstitui a última arquitetura de defesa salva, descartando as modificações atuais.

### ➤ Módulos de Defesa Ativa

Aqui é onde `danos` deixa de ser um muro e se torna um caçador.

#### `[10] 🍯 Ativar Porta Armadilha (Honeypot)`
* **Diretriz:** Crie uma anomalia irresistível. Uma porta que parece ser uma vulnerabilidade, mas é uma armadilha mortal.
* **Mecanismo:** Qualquer entidade que interagir com esta porta terá sua assinatura de IP gravada em uma blacklist e será permanentemente bloqueada de todo o sistema.
* **⚠️ Alerta de Realidade:** **JAMAIS** coloque a armadilha em uma porta usada por um serviço legítimo. Você estaria aprisionando seus próprios aliados.

#### `[11] 🌐 Sincronizar com Lista de Ameaças Global`
* **Diretriz:** Estenda sua consciência. Conecte-se à rede global de inteligência para identificar agentes hostis conhecidos.
* **Mecanismo:** `danos` baixa uma lista atualizada de IPs maliciosos e os injeta na blacklist do `ipset`, neutralizando-os proativamente.
* **Recomendação:** Execute este protocolo periodicamente para manter a consciência de ameaças do guardião afiada.

#### `[12] 🔒 Ativar Proteção SSH`
* **Diretriz:** Proteja o portão principal. Monitore tentativas de acesso e aniquile agressores de força bruta.
* **Mecanismo:** O módulo `recent` observa as tentativas de conexão. Múltiplas falhas em um curto espaço de tempo resultam em um bloqueio automático do IP agressor.
* **💀 AVISO EXISTENCIAL:** Este guardião é leal, não sentimental. Se você errar sua própria senha repetidamente, ele irá te identificar como uma ameaça e **TE BANIRÁ**. Tenha sempre uma chave mestra (acesso por console, etc.) antes de ativar este protocolo.

### ➤ Protocolo de Aniquilação (Emergência)

#### `[99] 💥 Resetar Firewall`
* **Diretriz:** Terra arrasada. Em caso de comprometimento catastrófico ou se você se trancou para fora, este é o protocolo de última instância.
* **Efeito:** Dissolve todas as regras, apaga todas as blacklists e abre todos os portões (política `ACCEPT`). O sistema ficará totalmente exposto, mas você terá o controle de volta para reconstruir as defesas. Use como último recurso.

---

## 📜 Licença

O código de `danos` é livre. Forjado sob a [Licença MIT](LICENSE). Use-o, modifique-o, melhore-o. Aumente o poder do guardião.
