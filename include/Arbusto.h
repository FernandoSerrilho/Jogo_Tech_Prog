#pragma once

#include "Obstaculo.h"
namespace Entidades {
	namespace Personagens {
		class Jogador;
		namespace Inimigos {
			class Inimigo;
		}
	}
}

namespace Entidades {
	namespace Obstaculos {
		class Arbusto : public Obstaculo {
		private:
			float lentidao;
		public:
			Arbusto();
			Arbusto(sf::Vector2f pos, sf::Vector2f tam);
			~Arbusto();
			void executar();
			void obstaculizar(Entidades::Personagens::Jogador* j1);
			void salvar();
		};
	}
}