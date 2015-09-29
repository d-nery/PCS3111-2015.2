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

#ifndef _MENSAGEM_COM_CURTIR_HPP_
#define _MENSAGEM_COM_CURTIR_HPP_

#include <string>

#include "Mensagem.hpp"

namespace Polikut {
	class MensagemComCurtir : public Mensagem {
	private:
		// Conteudo da mensagem
		int curtidas;

	public:
		// Cria uma mensagem vazia
		MensagemComCurtir();

		//Cria uma mensagem com conteudo
		MensagemComCurtir(std::string conteudo);

		// Destroi a mensagem
		~MensagemComCurtir();

		int getCurtidas();

		void curtir();
	};
}

#endif /* end of include guard: _MENSAGEM_COM_CURTIR_HPP_ */
