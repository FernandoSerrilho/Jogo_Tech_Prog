#pragma once

#include "Entidade.h"

namespace Entidades {
	class Chao : public Entidade {
	private:
	public:
		Chao(const char* caminhoTextura = " ");
		~Chao();
		void executar();
		void colidir(Entidade* pE);
	};
}