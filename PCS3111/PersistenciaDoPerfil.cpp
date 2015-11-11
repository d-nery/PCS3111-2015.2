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

#include <stdexcept>

#include "PersistenciaDoPerfil.hpp"

namespace Polikut {
    PersistenciaDoPerfil::PersistenciaDoPerfil(std::string arquivo) {
        dados.open(arquivo);
    }

    PersistenciaDoPerfil::~PersistenciaDoPerfil() {
        dados.close();
    }

    std::vector<Perfil*>& PersistenciaDoPerfil::obter() {
        std::vector<Perfil*> perfis;
        std::vector<Perfil*> contatos;
        Perfil* novoPerfil;
        std::string data[3];
        int numContatos, num, j = 0;

        while(dados) {
            if (dados.get() == 'P') {
                for (int i = 0; i < 3; i++)
                    dados >> data[i];
                novoPerfil = new Pessoa(data[0], data[1], data[2]);
                perfis.push_back(novoPerfil);
            } else if (dados.get() == 'D') {
                for (int i = 0; i < 2; i++)
                    dados >> data[i];
                novoPerfil = new Pessoa(data[0], data[1]);
                perfis.push_back(novoPerfil);
            } else if (dados.get() == '#') {
                while(!dados.eof()) {
                    dados >> numContatos;
                    for (int i = 0; i < numContatos; i++) {
                        dados >> num;
                        contatos.push_back(perfis[num]);
                    }
                    if (dynamic_cast<Departamento*>(perfis[j]) != nullptr) {
                        dados >> num;
                        perfis[j].setResponsavel(perfis[num]);
                    }
                    perfis[j++].setContatos(contatos);
                }
            } else {
                throw std::runtime_error("Formato de arquivo inválido");
            }
        }
        return perfis;
    }
}
