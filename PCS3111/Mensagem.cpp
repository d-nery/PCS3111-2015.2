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
#include "Mensagem.hpp"

namespace Polikut {
    Mensagem::Mensagem() {}

    Mensagem::Mensagem(std::string conteudo) :
        conteudo(conteudo)
    {}

    Mensagem::~Mensagem() {}

    std::string Mensagem::getConteudo() {
        return conteudo;
    }
}
