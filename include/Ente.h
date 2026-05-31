#pragma once
#include "SFML/Graphics.hpp"

namespace Gerenciadores {
    class Gerenciador_Grafico;
}

using namespace Gerenciadores;

class Ente {

    protected:
        int id;
        static Gerenciador_Grafico* pGG;
        static int cont_id;
        sf::Texture texturaGeral;
        sf::Sprite sprite;
    public:
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        void desenhar(sf::Vector2f posicao);
        static void setGG(Gerenciador_Grafico *pG);
        void setTexturas(sf::Texture pT, sf::Sprite pS);
        void setText(const char* caminhoTextura, sf::RectangleShape colisao);
        sf::Sprite getSprite();
};
