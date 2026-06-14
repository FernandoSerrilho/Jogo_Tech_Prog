#include "Obstaculo.h"

using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(bool flag) : Entidade(), danoso(flag){}
Obstaculo::~Obstaculo() { danoso = false; }
