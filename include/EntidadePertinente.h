#pragma once
#include "Entidade.h"

namespace Entidades {
    class EntidadePertinente : public Entidade{

    protected:
        sf::Vector2f vel;
        //std::ostream& buffer;               TODO
        float gravidade;
        float contraGravidade;
    public:
        EntidadePertinente();
        virtual ~EntidadePertinente();
    protected:
        // void salvarDataBuffer();           TODO
    public:
        virtual void executar() = 0;
        sf::Vector2f getVel();
        void setVel(float vx, float vy);
        //virtual void salvar() = 0;          TODO
    };
}