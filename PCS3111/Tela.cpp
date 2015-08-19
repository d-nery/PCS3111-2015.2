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

namespace Polikut {
	void Tela::principal() {
	    CLEAR
		//CBLUE cerr << "Tela principal criada" << endl; CRESET
		cout << "\nPolikut\n"
			 << "-----------------------------------------\n"
			 << "1) Cadastrar Pessoa\n"
			 << "2) Logar Como Pessoa\n"
			 << "3) Terminar\n" << endl
			 << "Digite uma opcao: ";
	}

	void Tela::cadastro() {
	    CLEAR
		//CBLUE cerr << "Tela de cadastro criada" << endl; CRESET
		if (numPessoas > 9) {
			cout << "Numero maximo de pessoas cadastradas.";
			return;
		}
		string nome, dataDeNascimento, pais;
		cout << "\nInforme os dados da pessoa: \n";

		cout << "Nome: ";
		cin.ignore();
		getline(cin, nome);

		cout << "Data de Nascimento: ";
		getline(cin, dataDeNascimento);

		cout << "Pais: ";
		getline(cin, pais);

		pessoas[numPessoas] = Pessoa(nome, dataDeNascimento, pais);
		cout << pessoas[numPessoas++].getNome()	<< " cadastrado com sucesso.\n";

        cout << "Aperte qualquer tecla para retornar\n";
        cin.get();
	}

	void Tela::login() {
		//CBLUE cerr << "Tela login criada" << endl; CRESET
		for(;;) {
	    CLEAR
			int opcao;
			cout << "\nEscolha uma das pessoas:\n";
			for (int i = 0; i < numPessoas; i++)
				cout << i + 1 << ") " << pessoas[i].getNome() << endl;
			cout << "Digite um numero ou 0 para voltar: ";
			cin >> opcao;
			if (opcao == 0)
				return;
			if (opcao >= 1 && opcao <= numPessoas)
				tela.info(pessoas[opcao - 1]);
			else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::info(Pessoa& pessoa) {
		//CBLUE cerr << "Tela info criada" << endl; CRESET
		for (;;) {
	    CLEAR
			int opcao = 0;
			cout << "Pessoa: " << pessoa.getNome() << endl;
			cout << pessoa.getDataDeNascimento() << " | " << pessoa.getPais() << endl;
			cout << "\nContatos: \n";
			pessoa.verContatos();
			cout << "-----------------------------------------\n\n"
				 << "Escolha uma opcao:\n"
				 << "1) Adicionar contato\n"
				 << "2) Ver mensagens enviadas\n"
				 << "3) Ver mensagens recebidas\n"
				 << "4) Escrever mensagem\n"
				 << "0) Voltar" << endl;

			cout << "Digite uma opcao: ";
	 		cin >> opcao;
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

	 			default:
	 			cout << "Digite uma opcao valida: ";
	 			cin.clear();
	 			while (cin.get() != '\n');
	 		}
		}
	}

	void Tela::adicionarContato(Pessoa& pessoa) {
	    CLEAR
		//CBLUE cerr << "Tela adicionar contato criada" << endl; CRESET
		int opcao = 0;
		cout << "Pessoas\n"
			 << "-----------------------------------------\n";
		for (int i = 0; i < numPessoas; i++)
			cout << i + 1 << ") " << pessoas[i].getNome() << "\n";
		cout << "\nEscolha um contato para adicionar ou 0 para voltar: ";
		for (;;) {
			cin >> opcao;
			if (opcao == 0)
				return;
			if (opcao >= 1 && opcao <= numPessoas) {
				pessoa.adiciona(&pessoas[opcao - 1]);
				cout << pessoas[opcao - 1].getNome() << " conectado a " << pessoa.getNome() << endl;
				cout << "Aperte qualquer tecla para retornar\n";
                cin.get(); cin.get();
				return;
			}
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	void Tela::mensagensEnviadas(Pessoa& pessoa) {
	    CLEAR
		//CBLUE cerr << "Tela mensagens enviadas criada" << endl; CRESET
		cout << "Mensagens Enviadas\n"
		 	 << "-----------------------------------------\n";
		pessoa.getMensagensEnviadas().listar();
        cout << "Aperte qualquer tecla para retornar\n";
		cin.get(); cin.get();
		return;
	}

	void Tela::mensagensRecebidas(Pessoa& pessoa) {
		for (;;) {
		    CLEAR
			//CBLUE cerr << "Tela mensagens recebidas criada" << endl; CRESET
			int opcao = 0;
			cout << "Mensagens Recebidas\n"
				 << "-----------------------------------------\n";
			pessoa.getMensagensRecebidas().listar();

			cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
			cin >> opcao;
			if (opcao == 0)
				return;
			if (opcao > 0 && opcao <= pessoa.getMensagensRecebidas().getTotal()) {
				pessoa.getMensagensRecebidas().getMensagem(opcao)->curtir();
				cout << "Mensagem curtida\n";
			} else {
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::escreverMensagem(Pessoa& pessoa) {
	    CLEAR
		//CBLUE cerr << "Tela escrever mensagem criada" << endl; CRESET
		string mensagem;
		cout << "Digite a mensagem: ";

		cin.ignore();
		getline(cin, mensagem);

		pessoa.envia(mensagem);
		cout << "Mensagem enviada a todos os contatos\n";
		cout << "Aperte qualquer tecla para retornar\n";
		cin.get();
	}
}
