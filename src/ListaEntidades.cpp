#include "ListaEntidades.h"
#include "Entidade.h"
#include <iostream>
using namespace std;
using namespace Entidades;
using namespace Listas;

ListaEntidades::ListaEntidades() : LEs(), it(LEs.begin()) { LEs.limpar(); }

ListaEntidades::~ListaEntidades() {
	LEs.limpar();
}

Lista<Entidades::Entidade>::Iterador   ListaEntidades::begin() {return LEs.begin();}
Lista<Entidades::Entidade>::Iterador   ListaEntidades::end() {return LEs.end();}

void ListaEntidades::incluir(Entidade* pE) {
	if (pE != nullptr)
		LEs.incluir(pE);
}

void ListaEntidades::percorrer() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		Lista<Entidade>::Iterador aux = it;
		++aux;

		if (e) {
			if (e->getVivo()) {
				e->executar();
			}
		}
		it = aux;
	}
}

void ListaEntidades::removeMortos() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		if (e->getVivo() == false) {
			LEs.remove(it.getIt());
		
		}
		++it;
	}

}

void ListaEntidades::limpar() {
	LEs.limpar();
}

void ListaEntidades::desenhar() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		if (e)
			e->desenhar(e->getPos());
		++it;
	}
}

