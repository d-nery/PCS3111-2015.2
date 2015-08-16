#include <iostream>
#include <iomanip>
#include <cmath>

#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"
#include "Mensagem.hpp"
#include "Pessoa.hpp"

using namespace std;
using namespace Polikut;

int main() {
	int opcao = 0;

	cout << "Polikut\n"
	 	 << "--------------------\n"
		 << "1) Cadastrar Pessoa\n"
		 << "2) Logar Como Pessoa\n"
		 << "3) Terminar\n" << endl
		 << "Digite uma opcao: ";
	while (opcao != 3) {
		cin >> opcao;
		switch (opcao) {
			case 1:
			cout << "cadastrar\n";
			break;

			case 2:
			cout << "logar\n";
			break;

			case 3:
			cout << "sair\n";
			break;

			default:
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return 0;
}
