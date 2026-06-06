#include "Arbusto.h"
#include "Jogador.h"
#include "Inimigo.h"

Arbusto::Arbusto():Obstaculo(), lentidao(0.3f) {}

Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), lentidao(0.3f) {
	colisao.setSize(tam);
	colisao.setPosition(pos);
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
    sf::Vector2f pos = j1->getPos();
    sf::Vector2f velJ = j1->getVel();
    sf::FloatRect boundsJ = j1->getBounds();
    sf::FloatRect boundsA = getBounds();

    //float overlapX = (boundsJ.left + boundsJ.width) - boundsA.left;
    //j1->setPos(pos.x - overlapX, pos.y);
    j1->setLent(true);
    j1->setmodifiVelo(lentidao);
}

void Arbusto::obstaculizar(Inimigo* i1) {
    int n = 45;
}