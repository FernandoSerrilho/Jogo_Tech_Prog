#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;

        class Drone : public Inimigo {

        private:
            sf::RectangleShape figura;
            Jogador* pJ;
            int vidas;
            bool emKnockback;
            sf::Clock relogioKnockback;
            sf::Vector2f vetorKnockback;


        public:
            Drone(Jogador* p = NULL, const char* caminhoTextura = "");
            ~Drone();

            int getVidas();
            void setVidas(int v);
            void danificar(Jogador* p);
            void initFigura();
            sf::RectangleShape getFigura();
            sf::FloatRect getBounds() const;

            void setJog(Jogador* p);
            void executar();
            void mover();
            void colidir(Jogador* j);
        };
    }
}