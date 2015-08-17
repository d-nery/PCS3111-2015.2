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

using namespace std;
using namespace Polikut;

extern int numPessoas;
extern Pessoa* pessoas;
extern Tela tela;

namespace Polikut {
	void Tela::principal() {
		cout << "\nPolikut\n"
			 << "--------------------\n"
			 << "1) Cadastrar Pessoa\n"
			 << "2) Logar Como Pessoa\n"
			 << "3) Terminar\n" << endl
			 << "Digite uma opcao: ";
	}

	void Tela::cadastro() {
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
	}

	void Tela::login() {
		int opcao;
		cout << "Escolha uma das pessoas:\n";
		for (int i = 0; i < numPessoas; i++)
			cout << i + 1 << ") " << pessoas[i].getNome() << endl;
		cout << "Digite um numero ou 0 para voltar: ";
		cin >> opcao;
		switch (opcao) {
			case 0:
			return;

			case 1: case 2: case 3: case 4: case 5:
			case 6: case 7: case 8: case 9: case 10:
			tela.info(pessoas[opcao - 1]);
			break;

			default:
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	void Tela::info(Pessoa& pessoa) {
		int opcao = 0;
		cout << "Pessoa: " << pessoa.getNome() << endl;
		cout << pessoa.getDataDeNascimento() << " | " << pessoa.getPais() << endl << endl;
		cout << "\nContatos: \n";
		pessoa.verContatos();
		cout << "-----------------------------\n\n"
			 << "Escolha uma opcao:\n"
			 << "1) Adicionar contato\n"
			 << "2) Ver mensagens enviadas\n"
			 << "3) Ver mensgaens recebidas\n"
			 << "4) Escrever mensagem\n"
			 << "0) Voltar" << endl;

		cout << "Digite uma opcao valida: ";
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

	void Tela::adicionarContato(Pessoa& pessoa) {
		int opcao = 0;
		cout << "Pessoas\n"
			 << "-------------------------\n";
		for (int i = 0; i < numPessoas; i++)
			cout << i + 1 << ") " << pessoas[i].getNome();
		cout << "\nEscolha um contato para adicionar ou 0 para voltar: ";
		for (;;) {
			cin >> opcao;
			switch (opcao) {
				case 0:
				tela.info(pessoa);
				break;

				case 1: case 2: case 3: case 4: case 5:
				case 6: case 7: case 8: case 9: case 10:
				pessoa.adiciona(pessoas[opcao - 1]);
				cout << pessoas[opcao - 1].getNome() << " conectado a " << pessoa.getNome() << endl;
				tela.info(pessoa);
				break;

				default:
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::mensagensEnviadas(Pessoa& pessoa) {
		cout << "Mensagens Enviadas\n"
		 	 << "-----------------------------------------\n";
		for (int i = 0; i < pessoa.getMensagensEnviadas().getTotal(); i++)
			cout << i + 1 << ") " << pessoa.getMensagensEnviadas().getMensagem(i).getConteudo() << endl;
		tela.info(pessoa);
	}

	void Tela::mensagensRecebidas(Pessoa& pessoa) {
		int opcao = 0;
		cout << "Mensagens Recebidas\n"
			 << "----------------------------\n";
		for (int i = 0; i < pessoa.getMensagensRecebidas().getTotal(); i++)
			cout << i + 1 << ") " << pessoa.getMensagensRecebidas().getMensagem(i).getConteudo() << "("
			 	 << pessoa.getMensagensRecebidas().getMensagem(i).getCurtidas() << " curtidas)\n";

		cout << "Digite o numero da mensagem para curtir ou 0 para voltar: ";
		for (;;) {
			cin >> opcao;
			if (opcao == 0)
				tela.info(pessoa);
			if (opcao > 0 && opcao <= pessoa.getMensagensRecebidas().getTotal()) {
				pessoa.getMensagensRecebidas().getMensagem(opcao).curtir();
				cout << "Mensagem curtida\n";
				tela.info(pessoa);
			} else {
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::escreverMensagem(Pessoa& pessoa) {
		string mensagem;
		cout << "Digite a mensagem: ";

		cin.ignore();
		getline(cin, mensagem);

		pessoa.envia(mensagem);
		cout << "Mensagem enviada a todos os contatos\n";

		tela.info(pessoa);
	}
}
