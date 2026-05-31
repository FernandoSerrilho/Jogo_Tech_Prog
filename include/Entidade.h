#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Entidades {

class Entidade : public Ente {

    protected:
        sf::Vector2f pos;
        sf::Vector2f vel;
        //std::ostream& buffer;               TODO
    public:
        Entidade();
        virtual ~Entidade();
    protected:
        // void salvarDataBuffer();           TODO
    public:
        virtual void executar() = 0;
        sf::Vector2f getPos();
        virtual sf::FloatRect getBounds() const = 0;
        //virtual void salvar() = 0;          TODO

};

}