#include "Inimigo.h"
#include "Jogador.h"
#include <Windows.h>

using namespace Entidades::EntidadesPertinentes::Personagens::Inimigos;


Inimigo::Inimigo() : Personagem(), nivel_maldade(0) , invulneravel(false),pontosDados(0){
    nivel_maldade = rand()%10 + 1;
}
Inimigo::~Inimigo() { nivel_maldade = -1; invulneravel = false; }

void Inimigo::sementear() {

    rand(); Sleep(100); time_t t;
    srand((unsigned) time(&t)); rand();

}

bool Inimigo::getInvulneravel() const { return invulneravel; }
void Inimigo::setInvulneravel(bool inv) { invulneravel = inv; }
sf::Clock& Inimigo::getRelogioInv() { return relogioinv; }
int Inimigo::getPontos() { return pontosDados; }


void Inimigo::salvarDataBuffer() {

    EntidadePertinente::salvarDataBuffer();

    if (buffer) {
        buffer << nivel_maldade << " " << invulneravel << " ";
    }
}