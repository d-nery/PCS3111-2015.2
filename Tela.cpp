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

#include <stdexcept>
#include <iostream>
#include <utility>
#include <string>

#include "Tela.hpp"
#include "colors.hpp"
#include "MensagemComCurtir.hpp"

using namespace std;
using namespace Polikut;

#ifdef _WIN32
extern HANDLE hOut;
#endif // _WIN32

namespace Polikut {
	void Tela::inicio() {
		string nome;

		cout << "Informe o nome do arquivo: ";
		cin >> nome;

		persistencia = new PersistenciaDoPerfil(nome);

		try {
			perfis = persistencia->obter();
			cout << "Perfis carregados com sucesso\n";
		} catch (runtime_error& e) {
			cout << e.what() << "\nIniciando uma rede social vazia\n";
		}
		cout << "Aperte enter para continuar\n";
		cin.get();
		while (cin.get() != '\n');
	}

	void Tela::principal() {
		CLEAR;
		cout << "\nPoli"; CPINK; cout << "Kut\n"; CRESET;
        cout << "-----------------------------------------\n"
			 << "1) Cadastrar Pessoa\n"
			 << "2) Cadastrar Departamento\n"
			 << "3) Logar Como Perfil\n"
			 << "0) Terminar\n" << endl
			 << "Digite uma opcao: ";
	}

	void Tela::cadastroPessoa() {
		CLEAR;
		string nome, dataDeNascimento, pais;
		cout << "\nInforme os dados da pessoa: \n";

		cout << "Nome: "; CGREEN;
		cin.ignore();
		getline(cin, nome); CRESET;

		cout << "Data de Nascimento: "; CGREEN;
		getline(cin, dataDeNascimento); CRESET;

		cout << "Pais: "; CGREEN;
		getline(cin, pais); CRESET;

		perfis.push_back(new Pessoa(nome, dataDeNascimento, pais));
		CGREEN; cout << perfis.back()->getNome(); CRESET; cout << " cadastrado com sucesso.\n";

		cout << "\nAperte Enter para retornar\n";
		while (cin.get() != '\n');
	}

	void Tela::cadastroDepartamento() {
		CLEAR;
		string nome, site;
		Pessoa* responsavel;

		int j = 1;

		cout << "\nInforme os dados do departamento: \n";

		cout << "Nome: "; CGREEN;
		cin.ignore();
		getline(cin, nome); CRESET;

		cout << "Site: "; CGREEN;
		getline(cin, site); CRESET;

		cout << "Escolha um responsavel:\n";
		for (auto &i : perfis) {
			cout << j << ") " << i->getNome() << endl;
			j++;
		}
		cout << "Digite um numero ou 0 para cancelar: ";
		for(;;) {
			if(cin >> j) {
				if (j == 0) return;
				if (j > int(perfis.size())) {
					cout << "Digite uma opcao valida: ";
					continue;
				}
				if ((responsavel = dynamic_cast<Pessoa*>(perfis[j - 1])) == nullptr) {
					cout << "Selecione uma pessoa: ";
				} else break;
			} else {
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');
			}
		}

		perfis.push_back(new Departamento(nome, site, responsavel));
		CGREEN; cout << perfis.back()->getNome(); CRESET; cout << " cadastrado com sucesso.\n";

		cout << "\nAperte Enter para retornar\n";
		cin.get();
		while (cin.get() != '\n');
	}

	void Tela::login() {
		for(;;) {
	    CLEAR;
			int opcao = 0;
			if (perfis.size() > 0) {
				cout << "\nEscolha um dos perfis:\n"; CGREEN;
				for (int i = 0; i < int(perfis.size()); i++)
					cout << i + 1 << ") " << perfis[i]->getNome() << endl;
				CRESET; cout << "\nDigite um numero para logar ou 0 para voltar: ";
			} else {
				cout << "\n--Não há perfis cadastradas no sistema--\n"
					 <<   "      Aperte Enter para retornar\n";
				cin.get();
				while (cin.get() != '\n');
				return;
			}
			if (cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao >= 1 && opcao <= int(perfis.size())) {
					Perfil* perf = dynamic_cast<Pessoa*>(perfis[opcao - 1]);
					if (perf == nullptr) {
						Departamento* dept = dynamic_cast<Departamento*>(perfis[opcao - 1]);
						info(dept);
					} else {
						Pessoa* pessoa = dynamic_cast<Pessoa*>(perfis[opcao - 1]);
						info(pessoa);
					}
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::info(Pessoa* pessoa) {
		for (;;) {
	    CLEAR;
			int opcao = 0;
			cout << "Pessoa: "; CGREEN; cout << pessoa->getNome() << endl;
			cout << pessoa->getDataDeNascimento(); CRESET; cout << " | "; CGREEN; cout << pessoa->getPais() << endl;
			CRESET;
			if (pessoa->getContatos().size() > 0 ) cout << "\nContatos: \n";
			CGREEN;
			for (auto& i : pessoa->getContatos())
				cout << '\t' << i->getNome() << endl;
			CRESET;
			cout << "-----------------------------------------\n\n"
				 << "Escolha uma opcao:\n"
				 << "1) Ver mensagens enviadas\n"
				 << "2) Ver mensagens recebidas\n"
				 << "3) Escrever mensagem\n"
				 << "4) Ver Contatos Alcancaveis\n"
				 << "5) Adicionar contato\n"
				 << "6) Remover contato\n"
				 << "0) Voltar" << endl;

			cout << "\nDigite uma opcao: ";
	 		if(cin >> opcao)
		 		switch (opcao) {
		 			case 0:
		 			return;

		 			case 1:
					mensagensEnviadas(pessoa);
					break;

					case 2:
					mensagensRecebidas(pessoa);
					break;

					case 3:
					escreverMensagem(pessoa);
					break;

					case 4:
					contatosAlcancaveis(pessoa);
		 			break;

					case 5:
					adicionarContato(pessoa);
					break;

					case 6:
					removerContato(pessoa);
		 			break;
	 			}
 			else {
	 			cin.clear();
	 			while (cin.get() != '\n');
			}
		}
	}

	void Tela::info(Departamento* departamento) {
		for (;;) {
	    CLEAR;
			int opcao = 0;
			cout << "Departamento: "; CGREEN; cout << departamento->getNome() << endl; CRESET;
			cout << "Site: "; CGREEN; cout << departamento->getSite() << endl; CRESET;
			cout << "Responsavel: " << departamento->getResponsavel()->getNome() << endl; CRESET;
			CRESET;
			if (departamento->getContatos().size() > 0 ) cout << "\nContatos: \n";
			CGREEN;
			for (auto& i : departamento->getContatos())
				cout << '\t' << i->getNome() << endl;
			CRESET;
			cout << "-----------------------------------------\n\n"
				 << "Escolha uma opcao:\n"
				 << "1) Ver mensagens enviadas\n"
				 << "2) Ver mensagens recebidas\n"
				 << "3) Escrever mensagem\n"
				 << "4) Ver Contatos Alcancaveis\n"
				 << "0) Voltar" << endl;

			cout << "\nDigite uma opcao: ";
	 		if(cin >> opcao)
		 		switch (opcao) {
		 			case 0:
		 			return;

		 			case 1:
					mensagensEnviadas(departamento);
					break;

					case 2:
					mensagensRecebidas(departamento);
					break;

					case 3:
					escreverMensagem(departamento);
					break;

					case 4:
					contatosAlcancaveis(departamento);
		 			break;
	 			}
 			else {
	 			cin.clear();
	 			while (cin.get() != '\n');
			}
		}
	}

	void Tela::adicionarContato(Pessoa* pessoa) {
		for (;;) {
	    CLEAR;
            int opcao = 0;
            cout << "Perfis\n"
                 << "-----------------------------------------\n";
			listarPerfis();
            cout << "\nEscolha um perfil para adicionar ou 0 para voltar: ";
			if (cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao >= 1 && opcao <= int(perfis.size())) {
					try {
						pessoa->adiciona(perfis[opcao - 1]);
						CGREEN; cout << perfis[opcao - 1]->getNome(); CRESET;
						cout << " conectado a ";
						CGREEN; cout << pessoa->getNome() << endl; CRESET;
					} catch (logic_error& e) {
						cout << e.what() << endl;
					}

                    cout << "\nAperte Enter para retornar\n";
                    cin.get();
                    while (cin.get() != '\n');
                    return;
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::removerContato(Pessoa* pessoa) {
		for (;;) {
		CLEAR;
			int opcao = 0;
			int i = 0;
			cout << "Contatos\n"
				<<  "-----------------------------------------\n";
			CGREEN;
			for (auto& c : pessoa->getContatos())
				cout << ++i << ") " << c->getNome() << endl;
			CRESET;
			cout << "\nEscolha um contato para remover ou 0 para voltar: ";
			if (cin >> opcao) {
				if (opcao == 0)
					return;
				if (opcao >= 1 && opcao <= int(pessoa->getContatos().size())) {
					if (pessoa->remove(pessoa->getContatos()[opcao - 1])) {
						CGREEN; cout << pessoa->getContatos()[opcao - 1]->getNome(); CRESET;
						cout << " removido com sucesso\n";
					} else {
						cout << "Não foi possível remover o contato\n";
					}

					cout << "\nAperte Enter para retornar\n";
                    cin.get();
                    while (cin.get() != '\n');
                    return;
				} else {
					cin.clear();
					while (cin.get() != '\n');
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::mensagensEnviadas(Perfil* perfil) {
		CLEAR;
		cout << "Mensagens Enviadas\n"
		 	 << "-----------------------------------------\n";
		for (auto& m : perfil->getMensagensEnviadas()) {
			cout << m << endl;
		}
        cout << "\nAperte Enter para retornar\n";
		cin.get();
		while (cin.get() != '\n');
		return;
	}

	void Tela::mensagensRecebidas(Perfil* perfil) {
		for (;;) {
		    CLEAR;
			int opcao = 0;
			int i = 0;
			vector<Mensagem*> mensagens;
			cout << "Mensagens Recebidas\n"
				 << "-----------------------------------------\n";
			for (auto& m : perfil->getMensagensRecebidas()) {
				mensagens.push_back(m);
				cout << ++i << ") " << m << endl;
			}

			if (perfil->getMensagensRecebidas().size() > 0)
				cout << "\nDigite o numero da mensagem para curtir ou 0 para voltar: ";
			else
				cout << "\nDigite 0 para voltar: ";

			if(cin >> opcao) {
				if (opcao == 0) {
					return;
				}
				if (opcao > 0 && opcao <= int(perfil->getMensagensRecebidas().size())) {
					MensagemComCurtir* msg = dynamic_cast<MensagemComCurtir*>(mensagens[opcao - 1]);
					if (msg != nullptr) msg->curtir();
				}
			} else {
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}

	void Tela::escreverMensagem(Perfil* perfil) {
		CLEAR;
	    if (perfil->getContatos().size() == 0) {
            cout << "Voce nao tem nenhum contato :(\n"
                << "Por que nao adiciona algum na tela anterior? =D\n";
            cout << "\nAperte Enter para retornar\n";
            cin.get();
            while (cin.get() != '\n');
            return;
	    }
		int opcao;
        string mensagem;

		if (dynamic_cast<Departamento*>(perfil) == nullptr) {
			cout << "A mensagem e privada? (0 - nao, 1 - sim): ";
			for (;;) {
				if(cin >> opcao) {
					if (opcao) {
						cout << "Escolha o destino:\n";
						listarPerfis();
						cout << "Digite um numero ou 0 para cancelar: ";
						cin >> opcao;
						if (opcao == 0) return;

						if (opcao >= 1 && opcao <= int(perfis.size())) {
							string aviso = "Mensagem enviada a " + perfis[opcao - 1]->getNome();
							cout << "Digite a mensagem: ";

					        cin.ignore();
					        getline(cin, mensagem);
							try {
								dynamic_cast<Pessoa*>(perfil)->envia(mensagem, perfis[opcao - 1]);
							} catch (logic_error& e) {
								aviso = e.what();
							}
							cout << aviso << endl;
						} else {
							cout << "Opcao invalida\n";
						}
						cout << "\nAperte Enter para retornar\n";
						while (cin.get() != '\n');
						return;
					} else break;
				} else {
					cout << "Digite uma opcao valida: ";
					cin.clear();
					while (cin.get() != '\n');
				}
			}
		}

		cout << "A mensagem pode ser curtida? (0 - nao, 1 - sim): ";
		for(;;) {
			if (cin >> opcao)
				break;
			else {
				cout << "Digite uma opcao valida: ";
				cin.clear();
				while (cin.get() != '\n');
			}
		}

        cout << "Digite a mensagem: ";

        cin.ignore();
        getline(cin, mensagem);

        perfil->envia(mensagem, bool(opcao));
        cout << "Mensagem enviada a todos os contatos\n";
		cout << "\nAperte Enter para retornar\n";
		while (cin.get() != '\n');
	}

	void Tela::contatosAlcancaveis(Perfil* perfil) {
		CLEAR;
		cout << "Contatos Alcancaveis\n"
            <<  "--------------------\n";
        for (auto& i : perfil->getContatosAlcancaveis())
			cout << i->getNome() << endl;
		cout << "\nAperte Enter para continuar\n";

		cin.get();
		while (cin.get() != '\n');
	}

	void Tela::listarPerfis() {
		CGREEN;
		for (int i = 0; i < int(perfis.size()); i++)
			cout << i + 1 << ") " << perfis[i]->getNome() << "\n";
		CRESET;
	}

	void Tela::savePersistencia() {
		persistencia->salvar(perfis);
	}
}
