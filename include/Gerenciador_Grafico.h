//Agradecimentos ao canal GEGE++ do Youtube, por fornecer uma base para o respectivo arquivo: https://www.youtube.com/channel/UCUa8BOx2F3hlxgPcpZmnBnQ

#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Ente;

namespace Gerenciadores {

    class Gerenciador_Grafico {

        private:
            sf::RenderWindow* janela;
            static Gerenciador_Grafico* pGG;
            Gerenciador_Grafico();

        public:
            ~Gerenciador_Grafico();
            static Gerenciador_Grafico* getGerenciadorG();
            void fechaJanela();
            void limpaJanela();
            const bool VerificajanelaAberta();
            void displayJanela();
            void setFrame(int n);
            sf::RenderWindow* getJanela();
            void desenharEnte(Ente* pE);
            void desenharTexto(sf::Text t);

    };


}