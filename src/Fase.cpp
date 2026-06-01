#include "Fase.h"
#include "Drone.h"
using namespace Fases;

Fase::Fase() :list_ents(), GC(NULL) {
	criarInmFaceis();
}

Fase::~Fase() {
	list_ents.limpar();
}

void Fase::criarInmFaceis() {
	const int MAX = 5;

	for (int i = 0; i < MAX;i++) {
		Drone* d1 = new Drone();
		d1->setPos(100.0f, 50.0f * i);
		list_ents.incluir(d1);
	}
}