#include "Entidade.h"

using namespace Entidades;


Entidade::Entidade() : Ente(), pos(0.0f,550.0f), vel(5.0f, 5.0f) {}
Entidade::~Entidade() {}


sf::Vector2f Entidade::getPos() {return pos;}








