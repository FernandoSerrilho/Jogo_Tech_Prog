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
        public:
            Jogador(const char* caminhoTextura = "");
            ~Jogador();

            void initFigura();
            void setVidas(int v);

            void colidir(Inimigo* pIn);
            void executar();
            //void salvar();                TODO
            void mover();

            sf::RectangleShape getFigura();
            sf::Vector2f getPos();
            sf::Vector2f getTam();
            void setPos(sf::Vector2f npos);
            sf::FloatRect getBounds() const;
        };
    }
}