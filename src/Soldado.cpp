#include "Soldado.h"
#include "Jogador.h"
#include <cmath>

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Soldado::Soldado(sf::Vector2f pos,const char* caminhoTextura) : Inimigo(),figura(sf::Vector2f(58.0f,75.0f))
,vidas(4),temp_parado(0.5f),vetorParado(sf::Vector2f(0.0f,0.0f)),parado(false){
	setText(caminhoTextura, figura);
	setPos(pos.x,pos.y);
	setVel(3.0f, 3.0f);
	figura.setPosition(pos);
}

Soldado::~Soldado() { pJ = nullptr;vidas = -1; }

sf::RectangleShape Soldado::getFigura() {
	return figura;
}

sf::FloatRect Soldado::getBounds() const {
	return figura.getGlobalBounds();
}

int Soldado::getVidas() { return vidas;}

void Soldado::setVidas(int v) { vidas = v;}

void Soldado::colidir(Jogador* j){}

void Soldado::danificar(Jogador* j) {
	if (j->getInvulneravel()) return;
	
	int v = j->getVidas();
	v--;
	j->setVidas(v);

	j->initInv();	

	vetorParado = sf::Vector2f(0.0f, 0.0f);
	parado = true;

	relogioParado.restart();
}

void Soldado::mover() {



	if (parado) {

		if (relogioParado.getElapsedTime().asSeconds() < temp_parado) {
			pos.y += vetorParado.y;
			pos.x += vetorParado.x;

			figura.setPosition(pos);
			desenhar(pos);
			return;
		}

		else {
			parado = false;
		}
	}

	static sf::Clock relogio;
	float tempo = relogio.getElapsedTime().asSeconds();


	pos.x += std::cos(tempo * 0.8f) * vel.x * 0.5f;
	pos.y += gravidade + contraGravidade;

	figura.setPosition(pos);
	desenhar(pos);
}

void Soldado::executar() {

	if (invulneravel && relogioinv.getElapsedTime().asSeconds() >= 0.5f) {
		invulneravel = false;
	}
	mover();
}
