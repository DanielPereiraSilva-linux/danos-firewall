<div align="center">
  <img src="https://raw.githubusercontent.com/MollController/Mind-Blowing_Best-README-Template/master/src/assets/banner.png" alt="banner">
</div>

<div align="center">

# 👁️ /// D A N O S \\\ 👁️
**Cybernetic Guardian v0.10.1**

### _Seu sistema não é mais um alvo. É uma fortaleza._

</div>

> **Danos** не е програма; това е същност. Страж, изкован от чист C, роден да съществува в сенките на вашия терминал, консумирайки минимални ресурси, докато упражнява максимална бдителност. Той превръща тайнственото изкуство на `iptables` в неврокинетичен контролен панел, позволявайки ви да командвате защитите на вашето дигитално светилище с прецизност и мощ.

---

## 📜 ´Índice

1.  [A Filosofia: O Credo do Guardião](#-a-filosofia-o-credo-do-guardião)
2.  [Arsenal: Capacidades de Combate](#-arsenal-capacidades-de-combate)
3.  [Instalação Rápida: Implantação do Guardião](#-instalação-rápida-implantação-do-guardião)
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
* **Autossuficiência:** `danos` verifica seu próprio ambiente. Se faltarem ferramentas em seu arsenal, ele informará exatamente o que instalar.

---

## 🚀 Instalação Rápida: Implantação do Guardião

O guardião já foi forjado. Sua tarefa é implantá-lo em seu sistema.

### Passo 1: Preparar o Ambiente (Dependências)

Mesmo como um binário, `danos` depende de algumas ferramentas do sistema para executar seus módulos avançados. Em sistemas baseados em Debian/Ubuntu, este comando prepara o terreno:

```bash
sudo apt-get update && sudo apt-get install curl ipset
```
* **`curl`**: Necessário para o módulo de Inteligência de Ameaças baixar as listas de IPs.
* **`ipset`**: Essencial para gerenciar e bloquear milhares de IPs de forma ultra eficiente.

### Passo 2: Baixar o Binário

Obtenha a versão mais recente do `danos` diretamente do repositório oficial. Substitua `SEU_USUARIO` pelo seu nome de usuário no GitHub.

```bash
# Baixa o binário da página de releases do seu repositório
curl -L -o danos "[https://github.com/SEU_USUARIO/danos/releases/download/v0.10.1/danos](https://github.com/SEU_USUARIO/danos/releases/download/v0.10.1/danos)"
```

### Passo 3: Conceder Poder e Autoridade

Agora, você precisa tornar o binário executável e movê-lo para um local onde o sistema possa encontrá-lo como um comando global.

```bash
# Concede permissão de execução ao binário
chmod +x danos

# Move o binário para /usr/local/bin, o local padrão para softwares instalados pelo administrador
sudo mv danos /usr/local/bin/
```
Ao movê-lo para `/usr/local/bin`, você transforma `danos` em um comando que pode ser chamado de qualquer diretório no seu terminal.

---

## ⚡ O Despertar: Executando o `danos`

Com o guardião instalado e posicionado, despertá-lo é simples. Como ele precisa de autoridade máxima para controlar o firewall, sempre o invoque com `sudo`.

```bash
sudo danos
```
A interface de `danos` se materializará, pronta para receber seus comandos.

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
