#pragma once
#include "Inimigo.h"
#include <vector>


namespace Entidades {
        namespace EntidadesPertinentes{
            class Projetil;
            namespace Personagens {
                class Jogador;
                namespace Inimigos {
                    class Tanque : public Inimigo {

                    private:
                        std::vector<Entidades::EntidadesPertinentes::Projetil*> balas;
                        sf::Clock relogiocooldown;
                        bool podeAtirar;
                        float cooldown;
                    public:
                        Tanque(const char* caminhoTextura = "");
                        ~Tanque();

                        bool getpodeAtirar();
                        void setPodeAtirar(bool p);

                        void resetClock();
                        void adicionarBala(Entidades::EntidadesPertinentes::Projetil* b);
                        void atirar();

                        void danificar(Entidades::EntidadesPertinentes::Personagens::Jogador* pJ);
                        void mover();
                        void executar();
                        void salvar();

                    };
                }
            }
    }
}