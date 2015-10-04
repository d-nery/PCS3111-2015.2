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

    void Pessoa::adicionadoPor(Perfil* contato) {
        std::string texto = contato->getNome() + " adicionou voce como contato.";
        Mensagem* m = new Mensagem(texto);
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
        Mensagem* mensagem = new Mensagem(texto);
        enviadas.adicionar(mensagem);
        contato->recebe(mensagem);
    }
}
