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

        while (dados) {
            c = dados.get();
            std::cerr << c << "\n";
            dados.get();
            if (c == 'P') {
                for (int i = 0; i < 3; i++)
                    std::getline(dados, data[i]);
                std::cerr << data[0] << " " << data[1] << " " << data[2] << " " << std::endl;
                _perfis.push_back(new Pessoa(data[0], data[1], data[2]));
            } else if (c == 'D') {
                for (int i = 0; i < 2; i++)
                    std::getline(dados, data[i]);
                std::cerr << data[0] << " " << data[1] << " "  << std::endl;
                _perfis.push_back(new Departamento(data[0], data[1]));
            } else if (c == '#') {
                while (dados) {
                    dados >> numContatos;
                    std::cerr << "numContatos: " << numContatos << "\n";
                    for (int i = 0; i < numContatos; i++) {
                        dados >> num;
                        std::cerr << num << "\n";
                        contatos.push_back(_perfis[num - 1]);
                    }
                    if (dynamic_cast<Departamento*>(_perfis[j]) != nullptr) {
                        dados >> num;
                        std::cerr << "Resp:" << num << "\n";
                        dynamic_cast<Departamento*>(_perfis[j])->setResponsavel(dynamic_cast<Pessoa*>(_perfis[num - 1]));
                    }
                    _perfis[j++]->setContatos(contatos);
                    contatos.clear();
                    if (j >= _perfis.size()) break;
                }
                break;
            } else {
                std::cerr << c << "!!\n";
                throw std::runtime_error("Formato de arquivo invalido");
            }
        }
        std::cerr << "returning\n";
        dados.close();
        return _perfis;
    }

    void PersistenciaDoPerfil::salvar(std::vector<Perfil*>& perfis) {
        dados.open(filename, std::ostream::out | std::ostream::trunc);

        for (auto& i : perfis)
            dados << i << std::endl;

        dados << '#' << std::endl;

        for (auto& i : perfis) {
            dados << i->getContatos().size() << " ";
            for (auto& j : i->getContatos()) {
                for (int k = 0; k < perfis.size(); k++) {
                    if (j == perfis[k])
                        dados << k + 1 << " ";
                }
            }
            if (dynamic_cast<Departamento*>(i) != nullptr) {
                for (int j = 0; j < perfis.size(); j++)
                    if (perfis[j] == dynamic_cast<Departamento*>(i)->getResponsavel())
                        dados << j + 1;
            }
            dados << std::endl;
        }

        dados.close();
    }
}
