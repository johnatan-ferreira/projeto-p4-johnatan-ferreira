# Projeto P4 — Um Problema, Quatro Paradigmas

Este repositório contém a solução para o problema de **Chaveamento de Torneios** desenvolvido ao longo da disciplina, explorando os paradigmas Imperativo, Orientado a Objetos, Funcional e Lógico.

---

## Especificação do Problema

### 1. Descrição do problema
O problema a ser resolvido nesse projeto se dá quando várias pessoas estão competindo em alguma coisa e é necessário ter apenas um vencedor.

### 2. Objetivo
O projeto deste repositório tem como objetivo implementar um software de chaveamento, onde $n$ competidores disputam entre si em pares e resta apenas um vencedor no final.

### 3. Entradas
Quantidade de competidores e seus respectivos nomes.

### 4. Saídas
Apenas um vencedor, informando seu nome.

### 5. Regras do problema
Em disputas de pares um vence. O vencedor cai em outra disputa com outro vencedor. O ciclo se repete até que não haja mais nenhum competidor para se disputar. Em caso de uma quantidade ímpar de jogadores, será utilizado o sistema *Bye*.

### 6. Casos de exemplo
* **4 jogadores:** `"Pedro", "Marcos", "Tiago", "Lucas"` $\rightarrow$ `"Vencedor: Lucas"`
* **2 jogadores:** `"Filipe", "Mateus"` $\rightarrow$ `"Vencedor: Mateus"`
* **3 jogadores:** `"Pedro", "Filipe", "Tiago"` $\rightarrow$ `"Vencedor: Pedro"`
* **1 jogador:** `"Tiago"` $\rightarrow$ `"Vencedor: Tiago"`
* **5 jogadores:** `"Pedro", "Marcos", "Mateus", "Tiago", "Lucas"` $\rightarrow$ `"Vencedor: Marcos"`

### 7. Casos-limite
* **Entrada Nula:** Caso a entrada seja nula, o programa não prossegue, exigindo que seja informado ao menos um jogador.
* **Torneio Unitário:** Quando há apenas um jogador ele é declarado automaticamente campeão.
* **Identificadores Duplicados:** Em caso de nomes repetidos, para evitar ambiguidade, será gerado internamente um ID próprio para cada participante.

### 8. Restrições
* Sem interface gráfica ou aplicação web.
* Sem persistência de dados ou arquivos externos.
* Sem sistemas de pontuação, placares acumulados, prorrogações ou empates.
* Sem suporte à repescagem.

### 9. Principais conceitos do domínio
* **Competidor:** Entidade participante da disputa.
* **Confronto / Partida:** Duelo direto entre dois competidores.
* **Rodada:** Etapa do torneio composta por um conjunto de confrontos.
* **Campeão:** O único participante que permanece invicto ao final do torneio.

### 10. Adequação aos quatro paradigmas
* **Imperativo:** O avanço de rodadas e a resolução de confrontos podem ser modelados de forma procedural e sequencial. As partidas e participantes podem ser armazenados em estruturas indexadas, como *arrays* ou vetores, enquanto a progressão do torneio é controlada por laços de repetição, alterando diretamente o estado da chave em memória à medida que cada vencedor é definido.
* **Orientado a Objetos (POO):** O problema possui entidades bem definidas. É possível modelar classes como `Competidor`, `Confronto` e `Torneio`. O estado do chaveamento fica encapsulado dentro do objeto do torneio, e a execução dos duelos ocorre por meio de mensagens e chamadas de métodos entre esses objetos.
* **Funcional:** Uma chave de torneio eliminatório é uma estrutura em árvore binária imutável. O avanço de uma rodada para a outra pode ser expresso como uma transformação pura de listas ou árvores através de funções de ordem superior (`map`, `fold`/`reduce`) e recursão. Cada fase gera uma nova lista imutável com os vencedores, sem modificar o estado das rodadas anteriores.
* **Lógico:** O torneio pode ser expresso declarativamente através de fatos e regras de inferência lógica. Relações como `confronto(A, B)`, `vencedor(A, B, V)` e a regra recursiva `campeao(X)` descrevem o que constitui um campeão no domínio do problema, deixando a cargo do mecanismo de inferência (como a resolução do Prolog) determinar e validar o vencedor final da chave.

### 11. Linguagens inicialmente consideradas
* **Imperativo:** C++
* **Orientado a Objetos:** C++ (ou Python, Java, C#)
* **Funcional:** Haskell
* **Lógico:** Prolog
