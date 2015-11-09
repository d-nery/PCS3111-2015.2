/**
Escola Politecnica da Universidade de Sao Paulo
23 de novembro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 3 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include "ListaDeMensagens.hpp"
#include "Perfil.hpp"

namespace Polikut {
	class Pessoa : public Perfil {
	private:
		// Dados da pessoa
		std::string dataDeNascimento;
		std::string pais;

	public:
		Pessoa(std::string nome, std::string dataDeNascimento, std::string pais);

		virtual ~Pessoa();

		std::string getPais();
		std::string getDataDeNascimento();

		// Adiciona o contato à lista de contatos da Pessoa
		void adiciona(Perfil* contato);

		// Implementa o método adicionadoPor para adicionar uma mensagem à pessoa que
		// ela foi adicionada pelo contato
		virtual void adicionadoPor(Perfil* contato);

		// Envia uma mensagem privada para um contato
		void envia(std::string texto, Perfil* contato);
	};
}

#endif /* end of include guard: _PESSOA_HPP_ */
