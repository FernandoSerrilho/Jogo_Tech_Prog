#include "Plataforma.h"
#include "Jogador.h"
#include "Inimigo.h"
#include <iostream>
using namespace std;

using namespace Obstaculos;

Plataforma::Plataforma() :Obstaculo(), altura(0), colisao(sf::Vector2f(200.0f, (float)altura)) {

}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(), colisao(sf::Vector2f(tam)), altura((int)pos.y) {
    InitColi(tam, pos);
    InitText();
}

void Plataforma::InitText() {
    setText("Texturas/Grama/Grama_QuadradoSemBorda.png", colisao);
}


Plataforma::~Plataforma() {}
sf::FloatRect Plataforma::getBounds() const {
    return colisao.getGlobalBounds();
}

void Plataforma::setDim(sf::Vector2f dim) {
    colisao.setSize(dim);
}

void Plataforma::setPos(sf::Vector2f pos) {
    colisao.setPosition(pos);
    Entidade::setPos(pos.x,pos.y);
}

void Plataforma::InitColi(sf::Vector2f dim, sf::Vector2f pos) {
    setDim(dim);
    setPos(pos);
}

sf::RectangleShape Plataforma::getColi() {
    return colisao;
}



void Plataforma::obstaculizar(Jogador* j1) {

    sf::Vector2f pos = j1->getPos();

    sf::FloatRect boundsj = j1->getBounds();
    sf::FloatRect boundsp = getBounds();

    //colisao com o topo da plataforma
    if (boundsj.top + boundsj.height <= (boundsp.top + 10.0f)) {
        j1->setPos(pos.x, boundsp.top - boundsj.height);

        j1->setVel(j1->getVel().x, 0.0f);

        j1->setPulavel(true);
    }
    //colisao por baixo da plataforma
    else if (boundsj.top >= boundsp.top + boundsp.height - 10.0f) {
        j1->setPos(pos.x, boundsp.top + boundsp.height);

        j1->setVel(j1->getVel().x, 0.0f);
    }
    //colisao pela esquerda
    else if (boundsj.left + boundsj.width <= boundsp.left + 10.0f) {
        j1->setPos(boundsp.left - boundsj.width, pos.y);
    }
    //colisao pela direita
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

    i1->setVel(velI.x,velI.y);

}

void Plataforma::executar() {
    desenhar(colisao.getPosition());
}