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

#ifndef _ELEMENTO_HPP_
#define _ELEMENTO_HPP_

#include "Mensagem.hpp"

namespace Polikut {
	class Elemento {
	private:
		int id;
		Mensagem* mensagem;
		Elemento* proximo;

	public:
		Elemento();
		~Elemento();
		void setId(int id);
		void setMensagem(Mensagem* msg);
		void setProximo(Elemento* prx);
		int getId();
		Mensagem* getMensagem();
		Elemento* getProximo();
	};
}

#endif /* end of include guard: _ELEMENTO_HPP_ */
