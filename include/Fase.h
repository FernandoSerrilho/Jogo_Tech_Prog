#pragma once
#include <list>
#include "Gerenciador_Colisoes.h"
using namespace Gerenciadores;
using namespace std;
namespace Entidades {
	class Entidade;
}
using namespace Entidades;

namespace Fases {
	class Fase : public Ente {
	protected:
		list<Entidade*> list_ents;
		Gerenciador_Colisoes GC;
		void criarInmFaceis();
		//void criarPlataformas();
	public:
		Fase();
		~Fase();
		//virtual void executar();
	};
}
