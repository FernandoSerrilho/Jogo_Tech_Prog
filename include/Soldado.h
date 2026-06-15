#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace Personagens {
		namespace Inimigos {
			class Soldado : public Inimigo {
			private:
				Jogador* pJ;
				sf::Clock relogioParado;
				float temp_parado;
				sf::Vector2f vetorParado;
				bool parado;
			public:
				Soldado(sf::Vector2f pos, const char* caminhoTextura = "");
				~Soldado();
				void executar();
				void danificar(Jogador* j);
				void colidir(Jogador* j);
				void mover();
			};
		}
	}
}