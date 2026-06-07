#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador(const char* caminhoTextura) : Personagem(), pontos(0), vidas(3), figura(sf::Vector2f(58.0f, 75.0f)), 
modifiVelo(1.0f),lento(false),velBase(5.0f),pulavel(false), invulneravel(false) , temp_inv(1.5f) {
    initFigura();
    setText(caminhoTextura, figura);
    setPos(100.0f,800.0f);
}

Jogador::~Jogador() {}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);
}

int Jogador::getVidas() { return vidas; }

void Jogador::setVidas(int v) { vidas = v; }

void Jogador::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
    figura.setPosition(x, y);
}

void Jogador::setPulavel(bool p) { pulavel = p; }

bool Jogador::getInvulneravel() { return invulneravel;}

void Jogador::initInv() {

    invulneravel = true;
    relogioInv.restart();

}

void Jogador::attInv() {

    if (invulneravel && relogioInv.getElapsedTime().asSeconds() >= temp_inv) {
        invulneravel = false;
    }


}

sf::RectangleShape Jogador::getFigura() { return figura; }

sf::Vector2f Jogador::getTam() { return figura.getSize(); }

void Jogador::setmodifiVelo(float v) { modifiVelo = v; }


sf::FloatRect Jogador::getBounds() const {

    return figura.getGlobalBounds();

}

void Jogador::colidir(Inimigo* pIn) {

    pIn->danificar(this);
}

void Jogador::executar() {
    mover();
    desenhar(getPos());
    attInv();
}

bool Jogador::verificaLent() const {
    return (lento);
}

void Jogador::setLent(bool v) {
    lento = v;
}


void Jogador::mover() {

    float gravidade = 0.3f;
    float velpulo = 10.0f;
    float tam = 1080.0f -50.0f;

    vel.y += gravidade;
    if (verificaLent())
        vel.x = velBase * modifiVelo;
    else
        vel.x = velBase;

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
    modifiVelo = 1.0f;
}