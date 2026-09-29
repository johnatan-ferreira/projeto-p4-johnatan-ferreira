#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Classe base para a abstracao do participante
class Participante {
public:
    virtual ~Participante() = default;
    virtual int getId() const = 0;
    virtual string getNome() const = 0;
};

// Classe derivada que herda de Participante
class Jogador : public Participante {
private:
    int id;
    string nome;

public:
    Jogador(int idDoJogador, string nomeDoJogador) {
        id = idDoJogador;
        nome = nomeDoJogador;
    }

    int getId() const override {
        return id;
    }

    string getNome() const override {
        return nome;
    }
};

// Classe que representa um duelo entre dois participantes
class Confronto {
private:
    Participante* p1;
    Participante* p2;

public:
    Confronto(Participante* participante1, Participante* participante2) {
        p1 = participante1;
        p2 = participante2;
    }

    Participante* executarDuelo() {
        cout << "\n----------------------------------------\n";
        cout << "CONFRONTO:\n";
        cout << " 1 - " << p1->getNome() << " - ID: " << p1->getId() << "\n";
        cout << " 2 - " << p2->getNome() << " - ID: " << p2->getId() << "\n";
        cout << "----------------------------------------\n";

        int escolha = 0;
        while (escolha != 1 && escolha != 2) {
            cout << "Quem venceu? Digite 1 ou 2: ";
            cin >> escolha;
        }

        if (escolha == 1) {
            cout << "-> " << p1->getNome() << " venceu!\n";
            return p1;
        } else {
            cout << "-> " << p2->getNome() << " venceu!\n";
            return p2;
        }
    }
};

// Classe principal que gerencia o torneio
class Torneio {
private:
    vector<Participante*> participantes;
    int numeroDaRodada;

    void cadastrarJogadores() {
        int total = 0;
        cout << "Digite a quantidade de jogadores: ";
        cin >> total;
        cin.ignore();

        if (total <= 0) {
            return;
        }

        for (int i = 0; i < total; i++) {
            string nome;
            cout << "Nome do jogador " << (i + 1) << ": ";
            getline(cin, nome);

            Jogador* novoJogador = new Jogador(i + 1, nome);
            participantes.push_back(novoJogador);
        }
    }

    vector<Participante*> executarRodada() {
        vector<Participante*> vencedores;
        int total = participantes.size();
        int i = 0;

        if (total % 2 != 0) {
            cout << "\n[BYE] O participante " << participantes[0]->getNome() << " avanca direto!\n";
            vencedores.push_back(participantes[0]);
            i = 1;
        }

        while (i < total) {
            Confronto confronto(participantes[i], participantes[i + 1]);
            Participante* vencedor = confronto.executarDuelo();
            vencedores.push_back(vencedor);
            i = i + 2;
        }

        return vencedores;
    }

    void limparMemoria() {
        for (size_t i = 0; i < participantes.size(); i++) {
            delete participantes[i];
        }
        participantes.clear();
    }

public:
    Torneio() {
        numeroDaRodada = 1;
    }

    ~Torneio() {
        limparMemoria();
    }

    void iniciar() {
        cout << "=== TORNEIO DE CHAVEAMENTO ===\n\n";
        cadastrarJogadores();

        if (participantes.empty()) {
            cout << "\nErro: O torneio precisa de pelo menos 1 jogador!\n";
            return;
        }

        if (participantes.size() == 1) {
            cout << "\n[TORNEIO UNITARIO]\n";
            cout << "Vencedor: " << participantes[0]->getNome() << "\n";
            return;
        }

        while (participantes.size() > 1) {
            cout << "\n========================================\n";
            cout << "RODADA " << numeroDaRodada << "\n";
            cout << "========================================\n";

            participantes = executarRodada();
            numeroDaRodada = numeroDaRodada + 1;
        }

        cout << "\n========================================\n";
        cout << "Vencedor: " << participantes[0]->getNome() << "\n";
        cout << "========================================\n";
    }
};

int main() {
    Torneio torneio;
    torneio.iniciar();
    return 0;
}