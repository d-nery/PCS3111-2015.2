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

#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include "ListaDeMensagens.hpp"
#include "Perfil.hpp"

using namespace std;

namespace Polikut {
	class Pessoa : public Perfil {
	private:
		// Dados da pessoa
		string dataDeNascimento;
		string pais;

	public:
		Pessoa(string nome, string dataDeNascimento, string pais);

		virtual ~Pessoa();

		string getPais();
		string getDataDeNascimento();

		// Adiciona o contato à lista de contatos da Pessoa
		void adiciona(Perfil* contato);

		// Implementa o método adicionadoPor para adicionar uma mensagem à pessoa que
		// ela foi adicionada pelo contato
		virtual void adicionadoPor(Perfil* contato);

		// Envia uma mensagem privada para um contato
		void envia(string texto, Perfil* contato);
	};
}

#endif /* end of include guard: _PESSOA_HPP_ */
