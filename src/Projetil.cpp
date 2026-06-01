#include "Projetil.h"

using namespace Entidades;



Projetil::Projetil(bool a) : Entidade(), ativo(a) , figura(sf::Vector2f(5.0f,5.0f)){


    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);

};

Projetil::~Projetil() {
    
};

void Projetil::executar() {


};
 
sf::RectangleShape Projetil::getFigura() { return figura;} 

sf::Vector2f Projetil::getPos() { return pos;}

sf::Vector2f Projetil::getVel() { return vel;}

void Projetil::setPos(sf::Vector2f npos) { 
    figura.setPosition(npos);
    pos = npos;
}

void Projetil::setVel(sf::Vector2f nvel) { vel = nvel ;}

sf::FloatRect Projetil::getBounds() const { 
    return figura.getGlobalBounds();
 }

