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

#ifndef _DEPARTAMENTO_HPP_
#define _DEPARTAMENTO_HPP_

#include <string>

#include "Perfil.hpp"
#include "Pessoa.hpp"

namespace Polikut {
	class Departamento : public Perfil {
	private:
		std::string nome;
		std::string site;

		Pessoa* responsavel;

		void listar(std::ostream& os) const;

	public:
		Departamento(std::string nome, std::string site, Pessoa* responsavel);

		Departamento(std::string nome, std::string site);

		virtual ~Departamento();

		std::string getSite();

		Pessoa* getResponsavel();

		// Deve ser usado apenas pela persistência
		void setResponsavel(Pessoa* responsavel);

		// Redefine o método "recebe" para repassa-la ao responsável.
		// A mensagem recebida deve também ser adicionada às mensagens recebidas do
		// departamento.
		virtual void recebe(Mensagem* m);

		// Implementa o método adicionadoPor para adicionar o Perfil como contato do
		// Departamento
		virtual void adicionadoPor(Perfil* contato);
	};
}

#endif /* end of include guard: _DEPARTAMENTO_HPP_ */
