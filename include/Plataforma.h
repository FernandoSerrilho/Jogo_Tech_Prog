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
			int altura;
		public:
			Plataforma();
			Plataforma(sf::Vector2f pos, sf::Vector2f tam);
			~Plataforma();
			void executar();
			void obstaculizar(Entidades::Personagens::Jogador* j1);
			void obstaculizar(Entidades::Personagens::Inimigos::Inimigo* i1);
			void salvar();
		};
	}
}