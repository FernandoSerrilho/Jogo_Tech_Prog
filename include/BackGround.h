#pragma once

#include "Entidade.h"

namespace Entidades {
	class BackGround : public Entidade {
	private:
		sf::RectangleShape colisao;
	public:
		BackGround(const char* caminhoTextura = "");
		~BackGround();
		sf::FloatRect getBounds() const;
		void executar();
	};
}