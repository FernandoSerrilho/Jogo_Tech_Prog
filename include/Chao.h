#pragma once
#include "Entidade.h"
namespace Entidades {
	class EntidadePertinente;
}

	class Chao : public Entidade {
	private:
	public:
		Chao(const char* caminhoTextura = " ");
		~Chao();
		void executar();
		void colidir(Entidades::EntidadePertinente* pE);
	};