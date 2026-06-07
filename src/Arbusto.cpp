#include "Arbusto.h"
#include "Jogador.h"
#include "Inimigo.h"

Arbusto::Arbusto():Obstaculo(), lentidao(0.3f) {}

Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), lentidao(0.3f) {
	colisao.setSize(tam);
	colisao.setPosition(pos);
	setPos(pos.x,pos.y);
	setText("Texturas/Arbusto/Bush.png", colisao);
}

Arbusto::~Arbusto(){}

sf::FloatRect Arbusto::getBounds() const {
	return colisao.getGlobalBounds();
}

void Arbusto::executar() {
	desenhar(colisao.getPosition());
}

void Arbusto::obstaculizar(Jogador* j1) {
    j1->setLent(true);
    j1->setmodifiVelo(lentidao);
}

void Arbusto::obstaculizar(Inimigo* i1) {
    //int n = 45;
}