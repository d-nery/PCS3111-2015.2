/**
Escola Politecnica da Universidade de Sao Paulo
2 de setembro de 2015

PCS3111 - Laboratorio de Programacao Orientada a Objetos
Exercicio Programa 1 - 2015

Turma 23
 	Daniel Nery Silva de Oliveira - 9349051
	Mateus Almeida Barbosa        - 9349072

Professor Jaime S. Sichman
**/

#ifndef _PESSOA_HPP_
#define _PESSOA_HPP_

#include "ListaDeMensagens.hpp"
#include "Mensagem.hpp"

using namespace std;

namespace Polikut {
	class Pessoa {
	private:
		// Dados da pessoa
		string nome;
		string dataDeNascimento;
		string pais;

		// Ponteiros para os contatos da pessoa
		Pessoa *contatos[9];

		// Listas de Mensagens enviadas e recebidas da pessoa
		ListaDeMensagens recebidas;
		ListaDeMensagens enviadas;

		// Numero de contatos da pessoa
		int numeroContatos;

	public:
		// Cria uma pessoa vazia
		Pessoa();
		
		// Cria uma pessoa com atributos
		Pessoa(string nome, string dataDeNascimento, string pais);

		// Destrói um objeto pessoa, destruindo todos os objetos auxiliares criados
		~Pessoa();

		// Métodos acessores: obtem o nome, data de nascimento e país
		string getNome();
		string getDataDeNascimento();
		string getPais();

		// Adiciona uma outra pessoa como contato desta pessoa
		int adiciona(Pessoa* contato);

		// Envia um texto como mensagem para todos os contatos da pessoa
		void envia(string texto);

		// Recebe uma mensagem enviada por uma pessoa que tem esta pessoa como contato.
		// Este método é chamado pelo "envia" da pessoa que está enviando a mensagem
		void recebe(Mensagem* m);

		// Obtêm uma referência para a lista ligada com as mensagens recebidas
		ListaDeMensagens& getMensagensRecebidas();

		// Obtêm uma referência para a lista ligada com as mensagens enviadas
		ListaDeMensagens& getMensagensEnviadas();

		// Apresenta em tela o nome dos contatos que esta pessoa possui
		void verContatos();
		
		// Retorna o numero de contatos da pessoa
		int getNumContatos();
	};
}

#endif /* end of include guard: _PESSOA_HPP_ */
