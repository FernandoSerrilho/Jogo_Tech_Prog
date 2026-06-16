#pragma once

#include "EntidadeBase.h"

	class BackGround : public EntidadeBase {
	public:
		BackGround(const char* caminhoTextura = "");
		~BackGround();
		void executar();
	};
