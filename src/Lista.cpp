#include "Lista.h"
using namespace Listas;

//Elemento
template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::Elemento() : pProx(nullptr), pInfo(nullptr) {

}

template <class TL>
template <class TE>
Lista<TL>::Elemento<TE>::~Elemento() {
	pProx = nullptr;
	pInfo = nullptr;
}

template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::incluir(TE* pE) {
	pInfo = pE;
}

template <class TL>
template <class TE>
void Lista<TL>::Elemento<TE>::setProx(Elemento<TE>* pTE) {
	pProx = pTE;
}

template <class TL>
template <class TE>
const typename Lista<TL>::template Elemento<TE>* Lista<TL>::Elemento<TE>::getProx() {
	return pProx;
}

template <class TL>
template <class TE>
TE* Lista<TL>::Elemento<TE>::getInfo() {
	return pInfo;
}

//Iterador
template <class TL>
Lista<TL>::Iterador::Iterador() :it(nullptr) {}

template <class TL>
Lista<TL>::Iterador::~Iterador() {
	it = nullptr;
}

template <class TL>
Lista<TL>::Iterador& Lista<TL>::Iterador::operator++() {
	if (it) {
		it = it->getProx();
		return *this;
	}
	return nullptr;
}

template <class TL>
TL* Lista<TL>::Iterador::operator *() {
	if (!it)
		return it->getInfo();
	return nullptr;
}

template <class TL>
bool Lista<TL>::Iterador::operator!=(const Elemento<TL>* pTL) const {
	return (this->it != pTL);
}

template <class TL>
bool Lista<TL>::Iterador::operator==(const Elemento<TL>* pTL) const {
	return (this->it == pTL);
}

template <class TL>
Lista<TL>::Iterador Lista<TL>::Lista::begin() {
	return Iterador(pPrim);
}

template <class TL>
Lista<TL>::Iterador Lista<TL>::Lista::end() {
	return Iterador(nullptr);
}


//Lista

template <class TL>
Lista<TL>::Lista() :pPrim(nullptr), pUlti(nullptr) {}

template <class TL>
Lista<TL>::~Lista() {
	pPrim = nullptr;
	pUlti = nullptr;
}


template <class TL>
void Lista<TL>::incluir(TL* pTL) {
	if (!pTL) return;

	Elemento<TL>* aux = new Elemento<TL>();
	aux->incluir(pTL);
	if (!pPrim) {
		pPrim = aux;
		pUlti = aux;
	}
	else {
		pUlti->setProx(aux);
		pUlti = aux;
	}
}


template <class TL>
void Lista<TL>::limpar() {
	Iterador it = begin();
	Elemento<TL>* aux;

	while (it != nullptr) {
		aux = it;
		delete (*aux);
		aux = nullptr;
		it++;
	}

	pPrim = nullptr;
	pUlti = nullptr;
}

template <class TL>
bool Lista<TL>::busca(Elemento<TL>* pTL) {
	Iterador it = begin();

	while (it != end()) {
		if (it == pTL)
			return true;
		it++;
	}
	return false;
}

template <class TL>
void Lista<TL>::remove(Elemento<TL>* pTL) {
	if (busca(pTL)) {
		if (pPrim == pTL) {
			pPrim = pTL->getProx();
			if (pPrim == nullptr)
				pUlti = nullptr;
			delete pTL;
			return;
		}
		Iterador it = begin();
		Elemento<TL>* ant;

		while (it != pTL) {
			ant = it;
			it++;
		}

		if (ant != nullptr) {
			ant->setProx(pTL->getProx());
			if (pTL == pUlti) {
				pUlti = ant;
			}
			delete pTL;
		}
	}
}




