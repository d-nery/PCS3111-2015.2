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

#ifndef _PERFIL_HPP_
#define _PERFIL_HPP_

#include <string>
#include <vector>
#include <list>

#include "Mensagem.hpp"

namespace Polikut {
	class Perfil {
	friend class Tela;
	protected:
		std::string nome;

		// Listas de Mensagens enviadas e recebidas da pessoa
		std::list<Mensagem*> enviadas;
		std::list<Mensagem*> recebidas;

		// Ponteiros para os contatos do perfil
		std::vector<Perfil*> contatos;

	public:
		Perfil(std::string nome);

		virtual ~Perfil();

		// Obtêm o nome do Perfil.
		std::string getNome();

		// Informa que o perfil foi adicionado pelo perfil "contato"
		virtual void adicionadoPor(Perfil* contato) = 0;

		// Envia uma mensagem para todos os contatos do perfil.
		// O curtir informa se a mensagem pode ser curtida ou não.
		virtual void envia(std::string texto, bool curtir);

		// Recebe uma mensagem.
		virtual void recebe(Mensagem* m);

		// Obtêm a lista ligada com as mensagens recebidas.
		std::list<Mensagem*>& getMensagensRecebidas();

		// Obtêm a lista ligada com as mensagens enviadas.
		std::list<Mensagem*>& getMensagensEnviadas();

		// Imprime a lista de contatos diretos.
		void verContatos();

		// Imprime a lista de contatos alcançáveis.
		void verContatosAlcancaveis();

		// retorna a lista de contatos de um perfil.
		std::vector<Perfil*>& getContatos();

	};
}

#endif /* end of include guard: _PERFIL_HPP_ */
