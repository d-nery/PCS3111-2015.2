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

#ifndef _ELEMENTO_HPP_
#define _ELEMENTO_HPP_

#include "Mensagem.hpp"

/*
 * Classe: Elemento
 *
 * Representa um elemento da lista ligada de mensagens
 */
namespace Polikut {
	class Elemento {
	private:
		// Chave do elemento
		int id;

		// Mensagem do elemento
		Mensagem* mensagem;

		// Proximo elemento
		Elemento* proximo;

	public:
		// Cria um elemento vazio
		Elemento();

		// Cria um elemento com atributos definidos
		Elemento(int id, Mensagem* msg, Elemento* prx);

		// Destroi o elemento, apagando seus ponteiros para a mensagem e para o proximo
		~Elemento();

		// Muda o proximo elemento
		void setProximo(Elemento* prx);

		// Retorna a chave do elemento
		int getId();

		// Retorna o ponteiro para a mensagem do elemento
		Mensagem* getMensagem();

		//Retorna o ponteiro para o proximo elemento
		Elemento* getProximo();
	};
}

#endif /* end of include guard: _ELEMENTO_HPP_ */
