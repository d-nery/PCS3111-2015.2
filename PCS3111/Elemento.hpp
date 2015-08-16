#ifndef _ELEMENTO_HPP_
#define _ELEMENTO_HPP_

#include "Mensagem.hpp"

namespace Polikut {
	class Elemento {
	public:
		Mensagem mensagem;
		Elemento* proximo;
	};
}

#endif /* end of include guard: _ELEMENTO_HPP_ */
