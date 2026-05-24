#pragma once

#include "Personagem.h"
#include "Inimigo.h"

namespace Entidades {

namespace Personagens {



class Jogador : public Personagem {

    protected:
        int pontos;
        int vidas;
        sf::RectangleShape figura;


    public:
        Jogador();
        ~Jogador();

        void initFigura();
        void setVidas(int v);

        void colidir(Inimigo* pIn);
        void executar();
        //void salvar();                TODO
        void mover();

        sf::RectangleShape getFigura();
        sf::Vector2f getPos();
        void setPos(sf::Vector2f npos);
        sf::FloatRect getBounds() const;

};

















}
}