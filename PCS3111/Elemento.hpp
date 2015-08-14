#pragma once

#include "Mensagem.hpp"

namespace Polikut {
	class Elemento {
	private:
		Mensagem mensagem;
		Elemento* proximo;
	};
}
