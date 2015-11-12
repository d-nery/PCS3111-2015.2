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

#include <iostream>

#include "Mensagem.hpp"

namespace Polikut {

    Mensagem::Mensagem(std::string conteudo, Perfil* autor) :
        conteudo(conteudo),
        autor(autor)
    {}

    Mensagem::~Mensagem() {}

    std::string Mensagem::getTexto() {
        return conteudo;
    }

    Perfil* Mensagem::getAutor() {
        return autor;
    }

    void Mensagem::listar(std::ostream& os) const {
        os << conteudo << " - " << autor->getNome();
    }

    std::ostream& operator<<(std::ostream& os, const Mensagem* msg) {
        msg->listar(os);
        return os;
    }
}
