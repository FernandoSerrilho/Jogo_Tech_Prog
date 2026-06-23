//Link do sprite do tanque: https://opengameart.org/content/pixel-tank
//Link do sprite da bala: https://opengameart.org/content/weapon-icons-1
//Link do sprite do chão: https://opengameart.org/content/stone-ground
//Link do sprite do fundo: https://opengameart.org/content/starfield-background
//Link do sprite da mina terestre: https://drive.google.com/file/d/1eCCxQ479SYTTpjwk2PwgGPxOtp-_eV8o/view?usp=drive_link
//Agradecimentos ao canal GEGE++ do Youtube, por fornecer uma base para o respectivo arquivo: https://www.youtube.com/channel/UCUa8BOx2F3hlxgPcpZmnBnQ
//Agradecimentos ao canal Dev Felipe do Youtube, por fornecer uma base para o respectivo arquivo: https://www.youtube.com/@devfelipe8214

#include "FaseDois.h"
#include "Jogador.h"
#include "Chao.h"
#include "BackGround.h"
#include "MinaTerrestre.h"
#include "Soldado.h"
#include "Tanque.h"
#include "Projetil.h"
#include <iostream>

using namespace Gerenciadores;
using namespace Listas;
using namespace Fases;
using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

FaseDois::FaseDois(Jogador* j1,Jogador* j2):Fase(j1,j2),maxTanques(rand() % 4 + 3),maxMinas(rand() % 3 + 3) {
	num_fase = 2;
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
        incluirEntidade(t1);
    }

}

void FaseDois::criarProjeteis() {

		for (int i = 0; i < 25; i++) {
        	Projetil* b1 = new Projetil(sf::Vector2f(2500.0f, 2500.0f), "Texturas/Tanque/Bala.png");

        	b1->setAtivo(false); 
        	GC.IncluirProjetil(b1);
        	incluirEntidade(b1);
    	}

	
}

void FaseDois::gerenciarProjeteis() {

	Lista<Entidades::Entidade>::Iterador it = list_ents.begin();

	while (it != list_ents.end()) {
		Entidades::Entidade* e = *it;

		if (e && e->getVivo()) {
			Tanque* t1 = dynamic_cast<Tanque*>(e);

			if (t1 && t1->getpodeAtirar()) {

				Lista<Entidades::Entidade>::Iterador itBala = list_ents.begin();
				bool achouAtiva = false;

				while (itBala != list_ents.end() && !achouAtiva) {

					Entidades::Entidade* eBala = *itBala;

					if (eBala) {
						Projetil* b1 = dynamic_cast<Projetil*>(eBala);

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
		incluirEntidade(mT);
	}
}

void FaseDois::criarObstaculos() {
	criarPlataformas();
	criarMinasTerrestres();

}

void FaseDois::criarCenario() {
	Entidades::BackGround* b = new Entidades::BackGround("Texturas/BackGround/BackgroundF2.png");
	bgFase = b;
	Entidades::Chao* c = new Entidades::Chao("Texturas/Grama/Chao2.png");
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

void FaseDois::incluirProjetil(Projetil* p) {
    if (p) {
        GC.IncluirProjetil(p);
        incluirEntidade(p);
    }
}

void FaseDois::inicializar(Jogador* j1,Jogador* j2) {
	incluirEntidade(j1);
	if (j2 && j2->getVivo()) {incluirEntidade(j2);} 
	criarCenario();
	criarObstaculos();
	criarInimigos(j1,j2);
	criarProjeteis();
}

void FaseDois::carregarFase(std::ifstream& arquivo, Entidades::Personagens::Jogador* j1,Entidades::Personagens::Jogador* j2, bool& j2Ativo) {
 	limparGC();
    limparListEnts();

    std::vector<int> idsTanquesSave;
    std::vector<Tanque*> tanquesNovos;

    std::vector<int> idsTanqueDaBala;
    std::vector<Projetil*> balasPendentes;

    std::string tipoLido;
    while (arquivo >> tipoLido) {
        int id; float px, py, vx, vy; bool vivo;
        arquivo >> id >> px >> py >> vx >> vy >> vivo;

        if (carregarEntidadeemComum(tipoLido, id, px, py, vx, vy, vivo, arquivo, j1, j2, j2Ativo)) {
            continue;
        }
        else if (tipoLido == "Tanque") {
            int vidas, nivel; bool inv, podeAtirar; float cooldown;
            arquivo >> vidas >> nivel >> inv >> podeAtirar >> cooldown;

            Tanque* t = new Tanque("Texturas/Tanque/tanque.png");
            t->setPos(px, py);
            t->setVel(vx, vy);
            t->setVivo(vivo);
            t->setVidas(vidas);
            t->setNivelMaldade(nivel);
            t->setInvulneravel(inv);
            t->setPodeAtirar(podeAtirar);
            incluirInimigo(t);

            idsTanquesSave.push_back(id);
            tanquesNovos.push_back(t);
        }
        else if (tipoLido == "MinaTerrestre") {
            bool danoso; float tempoAtivacao, raio; bool tempoAtivo;
            arquivo >> danoso >> tempoAtivacao >> raio >> tempoAtivo;

            MinaTerrestre* m = new MinaTerrestre(sf::Vector2f(px, py), sf::Vector2f(29.0f, 10.0f));
            m->setPos(px, py);
            m->setVivo(vivo);
            m->setTempoAtivo(tempoAtivo);
            m->setraio(raio);
            incluirObstaculo(m);
        }
        else if (tipoLido == "Projetil") {
            bool ativo; int idTanqueSalvo;
            arquivo >> ativo >> idTanqueSalvo;

            Projetil* b = new Projetil(sf::Vector2f(px, py), "Texturas/Tanque/Bala.png");
            b->setPos(px, py);
            b->setVel(vx, vy);
            b->setVivo(vivo);
            b->setAtivo(ativo);
            incluirProjetil(b);

            if (idTanqueSalvo != -1) {
                idsTanqueDaBala.push_back(idTanqueSalvo);
                balasPendentes.push_back(b);
            }
        }
        else {
            std::string lixo;
            std::getline(arquivo, lixo);
        }
    }

    for (size_t i = 0; i < balasPendentes.size(); i++) {
        int idProcurado = idsTanqueDaBala[i];
        Tanque* tanqueEncontrado = nullptr;

        for (size_t j = 0; j < idsTanquesSave.size(); j++) {
            if (idsTanquesSave[j] == idProcurado) {
                tanqueEncontrado = tanquesNovos[j];
                break;
            }
        }

        if (tanqueEncontrado) {
            tanqueEncontrado->setPodeAtirar(false);
            tanqueEncontrado->adicionarBala(balasPendentes[i]);
            balasPendentes[i]->setTanque(tanqueEncontrado);
        }
    }

}

void FaseDois::desenhar() {
	bgFase->executar();
	chaoFase->executar();
	list_ents.desenhar();
}

bool FaseDois::statusInimigos() {
	return GC.listaInimigosStatus();
}