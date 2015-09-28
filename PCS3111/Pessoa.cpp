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
        this->numeroContatos = 0;
    }

    Pessoa::~Pessoa() {}

    string Pessoa::getNome() {
        return this->nome;
    }

    string Pessoa::getDataDeNascimento() {
        return this->dataDeNascimento;
    }

    string Pessoa::getPais() {
        return this->pais;
    }

    //int
    void Pessoa::adiciona(Pessoa* contato) {
        if (contato == this) {
            std::cout << "Voce nao pode adicionar a si mesmo!\n"; // -
            return; //-2;
        }
        for (int i = 0; i < numeroContatos; i++) {
            if (contato == this->contatos[i]) {
                std::cout << "Contato ja adicionado!\n"; // -
                return;// -1;
            }
        }
        this->contatos[this->numeroContatos++] = contato;
        CGREEN std::cout << contato->getNome(); CRESET      // -
        std::cout << " conectado a ";                       // -
        CGREEN std::cout << this->getNome() << endl; CRESET // -
        return;// 0;
    }

    void Pessoa::envia(string texto) {
        Mensagem* mensagem = new Mensagem(texto);
        for (int i = 0; i < this->numeroContatos; i++)
            contatos[i]->recebe(mensagem);
        this->enviadas.adicionar(mensagem);
    }

    void Pessoa::recebe(Mensagem* m) {
        this->recebidas.adicionar(m);
    }

    ListaDeMensagens& Pessoa::getMensagensRecebidas() {
        return this->recebidas;
    }

    ListaDeMensagens& Pessoa::getMensagensEnviadas() {
        return this->enviadas;
    }

    void Pessoa::verContatos() {
        for (int i = 0; i < this->numeroContatos; i++) {
            cout << "\t" << contatos[i]->getNome() << endl;
        }
    }

    int Pessoa::getNumContatos() {
        return this->numeroContatos;
    }
}
