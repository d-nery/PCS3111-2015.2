/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#include <iostream>
#include <iomanip>
#include <cmath>

#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"
#include "Mensagem.hpp"
#include "Pessoa.hpp"
#include "main.hpp"

using namespace std;
using namespace Polikut;

static int numPessoas = 0; // Colocar dentro da classe de Pessoa | incrementa no construtor
static Pessoa* pessoas = new Pessoa [10];

int main() {
	int opcao = 0;

	menuPrincipal();

	for (;;) {
		cin >> opcao;
		switch (opcao) {
			case 1:
			cadastro();
			menuPrincipal();
			break;

			case 2:
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

void Polikut::menuPrincipal() {
	cout << "\nPolikut\n"
		 << "--------------------\n"
		 << "1) Cadastrar Pessoa\n"
		 << "2) Logar Como Pessoa\n"
		 << "3) Terminar\n" << endl
		 << "Digite uma opcao: ";
}

void Polikut::cadastro() {
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
