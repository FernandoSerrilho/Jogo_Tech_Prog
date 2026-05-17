#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores {

    class Gerenciador_Grafico {

        private:
            sf::RenderWindow janela;

        public:
            Gerenciador_Grafico();
            ~Gerenciador_Grafico();

            void executar();
            void desenharEnte(Ente* pE);

    };


}