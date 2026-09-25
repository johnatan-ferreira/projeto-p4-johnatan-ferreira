#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace {
    // Estrutura para os participantes
    struct Jogador {
        int id{};
        string nome;
    };
}

// Funcao para ler os nomes e a quantidade pelo terminal
static vector<Jogador> ler_jogadores() {
    int total = 0;
    cout << "Digite a quantidade de jogadores: ";
    cin >> total;
    cin.ignore();

    vector<Jogador> lista;

    // Validacao simples para entrada nula
    if (total <= 0) {
        return lista;
    }

    for (int i = 0; i < total; i++) {
        Jogador j;
        j.id = i + 1;
        cout << "Nome do jogador " << j.id << ": ";
        getline(cin, j.nome);
        lista.push_back(j);
    }

    return lista;
}

// Funcao que executa uma rodada do torneio
static vector<Jogador> rodada(const vector<Jogador> &lista) {
    vector<Jogador> vencedores;
    const auto total = lista.size(); //Em vez de INT passa a ser AUTO para fazer cast em caso de estouro
    int i = 0;

    // Regra de Bye caso a quantidade de jogadores seja impar
    if (total % 2 != 0) {
        cout << "\n[BYE] O jogador " << lista[0].nome << " avanca direto!\n";
        vencedores.push_back(lista[0]);
        i = 1; // Comeca o pareamento do proximo
    }

    // Laco simples para os confrontos de 2 em 2
    while (i < total) {
        const Jogador &j1 = lista[i];
        const Jogador &j2 = lista[i + 1];

        cout << "\n----------------------------------------\n";
        cout << "CONFRONTO:\n";
        cout << " (1) " << j1.nome << " (ID: " << j1.id << ")\n";
        cout << " (2) " << j2.nome << " (ID: " << j2.id << ")\n";
        cout << "----------------------------------------\n";

        int escolha = 0;
        while (escolha != 1 && escolha != 2) {
            cout << "Quem venceu? (1 ou 2): ";
            cin >> escolha;
        }

        if (escolha == 1) {
            vencedores.push_back(j1);
            cout << "-> " << j1.nome << " venceu!\n";
        } else {
            vencedores.push_back(j2);
            cout << "-> " << j2.nome << " venceu!\n";
        }

        i = i + 2; // Avanca para o proximo par
    }

    return vencedores;
}

int main() {
    cout << "=== TORNEIO DE CHAVEAMENTO ===\n\n";

    vector<Jogador> participantes = ler_jogadores();

    // Tratamento de caso invalido (0 jogadores)
    if (participantes.empty()) {
        cout << "\nErro: O torneio precisa de pelo menos 1 jogador!\n";
        return 0;
    }

    // Tratamento de caso limite (1 jogador)
    if (participantes.size() == 1) {
        cout << "\n[TORNEIO UNITARIO]\n";
        cout << "Vencedor: " << participantes[0].nome << "\n";
        return 0;
    }

    int num_rodada = 1;

    // Laco principal que roda ate restar apenas 1 campeao
    while (participantes.size() > 1) {
        cout << "\n========================================\n";
        cout << "RODADA " << num_rodada << "\n";
        cout << "========================================\n";

        participantes = rodada(participantes);
        num_rodada++;
    }

    // Exibicao do resultado final
    cout << "\n========================================\n";
    cout << "Vencedor: " << participantes[0].nome << "\n";
    cout << "========================================\n";

    return 0;
}
