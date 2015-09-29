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

#ifndef _MENSAGEM_HPP_
#define _MENSAGEM_HPP_

#include <string>

/**
 * Classe mensagem
 *
 * Representa uma mensagem simples
 */

namespace Polikut {
	class Mensagem {
	private:
		// Conteudo da mensagem
		std::string conteudo;

	public:
		// Cria uma mensagem vazia
		Mensagem();

		//Cria uma mensagem com conteudo
		Mensagem(std::string conteudo);

		// Destroi a mensagem
		virtual ~Mensagem();

		// Retorna o conteudo da mensagem
		std::string getConteudo();
	};
}

#endif /* end of include guard: _MENSAGEM_HPP_ */
