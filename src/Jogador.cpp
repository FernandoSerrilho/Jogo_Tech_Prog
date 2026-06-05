#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador(const char* caminhoTextura) : Personagem(), pontos(0), vidas(3), figura(sf::Vector2f(17.0f, 22.0f)) {
    initFigura();
    setText(caminhoTextura, figura);
    setPos(100.0f,800.0f);
    pulavel = false;
}

Jogador::~Jogador() {}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);
}

void Jogador::setVidas(int v) { vidas = v; }

void Jogador::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
    figura.setPosition(x, y);
}

void Jogador::setPulavel(bool p) { pulavel = p; }

sf::RectangleShape Jogador::getFigura() { return figura; }

sf::Vector2f Jogador::getTam() { return figura.getSize(); }


sf::FloatRect Jogador::getBounds() const {

    return figura.getGlobalBounds();

}

void Jogador::colidir(Inimigo* pIn) {


    int v = vidas - 1;

    setVidas(v);

    //std::cout << "Vidas:" << v << std::endl;
}

void Jogador::executar() {
    mover();
    desenhar(getPos());
}


void Jogador::mover() {

    float gravidade = 0.3f;
    float velpulo = 10.0f;
    float tam = 1080.0f -50.0f;

    

    vel.y += gravidade;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos.x += vel.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos.x -= vel.x;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pulavel) {
        vel.y -= velpulo;
        setPulavel(false);
    }

    pos.y += vel.y;

    setPos(pos.x,pos.y);

}