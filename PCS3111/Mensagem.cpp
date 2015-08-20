/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#include <iostream>
#include "Mensagem.hpp"

using namespace std;

namespace Polikut {
    Mensagem::Mensagem() {}

    Mensagem::Mensagem(string conteudo) {
        this->conteudo = conteudo;
        this->curtidas = 0;
    }

    Mensagem::~Mensagem() {}

    string Mensagem::getConteudo() {
        return this->conteudo;
    }

    int Mensagem::getCurtidas() {
        return this->curtidas;
    }

    void Mensagem::curtir() {
        this->curtidas++;
    }
}
