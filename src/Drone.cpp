#include "Drone.h"
#include "Jogador.h"

using namespace Personagens;



Drone::Drone() : Inimigo(), raio(25.0f), pJ(NULL) , figura(raio) {
    initFigura();
}
Drone::~Drone() {}

void Drone::initFigura() {

    figura.setFillColor(sf::Color::Red);
    setPos(400,300);
    figura.setPosition(pos);
    setVel(0.4f*(float)nivel_maldade + 1.0f,0.4f*(float)nivel_maldade + 1.0f);

}

sf::CircleShape Drone::getFigura() { return figura;}

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

void Drone::executar(){

    mover();
}

void Drone::mover() {

    if (pJ) {

        sf::Vector2f posj = pJ->getPos();

        if (posj.x - pos.x < 0)
            pos.x -= vel.x;
        if (posj.x - pos.x > 0)
            pos.x += vel.x;
        if (posj.y - pos.y < 0)
            pos.y -= vel.y;
        if (posj.y - pos.y > 0)
            pos.y += vel.y;


        figura.setPosition(pos);
    }


}
