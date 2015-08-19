/**
Escola Politecnica da Universidade de Sao Paulo

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio-Programa 1

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072
**/

#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include <string>

#include "ListaDeMensagens.hpp"
#include "Mensagem.hpp"

using namespace std;

namespace Polikut {
	class Pessoa {
	private:
		string nome;
		string dataDeNascimento;
		string pais;
		Pessoa *contatos[9];
		ListaDeMensagens recebidas;
		ListaDeMensagens enviadas;
		int numeroContatos;

	public:
		Pessoa();
		// Cria uma pessoa
		Pessoa(string nome, string dataDeNascimento, string pais);

		// Destrói um objeto pessoa, destruindo todos os objetos auxiliares criados
		~Pessoa();

		// Métodos acessores: obtem o nome, data de nascimento e país
		string getNome();
		string getDataDeNascimento();
		string getPais();

		// Adiciona uma outra pessoa como contato desta pessoa
		void adiciona(Pessoa* contato);

		// Envia um texto como mensagem para todos os contatos da pessoa
		void envia(string texto);

		// Recebe uma mensagem enviada por uma pessoa que tem esta pessoa como contato.
		// Este método é chamado pelo "envia" da pessoa que está enviando a mensagem
		void recebe(Mensagem* m);

		// Obtêm a lista ligada com as mensagens recebidas
		ListaDeMensagens& getMensagensRecebidas();

		// Obtêm a lista ligada com as mensagens enviadas
		ListaDeMensagens& getMensagensEnviadas();

		// Apresenta em tela o nome dos contatos que esta pessoa possui
		void verContatos();
	};
}

#endif /* end of include guard: _PESSOA_HPP_ */
