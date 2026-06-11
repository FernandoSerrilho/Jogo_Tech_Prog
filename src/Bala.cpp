#include "Bala.h"
#include "Jogador.h"


using namespace Entidades;
using namespace Entidades::Personagens;



Bala::Bala(const char* caminhoTextura = "", sf::Vector2f posicao) : Projetil(), colisao(sf::Vector2f(15.0f,15.0f)){

    setText(caminhoTextura, colisao);
    setPos(posicao.x,posicao.y);
    colisao.setPosition(posicao);

}

Bala::~Bala() {}


void Bala::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v -= 3;
    pJ->setVidas(v);


    pJ->initInv();

}

void Bala::mover() {

    float posx = pos.x + vel.x;
    

    setPos(posx, pos.y);
    colisao.setPosition(posx, pos.y);

}

void Bala::executar() {

    mover();

}