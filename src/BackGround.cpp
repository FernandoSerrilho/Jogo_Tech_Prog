#include "BackGround.h"

BackGround::BackGround() {
	colisao.setSize(sf::Vector2f(800.0f, 600.0f));
	Ente::setText("Texturas/BackGround/Ceu_Escuro.png", colisao);
}

BackGround::~BackGround() {}

sf::FloatRect BackGround::getBounds() const {
	return colisao.getGlobalBounds();
}

void BackGround::executar() {
	desenhar(colisao.getPosition());
}