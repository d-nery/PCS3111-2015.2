/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
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

		std::string getConteudo();
		int getCurtidas();
		void curtir();

	};
}

#endif /* end of include guard: _MENSAGEM_HPP_ */
