#include "Entidade.h"

using namespace Entidades;


Entidade::Entidade() : EntidadeBase(),vel(5.0f, 5.0f),gravidade(0.3f),contraGravidade(0.0f) {}
Entidade::~Entidade() { vivo = false; }

sf::Vector2f Entidade::getVel() {return vel;}

void Entidade::setVel(float vx, float vy) {

    vel.x = vx;
    vel.y = vy;

}






