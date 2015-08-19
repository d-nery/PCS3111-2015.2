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

#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"
#include "Mensagem.hpp"
#include "Pessoa.hpp"
#include "Tela.hpp"
#include "colors.hpp"

using namespace std;
using namespace Polikut;

int numPessoas = 0;
Pessoa* pessoas = new Pessoa [10];
Tela tela;

int main() {
	int opcao = 0;

	tela.principal();
	for (;;) {
		cin >> opcao;
		switch (opcao) {
			case 1:
			CLEAR
			tela.cadastro();
			tela.principal();
			break;

			case 2:
			tela.login();
			tela.principal();
			break;

			case 3:
			cout << "Volte Sempre!\n";
			delete[] pessoas;
			return 0;
			break;

			default:
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
