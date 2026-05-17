#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;



Jogador::Jogador(): Personagem(), pontos(0) , figura(sf::Vector2f(50.0f,50.0f)){
    initFigura();
}

Jogador::~Jogador() {}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);

}

sf::Vector2f Jogador::getPos() { return pos;}

sf::RectangleShape Jogador::getFigura() { return figura;}

void Jogador::executar() {
    mover();
}


void Jogador::mover() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos.x += vel.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos.x -= vel.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        pos.y -= vel.y;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        pos.y += vel.y;
    }



    figura.setPosition(pos);



}