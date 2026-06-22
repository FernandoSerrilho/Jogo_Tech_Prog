#include "Fase.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Jogador.h"
#include "Projetil.h"
#include "Entidade.h"
#include <iostream>
#include <cstdio>

using namespace Fases;
using namespace Listas;
using namespace Entidades;
using namespace EntidadesPertinentes;
using namespace Personagens;
using namespace Obstaculos;
using namespace Inimigos;

Fase::Fase(Jogador* j1,Jogador* j2) :list_ents(), GC(j1,j2),maxDrones(rand() % 3 + 5),maxPlataformas(rand() % 3 + 9),bgFase(nullptr),chaoFase(nullptr) , num_fase(0) {

}

Fase::~Fase() { bgFase = nullptr; chaoFase = nullptr; }

void Fase::incluirEntidade(Entidade* e) {
	list_ents.incluir(e);
}

void Fase::incluirInimigo(Inimigo* i) {
    if (i) {
        GC.incluirInimigo(i);
        incluirEntidade(i);
    }
}

void Fase::incluirObstaculo(Obstaculo* o) {
    if (o) {
        GC.incluirObstaculo(o);
        incluirEntidade(o);
    }
}

//void Fase::incluirProjetil(Projetil* p) {
   // if (p) {
    //    GC.IncluirProjetil(p);
   //     incluirEntidade(p);
  ///  }
//}

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

bool Fase::carregarEntidadeemComum(const std::string& tipoLido, int id, float px, float py, float vx, float vy, bool vivo,std::ifstream& arquivo, Jogador* j1, Jogador* j2, bool& j2Ativo) {
 if (tipoLido == "Jogador") {
        int vidas, num_jog, pontos;
        bool pulavel, atacando, podeAtacar, lento, invulneravel, olhandoEsquerda;
        std::string nomeLido;

        arquivo >> vidas;
        arquivo >> nomeLido >> num_jog >> pontos >> pulavel >> atacando >> podeAtacar >> lento >> invulneravel >> olhandoEsquerda;

        Jogador* j = (num_jog == 1) ? j1 : j2;
        if (j) {
            j->setPos(px, py);
            j->setVel(vx, vy);
            j->setVivo(vivo);
            j->setVidas(vidas);
            j->setNome(nomeLido);
            j->setPontos(pontos);
            j->setPulavel(pulavel);
            j->setLent(lento);
            incluirEntidade(j);

            if (num_jog == 2) { j2Ativo = true; }
        }
        return true;
    }
    else if (tipoLido == "Drone") {
        int vidas, nivel; bool inv, emKnock;
        arquivo >> vidas >> nivel >> inv >> emKnock;

        Drone* d = new Drone(j1, j2, "Texturas/Drone/drone_somente.png");
        d->setPos(px, py);
        d->setVel(vx, vy);
        d->setVivo(vivo);
        d->setVidas(vidas);
        d->setNivelMaldade(nivel);
        d->setInvulneravel(inv);
        d->setEmKnockback(emKnock);
        incluirInimigo(d);
        return true;
    }
    else if (tipoLido == "Plataforma") {
        bool danoso; int altura;
        arquivo >> danoso >> altura;

        Plataforma* p = new Plataforma(sf::Vector2f(px, py), sf::Vector2f(300.0f, 42.0f));
        p->setPos(px, py);
        p->setVivo(vivo);
        incluirObstaculo(p);
        return true;
    }

    return false;
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