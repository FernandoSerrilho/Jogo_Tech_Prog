#pragma once

#include "Personagem.h"
#include "windows.h"
#include "stdlib.h"

namespace Entidades {

namespace Personagens {

class Jogador;


class Inimigo : public Personagem {

    protected: 
        int nivel_maldade;
    public:
        Inimigo();
        ~Inimigo();
        
        //void salvarDataBuffer();     TODO
        virtual void executar() = 0;
        //virtual void danificar(Jogador* p) = 0; TODO
        //virtual void salva() = 0;    TODO
        static void sementear();

};


}
}