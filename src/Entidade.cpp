#include "Entidade.h"
using namespace Entidades;

Entidade::Entidade() : Ente(), pos(0.0f,500.0f),vivo(true){}
Entidade::~Entidade() { vivo = false; }

sf::Vector2f Entidade::getPos() {return pos;}

void Entidade::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
    figura.setPosition(x,y);
}

void Entidade::setVivo(bool v) { vivo = v;}

bool Entidade::getVivo() {return vivo;}


