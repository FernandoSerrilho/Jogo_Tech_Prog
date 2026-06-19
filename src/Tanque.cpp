#include "Tanque.h"
#include "Jogador.h"
#include "Projetil.h"
#include <cmath>
#include <iostream>


using namespace Entidades::Personagens;
using namespace Entidades::Personagens::Inimigos;

Tanque::Tanque(const char* caminhoTextura) : Inimigo(), podeAtirar(false), cooldown(0.0f){
    contraGravidade = 0.1f;
    setFigura(sf::Vector2f(58.0f, 38.0f));
    setText(caminhoTextura, figura);
    figura.setPosition(pos);
    balas.clear();
    setVidas(5);

    if (nivel_maldade <= 3 ) {
        cooldown = 7.0f;
    }
    else if (nivel_maldade > 3  && nivel_maldade <= 7) {
        cooldown = 10.0f - (float)nivel_maldade;
    }
    else {
        cooldown = 3.0f;
    }
}
Tanque::~Tanque() {balas.clear();}

bool Tanque::getpodeAtirar() { return podeAtirar;}
void Tanque::setPodeAtirar(bool p) {podeAtirar = p;};
void Tanque::adicionarBala(Projetil* b) { 

    if (b != nullptr) {
        balas.push_back(b);
    }

 }

void Tanque::resetClock() { relogiocooldown.restart();}

void Tanque::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v -= 1;
    pJ->setVidas(v);
    int VidasTanque = getVidas();
    VidasTanque++;
    setVidas(VidasTanque);

    pJ->initInv();
}

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



	pos.x += std::cos(tempo * 0.5f) * vel.x * 0.2f;
	
    gravitar();

    setPos(pos.x,pos.y);
	figura.setPosition(pos);
	desenhar(pos);
}

void Tanque::executar() {


    std::vector<Projetil*>::iterator it = balas.begin();

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

void Tanque::salvar() {

    salvarDataBuffer();

    if (buffer) {
        buffer << podeAtirar << " " << cooldown << "\n";
    }

}