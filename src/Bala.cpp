#include "Bala.h"
#include "Jogador.h"
#include <iostream>


using namespace Entidades;
using namespace Entidades::Personagens;



Bala::Bala(sf::Vector2f posicao,const char* caminhoTextura) : Projetil(), colisao(sf::Vector2f(15.0f,15.0f)){

    setText(caminhoTextura, colisao);
    setPos(posicao.x,posicao.y);
    colisao.setPosition(posicao);

}

Bala::~Bala() {}


void Bala::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v -= 2;
    pJ->setVidas(v);


    pJ->initInv();

}

sf::FloatRect Bala::getBounds() const {return colisao.getGlobalBounds();}

void Bala::mover() {

    float posx = pos.x + vel.x;
    

    setPos(posx, pos.y);
    colisao.setPosition(posx, pos.y);

    desenhar(pos);


    std::cout << "pos bala:" << pos.x << ", " << pos.y << std::endl;
}

void Bala::executar() {

    mover();

}