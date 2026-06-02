#include "FaseUm.h"
#include "Chao.h"
#include "BackGround.h"
using namespace Entidades;

FaseUm::FaseUm(Jogador* j1) : Fase(j1) {
	criarInimigos(j1);
	criarObstaculos();
	criarCenario();
	criarPlataformas();
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

}

void FaseUm::criarObstaculos() {
	criarPlataformas();
	criarObsMed();

}

void FaseUm::criarCenario() {
	Chao* c = new Chao("Texturas/Grama/Grama_QuadradoSemBorda.png");
	list_ents.incluir(c);
	BackGround* b = new BackGround();
	list_ents.incluir(b);
}

void FaseUm::executar() {
	list_ents.percorrer();
	GC.executar();
}