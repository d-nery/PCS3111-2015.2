/**
Escola Politecnica da Universidade de Sao Paulo
14 de outubro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 2 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#include <iostream>
#include <string>

#include "Tela.hpp"
#include "colors.hpp"

using namespace std;
using namespace Polikut;

#ifdef _WIN32
extern HANDLE hOut;
#endif // _WIN32

namespace Polikut {
	void Tela::principal() {
		CLEAR;
		cout << "\nPoli"; CPINK; cout << "Kut\n"; CRESET;
        cout << "-----------------------------------------\n"
			 << "1) Cadastrar Pessoa\n"
			 << "2) Cadastrar Departamento\n"
			 << "3) Logar Como Perfil\n"
			 << "0) Terminar\n" << endl
			 << "Digite uma opcao: ";
	}

	void Tela::cadastroPessoa() {
		CLEAR;
		if (perfis.size() > 9) {
			cout << "Numero maximo de perfis cadastrados.";
			cout << "\nAperte Enter para retornar\n";
			cin.get();
			while (cin.get() != '\n');
			return;
		}
		string nome, dataDeNascimento, pais;
		cout << "\nInforme os dados da pessoa: \n";

		cout << "Nome: "; CGREEN;
		cin.ignore();
		getline(cin, nome); CRESET;

		cout << "Data de Nascimento: "; CGREEN;
		getline(cin, dataDeNascimento); CRESET;

		cout << "Pais: "; CGREEN;
		getline(cin, pais); CRESET;

		perfis.push_back(new Pessoa(nome, dataDeNascimento, pais));
		CGREEN; cout << perfis[perfis.size()]->getNome(); CRESET; cout << " cadastrado com sucesso.\n";

		cout << "\nAperte Enter para retornar\n";
		while (cin.get() != '\n');
	}

	void Tela::cadastroDepartamento() {
		CLEAR;
		if (perfis.size() > 9) {
			cout << "Numero maximo de perfis cadastrados.";
			cout << "\nAperte Enter para retornar\n";
			cin.get();
			while (cin.get() != '\n');
			return;
		}
		string nome, site;
		cout << "\nInforme os dados da pessoa: \n";

		cout << "Nome: "; CGREEN;
		cin.ignore();
		getline(cin, nome); CRESET;

		cout << "Site: "; CGREEN;
		getline(cin, site); CRESET;

		cout << "Pais: "; CGREEN;
		getline(cin, pais); CRESET;

		perfis.push_back(new Pessoa(nome, dataDeNascimento, pais));
		CGREEN; cout << perfis[perfis.size()]->getNome(); CRESET; cout << " cadastrado com sucesso.\n";

		cout << "\nAperte Enter para retornar\n";
		while (cin.get() != '\n');
	}
}
