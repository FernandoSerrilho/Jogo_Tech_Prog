#pragma once

#include "Entidade.h"

namespace Entidades {


    class Projetil : public Entidade {

        protected:
            bool ativo;
            sf::RectangleShape figura;

        public:
            Projetil(bool a);
            ~Projetil();

            void executar();

            
            sf::RectangleShape getFigura();
            sf::Vector2f getPos();
            sf::Vector2f getVel();
            sf::Vector2f getTam();
            void setPos(sf::Vector2f npos);
            void setVel(sf::Vector2f nvel);
            sf::FloatRect getBounds() const;



};

}