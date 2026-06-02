#pragma once

#include "Entidade.h"
using namespace Entidades;

class Chao : public Entidade {
private:
	sf::RectangleShape colisao;
public:
	Chao(const char* caminhoTextura = " ");
	~Chao();
	void executar();
	sf::FloatRect getBounds() const;
};