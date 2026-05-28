#include "Fase.h"
#include "Drone.h"
using namespace Fases;

Fase::Fase() :list_ents(), GC(NULL) {
	list_ents.clear();
	criarInmFaceis();
}

Fase::~Fase() {}

void Fase::criarInmFaceis() {
	/*const int MAX = 5;

	list<sf::Vector2f> list_pos_drone;
	list_pos_drone.clear();
	sf::Vector2f pos(200.0f, 200.0f);
	for (int i = 0;i < 3;i++) {
		pos.y = 200 * i;
		list_pos_drone.push_back(pos);
	}

	while (MAX > 0) {
		Drone* d = new Drone()
	}*/
}