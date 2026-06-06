#include "Drone.h"
#include "Jogador.h"
#include "SFML/Graphics.hpp"
#include <cmath>

using namespace Personagens;
using namespace Entidades;



Drone::Drone(Jogador* p, const char* caminhoTextura) : Inimigo(), pJ(p), figura(sf::Vector2f(50.0f, 40.0f)) {
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

}

void Drone::executar() {
    mover();
    desenhar(getPos());
}

void Drone::colidir(Entidade* pE) {
    /*sf::FloatRect boundsD(getBounds());
    sf::FloatRect boundsPe(pE->getBounds());

    sf::Vector2f pos = getPos();
    sf::Vector2f velocidade(vel.x, vel.y);

    //colisao com o topo da plataforma
    if (boundsD.top + boundsD.height <= (boundsPe.top + 10.0f)) {
        setPos(pos.x, boundsPe.top - boundsD.height);
        setVel(velocidade.x, 0.0f);
    }
    //colisao por baixo da plataforma
    else if (boundsD.top >= boundsPe.top + boundsPe.height - 1.0f) {
        setPos(pos.x, boundsPe.top + boundsPe.height);

        setVel(velocidade.x, 0.0f);
    }
    //colisao pela esquerda
    else if (boundsD.left + boundsD.width <= boundsPe.left + 1.0f) {
        setPos(boundsPe.left - boundsD.width, pos.y);
        setVel(0.0f, velocidade.y);
    }
    //colisao pela direita
    else if(boundsD.left <= boundsPe.width + boundsPe.left + 1.0f){
        setPos(boundsPe.left + boundsD.width, pos.y);
        setVel(0.0f, velocidade.y);
    }
        setVel(velocidade.x,velocidade.y);*/
}

void Drone::mover() {
    
    
    
    if (pJ) {


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