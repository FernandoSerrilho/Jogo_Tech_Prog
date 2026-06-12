#include "Tanque.h"
#include "Jogador.h"
#include "Bala.h"
#include <cmath>


using namespace Entidades::Personagens;
using namespace Entidades::Personagens::Inimigos;

Tanque::Tanque(const char* caminhoTextura, Jogador* pJ) : Inimigo() , pJ(pJ), pB(nullptr), podeAtirar(false), velBala(nivel_maldade/2.0f + 4.0f), vidas(5), figura(sf::Vector2f(100.0f, 80.0f)) {

    initFigura();
    setText(caminhoTextura, figura);
    contraGravidade = -0.3f;
}
Tanque::~Tanque() {vidas = -1; pJ = nullptr; pB = nullptr;}

float Tanque::getVelBala() { return velBala;}
void Tanque::setBala(Bala* b) { pB = b; }

void Tanque::setVidas(int v) { vidas = v;}
int Tanque::getVidas() {return vidas;}

sf::RectangleShape Tanque::getFigura() {return figura;}

void Tanque::initFigura() {
    
    figura.setFillColor(sf::Color::Yellow);
    setPos(400, 600);
    figura.setPosition(pos);

}

sf::FloatRect Tanque::getBounds() const {return figura.getGlobalBounds();}

void Tanque::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v -= 1;
    pJ->setVidas(v);


    pJ->initInv();

}
void Tanque::colidir(Jogador* pJ) {}

void Tanque::atirar() {

    if (pB = nullptr) {

        pB->setVel(velBala,0.0f);

    }

}

void Tanque::mover() {

    static sf::Clock relogio;
	float tempo = relogio.getElapsedTime().asSeconds();



	pos.x += std::cos(tempo * 0.8f) * vel.x * 0.5f;
	pos.y += gravidade + contraGravidade;

	figura.setPosition(pos);
	desenhar(pos);


}

void Tanque::executar() {

    if (!podeAtirar) {
        relogiocooldown.restart();
    }

    
	if (invulneravel && relogioinv.getElapsedTime().asSeconds() >= 0.5f) {
		invulneravel = false;
	}

    mover();
}