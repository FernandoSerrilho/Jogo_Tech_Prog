#pragma once

#include "Entidade.h"

	class BackGround : public Entidade {
	public:
		BackGround(const char* caminhoTextura = "");
		~BackGround();
		void executar();
	};
