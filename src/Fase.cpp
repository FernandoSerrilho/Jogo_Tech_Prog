#include "Fase.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Chao.h"
using namespace Fases;

Fase::Fase(Jogador* j) :list_ents(), GC(j) {
	criarInmFaceis(j);
}

Fase::~Fase() {
	list_ents.limpar();
}

void Fase::criarInmFaceis(Jogador* j) {
	Inimigo::sementear();
	int MAX = rand() % 2 + 3;

	for (int i = 0; i < MAX;i++) {
		Drone* d1 = new Drone(NULL, "Texturas/Drone/drone_somente.png");
		d1->setPos(100.0f, 50.0f * i);
		d1->setJog(j);
		GC.incluirInimigo(d1);
		list_ents.incluir(d1);
	}
}

void Fase::criarPlataformas() {
	Inimigo::sementear();
	int MAX = 2;

	for (int i = 0;i < MAX;i++) {
		Plataforma* p = new Plataforma(sf::Vector2f(400.0f - 100 * i, 420.0f - 100 * i), sf::Vector2f(300.0f, 42.0f));
		GC.incluirObstaculo(p);
		list_ents.incluir(p);
	}
}
