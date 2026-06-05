#pragma once

#include "Entidade.h"
using namespace Entidades;

class BackGround : public Entidade {
private:
	sf::RectangleShape colisao;
public:
	BackGround();
	~BackGround();
	sf::FloatRect getBounds() const;
	void executar();
};