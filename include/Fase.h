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
		void criarInmFaceis(Jogador* j);
		void criarPlataformas();
		virtual void criarCenario() = 0;
		virtual void criarInimigos(Jogador* j) = 0;
		virtual void criarObstaculos() = 0;
	public:
		Fase(Jogador* j = nullptr);
		~Fase();
		virtual void executar() = 0;
	};
}
