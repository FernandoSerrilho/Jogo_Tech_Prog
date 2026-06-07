#include "Soldado.h"
#include "Jogador.h"

Soldado::Soldado(sf::Vector2f pos,const char* caminhoTextura) : Inimigo(),figura(sf::Vector2f(58.0f,75.0f))
,temp_parado(0.5f),vetorParado(sf::Vector2f(0.0f,0.0f)),parado(false){
	setText(caminhoTextura, figura);
	setPos(pos.x,pos.y);
	setVel(3.0f, 3.0f);
	figura.setPosition(pos);
}

Soldado::~Soldado(){}

sf::RectangleShape Soldado::getFigura() {
	return figura;
}

sf::FloatRect Soldado::getBounds() const {
	return figura.getGlobalBounds();
}

void Soldado::colidir(Entidade* pE){}

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

	figura.setPosition(pos);
	desenhar(pos);
}

void Soldado::executar() {
	mover();
}
