#pragma once

#include "Personagem.h"

namespace Entidades {

namespace Personagens {


class Jogador : public Personagem {

    protected:
        int pontos;
        sf::RectangleShape figura;


    public:
        Jogador();
        ~Jogador();

        void initFigura();

        //void colidir(Inimigo* pIn);   TODO
        void executar();
        //void salvar();                TODO
        void mover();

        sf::RectangleShape getFigura();
        sf::Vector2f getPos();

};

















}
}