#include "Projetil.h"


using namespace Entidades;



Projetil::Projetil() : EntidadePertinente() , ativo(true) {
}

Projetil::~Projetil() {}

bool Projetil::getAtivo() {return ativo;}

void Projetil::setAtivo(bool a) {ativo = a;}

void Projetil::executar() {}