#include <iostream>
#include <vector>

#include "PersistenciaDoPerfil.hpp"
#include "Departamento.hpp"
#include "Pessoa.hpp"
#include "Perfil.hpp"

using namespace std;
using namespace Polikut;

int main() {
	PersistenciaDoPerfil persist("perfis.txt");

	vector<Perfil*> perfis = persist.obter();

	for (auto &i : perfis) {
		cout << i->getNome() << endl;
		for (auto &j : i->getContatos())
			cout << '\t' << j->getNome() << endl;
	}

	// perfis.clear();
	//
	// perfis.push_back(new Pessoa("Pessoa", "10/1/1", "Pais qualquer"));
	// perfis.push_back(new Pessoa("Pessoa2", "15/1/1", "Pais qualquer 22"));
	// perfis.push_back(new Departamento("Dep", "pcs.com", dynamic_cast<Pessoa*>(perfis[1])));

	persist.salvar(perfis);

	return 0;
}
