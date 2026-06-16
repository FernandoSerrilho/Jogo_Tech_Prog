#include "FaseDois.h"
#include "Chao.h"
#include "BackGround.h"
#include "MinaTerrestre.h"
#include "Soldado.h"
#include "Tanque.h"
#include "Bala.h"
#include <iostream>

using namespace Gerenciadores;
using namespace Listas;
using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

FaseDois::FaseDois(Jogador* j1,Jogador* j2):Fase(j1,j2),maxTanques(rand() % 4 + 3),maxMinas(rand() % 3 + 3) {
	limparGC();
	limparListEnts();
	inicializar(j1,j2);
}

FaseDois::~FaseDois() {}

void FaseDois::criarInimigos(Jogador* j1,Jogador* j2) {
	criarDrones(j1,j2);
	criarTanques();
}

void FaseDois::criarTanques() {

		for (int i = 0; i < maxTanques; i++) {
        Tanque* t1 = new Tanque("Texturas/Tanque/tanque.png");
        sf::Vector2f p(0.0f, 0.0f);

        if (i < 2) {
            p.x = 500.0f + 1000.0f * i;
            p.y = 800.0f;
        }
        else if (i >= 2 && i < 4) {
            p.x = 300.0f + 700.0f * (i - 2);
            p.y = 660.0f;
        }
        else {
            p.x = 510.0f + 1000.0f * (i - 4);
            p.y = 530.0f;
        }

        t1->setPos(p.x, p.y);

        GC.incluirInimigo(t1);
        list_ents.incluir(t1);
    }

}

void FaseDois::criarProjeteis() {

		for (int i = 0; i < 25; i++) {
        	Bala* b1 = new Bala(sf::Vector2f(2500.0f, 2500.0f), "Texturas/Tanque/Bala.png");

        	b1->setAtivo(false); 
        	GC.IncluirProjetil(b1);
        	list_ents.incluir(b1);
    	}

	
}

void FaseDois::gerenciarProjeteis() {

	Lista<Entidade>::Iterador it = list_ents.begin();

	while (it != list_ents.end()) {
		Entidade* e = *it;

		if (e && e->getVivo()) {
			Tanque* t1 = dynamic_cast<Tanque*>(e);

			if (t1 && t1->getpodeAtirar()) {

				Lista<Entidade>::Iterador itBala = list_ents.begin();
				bool achouAtiva = false;

				while (itBala != list_ents.end() && !achouAtiva) {

					Entidade* eBala = *itBala;

					if (eBala) {
						Bala* b1 = dynamic_cast<Bala*>(eBala);

						if (b1 && !b1->getAtivo()) {

							b1->setPos(t1->getPos().x,t1->getPos().y);
							b1->setAtivo(true);

							t1->adicionarBala(b1);
							b1->setTanque(t1);
							t1->setPodeAtirar(false);

							achouAtiva = true;

						}
					}
					++itBala;
				}
			}
		}
		++it;
	}
}

void FaseDois::criarMinasTerrestres() {
	Entidades::Personagens::Inimigos::Inimigo::sementear();

	for (int i = 0;i < maxMinas;i++) {
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
	BackGround* b = new BackGround("Texturas/BackGround/BackgroundF2.png");
	bgFase = b;
	Chao* c = new Chao("Texturas/Grama/Chao2.png");
	GC.setChao(c);
	chaoFase = c;
}

void FaseDois::executar() {
	bgFase->executar();
	chaoFase->executar();
	gerenciarProjeteis();
	list_ents.percorrer();
	GC.executar();
}

void FaseDois::inicializar(Jogador* j1,Jogador* j2) {
	criarCenario();
	criarObstaculos();
	criarInimigos(j1,j2);
	criarProjeteis();
}

void FaseDois::desenhar() {
	bgFase->executar();
	chaoFase->executar();
	list_ents.desenhar();
}

bool FaseDois::statusInimigos() {
	return GC.listaInimigosStatus();
}