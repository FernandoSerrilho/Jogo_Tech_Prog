#pragma once
#include "Ente.h"
#include "ListaEntidade.h" 
#include "Gerenciador_Colisoes.h"

namespace Entidades {
	namespace Personagens{
		class Jogador;
	}
	class Entidade;
}

namespace Fases {
	class Fase : public Ente {
	protected:
		Listas::ListaEntidade list_ents;
		Gerenciadores::Gerenciador_Colisoes GC;
		void criarInmFaceis(Entidades::Personagens::Jogador* j);
		void criarPlataformas();
		virtual void criarCenario() = 0;
		virtual void criarInimigos(Entidades::Personagens::Jogador* j) = 0;
		virtual void criarObstaculos() = 0;
	public:
		Fase(Entidades::Personagens::Jogador* j = nullptr);
		~Fase();
		virtual void executar() = 0;
	};
}
