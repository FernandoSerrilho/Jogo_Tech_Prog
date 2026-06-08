#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>

namespace Entidades {

class Entidade : public Ente {

    protected:
        sf::Vector2f pos;
        sf::Vector2f vel;
        bool vivo;
        //std::ostream& buffer;               TODO
        float gravidade;
        float contraGravidade;
    public:
        Entidade();
        virtual ~Entidade();
    protected:
        // void salvarDataBuffer();           TODO
    public:
        virtual void executar() = 0;
        void setVivo(bool v);
        bool getVivo();
        sf::Vector2f getPos();
        sf::Vector2f getVel();
        virtual void setPos(float x, float y);
        virtual void setVel(float vx, float vy);
        virtual sf::FloatRect getBounds() const = 0;
        //virtual void salvar() = 0;          TODO

};

}