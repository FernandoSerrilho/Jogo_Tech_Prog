#pragma once
#include "Ente.h"

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
        //virtual void salvar() = 0;          TODO

};

}