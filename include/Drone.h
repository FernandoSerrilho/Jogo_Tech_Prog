#pragma once

#include "Inimigo.h"

namespace Entidades {

namespace Personagens {

class Drone : public Inimigo {

    private:
        float raio;
        sf::CircleShape figura;
        Jogador* pJ;

    public:
        Drone();
        ~Drone();
        
        //void danificar(Jogador* p);   TODO
        void setVel(float vx, float vy);
        void setPos(float x, float y);
        void initFigura();
        sf::CircleShape getFigura();

        void setJog(Jogador* p);
        void executar();
        void mover();







};


}
}