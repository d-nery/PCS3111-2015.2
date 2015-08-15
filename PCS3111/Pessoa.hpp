#pragma once

#include <iostream>

#include "ListaDeMensagens.hpp"
#include "Mensagem.hpp"

using namespace std;

namespace Polikut {
	class Pessoa {
	private:
		string nome;
		string dataDeNascimento;
		string pais;

	public:
		// Cria uma pessoa
		Pessoa(string nome, string dataDeNascimento, string pais);

		// Destrói um objeto pessoa, destruindo todos os objetos auxiliares criados
		~Pessoa();

		// Métodos acessores: obtem o nome, data de nascimento e país
		string getNome();
		string getDataDeNascimento();
		string getPais();

		// Adiciona uma outra pessoa como contato desta pessoa
		void adiciona(Pessoa& contato);

		// Envia um texto como mensagem para todos os contatos da pessoa
		void envia(string texto);

		// Recebe uma mensagem enviada por uma pessoa que tem esta pessoa como contato.
		// Este método é chamado pelo "envia" da pessoa que está enviando a mensagem
		void recebe(Mensagem& m);

		// Obtêm a lista ligada com as mensagens recebidas
		ListaDeMensagens& getMensagensRecebidas();

		// Obtêm a lista ligada com as mensagens enviadas
		ListaDeMensagens& getMensagensEnviadas();

		// Apresenta em tela o nome dos contatos que esta pessoa possui
		void verContatos();
	};
}
