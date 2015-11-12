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
#include <string>

#include "PersistenciaDoPerfil.hpp"
#include "Departamento.hpp"
#include "Pessoa.hpp"

namespace Polikut {
    PersistenciaDoPerfil::PersistenciaDoPerfil(std::string arquivo) :
        filename(arquivo)
    {}

    PersistenciaDoPerfil::~PersistenciaDoPerfil() {
        if (dados.is_open())
            dados.close();
    }

    std::vector<Perfil*>& PersistenciaDoPerfil::obter() {
        std::vector<Perfil*> contatos;
        std::string data[3];
        int numContatos, num, j = 0;

        char c;

        dados.open(filename, std::ostream::in);

        if (!dados)
            throw std::runtime_error("Arquivo inexistente");

        while (dados) {
            c = dados.get();
            dados.get();
            if (c == 'P') {
                for (int i = 0; i < 3; i++) {
                    std::getline(dados, data[i]);
                    if (data[i] == "") throw std::runtime_error("Formato de arquivo invalido");
                }
                _perfis.push_back(new Pessoa(data[0], data[1], data[2]));
            } else if (c == 'D') {
                for (int i = 0; i < 2; i++) {
                    std::getline(dados, data[i]);
                    if (data[i] == "") throw std::runtime_error("Formato de arquivo invalido");
                }
                _perfis.push_back(new Departamento(data[0], data[1]));
            } else if (c == '#') {
                while (dados) {
                    dados >> numContatos;
                    if (!dados) throw std::runtime_error("Formato de arquivo invalido");
                    for (int i = 0; i < numContatos; i++) {
                        dados >> num;
                        contatos.push_back(_perfis[num - 1]);
                    }
                    if (dynamic_cast<Departamento*>(_perfis[j]) != nullptr) {
                        dados >> num;
                        dynamic_cast<Departamento*>(_perfis[j])->setResponsavel(dynamic_cast<Pessoa*>(_perfis[num - 1]));
                    }
                    if (dados.get() != '\n') throw std::runtime_error("Formato de arquivo invalido - numero de contatos errado.");
                    _perfis[j++]->setContatos(contatos);
                    contatos.clear();
                    if (j >= _perfis.size()) break;
                }
                break;
            } else {
                std::string msg = "Formato de arquivo invalido - encontrado caracter de identificacao invalido: ";
                msg.push_back(c);
                throw std::runtime_error(msg);
            }
        }
        dados.close();
        return _perfis;
    }

    void PersistenciaDoPerfil::salvar(std::vector<Perfil*>& perfis) {
        dados.open(filename, std::ostream::out | std::ostream::trunc);

        for (auto& i : perfis)
            dados << i << std::endl;

        dados << '#' << std::endl;

        for (auto& i : perfis) {
            dados << i->getContatos().size();
            for (auto& j : i->getContatos()) {
                for (int k = 0; k < perfis.size(); k++) {
                    if (j == perfis[k])
                        dados << " " << k + 1;
                }
            }
            if (dynamic_cast<Departamento*>(i) != nullptr) {
                for (int j = 0; j < perfis.size(); j++)
                    if (perfis[j] == dynamic_cast<Departamento*>(i)->getResponsavel())
                        dados << " " << j + 1;
            }
            dados << std::endl;
        }

        dados.close();
    }
}
