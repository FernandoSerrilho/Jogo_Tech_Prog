#pragma once
#include "Personagem.h"
using namespace Personagens;

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
            virtual void danificar(Jogador* p) = 0; 
            virtual void colidir(Entidade* pJ) = 0;
            //virtual void salva() = 0;    TODO
            static void sementear();

        };
    }
}
