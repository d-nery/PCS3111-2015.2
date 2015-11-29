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
#include <stdexcept>

#include "Pessoa.hpp"
#include "colors.hpp"

using namespace std;

namespace Polikut {
    Pessoa::Pessoa (string nome, string dataDeNascimento, string pais) : Perfil(nome) {
        this->dataDeNascimento = dataDeNascimento;
        this->pais = pais;
    }

    Pessoa::~Pessoa() {}

    string Pessoa::getDataDeNascimento() {
        return this->dataDeNascimento;
    }

    string Pessoa::getPais() {
        return this->pais;
    }

    void Pessoa::adiciona(Perfil* contato) {
        if (contato == this) {
            throw logic_error("Voce nao pode adicionar a si mesmo");
            return;
        }
        for (auto &i : contatos) {
            if (contato == i) {
                throw logic_error("Contato ja adicionado");
                return;
            }
        }
        this->contatos.push_back(contato);
        contato->adicionadoPor(this);
    }

    bool Pessoa::remove(Perfil* contato) {
        int i;

        for (i = 0; i < int(contatos.size()); i++) {
            if (contatos[i] == contato) {
                Mensagem* msg = new Mensagem(nome + " removeu voce como contato.", this);
                contatos[i]->recebe(msg);
                contatos.erase(contatos.begin() + i);
                return true;
            }
        }

        return false;
    }

    void Pessoa::adicionadoPor(Perfil* contato) {
        std::string texto = contato->getNome() + " adicionou voce como contato.";
        Mensagem* m = new Mensagem(texto, contato);
        Perfil::recebe(m);
    }

    void Pessoa::envia(string texto, Perfil* contato) {
        bool temContato = false;
        for (auto &i : contatos) {
            if (i == contato) {
                temContato = true;
                break;
            }
        }
        if (!temContato)
            throw logic_error("Voce nao tem esse contato!");
        Mensagem* mensagem = new Mensagem(texto, this);
        enviadas.push_back(mensagem);
        contato->recebe(mensagem);
    }

    void Pessoa::listar(std::ostream& os) const {
        os << "P" << endl
            << nome << endl
            << dataDeNascimento << endl
            << pais;
    }
}
