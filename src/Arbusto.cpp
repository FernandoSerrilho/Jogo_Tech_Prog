#include "Arbusto.h"
#include "Jogador.h"
#include "Inimigo.h"

Arbusto::Arbusto():Obstaculo(), lentidao(((rand() % 3) / 0.1f) + 0.3f) {}

Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), lentidao(((rand()%5)/0.1f) + 0.3f) {
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

    j1->setmodifiVelo(lentidao);
    //j1->setVel(velJ.x,velJ.y);
}

void Arbusto::obstaculizar(Inimigo* i1) {
    int n = 45;
}