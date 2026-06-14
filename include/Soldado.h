#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Soldado : public Inimigo {
			private:
				sf::RectangleShape figura;
				Jogador* pJ;
				int vidas;
				sf::Clock relogioParado;
				float temp_parado;
				sf::Vector2f vetorParado;
				bool parado;
			public:
				Soldado(sf::Vector2f pos, const char* caminhoTextura = "");
				~Soldado();
				int getVidas();
				void setVidas(int v);
				void executar();
				void danificar(Jogador* j);
				void colidir(Jogador* j);
				void mover();
				sf::FloatRect getBounds() const;
				sf::RectangleShape getFigura();
			};
		}
	}
}