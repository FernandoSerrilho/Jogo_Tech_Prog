#pragma once

#include "Obstaculo.h"


namespace Entidades {
	namespace Personagem {
		class Jogador;
		class Inimigo;
	}
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
				/*class Explosao :public Ente {
					private:
						sf::RectangleShape exp;
						sf::Vector2f posicao;
					public:
						Explosao();
						Explosao(sf::Vector2f pos,sf::RectangleShape tam);
						~Explosao();
						void executar();
				};*/
				MinaTerrestre();
				MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam);
				~MinaTerrestre();
				void explodir(Jogador* pJ);
				void obstaculizar(Jogador* pJ);
				void obstaculizar(Inimigo* pI);
				sf::FloatRect getBounds() const;
				void executar();
		};
	}
}