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
			const Elemento<TE>* getProx();
			TE* getInfo();
		};

		Elemento<TL>* pPrim;
		Elemento<TL>* pUlti;

		class Iterador {
		private:
			Elemento<TL>* it;
		public:
			Iterador();
			~Iterador();
			Iterador& operator++();
			TL* operator*();
			bool operator==(const Elemento<TL>* pTL) const;
			bool operator!=(const Elemento<TL>* pTL) const;
		};

	public:
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