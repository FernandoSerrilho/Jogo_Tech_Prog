#include "Soldado.h"
#include "Jogador.h"
#include <cmath>

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Soldado::Soldado(sf::Vector2f pos,const char* caminhoTextura) : Inimigo()
,temp_parado(0.f),vetorParado(sf::Vector2f(0.0f,0.0f)),parado(false){
	setFigura(sf::Vector2f(58.0f, 75.0f));
	figura.setPosition(pos);
	setPos(pos.x, pos.y);
	setText(caminhoTextura, figura);
	setVel(3.0f, 3.0f);
	setVidas(4);
	contraGravidade = 4.0f;
	temp_parado = ((rand() % 10  + (10-nivel_maldade))/ 10.f);
}

Soldado::~Soldado() {}

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
	gravitar();

	figura.setPosition(pos);
	desenhar(pos);
}

void Soldado::executar() {

	if (invulneravel && relogioinv.getElapsedTime().asSeconds() >= 0.5f) {
		invulneravel = false;
	}
	mover();
}
