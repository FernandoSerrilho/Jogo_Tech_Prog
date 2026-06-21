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

namespace Entidades {
	namespace EntidadesPertinentes {
		namespace Obstaculos {
			class Arbusto : public Obstaculo {
			private:
				float lentidao;
			public:
				Arbusto();
				Arbusto(sf::Vector2f pos, sf::Vector2f tam);
				~Arbusto();
				void setLent(float lent);
				void executar();
				void obstaculizar(Entidades::EntidadesPertinentes::Personagens::Jogador* j1);
				void salvar();
			};
		}
	}
}