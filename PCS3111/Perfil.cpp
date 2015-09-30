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

#include "Perfil.hpp"
#include "MensagemComCurtir.hpp"

namespace Polikut {
	Perfil::Perfil(std::string nome) {
		this->nome = nome;
	}

	Perfil::~Perfil() {}

	std::string Perfil::getNome() {
		return this->nome;
	}

	void Perfil::envia(std::string texto, bool curtir) {
		Mensagem* mensagem;
		if (curtir) {
			mensagem = new MensagemComCurtir(texto);
		}
		else {
			mensagem = new Mensagem(texto);
		}
        for (auto &i : contatos)
            i->recebe(mensagem);

        this->enviadas.adicionar(mensagem);
	}

	void Perfil::recebe(Mensagem* m) {
		this->recebidas.adicionar(m);
	}

	ListaDeMensagens& Perfil::getMensagensRecebidas() {
		return this->recebidas;
	}

	ListaDeMensagens& Perfil::getMensagensEnviadas() {
		return this->enviadas;
	}

	void Perfil::verContatos() {
		for (auto &i : contatos)
			std::cout << i->getNome() << std::endl;
	}

	void Perfil::verContatosAlcancaveis() {
	    std::vector<Perfil*> visitados;
	    visitados.push_back(this);
	    bool visitado = false;
        for (auto &i : contatos) {
            std::cout << i->getNome() << std::endl;
            visitados.push_back(i);
        }
        for (unsigned int l = 1; l < visitados.size(); l++) {
            for (auto &j : visitados[l]->getContatos()) {
                visitado = false;
                for (auto &k : visitados) {
                    if (j == k) {visitado = true; break;}
                }
                if (!visitado) {
                    std::cout << j->getNome() << std::endl;
                    visitados.push_back(j);
                }
            }
        }
    }

    std::vector<Perfil*> Perfil::getContatos() {
        return contatos;
    }
}
