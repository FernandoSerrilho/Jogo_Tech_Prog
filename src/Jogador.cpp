#include "Jogador.h"
#include "Inimigo.h"

using namespace Entidades;
using namespace Personagens;



Jogador::Jogador(): Personagem(), pontos(0) , vidas(3), figura(sf::Vector2f(50.0f,50.0f)){
    initFigura();
}

Jogador::~Jogador() {}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);

}

void Jogador::setVidas(int v) { vidas = v;}

sf::Vector2f Jogador::getPos() { return pos;}

sf::RectangleShape Jogador::getFigura() { return figura;}

void Jogador::setPos(sf::Vector2f novapos) {

    figura.setPosition(novapos);
    pos = novapos;

}

sf::FloatRect Jogador::getBounds() const{

    return figura.getGlobalBounds();

}

void Jogador::colidir(Inimigo* pIn) {


    int v = vidas - 1;

    setVidas(v);

    std::cout << "Vidas:" << v  << std::endl; 



}

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

    setPos(pos);

}