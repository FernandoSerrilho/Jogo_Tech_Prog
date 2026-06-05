#pragma once

#include "Entidade.h"
#include "Jogador.h"
using namespace Entidades;

class Chao : public Entidade {
private:
	sf::RectangleShape colisao;
public:
	Chao(const char* caminhoTextura = " ");
	~Chao();
	void executar();
	sf::FloatRect getBounds() const;
	void colidir(Entidade * pE);
};