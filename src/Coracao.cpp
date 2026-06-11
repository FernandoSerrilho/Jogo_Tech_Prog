#include "Coracao.h"
using namespace Entidades;

Coracao::Coracao(){}

Coracao::Coracao(sf::Vector2f pos,const char* caminhoTextura) {
	colisao.setPosition(pos.x, pos.y);
	setPos(pos.x, pos.y);
	sf::Vector2f tam(48.0f, 45.0f);
	colisao.setSize(tam);
	setText(caminhoTextura, colisao);

	contraGravidade = -0.3f;
}

Coracao::~Coracao() {}

void Coracao::executar() {
	setPos(pos.x,pos.y + gravidade + contraGravidade);
	desenhar(colisao.getPosition());
}

sf::FloatRect Coracao::getBounds() const {
	return colisao.getGlobalBounds();
}
