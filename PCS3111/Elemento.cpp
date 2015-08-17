/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/
#include "Elemento.hpp"
#include "Mensagem.hpp"

namespace Polikut {
    Elemento::Elemento() {}
    Elemento::Elemento(std::string msg, Elemento* proximo) {
        mensagem = Mensagem(msg);
        this->proximo = proximo;
    }
    Elemento::Elemento(Mensagem& msg, Elemento* proximo) : mensagem(msg), proximo(proximo) {}
    Elemento::~Elemento() { delete proximo; }
}
