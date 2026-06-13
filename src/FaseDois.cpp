#include "FaseDois.h"
#include "Chao.h"
#include "BackGround.h"
#include "MinaTerrestre.h"
#include "Soldado.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

FaseDois::FaseDois(Jogador* j1,Jogador* j2):Fase(j1,j2),maxTanques(rand()%3+3),pBG(nullptr) {
	limparGC();
	limparListEnts();
	inicializar(j1,j2);
}

FaseDois::~FaseDois() { pBG = nullptr; }

void FaseDois::criarInimigos(Jogador* j1,Jogador* j2) {
	criarDrones(j1,j2);
	criarTanques();
}

void FaseDois::criarTanques() {
	
}

void FaseDois::criarMinasTerrestres() {
	Entidades::Personagens::Inimigos::Inimigo::sementear();
	int MAX = rand() % 3 + 3;

	for (int i = 0;i < MAX;i++) {
		sf::Vector2f p(0.0f, 0.0f);
		if (i < 1) {
			p.x = 950.0f;
			p.y = 1019.0f;
		}
		else if (i >= 1 && i < 3) {
			p.x = 500.0f + 1000 * (i - 1);
			p.y = 890.0f;
		}
		else if (i >= 3) {
			p.x = 300.0f + 700 * (i - 3);
			p.y = 760.0f;
		}

		MinaTerrestre* mT = new MinaTerrestre(sf::Vector2f(p.x, p.y), sf::Vector2f(29.0f, 10.0f));
		GC.incluirObstaculo(mT);
		list_ents.incluir(mT);
	}
}

void FaseDois::criarObstaculos() {
	criarPlataformas();
	criarMinasTerrestres();

}

void FaseDois::criarCenario() {
	pBG= new BackGround("Texturas/BackGround/BackgroundF2.png");
	Chao* c = new Chao("Texturas/Grama/Grama_QuadradoSemBorda.png");
	GC.setChao(c);
	list_ents.incluir(c);
}

void FaseDois::executar() {
	pBG->executar();
	GC.executar();
	list_ents.percorrer();
}

void FaseDois::inicializar(Jogador* j1,Jogador* j2) {
	criarCenario();
	criarObstaculos();
	criarInimigos(j1,j2);
}

void FaseDois::desenhar() {
	pBG->executar();
	list_ents.desenhar();
}

bool FaseDois::statusInimigos() {
	return GC.listaInimigosStatus();
}