#include "EntidadeBase.h"

EntidadeBase::EntidadeBase() : Ente(), pos(0.0f,500.0f),vivo(true){}
EntidadeBase::~EntidadeBase() { vivo = false; }

sf::Vector2f EntidadeBase::getPos() {return pos;}

void EntidadeBase::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
    figura.setPosition(x,y);
}

void EntidadeBase::setVivo(bool v) { vivo = v;}

bool EntidadeBase::getVivo() {return vivo;}






