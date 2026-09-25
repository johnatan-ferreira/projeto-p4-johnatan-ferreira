# [P4-ETAPA-03] Documentação da Implementação Imperativa

Esta documentação descreve as decisões de projeto e implementação adotadas para a solução do Chaveamento de Torneio utilizando o paradigma **Imperativo** em C++.

---

## 1. Estados Mantidos
* **Vetor de Participantes (`vector<Jogador>`):** Armazena sequencialmente os competidores ativos em memória durante cada rodada.
* **Índices de Iteração (`i` e `num_rodada`):** Variáveis escalares mutáveis que controlam o deslocamento iterativo pelos confrontos e o avanço das fases.

## 2. Operações que Modificam Estado
* **Reatribuição da Lista:** A cada iteração do laço `while`, a variável `participantes` é reatribuída com o retorno do vetor de vencedores da função `rodada` (`participantes = rodada(participantes)`).
* **Incremento de Índices:** Incremento manual da variável de controle (`i = i + 2`) a cada duelo e incremento de `num_rodada++`.

## 3. Onde Aparecem Efeitos Colaterais
* **Entrada e Saída (I/O):** Impressão direta no console via `cout` e leitura de dados do teclado via `cin` e `getline`.

## 4. Estruturas de Controle Escolhidas
* **`while (participantes.size() > 1)`:** Laço condicional principal responsável por repetir o torneio até restar apenas o campeão.
* **`while (i < total)`:** Laço iterativo para organizar os confrontos em pares da rodada.
* **`if / else`:** Condicionais para tratar a regra de *Bye* para números ímpares e verificar a opção escolhida pelo usuário.

## 5. Organização dos Subprogramas
* **`ler_jogadores`:** Subprograma responsável por ler interativamente do terminal a quantidade e os nomes dos competidores.
* **`rodada`:** Subprograma procedural que executa um ciclo de duelos, aplica o *Bye* se necessário e retorna o vetor de vencedores.
* **`main`:** Ponto de entrada que orquestra a chamada dos subprogramas e a exibição do campeão final.

## 6. Por que a solução é predominantemente Imperativa?
A solução foca em como a computação é realizada passo a passo por meio de instruções sequenciais, controle de fluxo explícito e mutação de variáveis:
* Não utiliza classes, herança ou conceitos de Orientação a Objetos.
* O fluxo é ditado por laços imperativos (`while`) e subprogramas procedimentos.
* A evolução do torneio ocorre por modificações explícitas de estado a cada rodada.
