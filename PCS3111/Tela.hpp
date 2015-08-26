/**
Escola Politecnica da Universidade de Sao Paulo
2 de setembro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#ifndef _TELA_HPP_
#define _TELA_HPP_

#include "Pessoa.hpp"

namespace Polikut {
	class Tela {
	public:
		// Menu Principal
		void principal();
		
		// Tela de cadastrar uma pessoa no sistema
		void cadastro();

		// Tela de entrar como uma pessoa no sistema
		void login();

		// Tela de informacoes de pessoa
		void info(Pessoa& pessoa);

		// Tela para adicionar um contato a pessoa
		void adicionarContato(Pessoa& pessoa);

		// Telas com as mensagens enviadas e recebidas de pessoa
		void mensagensEnviadas(Pessoa& pessoa);
		void mensagensRecebidas(Pessoa& pessoa);

		// Tela para escrever mensagem de pessoa para seus contatos
		void escreverMensagem(Pessoa& pessoa);
	};
}

#endif /* end of include guard: _TELA_HPP_ */
