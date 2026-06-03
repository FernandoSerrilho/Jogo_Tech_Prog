#include "FaseUm.h"
#include "Chao.h"
#include "BackGround.h"
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