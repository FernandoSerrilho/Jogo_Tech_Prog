#pragma once

#include "Entidade.h"

namespace Entidades {
    namespace EntidadesPertinentes {
        namespace Personagens {
            class Jogador;
        }
    }

    class Faca : public Entidade {

    private:
        Entidades::EntidadesPertinentes::Personagens::Jogador* pJog;

    public:
        Faca(Entidades::EntidadesPertinentes::Personagens::Jogador* pJ);
        ~Faca();
        void initFigura();
        void executar();

    };
}
