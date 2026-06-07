#include "ListaEntidade.h"
#include "Entidade.h"
#include <iostream>
using namespace std;
using namespace Entidades;

ListaEntidade::ListaEntidade() : LEs(), it(LEs.begin()) { LEs.limpar(); }

ListaEntidade::~ListaEntidade() {
	LEs.limpar();
}

void ListaEntidade::incluir(Entidade* pE) {
	if (pE != nullptr)
		LEs.incluir(pE);
}

void ListaEntidade::percorrer() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		if (e)
			e->executar();
		++it;
	}
}

void ListaEntidade::removeMortos() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		if (e->getVivo() == false) {
			LEs.remove(it.getIt());
		
		}
		++it;
	}

}

void ListaEntidade::limpar() {
	LEs.limpar();
}

void ListaEntidade::desenhar() {
	Lista<Entidade>::Iterador it = LEs.begin();

	while (it != LEs.end()) {
		Entidade* e = *it;

		if (e)
			e->desenhar(e->getPos());
		++it;
	}
}

