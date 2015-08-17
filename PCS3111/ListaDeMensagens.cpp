/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/
#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"

namespace Polikut {
    ListaDeMensagens::ListaDeMensagens() {
        total = 0;
        cabeca = Elemento("", NULL);
    }

    ListaDeMensagens::~ListaDeMensagens() {}

    void ListaDeMensagens::adicionar(Mensagem& m) {

    }

    Elemento ListaDeMensagens::getCabeca() {

    }
}
