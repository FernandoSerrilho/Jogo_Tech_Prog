#include "Drone.h"
#include "Jogador.h"
#include "SFML/Graphics.hpp"

using namespace Personagens;
using namespace Entidades;



Drone::Drone(Jogador* p,const char* caminhoTextura) : Inimigo(), pJ(p), figura(sf::Vector2f(50.0f,40.0f)) {
    initFigura();
    setText(caminhoTextura, figura);
    setJog(pJ);
}
Drone::~Drone() {}

void Drone::initFigura() {

    figura.setFillColor(sf::Color::Red);
    setPos(400,300);
    figura.setPosition(pos);
    setVel(0.2f*(float)nivel_maldade + 0.5f,0.2f*(float)nivel_maldade + 0.5f);

}

sf::RectangleShape Drone::getFigura() { return figura;}

sf::FloatRect Drone::getBounds() const {

    return figura.getGlobalBounds();

}

void Drone::setPos(float x, float y) {

    pos.x = x;
    pos.y = y;

}

void Drone::setVel(float vx, float vy) {
    vel.x = vx;
    vel.y = vy;
}

void Drone::setJog(Jogador* p) {

    pJ = p;
}

void Drone::danificar(Jogador* p) {



}

void Drone::executar(){
    mover();
    desenhar(getPos());
}

void Drone::mover() {
    if (pJ) {
        sf::Vector2f posj = pJ->getPos();
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


}
