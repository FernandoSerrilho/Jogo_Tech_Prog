#pragma once

#include "Projetil.h"




namespace Entidades {

    namespace Personagens {
        class Jogador;
    }


    class Bala : public Projetil {

        private:
            sf::RectangleShape colisao;

        public:
            Bala(sf::Vector2f posicao = sf::Vector2f(0.0f,0.0f), const char* caminhoTextura = "");
            ~Bala();

            sf::FloatRect getBounds() const;
            void danificar(Personagens::Jogador* pJ);
            void mover();
            void executar();
    };

}