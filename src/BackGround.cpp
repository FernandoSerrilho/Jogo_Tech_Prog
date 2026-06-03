#include "BackGround.h"

BackGround::BackGround() {
	colisao.setSize(sf::Vector2f(1920.0f, 1080.0f));
	Ente::setText("Texturas/BackGround/Fundo.png", colisao);
}

BackGround::~BackGround() {}

sf::FloatRect BackGround::getBounds() const {
	return colisao.getGlobalBounds();
}

void BackGround::executar() {
	desenhar(colisao.getPosition());
}