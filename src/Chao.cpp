#include "Chao.h"

Chao::Chao(const char* caminhoTextura) {
	colisao.setPosition(0.0f, 550.0f);
	sf::Vector2f tam(800.0f, 50.0f);
	colisao.setSize(tam);
	setText(caminhoTextura, colisao);
}

Chao::~Chao() {}

void Chao::executar() {
	desenhar(colisao.getPosition());
}

sf::FloatRect Chao::getBounds() const {
	return colisao.getGlobalBounds();
}