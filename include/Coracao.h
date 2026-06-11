#pragma once

#include "Entidade.h"

namespace Entidades {
	class Coracao : public Entidade {
	private:
		sf::RectangleShape colisao;
	public:
		Coracao();
		Coracao(sf::Vector2f pos,const char* caminhoTextura = " ");
		~Coracao();
		void executar();
		sf::FloatRect getBounds() const;
	};
}