#pragma once

#include "Obstaculo.h"

namespace Entidades {
	namespace EntidadesPertinentes {
		namespace Personagens {
			class Jogador;
			namespace Inimigos {
				class Inimigo;
			}
		}
	}
}

namespace Entidades{
	namespace EntidadesPertinentes {
		namespace Obstaculos {
			class MinaTerrestre :public Obstaculo {
			private:
				float tempoAtivacao;
				float raio;
				sf::RectangleShape explosao;
				sf::Clock tempoExplosao;
				bool tempoAtivo;
			public:
				MinaTerrestre();
				MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam);
				~MinaTerrestre();
				void setraio(float r);
				void setTempoAtivo(bool a);
				void explodir(Entidades::EntidadesPertinentes::Personagens::Jogador* pJ);
				void obstaculizar(Entidades::EntidadesPertinentes::Personagens::Jogador* pJ);
				void executar();
				void salvar();
			};
		}
	}
}