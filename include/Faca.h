#pragma once

#include "Entidade.h"

namespace Entidades {
    namespace Personagens {
        class Jogador;
    }
}

namespace Entidades {

    class Faca : public Entidade {

        private:
            sf::RectangleShape figura;
            Personagens::Jogador* pJog;

        public:
            Faca(Personagens::Jogador* pJ);
            ~Faca();

        void initFigura();
        void executar();
        sf::RectangleShape* getFigura();
        sf::FloatRect getBounds() const;

    };



}
