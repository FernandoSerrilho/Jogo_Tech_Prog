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

        public:
            Faca();
            ~Faca();

        void initFigura(Personagens::Jogador * j, bool olhandoesquerda);
        void executar();
        sf::RectangleShape* getFigura();
        sf::FloatRect getBounds() const;

    };



}
