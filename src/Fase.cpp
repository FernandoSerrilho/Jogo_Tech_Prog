#include "Fase.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Chao.h"
#include "Jogador.h"
#include <iostream>
#include <cstdio>

using namespace Fases;
using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Inimigos;

Fase::Fase(Jogador* j1,Jogador* j2) :list_ents(), GC(j1,j2),maxDrones(rand() % 3 + 5),maxPlataformas(rand() % 3 + 9),bgFase(nullptr),chaoFase(nullptr) , num_fase(0) {

}

Fase::~Fase() { bgFase = nullptr; }

void Fase::incluirEntidade(Entidade* e) {
	list_ents.incluir(e);
}

void Fase::criarDrones(Jogador* j1,Jogador* j2) {
	Inimigo::sementear();

	for (int i = 0; i < maxDrones;i++) {
		Drone* d1 = new Drone(NULL,NULL, "Texturas/Drone/drone_somente.png");
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
		d1->setJog(j1,0);
		d1->setJog(j2, 1);
		GC.incluirInimigo(d1);
		incluirEntidade(d1);

		std::cout <<"drone id:" << d1->getID() << std::endl;
	}
}

void Fase::criarPlataformas() {
	Inimigo::sementear();

	for (int i = 0;i < maxPlataformas;i++) {
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
		incluirEntidade(p1);
	}
}

void Fase::limparGC() {
	GC.limparListas();
}

void Fase::limparListEnts() {
	list_ents.limpar();
}

void Fase::salvarFase() {

	std::remove("save.txt");

	GS.abrirArquivo("save.txt");
	std::ofstream& buffer = Gerenciador_Salvamento::getArquivo();

	if (buffer) {
		buffer << num_fase << "\n";
	}

	Lista<Entidade>::Iterador it = list_ents.begin();
	while (it != list_ents.end()) {

		Entidade* e = *it;

		if (e) {
		EntidadePertinente* eP = dynamic_cast<EntidadePertinente*>(e);

		if (eP) {
			eP->salvar();
		}
		}

		++it;
	}

	GS.fecharArquivo();

}