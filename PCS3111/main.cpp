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

#include "Perfil.hpp"
#include "colors.hpp"      // Macros para colorir o terminal/console e limpa-lo
#include "Tela.hpp"

using namespace std;
using namespace Polikut;

#ifdef _WIN32
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
#endif

// Main
int main() {
#ifdef _WIN32
    system("title PoliKut");
#endif // _WIN32
    CRESET;
    Tela tela;                        ///< Interface com o usuario
	int opcao = 0;                    // Opcao digitada pelo  usuario

	tela.principal();                 // Mostra a tela inicial
	for (;;) {
		if(cin >> opcao)              // Recebe dados do usuario e checa o estado de cin para ver se o esperado (int) foi recebido
			switch (opcao) {
			case 1:
				tela.cadastroPessoa();      // Mostra a tela de cadastro de Pessoa
				tela.principal();
				break;

            case 2:
                tela.cadastroDepartamento();         // Mostra a tela de cadastro de Departamento
                tela.principal();
                break;

			case 3:
				tela.login();         // Mostra a tela de login
				tela.principal();
				break;

			case 0:
				cout << "Volte Sempre!\n";
				cin.get(); cin.get();       // Espera enter para nao fechar rapido demais
				return 0;

			default:                        // Nenhuma das opcoes foi digitada
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');  // Limpa resquicios no cin antes de receber informacoes novamente
			}
		else {                              // Algo nao numerico foi digitado
			cout << "Digite uma opcao valida: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}
}
