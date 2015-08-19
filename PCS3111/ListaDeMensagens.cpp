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
        cabeca = nullptr;
        // CRED std::cerr << "LdM criada" << std::endl; CRESET
    }

    ListaDeMensagens::~ListaDeMensagens() {
        delete cabeca;
    }

    void ListaDeMensagens::adicionar(Mensagem* m) {
        Elemento* novo = new Elemento();
        novo->setId(++total);
        novo->setMensagem(m);
        novo->setProximo(nullptr);

        Elemento* x = cabeca;
        if (x != nullptr) {
            while (x->getProximo() != nullptr) {
                x = x->getProximo();
            }
            x->setProximo(novo);
        } else {
            cabeca = novo;
        }
    }

    Elemento* ListaDeMensagens::getCabeca() {
        return cabeca;
    }

    Mensagem* ListaDeMensagens::getMensagem(int _id) {
        //CGREEN std::cerr << "Retornarndo msg de id: " << _id << "\n"; CRESET
        if (_id == 0) {
            return nullptr;
        }
        Elemento* x = cabeca;
        if (x != nullptr) {
            while (x->getProximo() != nullptr && x->getProximo()->getId() != _id) {
                x = x->getProximo();
            }
            return x->getProximo()->getMensagem();
        }
    }

    int ListaDeMensagens::getTotal() {
        return total;
    }

    void ListaDeMensagens::listar() {
        //CGREEN std::cerr << "Tentando listar\n"; CRESET
        Elemento* x = cabeca;
        if (x == nullptr) {
            std::cout << "Não há mensagens\n";
            return;
        }

        if (x->getProximo() == nullptr) {
            std::cout << x->getId() << ") " << x->getMensagem()->getConteudo() << " ("
                << x->getMensagem()->getCurtidas() << " curtidas)\n";
        } else {
            do {
                std::cout << x->getId() << ") " << x->getMensagem()->getConteudo() << " ("
                    << x->getMensagem()->getCurtidas() << " curtidas)\n";
                x = x->getProximo();
            } while (x != nullptr);
        }
    }
}
