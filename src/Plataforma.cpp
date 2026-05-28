#include "Plataforma.h"
#include "Jogador.h"
#include <iostream>
using namespace std;

using namespace Obstaculos;

Plataforma::Plataforma() :Obstaculo(), altura(0), colisao(sf::Vector2f(200.0f, (float)altura)) {

}

Plataforma::Plataforma(sf::Vector2f pos, sf::Color cor, sf::Vector2f tam) : Obstaculo(), colisao(sf::Vector2f(tam)), altura((int)pos.y) {
    InitColi(tam, pos, cor);
    InitText();
}

void Plataforma::InitText() {
    if (!textura.loadFromFile("Texturas/Grama/Grama_Quadrado.png")) {
        cout << "Textura Grama_Quadrado.png nao carregada!" << endl;
    }
    textura.setRepeated(true);
    sprites.setTexture(textura);
    sprites.setTextureRect(sf::IntRect(0, 0, (int)pos.x, (int)pos.y));
    sprites.setPosition(colisao.getPosition());
    setTexturas(textura, sprites);
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

void Plataforma::setCor(sf::Color cor) {
    colisao.setFillColor(cor);
}

void Plataforma::InitColi(sf::Vector2f dim, sf::Vector2f pos, sf::Color cor) {
    setDim(dim);
    setPos(pos);
    setCor(cor);
}

sf::RectangleShape Plataforma::getColi() {
    return colisao;
}

void Plataforma::obstaculizar(Jogador* j1) {

}

void Plataforma::executar() {
    sprites.setPosition(0, 400);
}
