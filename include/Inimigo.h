#pragma once
#include "Personagem.h"

namespace Entidades {
    namespace EntidadesPertinentes {
        namespace Personagens {

            class Jogador;
            namespace Inimigos {
                class Inimigo : public Personagem {

                protected:
                    int nivel_maldade;
                    bool invulneravel;
                    sf::Clock relogioinv;
                    int pontosDados;
                public:
                    Inimigo();
                    virtual ~Inimigo();

                    void salvarDataBuffer();
                    virtual void executar() = 0;
                    virtual void danificar(Jogador* p) = 0;
                    bool getInvulneravel() const;
                    void setInvulneravel(bool inv);
                    sf::Clock& getRelogioInv();
                    virtual void salvar() = 0;
                    static void sementear();
                    int getPontos();
                };
            }
        }
    }
}
