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

#ifndef _PERSISTENCIA_DO_PERFIL_HPP_
#define _PERSISTENCIA_DO_PERFIL_HPP_

#include <fstream>
#include <string>
#include <vector>

#include "Perfil.hpp"

namespace Polikut {
    class PersistenciaDoPerfil {
    private:
        static std::fstream dados;

        static std::vector<Perfil*> perfis;

    public:
        PersistenciaDoPerfil(std::string arquivo);
        ~PersistenciaDoPerfil();

        std::vector<Perfil*>& obter();

        void salvar(std::vector<Perfil*>& perfis);
    };
}


#endif // _PERSISTENCIA_DO_PERFIL_HPP_
