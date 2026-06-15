#include "Entidade.h"

using namespace Entidades;


Entidade::Entidade() : Ente(), pos(0.0f,500.0f), vel(5.0f, 5.0f),vivo(true),gravidade(0.3f),contraGravidade(0.0f) {}
Entidade::~Entidade() { vivo = false; }

sf::Vector2f Entidade::getPos() {return pos;}
sf::Vector2f Entidade::getVel() {return vel;}

void Entidade::setPos(float x, float y) {
    pos.x = x;
    pos.y = y;
    getFigura().setPosition(pos);
}

void Entidade::setVel(float vx, float vy) {

    vel.x = vx;
    vel.y = vy;

}

void Entidade::setVivo(bool v) { vivo = v;}

bool Entidade::getVivo() {return vivo;}






