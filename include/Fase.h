#pragma once
#include "Ente.h"
#include "ListaEntidades.h" 
#include "Gerenciador_Colisoes.h"

class BackGround;
class Chao;

namespace Entidades {
	namespace Personagens{
		class Jogador;
	}
	class EntidadePertinente;
}

namespace Fases {
	class Fase : public Ente {
	protected:
		Listas::ListaEntidades list_ents;
		Gerenciadores::Gerenciador_Colisoes GC;
		BackGround* bgFase;
		Chao* chaoFase;
		const int maxDrones;
		const int maxPlataformas;
		void criarDrones(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void criarPlataformas();
		virtual void criarCenario() = 0;
		virtual void criarInimigos(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2) = 0;
		virtual void criarObstaculos() = 0;
	public:
		Fase(Entidades::Personagens::Jogador* j1 = nullptr, Entidades::Personagens::Jogador* j2 = nullptr);
		~Fase();
		void limparGC();
		void limparListEnts();
		virtual void executar() = 0;
	};
}
