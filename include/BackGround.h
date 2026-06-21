#pragma once

#include "Entidade.h"

namespace Entidades {
	class BackGround : public Entidade {
	public:
		BackGround(const char* caminhoTextura = "");
		~BackGround();
		void executar();
	};
}
