#pragma once

#include "EntidadePertinente.h"

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
		class Obstaculo :public EntidadePertinente {
		private:
			bool danoso;
		public:
			Obstaculo(bool flag = false);
			~Obstaculo();
			void salvarDataBuffer();		
			virtual void executar() = 0;
			virtual void salvar() = 0;	
			virtual void obstaculizar(Entidades::Personagens::Jogador* j1) = 0;
		};
	}
}