#pragma once
#include "EntidadePertinente.h"

namespace Entidades {
        namespace Personagens {
            class Personagem : public EntidadePertinente {

            protected:
                int num_vidas;
            public:
                Personagem(int vidas = -1);
                ~Personagem();

                void setVidas(int v);
                int getVidas();
                void salvarDataBuffer();
                virtual void executar() = 0;
                virtual void salvar() = 0;
                virtual void mover() = 0;

            };
        }
}