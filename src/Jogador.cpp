#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador(const char* caminhoTextura) : Personagem(), pontos(0), vidas(3), figura(sf::Vector2f(17.0f, 22.0f)) {
    initFigura();
    setText(caminhoTextura, figura);
    sf::Vector2f aux(0.0f, 550.0f);
    setPos(aux);
    pulavel = false;
}

Jogador::~Jogador() {}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);
}

void Jogador::setVidas(int v) { vidas = v; }

void Jogador::setPulavel(bool p) { pulavel = p; }

sf::Vector2f Jogador::getPos() { return pos; }

sf::Vector2f Jogador::getVel() { return vel; }

sf::RectangleShape Jogador::getFigura() { return figura; }

sf::Vector2f Jogador::getTam() { return figura.getSize(); }

void Jogador::setPos(sf::Vector2f npos) {
    figura.setPosition(npos);
    pos = npos;
}

void Jogador::setVel(sf::Vector2f nvel) {
    vel = nvel;
}

sf::FloatRect Jogador::getBounds() const {

    return figura.getGlobalBounds();

}

void Jogador::colidir(Inimigo* pIn) {


    int v = vidas - 1;

    setVidas(v);

    std::cout << "Vidas:" << v << std::endl;
}

void Jogador::executar() {
    mover();
    desenhar(getPos());
}


void Jogador::mover() {

    float gravidade = 0.3f;
    float velpulo = 10.0f;
    float tam = 526;

    if (pos.y >= tam) {
        vel.y = 0;
        setPulavel(true);
    }
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

    setPos(pos);

}