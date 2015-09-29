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

#include <iostream>

#include "Perfil.hpp"

namespace Polikut {
	Perfil::Perfil(std::string nome) {
		this->nome = nome;
	}

	Perfil::~Perfil() {}

	std::string Perfil::getNome() {
		return this->nome;
	}

	void Perfil::envia(std::string texto, bool curtir) {
		Mensagem* mensagem;
		if (curtir) {
			mensagem = new MensagemComCurtir()
		}
        for (int i = 0; i < this->numeroContatos; i++)
            contatos[i]->recebe(mensagem);
        this->enviadas.adicionar(mensagem);
	}

	void Perfil::recebe(Mensagem* m) {
		this->recebidas.adicionar(m);
	}

	ListaDeMensagens& Perfil::getMensagensRecebidas() {


	}

	ListaDeMensagens& Perfil::getMensagensEnviadas() {


	}

	void Perfil::verContatos() {


	}

	void Perfil::verContatosAlcancaveis() {


	}
}
