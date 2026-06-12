#pragma once

#include "Entidade.h"


namespace Entidades {
    namespace Personagens {
        class Jogador;
    }


    class Projetil : public Entidade {

        protected:
            bool ativo;
        
        public:
            Projetil();
            ~Projetil();

            void executar();
            virtual void danificar(Personagens::Jogador* pJ) = 0;
            //void salvar();    TODO;

    };

}