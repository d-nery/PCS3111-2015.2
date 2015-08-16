#ifndef _ELEMENTO_HPP_
#define _ELEMENTO_HPP_

#include "Mensagem.hpp"

namespace Polikut {
	class Elemento {
	private:
		Mensagem mensagem;
		Elemento* proximo;

	public:
		Mensagem getMsg();
	};
}

#endif /* end of include guard: _ELEMENTO_HPP_ */
