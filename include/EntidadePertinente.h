#pragma once
#include "Entidade.h"
#include <fstream>

namespace Entidades {
        class EntidadePertinente : public Entidade {

        protected:
            sf::Vector2f vel;
            std::ostream& buffer;
            float gravidade;
            float contraGravidade;
        public:
            EntidadePertinente();
            virtual ~EntidadePertinente();
        protected:
            void salvarDataBuffer();
        public:
            virtual void executar() = 0;
            sf::Vector2f getVel();
            void setVel(float vx, float vy);
            void gravitar();
            virtual void salvar() = 0;
        };
}
