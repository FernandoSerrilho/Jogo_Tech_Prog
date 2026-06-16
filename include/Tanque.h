#pragma once
#include "Inimigo.h"
#include <vector>


namespace Entidades {
        class Bala;
    namespace Personagens {
            class Jogador;
        namespace Inimigos {
            class Tanque : public Inimigo {

                private: 
                    std::vector<Bala*> balas;
                    sf::Clock relogiocooldown;
                    bool podeAtirar;
                    float cooldown;
                public:
                    Tanque(const char* caminhoTextura = "");
                    ~Tanque();
                    
                    bool getpodeAtirar();
                    void setPodeAtirar(bool p);

                    void resetClock();
                    void adicionarBala(Bala* b);
                    void atirar();

                    void danificar(Jogador* pJ);     
                    void mover();
                    void executar();

            };
        }
    }
}