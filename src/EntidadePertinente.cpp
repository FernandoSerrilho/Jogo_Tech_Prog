#include "EntidadePertinente.h"

using namespace Entidades;


EntidadePertinente::EntidadePertinente() : Entidade(),vel(5.0f, 5.0f),gravidade(0.3f),contraGravidade(0.0f) {}
EntidadePertinente::~EntidadePertinente() { vivo = false; }

sf::Vector2f EntidadePertinente::getVel() {return vel;}

void EntidadePertinente::setVel(float vx, float vy) {

    vel.x = vx;
    vel.y = vy;

}


void EntidadePertinente::gravitar() {

    float acel_resultante = gravidade + contraGravidade;

    // t = 1.0f
     // y = y0 + v0t + (at²)/2
    pos.y += vel.y + (acel_resultante/2.0f);
    // v = v0 + at
    vel.y += acel_resultante;


}





