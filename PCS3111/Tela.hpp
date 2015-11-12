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

#ifndef _TELA_HPP_
#define _TELA_HPP_

#include "PersistenciaDoPerfil.hpp"
#include "Departamento.hpp"
#include "Perfil.hpp"
#include "Pessoa.hpp"

namespace Polikut {
	class Tela {
	private:
		std::vector<Perfil*> perfis;
		PersistenciaDoPerfil* persistencia;

	public:
		// Inicia a persistencia
		void inicio();

		// Menu Principal
		void principal();

		// Tela de cadastrar um pessoa no sistema
		void cadastroPessoa();

		// Tela de cadastrar um departamento no sistema
		void cadastroDepartamento();

		// Tela de entrar como um perfil no sistema
		void login();

		// Tela de informacoes de uma pessoa
		void info(Pessoa* pessoa);

		// Tela de informacoes de um departamento
		void info(Departamento* departamento);

		// Tela para adicionar um contato a pessoa
		void adicionarContato(Pessoa* pessoa);

		// Tela para remover um contato de pessoa
		void removerContato(Pessoa* pessoa);

		// Telas com as mensagens enviadas e recebidas de perfil
		void mensagensEnviadas(Perfil* perfil);
		void mensagensRecebidas(Perfil* perfil);

		// Tela para escrever mensagem de perfil para seus contatos
		void escreverMensagem(Perfil* perfil);

		// Tela com os contatos alcancaveis de um perfil
		void contatosAlcancaveis(Perfil* perfil);

		// Lista de perfis cadastrados
		void listarPerfis();

		// Salva o arquivo de persistencia
		void savePersistencia();
	};
}

#endif /* end of include guard: _TELA_HPP_ */
