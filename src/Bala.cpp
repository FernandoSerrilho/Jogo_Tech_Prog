#include "Bala.h"
#include "Jogador.h"
#include <iostream>


using namespace Entidades;
using namespace Entidades::Personagens;



Bala::Bala(sf::Vector2f posicao,const char* caminhoTextura) : Projetil(), colisao(sf::Vector2f(20.0f,20.0f)){

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


    setAtivo(false);
    setPos(2500.0f,2500.0f);

}

sf::FloatRect Bala::getBounds() const {return colisao.getGlobalBounds();}

void Bala::mover() {

    setVel(-5.0f,0.0f);
    float posx = pos.x + vel.x;
    

    setPos(posx, pos.y);
    colisao.setPosition(posx, pos.y);

    desenhar(pos);

}

void Bala::executar() {


    if (pos.x < -50.0f || pos.x > 2000.0f || pos.y < -50.0f || pos.y > 1500.0f) {
        setAtivo(false);    
        setPos(2500.0f, 2500.0f);     
    }

    mover();

}