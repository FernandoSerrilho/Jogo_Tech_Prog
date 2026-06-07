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
            float modifiVelo;
            float velBase;
            bool lento;
        public:
            Jogador(const char* caminhoTextura = "");
            ~Jogador();

            void initFigura();
            void setVidas(int v);
            void setPulavel(bool p);
            void setmodifiVelo(float v);
            bool verificaLent() const;
            void setLent(bool v);

            void colidir(Inimigo* pIn);
            void executar();
            //void salvar();                TODO
            void mover();

            void setPos(float x,float y);
            sf::RectangleShape getFigura();
            sf::Vector2f getTam();
            sf::FloatRect getBounds() const;
        };
    }
}