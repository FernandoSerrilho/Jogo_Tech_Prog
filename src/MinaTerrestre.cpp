#include "MinaTerrestre.h"
#include "Inimigo.h"
#include "Jogador.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

MinaTerrestre::MinaTerrestre() :Obstaculo(true), tempoAtivacao(0.6f), raio(rand() % 8 + 25.0f), tempoAtivo(false) { contraGravidade = -0.3f; }

MinaTerrestre::MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), tempoAtivacao(0.6f),raio(rand()% 8 + 15.0f), tempoAtivo(false) {
	setFigura(tam);
	figura.setPosition(pos);
	setPos(pos.x, pos.y);
	explosao.setSize(sf::Vector2f(raio,raio));
	explosao.setPosition(pos);
	setText("Texturas/Mina/MinaTerrestre.png", figura);
	contraGravidade = -0.3f;
}

MinaTerrestre::~MinaTerrestre(){
	tempoAtivo = false;
	raio = -1;
}

void MinaTerrestre::obstaculizar(Jogador* J){
	if (!tempoAtivo) {
		tempoAtivo = true;
		tempoExplosao.restart();
	}

	float tempo = tempoExplosao.getElapsedTime().asSeconds();
	if (tempo > 0.6f && tempo <= 0.7f) {
		if (J)
			explodir(J);
	}
}

void MinaTerrestre::explodir(Jogador* J) {
		if (J->getInvulneravel()) return;

		int vidas = J->getVidas();
		vidas--;
		J->setVidas(vidas);
		J->initInv();
}

void MinaTerrestre::executar() {
	setPos(pos.x, pos.y + gravidade + contraGravidade);
	if (tempoAtivo) {
		float tempo = tempoExplosao.getElapsedTime().asSeconds();
		if (tempo <= 0.6f) {
			desenhar(figura.getPosition());
		}
		else if (tempo > 0.6f && tempo <= 0.7f) {
			setText("Texturas/Mina/Explosao.png", explosao);
			desenhar(explosao.getPosition());
		}
		else if (tempo > 0.7f) {
			setPos(2500.0f, 2500.0f);
			setVivo(false);
		}
	}
	else {
		desenhar(figura.getPosition());
	}
}
