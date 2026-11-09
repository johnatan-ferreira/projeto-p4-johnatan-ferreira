#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;

namespace {
    struct Participante {
        int id;
        string nome;
    };
}

using FuncaoDuelo = function<Participante(Participante, Participante)>;

static vector<Participante>
processarRodada(const vector<Participante> &participantes, const FuncaoDuelo &resolverDuelo) {
    vector<Participante> vencedores;
    const auto total = participantes.size();
    int i = 0;

    if (total % 2 != 0) {
        vencedores.push_back(participantes[0]);
        i = 1;
    }

    while (i < total) {
        Participante vencedor = resolverDuelo(participantes[i], participantes[i + 1]);
        vencedores.push_back(vencedor);
        i += 2;
    }

    return vencedores;
}

static Participante executarTorneioRecursivo(const vector<Participante> &participantes,
                                             const FuncaoDuelo &resolverDuelo) {
    if (participantes.size() == 1) {
        return participantes[0];
    }
    const vector<Participante> proximaRodada = processarRodada(participantes, resolverDuelo);
    return executarTorneioRecursivo(proximaRodada, resolverDuelo);
}

int main() {
    cout << "=== TORNEIO FUNCIONAL ===\n";

    int total;
    cout << "Digite a quantidade de jogadores:\n";
    cin >> total;
    cin.ignore();

    vector<Participante> jogadoresIniciais;
    for (int i = 0; i < total; i++) {
        string nome;
        cout << "Nome do jogador " << (i + 1) << ":" << "\n";
        getline(cin, nome);
        jogadoresIniciais.push_back({i + 1, nome});
    }

    const FuncaoDuelo dueloInterativo = [](const Participante &p1, const Participante &p2) {
        cout << "\nDuelo: " << p1.nome << " vs " << p2.nome << "\n";
        int escolha = 0;
        while (escolha != 1 && escolha != 2) {
            cout << "Quem venceu? (1 para " << p1.nome << " / 2 para " << p2.nome << "):" << "\n";
            cin >> escolha;
        }
        return (escolha == 1) ? p1 : p2;
    };

    auto [id, nome] = executarTorneioRecursivo(jogadoresIniciais, dueloInterativo);

    cout << "\n========================================\n";
    cout << "Vencedor do Torneio (Paradigma Funcional): " << nome << "\n";
    cout << "========================================\n";

    return 0;
}
