/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#ifndef _LISTA_DE_MENSAGENS_HPP_
#define _LISTA_DE_MENSAGENS_HPP_

#include "Mensagem.hpp"
#include "Elemento.hpp"

namespace Polikut {
	class ListaDeMensagens {
	private:
		int total;
	public:
		// Cria uma lista ligada de mensagens
		ListaDeMensagens();

		// Destrói a lista ligada, apagando todos os elementos criados
		~ListaDeMensagens();

		// Adiciona uma mensagem à lista ligada
		void adicionar(Mensagem& m);

		// Obtém a cabeça da lista ligada
		// (Isso é necessário para varrer a lista)
		Elemento* getCabeca();

		int getTotal();
	};
}

#endif /* end of include guard: _LISTA_DE_MENSAGENS_HPP_ */
