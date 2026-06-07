#include "Fase.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Chao.h"
using namespace Fases;

Fase::Fase(Jogador* j) :list_ents(), GC(j) {

}

Fase::~Fase() {
	list_ents.limpar();
}

void Fase::criarInmFaceis(Jogador* j) {
	Inimigo::sementear();
	int MAX = rand() % 3 + 5;

	for (int i = 0; i < MAX;i++) {
		Drone* d1 = new Drone(NULL, "Texturas/Drone/drone_somente.png");
		sf::Vector2f p(0.0f, 0.0f);
		if (i < 2) {
			p.x = 500.0f + 1000.0f * i;
			p.y = 850.0f;
		}
		else if (i >= 2 && i < 5) {
			p.x = 200.0f + 700.0f * (i - 2);
			p.y = 710.0f;
		}

		else if (i >= 5 && i < 7) {
			p.x = 400.0f + 1000.0f * (i - 5);
			p.y = 580.0f;
		}
		else if (i >= 7) {
			p.x = 200.0f + 700.0f * (i - 7);
			p.y = 480.0f;
		}
		d1->setPos(p.x, p.y);
		d1->setJog(j);
		GC.incluirInimigo(d1);
		list_ents.incluir(d1);
	}
}

void Fase::criarPlataformas() {
	Inimigo::sementear();
	int MAX = rand()%3 + 9;

	for (int i = 0;i < MAX;i++) {
		sf::Vector2f p(0.0f, 0.0f);
		if (i < 2) {
			p.x = 400.0f + 1000.0f * i;
			p.y = 900.0f;
		}
		else if (i>=2 && i<5){
			p.x = 200.0f + 700.0f*(i-2);
			p.y = 770.0f;
		}

		else if (i >= 5 && i<7) {
			p.x = 400.0f + 1000.0f * (i-5);
			p.y = 640.0f;
		}
		else if (i>= 7 && i<10) {
			p.x = 200.0f + 700.0f * (i - 7);
			p.y = 510.0f;
		}
		else if (i >=10) {
			p.x = 400.0f + 1000.0f * (i - 10);
			p.y = 380.0f;
		}
		Plataforma* p1 = new Plataforma(sf::Vector2f(p.x,p.y), sf::Vector2f(300.0f, 42.0f));
		GC.incluirObstaculo(p1);
		list_ents.incluir(p1);
	}
}
