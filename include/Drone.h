#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
        namespace Inimigos {
            class Drone : public Inimigo {

            private:
                sf::RectangleShape figura;
                Entidades::Personagens::Jogador* pJ[2];
                int vidas;
                bool emKnockback;
                sf::Clock relogioKnockback;
                sf::Vector2f vetorKnockback;

            public:
                Drone(Jogador* p1 = NULL, Jogador* p2 = NULL, const char* caminhoTextura = "");
                ~Drone();

                int getVidas();
                void setVidas(int v);
                void danificar(Jogador* p);
                void initFigura();
                sf::RectangleShape getFigura();
                sf::FloatRect getBounds() const;

                void setJog(Jogador* p,int n);
                void executar();
                void mover();
                void colidir(Jogador* j);
            };
        }
    }
}