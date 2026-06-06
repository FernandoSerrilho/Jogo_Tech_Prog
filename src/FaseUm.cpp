#include "FaseUm.h"
#include "Chao.h"
#include "BackGround.h"
#include "Arbusto.h"
using namespace Entidades;

FaseUm::FaseUm(Jogador* j1) : Fase(j1) {
}

FaseUm::~FaseUm() {

}

void FaseUm::criarInimigos(Jogador* j) {
	criarInmFaceis(j);
	criarIniMed();
}

void FaseUm::criarIniMed() {

}

void FaseUm::criarObsMed() {
	Inimigo::sementear();
	int MAX = /*rand() % 2 + */ 3;

	for (int i = 0;i < MAX;i++) {
		sf::Vector2f p(0.0f, 0.0f);
		if (i < 2) {
			p.x = 400.0f + 400.0f * i;
			p.y = 1012.0f;
		}
		else {
			p.x = 600.0f;
			p.y = 883.0f;
		}

			Arbusto* a = new Arbusto(sf::Vector2f(p.x,p.y), sf::Vector2f(29.0f, 17.0f));
			GC.incluirObstaculo(a);
			list_ents.incluir(a);
	}

}

void FaseUm::criarObstaculos() {
	criarPlataformas();
	criarObsMed();

}

void FaseUm::criarCenario() {
	BackGround* b = new BackGround();
	list_ents.incluir(b);
	Chao* c = new Chao("Texturas/Grama/Grama_QuadradoSemBorda.png");
	GC.setChao(c);
	list_ents.incluir(c);
}

void FaseUm::executar() {
	list_ents.percorrer();
	GC.executar();
}

void FaseUm::inicializar(Jogador* j1) {
	criarCenario();
	criarObstaculos();
	criarPlataformas();
	criarInimigos(j1);


}