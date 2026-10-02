# [P4-ETAPA-05] Análise Comparativa: Imperativo vs. POO

Este documento compara as implementações do Chaveamento de Torneio nos paradigmas **Imperativo** (Etapa 03) e **Orientado a Objetos** (Etapa 04).

---

## 1. Comparação dos Aspectos Técnico-Conceituais

* **Representação do Estado:** No imperativo, os dados dos jogadores e do torneio ficam em vetores de `structs` e variáveis locais passadas entre funções. Na POO, os dados ficam protegidos em atributos privados (`private`) dentro de cada classe (`Jogador`, `Torneio`).
* **Mutabilidade:** No imperativo, qualquer função com acesso ao vetor pode alterar os dados diretamente. Na POO, a alteração de dados é controlada e feita apenas por métodos da própria classe.
* **Fluxo de Controle:** O imperativo segue uma sequência direta chamando funções ordenadamente. Na POO, o fluxo ocorre através da troca de mensagens (chamadas de métodos) entre os objetos.
* **Decomposição do Problema:** O imperativo divide o programa em **funções e tarefas** (o que o código faz). A POO divide o programa em **entidades e papéis** (`Jogador`, `Confronto`, `Torneio`).
* **Reutilização:** Na POO, a classe `Confronto` pode ser copiada e usada em outro projeto sem modificações. No imperativo, as funções dependem do formato específico da `struct` usada.
* **Manutenção:** Se a forma de exibir o jogador mudar na POO, alteramos apenas a classe `Jogador`. No imperativo, é necessário alterar todas as funções que formatam a saída no terminal.
* **Facilidade de Extensão:** Para adicionar um novo tipo de participante (como um jogador robô), a POO permite criar uma subclasse de `Participante` via herança, sem alterar a regra do torneio.
* **Tratamento de Erros:** Na POO, a validação pode ocorrer na criação do objeto (no construtor), evitando instâncias inválidas. No imperativo, a validação precisa ser feita antes de cada chamada de função.
* **Efeitos Colaterais:** Menores na POO, pois os objetos isolam suas variáveis internas. No imperativo, a passagem de vetores por referência pode alterar dados em outras partes do código.
* **Facilidade para Testar:** Na POO, é possível instanciar e testar a classe `Confronto` isoladamente. No imperativo, o teste de um duelo depende do estado geral das variáveis da `main`.
* **Organização do Código:** O código imperativo agrupa a lógica em funções sequenciais. A POO distribui as responsabilidades em classes com papéis bem definidos.
* **Complexidade:** O modelo imperativo é mais simples e rápido de escrever para programas pequenos. A POO exige mais estrutura inicial, mas oferece melhor organização para o crescimento do sistema.

---

## 2. Perguntas e Respostas

### 1. Qual problema ficou mais fácil de expressar de forma imperativa?
A leitura sequencial do nome dos jogadores via terminal e o laço principal que repete as rodadas.

### 2. Qual problema ficou mais fácil de expressar utilizando orientação a objetos?
A modelagem do duelo (`Confronto`). Tratar a disputa como um objeto que recebe dois participantes e retorna o vencedor deixou a lógica muito clara.

### 3. Onde a orientação a objetos realmente trouxe vantagem?
No encapsulamento para proteger os dados dos participantes e no polimorfismo, que permite ao torneio manipular participantes genéricos via ponteiros.

### 4. Em quais situações a utilização de objetos acrescentou complexidade desnecessária?
Na classe `Jogador`, que serviu basicamente para armazenar `id` e `nome`, tarefas que uma `struct` simples no modo imperativo resolvia de forma mais enxuta.

### 5. Que partes do problema praticamente não mudaram entre as duas implementações?
A regra de chaveamento: a aplicação do *Bye* para número ímpar de participantes e a lógica de avançar os vencedores para a próxima fase.

### 6. Que partes precisaram ser completamente remodeladas?
A execução dos duelos. No modelo imperativo, o código comparava índices do vetor diretamente (`vetor[i]` com `vetor[i+1]`). Na POO, cada duelo passou a ser instanciado como um objeto `Confronto`.