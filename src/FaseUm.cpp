//Link do sprite do chão: https://imdaniell.itch.io/dirt-walls-and-platforms
// Link do sprite do background: https://gamer247.itch.io/sky
//Link do sprite do soldado: https://opengameart.org/content/green-soldier
//Link do sprite do arbusto: https://karsiori.itch.io/free-pixel-art-bush-pack

#include "FaseUm.h"
#include "Jogador.h"
#include "Chao.h"
#include "BackGround.h"
#include "Arbusto.h"
#include "Soldado.h"

using namespace Gerenciadores;
using namespace Listas;
using namespace Fases;
using namespace Entidades;
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
	Entidades::Personagens::Inimigos::Inimigo::sementear();

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
	Entidades::Personagens::Inimigos::Inimigo::sementear();

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

void FaseUm::carregarFase(std::ifstream& arquivo, Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2, bool& j2Ativo) {

	limparGC();
    limparListEnts();

    std::string tipoLido;
    while (arquivo >> tipoLido) {
        int id; float px, py, vx, vy; bool vivo;
        arquivo >> id >> px >> py >> vx >> vy >> vivo;

        if (carregarEntidadeemComum(tipoLido, id, px, py, vx, vy, vivo, arquivo, j1, j2, j2Ativo)) {
            continue;
        }
        else if (tipoLido == "Soldado") {
            int vidas, nivel; bool inv, parado; float tempoParado;
            arquivo >> vidas >> nivel >> inv >> parado >> tempoParado;

            Soldado* s = new Soldado(sf::Vector2f(px, py), "Texturas/Soldado/SoldadoInimigo.png");
            s->setPos(px, py);
            s->setVel(vx, vy);
            s->setVivo(vivo);
            s->setVidas(vidas);
            s->setNivelMaldade(nivel);
            s->setInvulneravel(inv);
            s->setParado(parado);
            incluirInimigo(s);
        }
        else if (tipoLido == "Arbusto") {
            bool danoso; float lentidao;
            arquivo >> danoso >> lentidao;

            Arbusto* a = new Arbusto(sf::Vector2f(px, py), sf::Vector2f(29.0f, 17.0f));
            a->setPos(px, py);
            a->setVivo(vivo);
            incluirObstaculo(a);
        }
        else {
            std::string lixo;
            std::getline(arquivo, lixo);
        }
    }
}


void FaseUm::desenhar() {
	bgFase->executar();
	chaoFase->executar();
	list_ents.desenhar();
}

bool FaseUm::statusInimigos() {
	return GC.listaInimigosStatus();
}