/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#ifndef _ELEMENTO_HPP_
#define _ELEMENTO_HPP_

#include <string>

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
