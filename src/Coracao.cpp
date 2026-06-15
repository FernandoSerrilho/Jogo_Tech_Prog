#include "Coracao.h"

Coracao::Coracao(){}

Coracao::Coracao(sf::Vector2f pos,const char* caminhoTextura):Ente() {
	sf::Vector2f tam(48.0f, 45.0f);
	setFigura(tam);
	figura.setPosition(pos.x, pos.y);
	setText(caminhoTextura, figura);
}

Coracao::~Coracao() {}

void Coracao::executar() {
	desenhar(figura.getPosition());
}
