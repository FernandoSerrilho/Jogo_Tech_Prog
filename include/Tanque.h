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
                    Jogador* pJ;
                    //Bala* pB;
                    std::vector<Bala*> balas;
                    sf::Clock relogiocooldown;
                    bool podeAtirar;
                    float cooldown;
                public:
                    Tanque(const char* caminhoTextura = "", Jogador* pJ = nullptr);
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