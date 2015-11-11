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

#include "colors.hpp"

#include "MensagemComCurtir.hpp"

namespace Polikut {
    MensagemComCurtir::MensagemComCurtir() {}

    MensagemComCurtir::MensagemComCurtir(std::string conteudo, std::string autor) :
		Mensagem(conteudo, autor),
		curtidas(0)
	{}

    MensagemComCurtir::~MensagemComCurtir() {}

    int MensagemComCurtir::getCurtidas() const {
        return curtidas;
    }

    void MensagemComCurtir::curtir() {
        curtidas++;
    }

    void MensagemComCurtir::listar(std::ostream& os) const {
        os << conteudo << "  (" << curtidas << " curtida"
            << (curtidas > 1 ? "s)" : ")");
    }
}
