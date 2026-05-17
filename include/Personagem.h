#pragma once

#include "Entidade.h"

using namespace Entidades;

namespace Entidades {

namespace Personagens {


class Personagem : public Entidade {

    protected:
        int num_vidas;
    public:
        Personagem();
        ~Personagem();
        
        //void salvarDataBuffer();          TODO
        virtual void executar() = 0;
        //virtual void salvar() = 0;        TODO
        virtual void mover() = 0;

};

}
}