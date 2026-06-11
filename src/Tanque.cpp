#include "Tanque.h"
#include "Jogador.h"


using namespace Entidades::Personagens;
using namespace Entidades::Personagens::Inimigos;

Tanque::Tanque(const char* caminhoTextura = "", Jogador* pJ) : Inimigo() , pJ(pJ), pB(nullptr), velBala(nivel_maldade/2.0f + 4.0f), vidas(5), figura(sf::Vector2f(100.0f, 80.0f)) {

    initFigura();
    setText(caminhoTextura, figura);
}
Tanque::~Tanque() {vidas = -1; pJ = nullptr; pB = nullptr;}

void Tanque::setBala(Bala* b) { pB = b; }

void Tanque::setVidas(int v) { vidas = v;}
int Tanque::getVidas() {return vidas;}

sf::RectangleShape Tanque::getFigura() {return figura;}

void Tanque::initFigura() {
    
    figura.setFillColor(sf::Color::Yellow);
    setPos(400, 600);
    figura.setPosition(pos);

}

sf::FloatRect Tanque::getBounds() const {return figura.getGlobalBounds();}

void Tanque::danificar(Jogador* pJ) {

    if(pJ->getInvulneravel()) return;

    int v = pJ->getVidas();
    v -= 1;
    pJ->setVidas(v);


    pJ->initInv();

}
void Tanque::colidir(Jogador* pJ) {}

void Tanque::atirar() {

    if (pB = nullptr) {

        pB = new Bala();
    }




}

void Tanque::mover() {}

void Tanque::executar() {}