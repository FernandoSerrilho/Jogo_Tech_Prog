#pragma once

#include "Ente.h"
class Chao : public Ente {
private:
	sf::RectangleShape colisao;
public:
	Chao(const char* caminhoTextura = " ");
	~Chao();
	void executar();
};