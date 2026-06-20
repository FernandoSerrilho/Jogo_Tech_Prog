#pragma once
#include "Entidade.h"
namespace Entidades {
	namespace EntidadesPertinentes {
		class EntidadePertinente;
	}

	class Chao : public Entidade {
	private:
	public:
		Chao(const char* caminhoTextura = " ");
		~Chao();
		void executar();
		void colidir(Entidades::EntidadesPertinentes::EntidadePertinente* pE);
	};
}