/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#include <iostream>
#include <iomanip>

#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"
#include "Mensagem.hpp"
#include "Pessoa.hpp"
#include "colors.hpp"
#include "Tela.hpp"

using namespace std;
using namespace Polikut;

int numPessoas = 0;
Pessoa* pessoas = new Pessoa [10];
Tela tela;

#ifdef _WIN32
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO original;
#endif //

int main() {
#ifdef _WIN32
GetConsoleScreenBufferInfo(hOut, &original);
#endif // _WIN32
    CRESET
	int opcao = 0;

	tela.principal();
	for (;;) {
		cin >> opcao;
		switch (opcao) {
			case 1:
			tela.cadastro();
			tela.principal();
			break;

			case 2:
			tela.login();
			tela.principal();
			break;

			case 3:
			cout << "Volte Sempre!\n";
			return 0;
			break;

			default:
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
