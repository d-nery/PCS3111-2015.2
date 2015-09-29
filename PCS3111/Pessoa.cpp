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

#ifdef _WIN32
extern HANDLE hOut;
#endif // _WIN32

namespace Polikut {
    Pessoa::Pessoa() {}

    Pessoa::Pessoa (string nome, string dataDeNascimento, string pais) {
        this->nome = nome;
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

    //int
    void Pessoa::adiciona(Perfil* contato) {
        if (contato == this) {
            throw logic_error("Voce nao pode adicionar a si mesmo"); // -
            return; //-2;
        }
        for (auto &i : contatos) {
            if (contato == i) {
                throw logic_error("Contato ja adicionado");
                return;// -1;
            }
        }
        this->contatos->push_back(contato);
    }

    void Pessoa::adicionadoPor(Perfil* contato) {
        std::string texto = contato->getNome() + " adicionou voce como contato.";
        m = new Mensagem(texto)
        Perfil::recebe(m);
    }

    void Pessoa::envia(string texto, Perfil* contato){
        mensagem = new Mensagem(texto);
        contato->recebe(mensagem);
    }
}
