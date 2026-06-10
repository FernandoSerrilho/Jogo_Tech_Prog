#pragma once

#include "Entidade.h"

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
		class Obstaculo :public Entidade {
		private:
			bool danoso;
		public:
			Obstaculo(bool flag = false);
			~Obstaculo();
			//void salvarDataBuffer();		TODO
			virtual void executar() = 0;
			//virtual void salvar() = 0;	TODO
			virtual void obstaculizar(Entidades::Personagens::Jogador* j1) = 0;
			virtual void obstaculizar(Entidades::Personagens::Inimigos::Inimigo* i1) = 0;

		};
	}
}