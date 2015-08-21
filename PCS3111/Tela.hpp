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
		void principal();
		void cadastro();
		void login();
		void info(Pessoa& pessoa);
		void adicionarContato(Pessoa& pessoa);
		void mensagensEnviadas(Pessoa& pessoa);
		void mensagensRecebidas(Pessoa& pessoa);
		void escreverMensagem(Pessoa& pessoa);
	};
}

#endif /* end of include guard: _TELA_HPP_ */
