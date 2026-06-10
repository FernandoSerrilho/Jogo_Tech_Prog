#include "Personagem.h"

using namespace Entidades::Personagens;

Personagem::Personagem(): Entidade(), num_vidas(3) {}
Personagem::~Personagem() { num_vidas = -1; }


