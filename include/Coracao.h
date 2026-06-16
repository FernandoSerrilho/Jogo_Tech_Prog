#pragma once

#include "EntidadeBase.h"

	class Coracao : public EntidadeBase {
	private:
	public:
		Coracao();
		Coracao(sf::Vector2f pos,const char* caminhoTextura = " ");
		~Coracao();
		void executar();
	};