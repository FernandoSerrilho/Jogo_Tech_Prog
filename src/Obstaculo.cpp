#include "Obstaculo.h"

using namespace Entidades::EntidadesPertinentes;
using namespace Obstaculos;

Obstaculo::Obstaculo(bool flag) : EntidadePertinente(), danoso(flag){}
Obstaculo::~Obstaculo() { danoso = false; }


void Obstaculo::salvarDataBuffer() {

    EntidadePertinente::salvarDataBuffer();

    if (buffer) {
        buffer << danoso << " ";
    }

}