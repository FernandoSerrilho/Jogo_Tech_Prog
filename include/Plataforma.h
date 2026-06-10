#pragma once

#include "Obstaculo.h"

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Inimigo;
		}
		class Jogador;
	}
}

namespace Entidades {
	namespace Obstaculos {
		class Plataforma : public Obstaculo {
		private:
			sf::RectangleShape colisao;
			sf::Texture textura;
			sf::Sprite sprites;
			int altura;
		public:
			Plataforma();
			Plataforma(sf::Vector2f pos, sf::Vector2f tam);
			~Plataforma();
			void executar();
			void obstaculizar(Entidades::Personagens::Jogador* j1);
			void obstaculizar(Entidades::Personagens::Inimigos::Inimigo* i1);
			sf::FloatRect getBounds() const;
			void setDim(sf::Vector2f dim);
			void setPos(sf::Vector2f pos);
			void InitColi(sf::Vector2f dim, sf::Vector2f pos);
			void InitText();
			sf::RectangleShape getColi();
		};
	}
}