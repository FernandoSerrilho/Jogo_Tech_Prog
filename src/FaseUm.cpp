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
	int MAX = rand() % 3 + 3;

	for (int i = 0;i < MAX;i++) {
		sf::Vector2f p(0.0f, 0.0f);
		if (i < 1) {
			p.x = 950.0f;
			p.y = 1012.0f;
		}
		else if(i>=1 && i<3){
			p.x = 500.0f + 1000*(i-1);
			p.y = 883.0f;
		}
		else if (i >= 3) {
			p.x = 300.0f + 700 * (i - 3);
			p.y = 753.0f;
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
	BackGround* b = new BackGround("Texturas/BackGround/Fundo.png");
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

void FaseUm::desenhar() {
	list_ents.desenhar();
}