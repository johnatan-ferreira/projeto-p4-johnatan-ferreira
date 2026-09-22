# [P4-ETAPA-02] Contrato Semântico e Casos de Teste

Este documento estabelece o contrato semântico do sistema de chaveamento de torneios eliminatórios. Os casos de teste aqui definidos servem como especificação comportamental e devem ser satisfeitos por todas as implementações do projeto (Imperativa, POO, Funcional e Lógica).

---

## 1. Casos Normais (10 casos)

### CT-NORM-01: Final direta com 2 competidores
* **Descrição:** Torneio de menor chave válida com número par perfeito.
* **Entradas:**
  * Lista de Participantes: `["Filipe", "Mateus"]`
  * Escolha/Vencedores dos Duelos: `[Duelo 1: Mateus]`
* **Saída Esperada:** `Campeão: Mateus`

### CT-NORM-02: Chave perfeita com 4 competidores
* **Descrição:** Torneio com 2 rodadas completas sem necessidade de isenções (*byes*).
* **Entradas:**
  * Lista de Participantes: `["Pedro", "Marcos", "Tiago", "Lucas"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Marcos, Lucas]`, `[Final: Lucas]`
* **Saída Esperada:** `Campeão: Lucas`

### CT-NORM-03: Chave perfeita com 8 competidores
* **Descrição:** Torneio de 3 rodadas (Quartas, Semifinal e Final) com potência de 2 ($2^3$).
* **Entradas:**
  * Lista de Participantes: `["Ana", "Bruno", "Carla", "Daniel", "Eduardo", "Fernanda", "Gabriel", "Helena"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Bruno, Daniel, Fernanda, Helena]`, `[Rodada 2: Bruno, Helena]`, `[Final: Helena]`
* **Saída Esperada:** `Campeão: Helena`

### CT-NORM-04: Torneio com 3 competidores (1 Bye na 1ª rodada)
* **Descrição:** Aplicação do sistema de *Bye* para ajustar número ímpar de participantes em chave inferior a 4.
* **Entradas:**
  * Lista de Participantes: `["Pedro", "Filipe", "Tiago"]`
  * Estrutura da Rodada 1: `Pedro` ganha Bye; Duelo: `Filipe` vs `Tiago`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Tiago]`, `[Final (Pedro x Tiago): Pedro]`
* **Saída Esperada:** `Campeão: Pedro`

### CT-NORM-05: Torneio com 5 competidores (3 Byes na 1ª rodada)
* **Descrição:** Ajuste de chave para 5 participantes (próxima potência de 2 = 8, gerando 3 *byes*).
* **Entradas:**
  * Lista de Participantes: `["Pedro", "Marcos", "Mateus", "Tiago", "Lucas"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1 (Duelo 1): Marcos]`, `[Rodada 2 (Semifinais): Marcos, Lucas]`, `[Final: Marcos]`
* **Saída Esperada:** `Campeão: Marcos`

### CT-NORM-06: Torneio com 6 competidores (2 Byes na 1ª rodada)
* **Descrição:** Ajuste de chave para número par que não é potência de 2.
* **Entradas:**
  * Lista de Participantes: `["A", "B", "C", "D", "E", "F"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: B, D]`, `[Rodada 2 (Semifinais): B, F]`, `[Final: F]`
* **Saída Esperada:** `Campeão: F`

### CT-NORM-07: Torneio com 7 competidores (1 Bye na 1ª rodada)
* **Descrição:** Ajuste de chave para 7 participantes (1 *bye* alocado na 1ª fase).
* **Entradas:**
  * Lista de Participantes: `["A", "B", "C", "D", "E", "F", "G"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: A, C, E]`, `[Rodada 2: A, E]`, `[Final: E]`
* **Saída Esperada:** `Campeão: E`

### CT-NORM-08: Vitória consecutiva do primeiro da lista
* **Descrição:** Validação de ordenação quando o primeiro competidor cadastrado vence todas as rodadas.
* **Entradas:**
  * Lista de Participantes: `["Alfa", "Beta", "Gama", "Delta"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Alfa, Gama]`, `[Final: Alfa]`
* **Saída Esperada:** `Campeão: Alfa`

### CT-NORM-09: Vitória consecutiva do último da lista
* **Descrição:** Validação de ordenação quando o último competidor cadastrado vence todas as rodadas.
* **Entradas:**
  * Lista de Participantes: `["Alfa", "Beta", "Gama", "Delta"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Beta, Delta]`, `[Final: Delta]`
* **Saída Esperada:** `Campeão: Delta`

### CT-NORM-10: Nomes longos ou com caracteres especiais
* **Descrição:** Verificação da integridade de manipulação de *strings* complexas.
* **Entradas:**
  * Lista de Participantes: `["João da Silva #1", "Maria-Clara_2026"]`
  * Escolha/Vencedores dos Duelos: `[Duelo 1: Maria-Clara_2026]`
* **Saída Esperada:** `Campeão: Maria-Clara_2026`

---

## 2. Casos-Limite (3 casos)

### CT-LIM-01: Torneio Unitário (1 único participante)
* **Descrição:** Processamento de entrada contendo exatamente 1 competidor.
* **Entradas:**
  * Lista de Participantes: `["Tiago"]`
* **Saída Esperada:** `Campeão: Tiago` (Sem geração de partidas ou rodadas).

### CT-LIM-02: Nomes de Participantes Duplicados
* **Descrição:** Entrada contendo nomes idênticos de participantes na mesma lista.
* **Entradas:**
  * Lista de Participantes: `["Carlos", "Ana", "Carlos"]`
  * Escolha/Vencedores dos Duelos: `[Rodada 1: Carlos (ID: 1)]`, `[Final: Carlos (ID: 1)]`
* **Saída Esperada:** `Campeão: Carlos (ID: 1)` (Diferenciação correta por identificador interno para evitar colisão).

### CT-LIM-03: Grande quantidade de participantes (Chave com 16 competidores - $2^4$)
* **Descrição:** Teste de profundidade máxima da árvore de chaveamento sem degradação do estado.
* **Entradas:**
  * Lista de Participantes: `["P1", "P2", "P3", "P4", "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12", "P13", "P14", "P15", "P16"]`
  * Escolha/Vencedores dos Duelos: `[Vencedores R1: P1, P3, P5, P7, P9, P11, P13, P15]`, `[Vencedores R2: P1, P5, P9, P13]`, `[Semifinais: P1, P9]`, `[Final: P9]`
* **Saída Esperada:** `Campeão: P9`

---

## 3. Casos de Entrada Inválida (2 casos)

### CT-INV-01: Entrada Vazia (0 participantes)
* **Descrição:** Tentativa de inicializar o torneio enviando uma lista sem elementos.
* **Entradas:**
  * Lista de Participantes: `[]`
* **Saída Esperada:** `Erro: A lista de participantes não pode ser vazia. Mínimo de 1 participante exigido.`

### CT-INV-02: Escolha de Vencedor Inexistente na Partida
* **Descrição:** Tentativa de declarar como vencedor de um duelo um participante que não faz parte daquela disputa.
* **Entradas:**
  * Lista de Participantes: `["Pedro", "Marcos"]`
  * Escolha/Vencedor informado: `"Lucas"` (que não está na disputa entre Pedro e Marcos)
* **Saída Esperada:** `Erro: O vencedor informado não pertence ao confronto atual.`