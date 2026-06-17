#pragma once

#include "Lista.h"

	class Entidade;

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidade> LEs;
		Lista<Entidade>::Iterador it;
	public:
		ListaEntidades();
		~ListaEntidades();
		Lista<Entidade>::Iterador begin();
		Lista<Entidade>::Iterador end();
		void incluir(Entidade* pE);
		void percorrer();
		void removeMortos();
		void desenhar();
		void limpar();

	};
}