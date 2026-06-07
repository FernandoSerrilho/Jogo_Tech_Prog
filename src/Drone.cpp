#include "Drone.h"
#include "Jogador.h"
#include "SFML/Graphics.hpp"
#include <cmath>

using namespace Personagens;
using namespace Entidades;



Drone::Drone(Jogador* p, const char* caminhoTextura) : Inimigo(), pJ(p), emKnockback(false), temp_knockback(0.3f), vetorKnockback(sf::Vector2f()), figura(sf::Vector2f(50.0f, 40.0f)) {
    initFigura();
    setText(caminhoTextura, figura);
    setJog(pJ);
}
Drone::~Drone() {}

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


void Drone::setJog(Jogador* p) {

    pJ = p;
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
}

void Drone::colidir(Entidade* pE) {
  
}

void Drone::mover() {
    
    
    
    if (pJ) {

        if (emKnockback) {

           if (relogioKnockback.getElapsedTime().asSeconds() < temp_knockback) { 
            pos.y += vetorKnockback.y * 10.0f;
            pos.x += vetorKnockback.x * 10.0f;


            figura.setPosition(pos);
                return;
           }

           else {
              emKnockback = false;
           }


        }


        float raio_det = 200.0f;

        sf::Vector2f posj = pJ->getPos();

        float dy = (pJ->getBounds().top + pJ->getBounds().height)/2.0f - (getBounds().top + getBounds().height)/2.0f;
        float dx = (pJ->getBounds().left + pJ->getBounds().width)/2.0f - (getBounds().left + getBounds().width)/2.0f;

        float dist = std::sqrt(dx*dx + dy*dy);



        if (dist <= raio_det) {


        sf::Vector2f tamD = figura.getSize();
        sf::Vector2f tamJ = pJ->getTam();
        float tamRy = tamD.y - tamJ.y;
        float tamRx = tamD.x - tamJ.x;

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


}