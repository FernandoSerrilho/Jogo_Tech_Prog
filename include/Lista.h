#pragma once

namespace Listas {
	template <class TL>
	class Lista {
	private:

		template <class TE>
		class Elemento {
		private:
			Elemento<TE>* pProx;
			TE* pInfo;
		public:
			Elemento();
			~Elemento();
			void incluir(TE* pE);
			void setProx(Elemento<TE>* pTE);
			Elemento<TE>* getProx();
			TE* getInfo();
		};

		Elemento<TL>* pPrim;
		Elemento<TL>* pUlti;

	public:
		class Iterador {
		private:
			Elemento<TL>* it;
		public:
			Iterador(Elemento<TL>* n = nullptr);
			~Iterador();
			Iterador& operator++();
			TL* operator*();
			bool operator==(const Elemento<TL>* pElem) const;
			bool operator!=(const Elemento<TL>* pElem) const;
			bool operator==(const Iterador& pTL) const;
			bool operator!=(const Iterador& pTL) const;
			Elemento<TL>* getIt() const { return it; }
		};
		Lista();
		~Lista();
		void incluir(TL* pTl);
		void limpar();
		bool busca(Elemento<TL>* pTl);
		void remove(Elemento<TL>* pTl);
		Iterador begin();
		Iterador end();
	};
}

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
Lista<TL>::Elemento<TE>* Lista<TL>::Elemento<TE>::getProx() {
	return pProx;
}

template <class TL>
template <class TE>
TE* Lista<TL>::Elemento<TE>::getInfo() {
	return pInfo;
}

//Iterador
template <class TL>
Lista<TL>::Iterador::Iterador(Elemento<TL>* n) :it(n) {}

template <class TL>
Lista<TL>::Iterador::~Iterador() {
	it = nullptr;
}

template <class TL>
Lista<TL>::Iterador& Lista<TL>::Iterador::operator++() {
	if (it) {
		it = it->getProx();
	}
	return *this;
}

template <class TL>
TL* Lista<TL>::Iterador::operator *() {
	if (it)
		return it->getInfo();
	return nullptr;
}

template <class TL>
bool Lista<TL>::Iterador::operator!=(const Elemento<TL>* pElem) const {
	return (this->it != pElem);
}

template <class TL>
bool Lista<TL>::Iterador::operator==(const Elemento<TL>* pElem) const {
	return (this->it == pElem);
}

template <class TL>
bool Lista<TL>::Iterador::operator==(const Iterador& pTL) const {
	return (this->it == pTL.it);
}

template <class TL>
bool Lista<TL>::Iterador::operator!=(const Iterador& pTL) const {
	return (this->it != pTL.it);
}

template <class TL>
typename Lista<TL>::Iterador Lista<TL>::begin() {
	return Iterador(pPrim);
}

template <class TL>
typename Lista<TL>::Iterador Lista<TL>::end() {
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
	Elemento<TL>* atual = pPrim;
	Elemento<TL>* proximo = nullptr;

	while (atual != nullptr) {
		proximo = atual->getProx();
		delete atual;
		atual = proximo;
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
		++it;
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
			ant = it.getIt();
			++it;
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




