#include "Plataforma.h"
#include "Jogador.h"
#include "Inimigo.h"
#include <iostream>
using namespace std;

using namespace Entidades::EntidadesPertinentes;
using namespace Personagens;
using namespace Inimigos;
using namespace Obstaculos;

Plataforma::Plataforma() :Obstaculo(), altura(rand()%10 + 25){

}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(), altura(rand() % 10 + 25) {
    tam.y = (float)altura;
    setFigura(tam);
    setPos(pos.x,pos.y);
    setVel(0.0f,0.0f);
    figura.setPosition(pos);
    setText("Texturas/Grama/QuadradoPlat.png", figura);
    contraGravidade = -0.3f;
}

Plataforma::~Plataforma() { altura = -1; }

void Plataforma::obstaculizar(Jogador* j1) {

    sf::Vector2f pos = j1->getPos();

    sf::FloatRect boundsj = j1->getBounds();
    sf::FloatRect boundsp = getBounds();

    if (boundsj.top + boundsj.height <= (boundsp.top + 10.0f)) {
        j1->setPos(pos.x, boundsp.top - boundsj.height);

        j1->setVel(j1->getVel().x, 0.0f);

        j1->setPulavel(true);
    }
    else if (boundsj.top >= boundsp.top + boundsp.height - 10.0f) {
        j1->setPos(pos.x, boundsp.top + boundsp.height);

        j1->setVel(j1->getVel().x, 0.0f);
    }
    else if (boundsj.left + boundsj.width <= boundsp.left + 10.0f) {
        j1->setPos(boundsp.left - boundsj.width, pos.y);
    }
    else {
        j1->setPos(boundsp.left + boundsp.width, pos.y);

    }

}

void Plataforma::obstaculizar(Inimigo* i1) {
    sf::Vector2f pos = i1->getPos();

    sf::FloatRect boundsj = i1->getBounds();
    sf::FloatRect boundsp = getBounds();


    sf::Vector2f velI = i1->getVel();

    //colisao com o topo da plataforma
    if (boundsj.top + boundsj.height <= (boundsp.top + 10.0f)) {
        i1->setPos(pos.x, boundsp.top - boundsj.height);
        i1->setVel(i1->getVel().x, 0.0f);
    }
    //colisao por baixo da plataforma
    else if (boundsj.top >= boundsp.top + boundsp.height - 10.0f) {
        i1->setPos(pos.x, boundsp.top + boundsp.height);
        i1->setVel(i1->getVel().x, 0.0f);
    }
    //colisao pela esquerda
    else if (boundsj.left + boundsj.width <= boundsp.left + 10.0f) {
        i1->setPos(boundsp.left - boundsj.width, pos.y);
    }
    //colisao pela direita
    else {
        i1->setPos(boundsp.left + boundsj.width, pos.y);
    }
}

void Plataforma::executar() {
    sf::Vector2f posP = getPos();
    gravitar();
    setPos(posP.x,posP.y);
    desenhar(figura.getPosition());
}

void Plataforma::salvar() {

    if (buffer) {
		buffer << "Plataforma" << " ";
	}

    salvarDataBuffer();

    if (buffer) {
        buffer << altura << "\n";
    }

}