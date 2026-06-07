#pragma once

#include "Inimigo.h"

class Soldado : public Inimigo {
	private:
		sf::RectangleShape figura;
		Jogador* pJ;
		sf::Clock relogioParado;
		float temp_parado;
		sf::Vector2f vetorParado;
		bool parado;
	public:
		Soldado(sf::Vector2f pos,const char* caminhoTextura = "");
		~Soldado();
		void executar();
		void danificar(Jogador* j);
		void colidir(Entidade* pE);
		void mover();
		sf::FloatRect getBounds() const;
		sf::RectangleShape getFigura();
};