#pragma once
#include "ListaEntidade.h"
#include "Gerenciador_Colisoes.h"
using namespace Gerenciadores;
namespace Entidades {
	class Entidade;
}
using namespace Entidades;

namespace Fases {
	class Fase : public Ente {
	protected:
		ListaEntidade list_ents;
		Gerenciador_Colisoes GC;
		void criarInmFaceis();
		//void criarPlataformas();
	public:
		Fase();
		~Fase();
		//virtual void executar();
	};
}
