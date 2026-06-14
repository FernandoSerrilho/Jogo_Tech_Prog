#include "Drone.h"
#include "Jogador.h"
#include "SFML/Graphics.hpp"
#include <cmath>

using namespace Entidades::Personagens::Inimigos;

Drone::Drone(Jogador* p,Jogador* p1, const char* caminhoTextura) : Inimigo(), vidas(2), emKnockback(false), vetorKnockback(sf::Vector2f()), figura(sf::Vector2f(50.0f, 40.0f)) {
    initFigura();
    setText(caminhoTextura, figura);
    pJ[0] = p;
    pJ[1] = p1;
    contraGravidade = -0.3f;
}
Drone::~Drone() { vidas = -1; emKnockback = false; vidas = -1; pJ[0] = nullptr;pJ[1] = nullptr;}

void Drone::initFigura() {

    figura.setFillColor(sf::Color::Red);
    setPos(400, 600);
    figura.setPosition(pos);
    setVel(0.2f * (float)nivel_maldade + 0.5f, 0.2f * (float)nivel_maldade + 0.5f);
}

sf::RectangleShape Drone::getFigura() { return figura; }

sf::FloatRect Drone::getBounds() const {

    return figura.getGlobalBounds();

}


int Drone::getVidas() { return vidas;}

void Drone::setVidas(int v) { vidas = v;}

void Drone::setJog(Jogador*j,int n) {

    pJ[n] = j;
}

void Drone::danificar(Jogador* p) {


    if(p->getInvulneravel()) return;

    int v = p->getVidas();
    v -= 1;
    p->setVidas(v);


    p->initInv();

    float dy = (p->getBounds().top + p->getBounds().height/2.0f) - (getBounds().top + getBounds().height/2.0f);
    float dx = (p->getBounds().left + p->getBounds().width/2.0f) - (getBounds().left + getBounds().width/2.0f);
    float dist = std::sqrt(dx*dx + dy*dy);

    if (dist != 0) {

        vetorKnockback = sf::Vector2f(-dx/dist , -dy/dist);
    }
    else {

        vetorKnockback = sf::Vector2f(0.0f, -1.0f); 
    }


    emKnockback = true;

    relogioKnockback.restart();



}

void Drone::executar() {

    mover();
    desenhar(getPos());
    if (invulneravel && relogioinv.getElapsedTime().asSeconds() >= 0.5f) {
		invulneravel = false;
	}
}

void Drone::colidir(Jogador* j) {

  
}

void Drone::mover() {
    vel.y += gravidade + contraGravidade;

    if (emKnockback) {
        if (relogioKnockback.getElapsedTime().asSeconds() < 0.3f) {
            pos.y += vetorKnockback.y * 10.0f;
            pos.x += vetorKnockback.x * 10.0f;
            figura.setPosition(pos);
            return;
        }
        else {
            emKnockback = false;
        }
    }

    Jogador* alvo = nullptr;
    float menorDistancia = 999999.0f;

    for (int i = 0; i < 2; i++) {
        if (pJ[i] != nullptr && pJ[i]->getVivo()) {
            float dx = (pJ[i]->getBounds().left + pJ[i]->getBounds().width / 2.0f) - (getBounds().left + getBounds().width / 2.0f);
            float dy = (pJ[i]->getBounds().top + pJ[i]->getBounds().height / 2.0f) - (getBounds().top + getBounds().height / 2.0f);
            float dist = std::sqrt(dx * dx + dy * dy);

            if (dist < menorDistancia) {
                menorDistancia = dist;
                alvo = pJ[i];
            }
        }
    }

    float raio_det = 350.0f;

    if (alvo != nullptr && menorDistancia <= raio_det) {
        sf::Vector2f posj = alvo->getPos();
        sf::Vector2f tamD = figura.getSize();
        sf::Vector2f tamJ = alvo->getTam();
        float tamRy = tamD.y - tamJ.y;

        vel.y = 0.2f * (float)nivel_maldade + 0.5f;

        if (posj.x - pos.x < 0)
            pos.x -= vel.x;
        if (posj.x - pos.x > 0)
            pos.x += vel.x;
        if (posj.y - pos.y - tamRy < 0)
            pos.y -= vel.y;
        if (posj.y - pos.y - tamRy > 0)
            pos.y += vel.y;
        figura.setPosition(pos);
    }
    else {
        static sf::Clock relogio;
        float tempo = relogio.getElapsedTime().asSeconds();

        pos.x += std::cos(tempo * 0.8f) * vel.x * 0.5f;
        figura.setPosition(pos);
    }
}