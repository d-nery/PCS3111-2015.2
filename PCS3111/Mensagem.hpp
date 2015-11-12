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

#ifndef _MENSAGEM_HPP_
#define _MENSAGEM_HPP_

#include <iostream>
#include <string>

/**
 * Classe mensagem
 *
 * Representa uma mensagem simples
 */

namespace Polikut {
	class Mensagem {
	protected:
		// Conteudo da mensagem
		std::string conteudo;

		std::string autor;

		friend std::ostream& operator<<(std::ostream& os, const Mensagem* msg);

		// Lista a msg
		virtual void listar(std::ostream& os) const;
	public:
		// Cria uma mensagem vazia
		Mensagem();

		//Cria uma mensagem com conteudo
		Mensagem(std::string conteudo, std::string autor);

		// Destroi a mensagem
		virtual ~Mensagem();

		// Retorna o conteudo da mensagem
		std::string getConteudo() const;
	};
}

#endif /* end of include guard: _MENSAGEM_HPP_ */
