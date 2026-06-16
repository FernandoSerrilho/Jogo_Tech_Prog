#pragma once
#include "Ente.h"

class EntidadeBase : public Ente {

    protected:
        sf::Vector2f pos;
        bool vivo;
    public:
        EntidadeBase();
        virtual ~EntidadeBase();
        virtual void executar() = 0;
        void setVivo(bool v);
        bool getVivo();
        sf::Vector2f getPos();
        void setPos(float x, float y);
};
