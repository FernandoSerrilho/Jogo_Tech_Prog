#include "BackGround.h"

BackGround::BackGround(const char* caminhoTextura) {
	colisao.setSize(sf::Vector2f(1920.0f, 1080.0f));
	Entidade::setPos(0.0f, 0.0f);
	Ente::setText(caminhoTextura, colisao);
}

BackGround::~BackGround() {}

sf::FloatRect BackGround::getBounds() const {
	return colisao.getGlobalBounds();
}

void BackGround::executar() {
	desenhar(colisao.getPosition());
}