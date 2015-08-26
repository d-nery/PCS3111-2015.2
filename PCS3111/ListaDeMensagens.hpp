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

#ifndef _LISTA_DE_MENSAGENS_HPP_
#define _LISTA_DE_MENSAGENS_HPP_

#include "Mensagem.hpp"
#include "Elemento.hpp"

namespace Polikut {
	class ListaDeMensagens {
	private:
		// Total de mensagens na lista
		int total;

		// Cabeca da lista ligada
		Elemento* cabeca;

	public:
		// Cria uma lista ligada de mensagens
		ListaDeMensagens();

		// Destroi a lista ligada, apagando todos os elementos criados
		~ListaDeMensagens();

		// Adiciona uma mensagem à lista ligada
		void adicionar(Mensagem* m);

		// Obtém a cabeça da lista ligada
		// (Isso é necessário para varrer a lista)
		Elemento* getCabeca();

		// Obtem a mensagem apontada pelo elemento de chave id
		Mensagem* getMensagem(int id);

		// Retorna o total de mensgaens na lista
		int getTotal();

		// Lista as mensagens da lista
		void listar();
	};
}

#endif /* end of include guard: _LISTA_DE_MENSAGENS_HPP_ */
