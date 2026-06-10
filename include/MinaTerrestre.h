#pragma once

#include "Obstaculo.h"

namespace Entidades {
	namespace Personagem {
		class Jogador;
		namespace Inimigos {
			class Inimigo;
		}
	}
}

namespace Entidades{
	namespace Obstaculos {
		class MinaTerrestre :public Obstaculo {
			private:
				float tempoAtivacao;
				float raio;
				sf::RectangleShape colisao;
				sf::RectangleShape explosao;
				sf::Clock tempoExplosao;
				bool tempoAtivo;
			public:
				MinaTerrestre();
				MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam);
				~MinaTerrestre();
				void explodir(Entidades::Personagens::Jogador* pJ);
				void obstaculizar(Entidades::Personagens::Jogador* pJ);
				void obstaculizar(Entidades::Personagens::Inimigos::Inimigo* pI);
				sf::FloatRect getBounds() const;
				void executar();
		};
	}
}