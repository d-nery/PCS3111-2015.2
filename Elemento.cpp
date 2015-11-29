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

#include "Elemento.hpp"
#include "Mensagem.hpp"

namespace Polikut {
    Elemento::Elemento() {
        id = 0;
        mensagem = nullptr;
        proximo = nullptr;
    }

	Elemento::Elemento(int id, Mensagem* msg, Elemento* prx) :
		id(id),
		mensagem(msg),
		proximo(prx)
	{}

    Elemento::~Elemento() {
        delete mensagem;
        delete proximo;
    }

    void Elemento::setProximo(Elemento* prx) {
        proximo = prx;
    }

    int Elemento::getId() {
        return id;
    }

    Mensagem* Elemento::getMensagem() {
        return mensagem;
    }

    Elemento* Elemento::getProximo() {
        return proximo;
    }
}
