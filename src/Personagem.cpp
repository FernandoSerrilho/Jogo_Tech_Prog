#include "Personagem.h"

using namespace Entidades::Personagens;

Personagem::Personagem(int vidas): Entidade(), num_vidas(vidas) {}
Personagem::~Personagem() { num_vidas = -1; }
void Personagem::setVidas(int v) { num_vidas = v; }
int Personagem::getVidas() { return num_vidas; }


