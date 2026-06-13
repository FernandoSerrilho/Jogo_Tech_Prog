#include "Coracao.h"
using namespace Entidades;

Coracao::Coracao(){}

Coracao::Coracao(sf::Vector2f pos,const char* caminhoTextura) {
	colisao.setPosition(pos.x, pos.y);
	sf::Vector2f tam(48.0f, 45.0f);
	colisao.setSize(tam);
	setText(caminhoTextura, colisao);
}

Coracao::~Coracao() {}

void Coracao::executar() {
	desenhar(colisao.getPosition());
}
