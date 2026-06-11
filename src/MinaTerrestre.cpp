#include "MinaTerrestre.h"
#include "Inimigo.h"
#include "Jogador.h"

using namespace Entidades;
using namespace Obstaculos;
using namespace Personagens;
using namespace Inimigos;

MinaTerrestre::MinaTerrestre(Jogador* J) :pJ(J),Obstaculo(true), tempoAtivacao(0.6f), colisao(), raio(rand() % 8 + 25.0f), tempoAtivo(false) { contraGravidade = -0.3f; }

MinaTerrestre::MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam,Jogador* j) :Obstaculo(), tempoAtivacao(0.6f),raio(rand()% 8 + 15.0f), tempoAtivo(false),pJ(j) {
	colisao.setSize(tam);
	colisao.setPosition(pos);
	setPos(pos.x, pos.y);
	explosao.setSize(sf::Vector2f(raio,raio));
	explosao.setPosition(pos);
	setText("Texturas/Mina/MinaTerrestre.png", colisao);
	contraGravidade = -0.3f;
}

MinaTerrestre::~MinaTerrestre(){
	tempoAtivo = false;
	raio = -1;
}

void MinaTerrestre::obstaculizar(Jogador* J){
	if (!tempoAtivo) {
		J = pJ;
		tempoAtivo = true;
		tempoExplosao.restart();
	}
}

void MinaTerrestre::explodir(Jogador* J) {
		if (pJ->getInvulneravel()) return;

		int vidas = pJ->getVidas();
		vidas--;
		pJ->setVidas(vidas);
		pJ->initInv();
}

void MinaTerrestre::obstaculizar(Inimigo* pI) {
	int n = 45;
}

sf::FloatRect MinaTerrestre::getBounds() const {
	return colisao.getGlobalBounds();
}

void MinaTerrestre::executar(){


	if (tempoAtivo) {
		explodir(pJ);
	}

	setPos(pos.x, pos.y + gravidade + contraGravidade);
	if (tempoAtivo) {
		if (tempoExplosao.getElapsedTime().asSeconds() <= 0.6f) {
			desenhar(colisao.getPosition());
		}
		else if (tempoExplosao.getElapsedTime().asSeconds() > 0.6f && tempoExplosao.getElapsedTime().asSeconds() <= 0.7f) {
			setText("Texturas/Mina/Explosao.png", explosao);
			desenhar(explosao.getPosition());
			if(pJ)
				explodir(pJ);
		}
		else if (tempoExplosao.getElapsedTime().asSeconds() > 0.7f) {
			setPos(2500.0f, 2500.0f);
			setVivo(false);
		}
	}
	desenhar(colisao.getPosition());
}
