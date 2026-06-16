#pragma once

#include "EntidadeBase.h"
namespace Entidades {
	class Entidade;
}

	class Chao : public EntidadeBase {
	private:
	public:
		Chao(const char* caminhoTextura = " ");
		~Chao();
		void executar();
		void colidir(Entidades::Entidade* pE);
	};