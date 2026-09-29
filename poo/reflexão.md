# [P4-ETAPA-04] Documento de Reflexão - Transição de Imperativo para Orientado a Objetos

Este documento apresenta a reflexão sobre a mudança de paradigma do modelo **Imperativo** para o modelo **Orientado a Objetos (POO)** na solução do Chaveamento de Torneio em C++.

No modelo imperativo, o código funcionava com uma estrutura passiva de dados e funções soltas que manipulavam esses dados diretamente.

No modelo orientado a objetos, o problema foi dividido em entidades autônomas chamadas classes (`Jogador`, `Confronto` e `Torneio`). Cada classe passou a ser responsável por seus próprios dados e pelas ações que realiza.

* **Imperativo:** O estado do torneio e dos jogadores ficava exposto em vetores globais ou locais, passados de função em função no fluxo da `main`.
* **Orientado a Objetos:** O estado fica protegido dentro dos atributos privados de cada classe (`private:`). Por exemplo, o nome e o ID do jogador pertencem exclusivamente ao objeto `Jogador`, e a rodada atual pertence ao objeto `Torneio`.

Cada componente possui um papel bem definido na arquitetura:
* **`Participante` / `Jogador`:** Mantém os dados do competidor e fornece métodos para consultar nome e ID sem expor as variáveis.
* **`Confronto`:** Cuida exclusivamente da lógica de um duelo entre dois participantes, exibindo as opções e lendo a escolha do vencedor.
* **`Torneio`:** Gerencia a lista geral de participantes, controla o avanço das rodadas, aplica a regra de Bye e declara o campeão.

* **Herança e Polimorfismo:** A classe `Jogador` herda da classe abstrata `Participante`. O uso de ponteiros (`Participante*`) permite tratar qualquer competidor de forma genérica.
* **Composição e Agregação:** A classe `Confronto` contém dois ponteiros para `Participante` para realizar o duelo. A classe `Torneio` possui um vetor contendo todos os participantes inscritos.

No paradigma orientado a objetos, as classes podem ser reaproveitadas em outros projetos de forma independente. A classe `Confronto`, por exemplo, pode ser utilizada em qualquer outro formato de disputa sem precisar de alterações.

O uso dos modificadores `private` e `public` garante que os dados internos de uma classe não sejam alterados indevidamente por partes externas do programa. A leitura e escrita de dados ocorrem apenas por métodos autorizados, evitando inconsistências no estado do sistema.

A arquitetura se tornou mais flexível para mudanças. Caso seja necessário adicionar um jogador controlado por inteligencia artificial no futuro, basta criar uma nova classe derivada de `Participante` sem precisar modificar o motor do `Torneio` ou a classe `Confronto`.

A herança foi utilizada exclusivamente na relação onde um `Jogador` **e um** `Participante`. Para as demais relações do sistema, foi utilizada a composição, onde um `Torneio` **tem** participantes e um `Confronto` **tem** dois duelistas, respeitando a boa pratica de modelagem orientada a objetos.
