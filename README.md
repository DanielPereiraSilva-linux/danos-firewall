<div align="center">

# ❗ Guia de Sobrevivência do Git ❗
### Resolvendo `push rejected` e `divergent branches`

</div>

Este guia é um manual de campo para resolver um dos problemas mais comuns que desenvolvedores enfrentam ao colaborar com Git: branches que divergem e impedem o `git push`. Se você já viu um dos erros abaixo, este documento é para você.

---

## 📜 ´Índice

1.  [Os Sintomas: Identificando o Problema](#-os-sintomas-identificando-o-problema)
2.  [O Diagnóstico: Por Que Isso Acontece?](#-o-diagnóstico-por-que-isso-acontece)
3.  [A Escolha Estratégica: Merge vs. Rebase](#-a-escolha-estratégica-merge-vs-rebase)
4.  [Plano de Ação: Resolvendo o Impasse](#-plano-de-ação-resolvendo-o-impasse)
    * [Passo 1: Sincronizar com o Remoto](#passo-1-sincronizar-com-o-repositório-remoto)
    * [Passo 1.1: **Lidando com Conflitos** (Leitura Obrigatória)](#passo-11--lidando-com-conflitos-leitura-obrigatória)
    * [Passo 2: Enviar Suas Alterações](#passo-2-enviar-suas-alterações)
5.  [Configuração Permanente: Evitando o Erro no Futuro](#-configuração-permanente-evitando-o-erro-no-futuro)
6.  [Resumo Rápido (TL;DR)](#-resumo-rápido-tldr)

---

## 🚨 Os Sintomas: Identificando o Problema

Você trabalhou em seu código, fez um `git commit`, mas na hora de enviar para o GitHub, você se depara com um destes cenários:

#### Sintoma 1: O `push` é Rejeitado

Você executa `git push` e recebe:
```bash
To github.com:user/repo.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'github.com:user/repo.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally.
hint: ... use 'git pull' before pushing again.
```

#### Sintoma 2: O `pull` Falha com "Divergent Branches"

Seguindo a dica, você executa `git pull` e recebe:
```bash
From github.com:user/repo
 * branch            main       -> FETCH_HEAD
hint: You have divergent branches and need to specify how to reconcile them.
fatal: Need to specify how to reconcile divergent branches.
```

---

## 🩺 O Diagnóstico: Por Que Isso Acontece?

A causa é simples: **seu repositório local e o repositório remoto (GitHub) estão dessincronizados.**

Enquanto você trabalhava, outra pessoa (ou você mesmo, em outra máquina) enviou atualizações para o mesmo branch. O histórico do repositório remoto avançou, e seu histórico local divergiu, criando dois "futuros" diferentes.

> **Analogia:** Imagine que você baixou um documento de texto para editar. Enquanto você escrevia, outra pessoa editou a versão online. Agora, você não pode simplesmente colar seu texto por cima, pois apagaria o trabalho da outra pessoa. Você precisa primeiro baixar as alterações dela e integrá-las ao seu documento. Git está forçando você a fazer exatamente isso.

---

## ⚖️ A Escolha Estratégica: Merge vs. Rebase

Git oferece duas maneiras principais de integrar as novas alterações remotas ao seu trabalho local. A versão mais recente do Git pede que você escolha uma.

### 1. Merge (Fundir) - O Padrão Tradicional

Cria um novo "commit de merge" que une os dois históricos.

* **Prós:** Preserva o histórico exatamente como aconteceu, mostrando os pontos onde o trabalho divergiu e foi reunido. É considerado mais seguro e menos "destrutivo".
* **Contras:** Pode poluir o histórico com muitos commits de merge, tornando-o mais difícil de ler.

**Visualização do Histórico:**
```
---A---B---C---F---G  (main local)
      \         /
       ---D---E--  (origin/main)

(F é o commit de merge)
```

### 2. Rebase (Rebasear) - A Abordagem "Limpa"

Pega seus commits locais, os coloca temporariamente de lado, baixa os commits remotos e, em seguida, reaplica seus commits no topo, um por um.

* **Prós:** Cria um histórico de commits linear e limpo, como se todo o trabalho tivesse sido feito em sequência.
* **Contras:** Reescreve o histórico. Se feito incorretamente em branches compartilhados, pode causar problemas para outros colaboradores.

**Visualização do Histórico:**
```
---A---B---D---E---C'---G'  (main local e origin/main)

(C' e G' são seus commits originais, mas reescritos no topo de E)
```

> **Qual escolher?** Para iniciantes ou para quem trabalha em equipe e quer um registro explícito de quando as coisas foram mescladas, **Merge é a escolha mais segura e recomendada.** Rebase é excelente para quem prefere um histórico perfeitamente linear.

---

## 🔧 Plano de Ação: Resolvendo o Impasse

### Passo 1: Sincronizar com o Repositório Remoto

Execute `git pull` novamente, mas desta vez, diga explicitamente qual estratégia usar.

#### **Opção A (Recomendado): Usando Merge**
```bash
git pull --no-rebase
```
*Este é o comando mais seguro. Ele tentará fundir as alterações remotas com as suas.*

#### **Opção B (Avançado): Usando Rebase**
```bash
git pull --rebase
```
*Use este comando se você preferir um histórico linear.*

### Passo 1.1: 🚑 Lidando com Conflitos (Leitura Obrigatória)

Se você e outra pessoa modificaram as **mesmas linhas** do mesmo arquivo, o Git não conseguirá mesclar automaticamente e irá pausar, reportando um **CONFLITO**.

1.  **Identifique os arquivos:** O Git listará os arquivos em conflito.
2.  **Abra os arquivos:** Dentro deles, você verá marcadores especiais:
    ```diff
    <<<<<<< HEAD
    O seu código conflitante está aqui.
    =======
    O código conflitante que veio do servidor está aqui.
    >>>>>>> commit-hash-remoto
    ```
3.  **Resolva o conflito:** Edite o arquivo **manualmente**. Apague os marcadores (`<<<`, `===`, `>>>`) e decida qual código manter, ou combine os dois da maneira que fizer sentido.
4.  **Finalize a resolução:**
    * **Se você usou MERGE (`--no-rebase`):**
        ```bash
        git add .
        git commit 
        # (Apenas salve e feche o editor que abrir)
        ```
    * **Se você usou REBASE (`--rebase`):**
        ```bash
        git add .
        git rebase --continue
        ```

### Passo 2: Enviar Suas Alterações

Após o `pull` ser bem-sucedido e todos os conflitos serem resolvidos, seu repositório local estará sincronizado e à frente do remoto. Agora, o `push` funcionará.

```bash
git push
```

---

## ⚙️ Configuração Permanente: Evitando o Erro no Futuro

Para não ter que digitar `--rebase` ou `--no-rebase` toda vez, você pode configurar um padrão para o Git.

#### Para usar **MERGE** como padrão (Recomendado):
```bash
git config --global pull.rebase false
```

#### Para usar **REBASE** como padrão:
```bash
git config --global pull.rebase true
```
*O `--global` aplica a configuração a todos os seus repositórios.*

---

## 🚀 Resumo Rápido (TL;DR)

1.  Seu `git push` falhou? Seu repositório está desatualizado.
2.  Execute `git pull --no-rebase` (ou `git pull --rebase` se preferir).
3.  Se houver conflitos, edite os arquivos para resolvê-los e finalize com `git commit` ou `git rebase --continue`.
4.  Execute `git push` novamente.
5.  Para evitar o erro no futuro, configure um padrão com `git config --global pull.rebase false`.
