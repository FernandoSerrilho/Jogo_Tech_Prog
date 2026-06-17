#pragma once

#include "Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}

    class Faca : public Entidade {

    private:
        Entidades::Personagens::Jogador* pJog;

    public:
        Faca(Entidades::Personagens::Jogador* pJ);
        ~Faca();
        void initFigura();
        void executar();

    };
