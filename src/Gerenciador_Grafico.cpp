#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Drone.h"
#include "Gerenciador_Colisoes.h"
#include <iostream>
using namespace std;

using namespace Personagens;

using namespace Gerenciadores;

Gerenciador_Grafico* Gerenciador_Grafico::pGG = nullptr;

Gerenciador_Grafico::Gerenciador_Grafico() : janela(new sf::RenderWindow(sf::VideoMode(1920, 1080), "Teste SFML - UTFPR"))
{    
    if (janela == nullptr)
        cout << "Erro, janela não criada" << endl;
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

void Gerenciador_Grafico::fechaJanela() {
    if(VerificajanelaAberta())
        janela->close();
}

void Gerenciador_Grafico::limpaJanela() {
    if (VerificajanelaAberta())
        janela->clear();
}

void Gerenciador_Grafico::displayJanela() {
    if (VerificajanelaAberta())
        janela->display();
}

Gerenciador_Grafico* Gerenciador_Grafico::getGerenciadorG() {
    if (pGG == nullptr)
        pGG = new Gerenciador_Grafico();
    return pGG;
}

const bool Gerenciador_Grafico::VerificajanelaAberta() {
    if (janela->isOpen())
        return true;
    return false;
}

sf::RenderWindow* Gerenciador_Grafico::getJanela() {
    return janela;
}

void Gerenciador_Grafico::setFrame(int n) {
    janela->setFramerateLimit(n);
}

void Gerenciador_Grafico::desenharfaca(sf::RectangleShape* faca) {
    if (faca) {
        janela->draw(*faca);
    }
}


void Gerenciador_Grafico::desenharEnte(Ente* pE) {
    janela->draw(pE->getSprite());


}

void Gerenciador_Grafico::desenharTexto(sf::Text t) {
    janela->draw(t);
}