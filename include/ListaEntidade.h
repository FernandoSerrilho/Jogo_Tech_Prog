#pragma once

#include "Lista.h"

namespace Entidades {
	class Entidade;
}

namespace Listas {
	class ListaEntidade {
	private:
		Lista<Entidades::Entidade> LEs;
		Lista<Entidades::Entidade>::Iterador it;
	public:
		ListaEntidade();
		~ListaEntidade();
		Lista<Entidades::Entidade>::Iterador begin();
		Lista<Entidades::Entidade>::Iterador end();
		void incluir(Entidades::Entidade* pE);
		void percorrer();
		void removeMortos();
		void desenhar();
		void limpar();

	};
}