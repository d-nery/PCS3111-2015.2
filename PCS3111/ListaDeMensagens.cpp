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
#include "colors.hpp"

namespace Polikut {
    ListaDeMensagens::ListaDeMensagens() {
        total = 0;
        cabeca = Elemento("__cabeca__", NULL);
        // CRED std::cerr << "LdM criada" << std::endl; CRESET
    }

    ListaDeMensagens::~ListaDeMensagens() {}

    void ListaDeMensagens::adicionar(Mensagem& m) {
        CGREEN std::cerr << "Adicinando mensagem\n"; CRESET
        Elemento* novo = new Elemento(m, cabeca.proximo);
        CGREEN std::cerr << cabeca.proximo << std::endl; CRESET
        CGREEN std::cerr << novo->mensagem.getConteudo() << std::endl; CRESET
        CGREEN std::cerr << novo << std::endl; CRESET
        cabeca.proximo = novo;
        CGREEN std::cerr << cabeca.proximo << std::endl; CRESET
        novo->id = ++total;
        CGREEN std::cerr << novo->id << std::endl; CRESET
        CGREEN std::cerr << total << std::endl; CRESET


    }

    Elemento ListaDeMensagens::getCabeca() {
        return cabeca;
    }

    Mensagem& ListaDeMensagens::getMensagem(int _id) {
        CGREEN std::cerr << "Retornarndo msg de id: " << _id << "\n"; CRESET
        Elemento x = cabeca;
        while (x.proximo != NULL) {
            CGREEN std::cerr << total - x.proximo->id + 1 << std::endl; CRESET
            if (total - x.proximo->id + 1 == _id)
                return x.proximo->mensagem;
            x.proximo = x.proximo->proximo;
        }
        return cabeca.mensagem;
    }

    int ListaDeMensagens::getTotal() {
        return total;
    }

    void ListaDeMensagens::listar() {
        CGREEN std::cerr << "Tentando listar\n"; CRESET
        Elemento x = cabeca;
        CGREEN std::cerr << "Elemento x criado\n"; CRESET
        CGREEN std::cerr << x.proximo << std::endl; CRESET
        while (x.proximo != NULL) {
            CGREEN std::cerr << "Entrando no while\n"; CRESET
            CGREEN std::cerr << "Elemento x id " << x.proximo->id << std::endl; CRESET
            std::cerr << this->total - x.proximo->id + 1 << ") " << x.proximo->mensagem.getConteudo()
                << " (" << x.proximo->mensagem.getCurtidas() << " curtidas)"<< std::endl;
            x.proximo = x.proximo->proximo;
        }
    }
}
