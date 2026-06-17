#include "Obstaculo.h"

using namespace Entidades;
using namespace Obstaculos;

Obstaculo::Obstaculo(bool flag) : EntidadePertinente(), danoso(flag){}
Obstaculo::~Obstaculo() { danoso = false; }
