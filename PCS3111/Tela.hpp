#ifndef _TELA_HPP_
#define _TELA_HPP_

#include "Pessoa.hpp"

namespace Polikut {
	class Tela {
	public:
		void principal();
		void cadastro();
		void login();
		void info(Pessoa& pessoa);
	};
}

#endif /* end of include guard: _TELA_HPP_ */
