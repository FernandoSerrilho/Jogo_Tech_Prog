#pragma once

#include "Ente.h"

	class BackGround : public Ente {
	private:
		sf::RectangleShape colisao;
	public:
		BackGround(const char* caminhoTextura = "");
		~BackGround();
		void executar();
	};