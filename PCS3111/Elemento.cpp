/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/
#include <iostream>

#include "Elemento.hpp"
#include "Mensagem.hpp"

namespace Polikut {
    Elemento::Elemento() {
        id = 0;
        mensagem = nullptr;
        proximo = nullptr;
    }

    Elemento::~Elemento() {
        delete mensagem;
        delete proximo;
    }

    void Elemento::setId(int _id) {
        id = _id;
    }

    void Elemento::setMensagem(Mensagem* msg) {
        mensagem = msg;
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
