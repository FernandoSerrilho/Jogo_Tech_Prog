#pragma once

#include "Entidade.h"

namespace Entidades{
	class Coracao : public Entidade {
	private:
	public:
		Coracao();
		Coracao(sf::Vector2f pos,const char* caminhoTextura = " ");
		~Coracao();
		void executar();
	};
}