#pragma once

#include "Entidade.h"

	class Coracao : public Entidade {
	private:
	public:
		Coracao();
		Coracao(sf::Vector2f pos,const char* caminhoTextura = " ");
		~Coracao();
		void executar();
	};