/**
Escola Politecnica da Universidade de Sao Paulo
2 de setembro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#include <iostream>

#include "ListaDeMensagens.hpp"

namespace Polikut {
    ListaDeMensagens::ListaDeMensagens() {
        total = 0;
        cabeca = nullptr;
    }

    ListaDeMensagens::~ListaDeMensagens() {
        delete cabeca;
    }

    void ListaDeMensagens::adicionar(Mensagem* m) {
        Elemento* novo = new Elemento(++total, m, nullptr); // Cria um novo elemento

        Elemento* x = cabeca;                     // Iterador para percorrer a lista ate o final
        if (x != nullptr) {                       // Checa se a lista esta vazia
            while (x->getProximo() != nullptr)
                x = x->getProximo();
            x->setProximo(novo);                  // Adiciona o novo elemento ao final da lista
        } else {
            cabeca = novo;
        }
    }

    Elemento* ListaDeMensagens::getCabeca() {
        return cabeca;
    }

    Mensagem* ListaDeMensagens::getMensagem(int _id) {
        if (_id == 0)              // Nao ha item de id 0
            return nullptr;

        Elemento* x = cabeca;
        if (_id == 1)              // Primeiro item da lista
            return x->getMensagem();

        if (x != nullptr) {
            while (x->getProximo() != nullptr && x->getProximo()->getId() != _id) // Percorre a lista ate o final ou ate achar o id
                x = x->getProximo();
			return x->getProximo()->getMensagem();
        }
	    return nullptr;
    }

    int ListaDeMensagens::getTotal() {
        return total;
    }

    void ListaDeMensagens::listar() {
        Elemento* x = cabeca;
        if (x == nullptr) {
            std::cout << "Nao ha mensagens\n";
            return;
        }

        if (x->getProximo() == nullptr) {        // 1 item na lista
            std::cout << x->getId() << ") " << x->getMensagem()->getConteudo() << " ("
                << x->getMensagem()->getCurtidas() << " curtida";
            if(x->getMensagem()->getCurtidas() > 1) std::cout << "s)\n";
            else std::cout << ")\n";
        } else {                                 // Percorre a lista, imprimindo o conteudo das mensagens de seus elementos
            do {
                std::cout << x->getId() << ") " << x->getMensagem()->getConteudo() << " ("
                    << x->getMensagem()->getCurtidas() << " curtida";
				if (x->getMensagem()->getCurtidas() > 1) std::cout << "s)\n";
				else std::cout << ")\n";
                x = x->getProximo();
            } while (x != nullptr);
        }
    }
}
