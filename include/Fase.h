#pragma once
#include "Ente.h"
#include "ListaEntidades.h" 
#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Salvamento.h"

namespace Entidades {
	class BackGround;
	class Chao;
	//class Entidade;
	namespace EntidadesPertinentes {
			class Projetil;
		namespace Personagens {
			class Jogador;
		}
	}
}

	namespace Fases {
		class Fase : public Ente {
		protected:
			Listas::ListaEntidades list_ents;
			Gerenciadores::Gerenciador_Colisoes GC;
			Gerenciadores::Gerenciador_Salvamento GS;
			Entidades::BackGround* bgFase;
			Entidades::Chao* chaoFase;
			int num_fase;
			const int maxDrones;
			const int maxPlataformas;
			void criarDrones(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2);
			void criarPlataformas();
			virtual void criarCenario() = 0;
			virtual void criarInimigos(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2) = 0;
			virtual void criarObstaculos() = 0;
		public:
			Fase(Entidades::EntidadesPertinentes::Personagens::Jogador* j1 = nullptr, Entidades::EntidadesPertinentes::Personagens::Jogador* j2 = nullptr);
			~Fase();
			void incluirEntidade(Entidades::Entidade* e);
			void incluirInimigo(Entidades::EntidadesPertinentes::Personagens::Inimigos::Inimigo* i);
    		void incluirObstaculo(Entidades::EntidadesPertinentes::Obstaculos::Obstaculo* o);
			void incluirProjetil(Entidades::EntidadesPertinentes::Projetil* p);
			void limparGC();
			void limparListEnts();
			virtual void executar() = 0;
			void salvarFase();
		};
	}
