#pragma once
#include "Personagem.h"

namespace Entidades {
    namespace Personagens {

        class Jogador;
        namespace Inimigos {
            class Inimigo : public Personagem {

            protected:
                int nivel_maldade;
                bool invulneravel;
                sf::Clock relogioinv;
            public:
                Inimigo();
                virtual ~Inimigo();

                //void salvarDataBuffer();     TODO
                virtual int getVidas() = 0;
                virtual void setVidas(int v) = 0;
                virtual void executar() = 0;
                virtual void danificar(Jogador* p) = 0;
                virtual void colidir(Jogador* j) = 0;
                bool getInvulneravel() const;
                void setInvulneravel(bool inv);
                sf::Clock& getRelogioInv();
                //virtual void salva() = 0;    TODO
                static void sementear();

            };
        }
    }
}
