#pragma once

#include "Entidade.h"
namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}
using namespace Entidades::Personagens;

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
			virtual void obstaculizar(Jogador* j1) = 0;

		};
	}
}