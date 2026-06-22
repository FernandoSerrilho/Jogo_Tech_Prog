#pragma once
#include "Ente.h"
#include "ListaEntidades.h" 
#include "Gerenciador_Colisoes.h"

namespace Entidades {
	class BackGround;
	class Chao;
			class Projetil;
		namespace Personagens {
			class Jogador;
		}
}

	namespace Fases {
		class Fase : public Ente {
		protected:
			Listas::ListaEntidades list_ents;
			Gerenciadores::Gerenciador_Colisoes GC;
			Entidades::BackGround* bgFase;
			Entidades::Chao* chaoFase;
			int num_fase;
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
			void incluirEntidade(Entidades::Entidade* e);
			void incluirInimigo(Entidades::Personagens::Inimigos::Inimigo* i);
    		void incluirObstaculo(Entidades::Obstaculos::Obstaculo* o);
			void limparGC();
			void limparListEnts();
			virtual void executar() = 0;
			void salvarFase();
			bool carregarEntidadeemComum(const std::string& tipoLido, int id, float px ,float py , float vx, float vy, bool vivo ,std::ifstream& arquivo,
				 Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2, bool& j2Ativo);
			virtual void carregarFase(std::ifstream& arquivo, Entidades::Personagens::Jogador* j1,
				Entidades::Personagens::Jogador* j2, bool& j2Ativo) = 0;
		};
	}
