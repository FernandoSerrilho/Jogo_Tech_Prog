#pragma once

#include "Lista.h"
using namespace Listas;

namespace Entidades {
	class Entidade;
}
using namespace Entidades;

class ListaEntidade {
private:
	Lista<Entidade> LEs;
	Lista<Entidade>::Iterador it;
public:
	ListaEntidade();
	~ListaEntidade();
	void incluir(Entidade* pE);
	void percorrer();
	void desenhar();
	void limpar();

};