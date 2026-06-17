#include "Projetil.h"
#include "Jogador.h"
#include "Tanque.h"

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;


Projetil::Projetil(sf::Vector2f posicao, const char* caminhoTextura) : EntidadePertinente() , ativo(true), pTq(nullptr) {
    setFigura(sf::Vector2f(26.0f, 11.0f));
    figura.setPosition(posicao);
    setText(caminhoTextura, figura);
    setPos(posicao.x,posicao.y);
}

Projetil::~Projetil() { pTq = nullptr;}

void Projetil::setTanque(Tanque* t) {pTq = t;}


void Projetil::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v--;
    pJ->setVidas(v);


    pJ->initInv();


    int vTq = pTq->getVidas();
    vTq++;
    pTq->setVidas(vTq);


    setAtivo(false);
    setPos(2500.0f,2500.0f);

}

void Projetil::mover() {

    setVel(-5.0f,0.0f);
    float posx = pos.x + vel.x;
    
    setPos(posx, pos.y);
    figura.setPosition(posx, pos.y);

    desenhar(pos);
}

bool Projetil::getAtivo() {return ativo;}
void Projetil::setAtivo(bool a) {ativo = a;}

void Projetil::executar() {


    if (pos.x < -50.0f || pos.x > 2000.0f || pos.y < -50.0f || pos.y > 1500.0f) {
        setAtivo(false);    
        setPos(2500.0f, 2500.0f);    
        return; 
    }

    mover();

}

