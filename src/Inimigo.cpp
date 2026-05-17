#include "Inimigo.h"
#include "Jogador.h"

using namespace Personagens;


Inimigo::Inimigo() : Personagem(), nivel_maldade(0) {

    sementear();
    nivel_maldade = rand()%10 + 1;

}
Inimigo::~Inimigo() {}

void Inimigo::sementear() {

    rand(); Sleep(100); time_t t;
    srand((unsigned) time(&t)); rand();

}