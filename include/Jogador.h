#pragma once
#include "Personagem.h"

namespace Entidades {
    namespace Personagens {
        class Inimigo;
        class Jogador : public Personagem {

        protected:
            int pontos;
            int vidas;
            sf::RectangleShape figura;
            bool pulavel;
        public:
            Jogador(const char* caminhoTextura = "");
            ~Jogador();

            void initFigura();
            void setVidas(int v);
            void setPulavel(bool p);

            void colidir(Inimigo* pIn);
            void executar();
            //void salvar();                TODO
            void mover();

            sf::RectangleShape getFigura();
            sf::Vector2f getPos();
            sf::Vector2f getVel();
            sf::Vector2f getTam();
            void setPos(sf::Vector2f npos);
            void setVel(sf::Vector2f nvel);
            sf::FloatRect getBounds() const;
        };
    }
}