#include "Arbusto.h"
#include "Jogador.h"
#include "Inimigo.h"

using namespace Entidades::EntidadesPertinentes;
using namespace Obstaculos;
using namespace Personagens;

Arbusto::Arbusto():Obstaculo(), lentidao(0.3f) {}

Arbusto::Arbusto(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), lentidao((float)(rand() % 10) * 0.1f + 0.2f) {
	setFigura(tam);
	figura.setPosition(pos);
	setPos(pos.x,pos.y);
	setVel(0.0f,0.0f);
	setText("Texturas/Arbusto/Bush.png", figura);

	contraGravidade = -0.3f;
}

Arbusto::~Arbusto(){
	lentidao = -1;
}

void Arbusto::setLent(float lent) {lentidao = lent;}

void Arbusto::executar() {
	gravitar();
	desenhar(figura.getPosition());
}

void Arbusto::obstaculizar(Jogador* j1) {
    j1->setLent(true);
    j1->setmodifiVelo(lentidao);
}

void Arbusto::salvar() {
	if (buffer) {
		buffer << "Arbusto" << " ";
	}

	salvarDataBuffer();

	if (buffer) {
		buffer << lentidao << "\n";
	}

}