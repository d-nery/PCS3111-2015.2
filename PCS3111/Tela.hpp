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

#ifndef _TELA_HPP_
#define _TELA_HPP_

#include "Perfil.hpp"
#include "Pessoa.hpp"
#include "Departamento.hpp"

namespace Polikut {
	class Tela {
	private:
		std::vector<Perfil*> perfis;

	public:
		// Menu Principal
		void principal();

		// Tela de cadastrar um pessoa no sistema
		void cadastroPessoa();

		// Tela de cadastrar um departamento no sistema
		void cadastroDepartamento();

		// Tela de entrar como um perfil no sistema
		void login();

		// Tela de informacoes de uma pessoa
		void info(Pessoa& pessoa);

		// Tela de informacoes de um departamento
		void info(Departamento& departamento);

		// Tela para adicionar um contato a perfil
		void adicionarContato(Perfil& perfil);

		// Telas com as mensagens enviadas e recebidas de perfil
		void mensagensEnviadas(Perfil& perfil);
		void mensagensRecebidas(Perfil& perfil);

		// Tela para escrever mensagem de perfil para seus contatos
		void escreverMensagem(Perfil& perfil);
	};
}

#endif /* end of include guard: _TELA_HPP_ */
