#pragma once
#include "Inimigo.h"

namespace Entidades {
        namespace Personagens {
            class Jogador;
            namespace Inimigos {
                class Drone : public Inimigo {

                private:
                    Entidades::Personagens::Jogador* pJ[2];
                    bool emKnockback;
                    sf::Clock relogioKnockback;
                    sf::Vector2f vetorKnockback;

                public:
                    Drone(Jogador* p1 = NULL, Jogador* p2 = NULL, const char* caminhoTextura = "");
                    ~Drone();
                    void danificar(Jogador* p);
                    void setEmKnockback(bool k);
                    void setJog(Jogador* p, int n);
                    void executar();
                    void mover();
                    void colidir(Jogador* j);
                    void salvar();
                };
            }
        }
    
}