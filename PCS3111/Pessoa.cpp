/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#include <iostream>
#include "Pessoa.hpp"

using namespace std;

namespace Polikut {
    Pessoa::Pessoa() {}

    Pessoa::Pessoa (string nome, string dataDeNascimento, string pais) {
        this->nome = nome;
        this->dataDeNascimento = dataDeNascimento;
        this->pais = pais;
        this->numeroContatos = 0;
        //   this->recebidas = ListaDeMensagens();
        //   this->enviadas = ListaDeMensagens();
        //CRED
        //cerr << "Pessoa criada" << endl;
        //CRESET
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

    void Pessoa::adiciona(Pessoa* contato) {
        if (this->numeroContatos >= 9)
            return;
        this->contatos[this->numeroContatos++] = contato;
    }

    void Pessoa::envia(string texto) {
        Mensagem mensagem(texto);
        for (int i = 0; i < this->numeroContatos; i++)
            contatos[i]->recebe(&mensagem);
        this->enviadas.adicionar(&mensagem);
    }

    void Pessoa::recebe(Mensagem* m) {
        this->recebidas.adicionar(m);
    }

    ListaDeMensagens& Pessoa::getMensagensRecebidas() {
        //CGREEN cerr << "retornando mensagens recebidas\n"; CRESET
        return this->recebidas;
    }

    ListaDeMensagens& Pessoa::getMensagensEnviadas() {
        //CGREEN cerr << "retornando mensagens enviadas\n"; CRESET
        return this->enviadas;
    }

    void Pessoa::verContatos() {
        //CRED cerr << "Vendo contatos\n"; CRESET
        for (int i = 0; i < this->numeroContatos; i++) {
            //cerr << "Contato visto\n"; CRESET
            cout << "\t" << contatos[i]->getNome() << endl;
        }
        //CRED cerr << "Fim de ver contatos\n"; CRESET
    }

}
