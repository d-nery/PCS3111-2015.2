/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/
#include <iostream>

#include "ListaDeMensagens.hpp"
#include "Elemento.hpp"

namespace Polikut {
    ListaDeMensagens::ListaDeMensagens() {
        total = 0;
        cabeca = Elemento("", NULL);
    }

    ListaDeMensagens::~ListaDeMensagens() {}

    void ListaDeMensagens::adicionar(Mensagem& m) {
        Elemento novo(m, cabeca.proximo);
        cabeca.proximo = &novo;
        total++;
    }

    Elemento ListaDeMensagens::getCabeca() {
        return cabeca;
    }

    int ListaDeMensagens::getTotal() {
        return total;
    }

    void ListaDeMensagens::listar() {
        Elemento x = cabeca;
        int i = 1;
        while (x.proximo != NULL) {
            std::cout << i << ") " << x.proximo->mensagem.getConteudo() << std::endl;
        }
    }
}
