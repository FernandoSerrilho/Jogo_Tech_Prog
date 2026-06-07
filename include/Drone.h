#pragma once
#include "Inimigo.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;

        class Drone : public Inimigo {

        private:
            sf::RectangleShape figura;
            Jogador* pJ;
            bool emKnockback;
            sf::Clock relogioKnockback;
            float temp_knockback;
            sf::Vector2f vetorKnockback;


        public:
            Drone(Jogador* p = NULL, const char* caminhoTextura = "");
            ~Drone();

            void danificar(Jogador* p);
            void initFigura();
            sf::RectangleShape getFigura();
            sf::FloatRect getBounds() const;

            void setJog(Jogador* p);
            void executar();
            void mover();
            void colidir(Entidade* pE);
        };
    }
}