#pragma once
#include "Projetil.h"

namespace Entidades {
    namespace Personagens {
        namespace Inimigos {
            class Tanque;
        }
    }
}

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }

    class Bala : public Projetil {

        private:
            Personagens::Inimigos::Tanque* pTq;
        public:
            Bala(sf::Vector2f posicao = sf::Vector2f(0.0f,0.0f), const char* caminhoTextura = "");
            ~Bala();

            void setTanque(Personagens::Inimigos::Tanque* t);
            void danificar(Personagens::Jogador* pJ);
            void mover();
            void executar();
    };
}