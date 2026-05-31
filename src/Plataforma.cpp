#include "Plataforma.h"
#include "Jogador.h"
#include <iostream>
using namespace std;

using namespace Obstaculos;

Plataforma::Plataforma() :Obstaculo(), altura(0), colisao(sf::Vector2f(200.0f, (float)altura)) {

}

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam) : Obstaculo(), colisao(sf::Vector2f(tam)), altura((int)pos.y) {
    InitColi(tam, pos);
    InitText();
}

void Plataforma::InitText() {
    setText("Texturas/Grama/Grama_QuadradoSemBorda.png", colisao);
}


Plataforma::~Plataforma() {}
sf::FloatRect Plataforma::getBounds() const {
    return colisao.getGlobalBounds();
}

void Plataforma::setDim(sf::Vector2f dim) {
    colisao.setSize(dim);
}

void Plataforma::setPos(sf::Vector2f pos) {
    colisao.setPosition(pos);
}

void Plataforma::InitColi(sf::Vector2f dim, sf::Vector2f pos) {
    setDim(dim);
    setPos(pos);
}

sf::RectangleShape Plataforma::getColi() {
    return colisao;
}

void Plataforma::obstaculizar(Jogador* j1) {

}

void Plataforma::executar() {
    desenhar(colisao.getPosition());
}
