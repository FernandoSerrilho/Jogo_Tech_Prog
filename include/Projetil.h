#pragma once

#include "EntidadePertinente.h"


namespace Entidades {
    namespace Personagens {
        class Jogador;
    }


    class Projetil : public EntidadePertinente {

        protected:
            bool ativo;
        
        public:
            Projetil();
            ~Projetil();

            void executar();
            bool getAtivo();
            void setAtivo(bool a);
            virtual void danificar(Personagens::Jogador* pJ) = 0;
            //void salvar();    TODO;

    };

}