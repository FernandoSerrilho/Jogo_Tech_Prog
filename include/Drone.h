#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;

        class Drone : public Inimigo {

        private:
            sf::RectangleShape figura;
            Jogador* pJ;

        public:
            Drone(Jogador* p = NULL,const char* caminhoTextura = "");
            ~Drone();

            //void danificar(Jogador* p);   TODO
            void setVel(float vx, float vy);
            void setPos(float x, float y);
            void initFigura();
            sf::RectangleShape getFigura();
            sf::FloatRect getBounds() const;

            void setJog(Jogador* p);
            void executar();
            void mover();
        };
    }
}
