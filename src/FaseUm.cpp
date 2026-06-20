#include "FaseUm.h"
#include "Jogador.h"
#include "Chao.h"
#include "BackGround.h"
#include "Arbusto.h"
#include "Soldado.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Fases;
using namespace Entidades::EntidadesPertinentes;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

FaseUm::FaseUm(Jogador* j1,Jogador* j2) : Fase(j1,j2),maxSoldados(rand() % 4 + 3),maxArbustos(rand() % 3 + 3) {
	num_fase = 1;
	limparGC();
	limparListEnts();
	inicializar(j1,j2);
}

FaseUm::~FaseUm() {

}

void FaseUm::criarInimigos(Jogador* j1,Jogador* j2) {
	criarDrones(j1,j2);
	criarSoldados();
}

void FaseUm::criarSoldados() {
	Entidades::EntidadesPertinentes::Personagens::Inimigos::Inimigo::sementear();

	sf::Vector2f p(0.0f, 0.0f);

	for (int i = 0;i < maxSoldados;i++) {
		if (i < 2) {
			p.x = 700.0f + 400 * i;
			p.y = 957.0f;
		}

		else if (i >= 2 && i < 4) {
			p.x = 520.0f + 1000.0f * (i - 2);
			p.y = 835.0f;
		}
		else if (i >= 4) {
			p.x = 510.0f + 1000.0f * (i - 4);
			p.y = 570.0f;
		}

		Soldado* s = new Soldado(p, "Texturas/Soldado/SoldadoInimigo.png");
		s->setPos(p.x, p.y);
		GC.incluirInimigo(s);
		incluirEntidade(s);
	}
}

void FaseUm::criarArbustos() {
	Entidades::EntidadesPertinentes::Personagens::Inimigos::Inimigo::sementear();

	for (int i = 0;i < maxArbustos;i++) {
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
			incluirEntidade(a);
	}
}

void FaseUm::criarObstaculos() {
	criarPlataformas();
	criarArbustos();

}

void FaseUm::criarCenario() {
	Entidades::BackGround* b = new Entidades::BackGround("Texturas/BackGround/Fundo.png");
	bgFase = b;
	Entidades::Chao* c = new Entidades::Chao("Texturas/Grama/Grama_QuadradoSemBorda.png");
	GC.setChao(c);
	chaoFase = c;
}

void FaseUm::executar() {
	bgFase->executar();
	chaoFase->executar();
	GC.executar();
	list_ents.percorrer();
}

void FaseUm::inicializar(Jogador* j1,Jogador* j2) {
	incluirEntidade(j1);
	if (j2) {incluirEntidade(j2);}
	criarCenario();
	criarObstaculos();
	criarInimigos(j1,j2);
}

void FaseUm::desenhar() {
	bgFase->executar();
	chaoFase->executar();
	list_ents.desenhar();
}

bool FaseUm::statusInimigos() {
	return GC.listaInimigosStatus();
}