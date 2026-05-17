#include "Ente.h"

using namespace Gerenciadores;


Ente::Ente() : id(cont_id++) {}
Ente::~Ente() {}

void Ente::setGG(Gerenciador_Grafico* pG) {
    pGG = pG;
}

void Ente::desenhar() {

    if (pGG) {
    pGG->desenharEnte(this);
    }
}

int Ente::cont_id = 0;
Gerenciador_Grafico* Ente::pGG = NULL;