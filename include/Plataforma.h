#pragma once

#include "Obstaculo.h"

namespace Entidades {
	namespace Personagens {
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
			void obstaculizar(Jogador* j1);
			sf::FloatRect getBounds() const;
			void setDim(sf::Vector2f dim);
			void setPos(sf::Vector2f pos);
			void InitColi(sf::Vector2f dim, sf::Vector2f pos);
			void InitText();
			sf::RectangleShape getColi();
		};
	}
}
