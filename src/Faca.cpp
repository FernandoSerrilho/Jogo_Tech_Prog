    #include "Faca.h"
    #include "Jogador.h"

 
    using namespace Entidades;
    using namespace Entidades::Personagens;



    Faca::Faca() : Entidade(), figura(sf::Vector2f(58.0f, 70.0f)) {

        figura.setFillColor(sf::Color::White);
    }


    Faca::~Faca() {}


    void Faca::initFigura(Jogador * j, bool olhandoesquerda) {

       sf::Vector2f posj = j->getPos();
       sf::FloatRect boundsj = j->getBounds();

       if (olhandoesquerda) {

            figura.setPosition(boundsj.left - 58.0f - 10.0f, boundsj.top);
       }

       else 
            figura.setPosition(boundsj.left + boundsj.width + 10.0f, boundsj.top);


    }

    sf::RectangleShape* Faca::getFigura() { return &figura;};

    sf::FloatRect Faca::getBounds() const {

    return figura.getGlobalBounds();

    }


    void Faca::executar() {
    }