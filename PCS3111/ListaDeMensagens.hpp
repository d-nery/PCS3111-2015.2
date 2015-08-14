#pragma once

#include "Mensagem.hpp"
#include "Elemento.hpp"

namespace Polikut {
	class ListaDeMensagens {
	public:
		// Cria uma lista ligada de mensagens
		ListaDeMensagens();

		// Adiciona uma mensagem à lista ligada
		void adicionar(Mensagem m);

		// Obtém a cabeça da lista ligada
		// (Isso é necessário para varrer a lista)
		Elemento getCabeca();

		// Destrói a lista ligada, apagando todos os elementos criados
		~ListaDeMensagens();
	};
}
