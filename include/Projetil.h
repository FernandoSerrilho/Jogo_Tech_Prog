#pragma once

#include "EntidadePertinente.h"


namespace Entidades {
    namespace Personagens {
        class Jogador;
        namespace Inimigos {
            class Tanque;
        }
    }


    class Projetil : public EntidadePertinente {

        protected:
            bool ativo;
        private:
            Personagens::Inimigos::Tanque* pTq;
        public:
            Projetil(sf::Vector2f posicao = sf::Vector2f(0.0f,0.0f), const char* caminhoTextura = "");
            ~Projetil();

            void setTanque(Personagens::Inimigos::Tanque* t);
            void danificar(Personagens::Jogador* pJ);

            void mover();
            void executar();

            bool getAtivo();
            void setAtivo(bool a);
            //void salvar();    TODO;

    };

}