#include "Ente.h"
#include "Gerenciador_Grafico.h"
#include <iostream>
using namespace std;

using namespace Gerenciadores;

Ente::Ente() : id(cont_id++) {}
Ente::~Ente() {}

void Ente::setGG(Gerenciador_Grafico* pG) {
    pGG = pG;
}

void Ente::desenhar(sf::Vector2f posicao) {
    if (pGG) {
    sprite.setPosition(posicao);
    pGG->desenharEnte(this);
    }
}

void Ente::setTexturas(sf::Texture pT, sf::Sprite pS) {
    texturaGeral = pT;
    sprite = pS;
}

sf::Sprite Ente::getSprite() {
    return sprite;
}

void Ente::setText(const char* caminhoTextura, sf::RectangleShape colisao) {
    if (!texturaGeral.loadFromFile(caminhoTextura)) {
        cout << "Textura Grama_QuadradoSemBorda.png nao carregada!" << endl;
    }
    texturaGeral.setRepeated(true);
    sprite.setTexture(texturaGeral);
    sf::Vector2f tam = colisao.getSize();
    sprite.setTextureRect(sf::IntRect(0, 0, (int)tam.x, (int)tam.y));
    sprite.setPosition(colisao.getPosition());
}

int Ente::cont_id = 0;
Gerenciador_Grafico* Ente::pGG = NULL;