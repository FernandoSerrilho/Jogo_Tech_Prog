#include "MinaTerrestre.h"
#include "Jogador.h"

using namespace Entidades::Obstaculos;

MinaTerrestre::MinaTerrestre() :Obstaculo(true), tempoAtivacao(0.6f), colisao(), raio(rand() % 8 + 25.0f), tempoAtivo(false) { contraGravidade = -0.3f; }

MinaTerrestre::MinaTerrestre(sf::Vector2f pos, sf::Vector2f tam) :Obstaculo(), tempoAtivacao(0.6f),raio(rand()% 8 + 25.0f), tempoAtivo(false) {
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

void MinaTerrestre::obstaculizar(Jogador* pJ){
	if (!tempoAtivo) {
		tempoAtivo = true;
		tempoExplosao.restart();
	}

	explodir(pJ);

}

void MinaTerrestre::explodir(Jogador* pJ) {

	sf::FloatRect boundsj = pJ->getBounds();
	sf::FloatRect boundsE = explosao.getGlobalBounds();


	if (tempoExplosao.getElapsedTime().asSeconds() >= 0.6f) {

		if (boundsj.intersects(boundsE)) {

			if (pJ->getInvulneravel()) return;

			int vidas = pJ->getVidas();
			vidas--;
			pJ->setVidas(vidas);

		}
		setText("", explosao);
		desenhar(explosao.getPosition());

		if (tempoExplosao.getElapsedTime().asSeconds() >= 0.6f + 0.3f) {
			setPos(2500.0f, 2500.0f);
			setVivo(false);
		}
	}
}

void MinaTerrestre::obstaculizar(Inimigo* pI) {}

sf::FloatRect MinaTerrestre::getBounds() const {
	return colisao.getGlobalBounds();
}

void MinaTerrestre::executar(){
	setPos(pos.x, pos.y + gravidade + contraGravidade);
	desenhar(colisao.getPosition());
}

/*
MinaTerrestre::Explosao::Explosao(sf::Vector2f pos,sf::RectangleShape tam) : Ente(),posicao(pos),exp(tam) { 
	exp.setSize(sf::Vector2f(tam.getSize()));
	exp.setPosition(pos);
	setText("", exp);
}

MinaTerrestre::Explosao::Explosao():Ente(){}

MinaTerrestre::Explosao::~Explosao(){}

void MinaTerrestre::Explosao::executar(){

}*/