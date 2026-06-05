#include "Entidade.h"

using namespace Entidades;


Entidade::Entidade() : Ente(), pos(0.0f,500.0f), vel(5.0f, 5.0f) {}
Entidade::~Entidade() {}

sf::Vector2f Entidade::getPos() {return pos;}
sf::Vector2f Entidade::getVel() {return vel;}

void Entidade::setPos(float x, float y) {

    pos.x = x;
    pos.y = y;

}

void Entidade::setVel(float vx, float vy) {

    vel.x = vx;
    vel.y = vy;

}






