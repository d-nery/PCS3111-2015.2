/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio- Programa 1 - 2015

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#include <iostream>
#include <iomanip>

#include "Pessoa.hpp"
#include "Tela.hpp"
#include "colors.hpp"

using namespace std;
using namespace Polikut;

extern int numPessoas;
extern Pessoa* pessoas;
extern Tela tela;

#ifdef _WIN32
extern HANDLE hOut;
extern CONSOLE_SCREEN_BUFFER_INFO original;
#endif //

namespace Polikut {
	void Tela::principal() {
	    CLEAR
		cout << "\nPoli"; CBLUE cout << "Social\n"; CRESET
        cout << "-----------------------------------------\n"
			 << "1) Cadastrar Pessoa\n"
			 << "2) Logar Como Pessoa\n"
			 << "3) Terminar\n" << endl
			 << "Digite uma opcao: ";
	}

	void Tela::cadastro() {
	    CLEAR
		if (numPessoas > 9) {
			cout << "Numero maximo de pessoas cadastradas.";
            cout << "\nAperte Enter para retornar\n";
            cin.get();
            while (cin.get() != '\n');
			return;
		}
		string nome, dataDeNascimento, pais;
		cout << "\nInforme os dados da pessoa: \n";

		cout << "Nome: "; CRED
		cin.ignore();
		getline(cin, nome); CRESET

		cout << "Data de Nascimento: "; CRED
		getline(cin, dataDeNascimento); CRESET

		cout << "Pais: "; CRED
		getline(cin, pais); CRESET

		pessoas[numPessoas] = Pessoa(nome, dataDeNascimento, pais);
		CRED cout << pessoas[numPessoas++].getNome(); CRESET cout << " cadastrado com sucesso.\n";

        cout << "\nAperte Enter para retornar\n";
        while (cin.get() != '\n');
	}

	void Tela::login() {
		for(;;) {
	    CLEAR
			int opcao;
			if (numPessoas > 0) {
				cout << "\nEscolha uma das pessoas:\n"; CRED
				for (int i = 0; i < numPessoas; i++)
					cout << i + 1 << ") " << pessoas[i].getNome() << endl;
				CRESET cout << "Digite um numero ou 0 para voltar: ";
			} else {
				cout << "\n--Não há pessoas cadastradas no sistema--\n"
					 <<   "      Aperte Enter para retornar\n";
				cin.get();
				while (cin.get() != '\n');
				return;
			}
			if (cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao >= 1 && opcao <= numPessoas)
					tela.info(pessoas[opcao - 1]);
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::info(Pessoa& pessoa) {
		for (;;) {
	    CLEAR
			int opcao = 0;
			cout << "Pessoa: "; CRED cout << pessoa.getNome() << endl;
			cout << pessoa.getDataDeNascimento(); CRESET cout << " | "; CRED cout << pessoa.getPais() << endl;
			CRESET cout << "\nContatos: \n";
			CRED pessoa.verContatos(); CRESET
			cout << "-----------------------------------------\n\n"
				 << "Escolha uma opcao:\n"
				 << "1) Adicionar contato\n"
				 << "2) Ver mensagens enviadas\n"
				 << "3) Ver mensagens recebidas\n"
				 << "4) Escrever mensagem\n"
				 << "0) Voltar" << endl;

			cout << "Digite uma opcao: ";
	 		if(cin >> opcao)
		 		switch (opcao) {
		 			case 0:
		 			return;

		 			case 1:
					tela.adicionarContato(pessoa);
					break;

					case 2:
					tela.mensagensEnviadas(pessoa);
					break;

					case 3:
					tela.mensagensRecebidas(pessoa);
					break;

					case 4:
					tela.escreverMensagem(pessoa);
		 			break;
	 			}
 			else {
	 			cin.clear();
	 			while (cin.get() != '\n');
			}
		}
	}

	void Tela::adicionarContato(Pessoa& pessoa) {
		for (;;) {
	    CLEAR
            int opcao = 0;
            cout << "Pessoas\n"
                 << "-----------------------------------------\n";
            for (int i = 0; i < numPessoas; i++)
                cout << i + 1 << ") " << pessoas[i].getNome() << "\n";
            cout << "\nEscolha um contato para adicionar ou 0 para voltar: ";
			if(cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao >= 1 && opcao <= numPessoas) {
					switch(pessoa.adiciona(&pessoas[opcao - 1])) {
                    case 0:
                        cout << pessoas[opcao - 1].getNome() << " conectado a " << pessoa.getNome() << endl;
                        break;
                    case (-1):
                        cout << "Contato ja adicionado!\n";
                        break;
                    case (-2):
                        cout << "Voce nao pode adicionar a si mesmo!\n";
                        break;
                    }
                    cout << "\nAperte Enter para retornar\n";
                    cin.get();
                    while (cin.get() != '\n');
                    return;
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::mensagensEnviadas(Pessoa& pessoa) {
	    CLEAR
		cout << "Mensagens Enviadas\n"
		 	 << "-----------------------------------------\n";
		pessoa.getMensagensEnviadas().listar();
        cout << "\nAperte Enter para retornar\n";
		cin.get();
		while (cin.get() != '\n');
		return;
	}

	void Tela::mensagensRecebidas(Pessoa& pessoa) {
		for (;;) {
		    CLEAR
			int opcao = 0;
			cout << "Mensagens Recebidas\n"
				 << "-----------------------------------------\n";
			pessoa.getMensagensRecebidas().listar();

			cout << "\nDigite o numero da mensagem para curtir ou 0 para voltar: ";
			if(cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao > 0 && opcao <= pessoa.getMensagensRecebidas().getTotal()) {
					pessoa.getMensagensRecebidas().getMensagem(opcao)->curtir();
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::escreverMensagem(Pessoa& pessoa) {
	    CLEAR
	    if (pessoa.getNumContatos() == 0) {
            cout << "Voce nao tem nenhum contato :(\n"
                << "Por que nao adiciona algum na tela anterior? =D\n";
            cout << "\nAperte Enter para retornar\n";
            cin.get();
            while (cin.get() != '\n');
            return;
	    }
        string mensagem;
        cout << "Digite a mensagem: ";

        cin.ignore();
        getline(cin, mensagem);

        pessoa.envia(mensagem);
        cout << "Mensagem enviada a todos os contatos\n";
		cout << "\nAperte Enter para retornar\n";
		while (cin.get() != '\n');
	}
}
