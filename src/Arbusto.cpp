#include "Arbusto.h"
#include "Jogador.h"
#include "Inimigo.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;

Arbusto::Arbusto():Obstaculo(), lentidao(0.3f) {}

Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), lentidao(0.3f) {
	setFigura(tam);
	figura.setPosition(pos);
	setPos(pos.x,pos.y);
	setText("Texturas/Arbusto/Bush.png", figura);

	contraGravidade = -0.3f;
}

Arbusto::~Arbusto(){
	lentidao = -1;
}

void Arbusto::executar() {
	setPos(pos.x,pos.y + gravidade + contraGravidade);
	desenhar(figura.getPosition());
}

void Arbusto::obstaculizar(Jogador* j1) {
    j1->setLent(true);
    j1->setmodifiVelo(lentidao);
}