#include "Tanque.h"
#include "Jogador.h"
#include "Bala.h"
#include <cmath>
#include <iostream>


using namespace Entidades::Personagens;
using namespace Entidades::Personagens::Inimigos;

Tanque::Tanque(const char* caminhoTextura, Jogador* pJ) : Inimigo() , pJ(pJ), podeAtirar(false), cooldown(10.0f/nivel_maldade), vidas(5), figura(sf::Vector2f(100.0f, 80.0f)) {

    initFigura();
    setText(caminhoTextura, figura);
    balas.clear();

   std::cout << "Tanque criado com maldade: " << nivel_maldade << " e cooldown: " << this->cooldown << std::endl;
}
Tanque::~Tanque() {vidas = -1; pJ = nullptr; balas.clear();}

bool Tanque::getpodeAtirar() { return podeAtirar;}
void Tanque::setPodeAtirar(bool p) {podeAtirar = p;};
void Tanque::adicionarBala(Bala* b) { 

    if (b != nullptr) {
        balas.push_back(b);
    }

 }

void Tanque::setVidas(int v) { vidas = v;}
int Tanque::getVidas() {return vidas;}

sf::RectangleShape Tanque::getFigura() {return figura;}

void Tanque::resetClock() { relogiocooldown.restart();}

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

    for (size_t i = 0; i < balas.size(); i++) {
        if (balas[i] != nullptr) {
            balas[i]->setVel(-5.0f,0.0f);
        }
    }

}

void Tanque::mover() {

    static sf::Clock relogio;
	float tempo = relogio.getElapsedTime().asSeconds();

    vel.y += gravidade + contraGravidade;


	pos.x += std::cos(tempo * 0.8f) * vel.x * 0.5f;
	pos.y += vel.y;

    setPos(pos.x,pos.y);
	figura.setPosition(pos);
	desenhar(pos);


}

void Tanque::executar() {


    std::vector<Bala*>::iterator it = balas.begin();

    while (it != balas.end()) {
        if ((*it) == nullptr || !(*it)->getAtivo()) {
            it = balas.erase(it); 
        } else {
            ++it;
        }
    }

    if (relogiocooldown.getElapsedTime().asSeconds() >= cooldown) {
        setPodeAtirar(true);
        resetClock();
    }
    
	if (invulneravel && relogioinv.getElapsedTime().asSeconds() >= 0.5f) {
		invulneravel = false;
	}

    mover();
    atirar();
}