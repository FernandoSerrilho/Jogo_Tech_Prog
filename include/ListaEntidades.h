#pragma once

#include "Lista.h"

namespace Entidades {
	class Entidade;
}

namespace Listas {
	class ListaEntidades {
	private:
		Lista<Entidades::Entidade> LEs;
		Lista<Entidades::Entidade>::Iterador it;
	public:
		ListaEntidades();
		~ListaEntidades();
		Lista<Entidades::Entidade>::Iterador begin();
		Lista<Entidades::Entidade>::Iterador end();
		void incluir(Entidades::Entidade* pE);
		void percorrer();
		void removeMortos();
		void desenhar();
		void limpar();

	};
}