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
#include <list>

#include "Perfil.hpp"
#include "MensagemComCurtir.hpp"

#include "colors.hpp"

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
			mensagem = new MensagemComCurtir(texto, this);
		}
		else {
			mensagem = new Mensagem(texto, this);
		}
        for (auto &i : contatos)
            i->recebe(mensagem);

        this->enviadas.push_back(mensagem);
	}

	void Perfil::recebe(Mensagem* m) {
		this->recebidas.push_back(m);
	}

	std::list<Mensagem*>& Perfil::getMensagensRecebidas() {
		return this->recebidas;
	}

	std::list<Mensagem*>& Perfil::getMensagensEnviadas() {
		return this->enviadas;
	}

	void Perfil::setContatos(std::vector<Perfil*>& perfis) {
        this->contatos = perfis;
	}


    std::vector<Perfil*>& Perfil::getContatos() {
        return contatos;
    }

	std::vector<Perfil*>& Perfil::getContatosAlcancaveis() {
		visitados.clear();
	    visitados.push_back(this);
	    bool visitado = false;
        for (int l = 0; l < int(visitados.size()); l++) {
            for (auto &j : visitados[l]->getContatos()) {
                visitado = false;
                for (auto &k : visitados) {
                    if (j == k) {visitado = true; break;}
                }
                if (!visitado) {
                    visitados.push_back(j);
                }
            }
        }

		visitados.erase(visitados.begin());
        return visitados;
    }

	std::ostream& operator<<(std::ostream& os, const Perfil* perf) {
		perf->listar(os);
		return os;
	}
}
