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

#include <algorithm>
#include <iostream>

#include "Departamento.hpp"

namespace Polikut {
	Departamento::Departamento(std::string nome, std::string site, Pessoa* responsavel) :
		Perfil(nome),
		site(site),
		responsavel(responsavel)
	{}

	Departamento::Departamento(std::string nome, std::string site) :
		Perfil(nome),
		site(site)
	{}

	Departamento::~Departamento() {}

	std::string Departamento::getSite() {
		return this->site;
	}

	Pessoa* Departamento::getResponsavel() {
		return this->responsavel;
	}

	void Departamento::setResponsavel(Pessoa* responsavel) {
		this->responsavel = responsavel;
	}

	void Departamento::recebe(Mensagem* m) {
		Perfil::recebe(m);
		responsavel->recebe(m);
	}

	void Departamento::adicionadoPor(Perfil* contato) {
		if (find(contatos.begin(), contatos.end(), contato) != contatos.end()) // Contato ja adicionado
			return;
		this->contatos.push_back(contato);
		contato->adicionadoPor(this);
	}

    void Departamento::listar(std::ostream& os) const {
        os << "D" << std::endl
            << nome << std::endl
            << site;
    }
}
