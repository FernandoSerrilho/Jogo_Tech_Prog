#pragma once

#include "EntidadeBase.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}

    class Faca : public EntidadeBase {

    private:
        Entidades::Personagens::Jogador* pJog;

    public:
        Faca(Entidades::Personagens::Jogador* pJ);
        ~Faca();
        void initFigura();
        void executar();

    };
