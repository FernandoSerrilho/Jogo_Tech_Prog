#pragma once

#include "Ente.h"

	class Coracao : public Ente {
	private:
	public:
		Coracao();
		Coracao(sf::Vector2f pos,const char* caminhoTextura = " ");
		~Coracao();
		void executar();
	};