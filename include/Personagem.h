#pragma once
#include "Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Personagem : public Entidade {

        protected:
            int num_vidas;
        public:
            Personagem(int vidas = -1);
            ~Personagem();

            void setVidas(int v);
            int getVidas();
            //void salvarDataBuffer();          TODO
            virtual void executar() = 0;
            //virtual void salvar() = 0;        TODO
            virtual void mover() = 0;

        };

    }
}