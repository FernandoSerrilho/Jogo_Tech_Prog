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
            Bala(const char* caminhoTextura = "", sf::Vector2f posicao);
            ~Bala();

            void danificar(Personagens::Jogador* pJ);
            void mover();
            void executar();
    };

}