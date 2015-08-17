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

namespace Polikut {
    ListaDeMensagens::ListaDeMensagens() {
        total = 0;
        cabeca = Elemento("__cabeca__", NULL);
    }

    ListaDeMensagens::~ListaDeMensagens() {}

    void ListaDeMensagens::adicionar(Mensagem& m) {
        Elemento novo(m, cabeca.proximo);
        cabeca.proximo = &novo;
        novo.id = ++total;
    }

    Elemento& ListaDeMensagens::getCabeca() {
        return cabeca;
    }

    Mensagem& ListaDeMensagens::getMensagem(int id) {
        Elemento x = cabeca;
        while (x.proximo != NULL) {
            if (total - x.proximo->id + 1 == id)
                return x.proximo->mensagem;
            x.proximo = x.proximo->proximo;
        }
        return cabeca.mensagem;
    }

    int ListaDeMensagens::getTotal() {
        return total;
    }

    void ListaDeMensagens::listar() {
        Elemento x = cabeca;
        while (x.proximo != NULL) {
            std::cout << total - x.proximo->id + 1 << ") " << x.proximo->mensagem.getConteudo() << std::endl;
            x.proximo = x.proximo->proximo;
        }
    }
}
