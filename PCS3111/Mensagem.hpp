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

#ifndef _MENSAGEM_HPP_
#define _MENSAGEM_HPP_

#include <string>

namespace Polikut {
	class Mensagem {
	private:
		std::string conteudo;
		int curtidas;

	public:
		Mensagem();
		Mensagem(std::string conteudo);

		~Mensagem();

		std::string getConteudo();
		int getCurtidas();
		void curtir();

	};
}

#endif /* end of include guard: _MENSAGEM_HPP_ */
