#pragma once
#include "Inimigo.h"
#include <vector>


namespace Entidades {
            class Projetil;
            namespace Personagens {
                class Jogador;
                namespace Inimigos {
                    class Tanque : public Inimigo {

                    private:
                        std::vector<Entidades::Projetil*> balas;
                        sf::Clock relogiocooldown;
                        bool podeAtirar;
                        float cooldown;
                    public:
                        Tanque(const char* caminhoTextura = "");
                        ~Tanque();

                        bool getpodeAtirar();
                        void setPodeAtirar(bool p);

                        void resetClock();
                        void adicionarBala(Entidades::Projetil* b);
                        void atirar();

                        void danificar(Entidades::Personagens::Jogador* pJ);
                        void mover();
                        void executar();
                        void salvar();

                    };
                }
            }
}