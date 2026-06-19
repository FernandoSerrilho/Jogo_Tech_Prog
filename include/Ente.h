#pragma once
#include "SFML/Graphics.hpp"

namespace Gerenciadores {
    class Gerenciador_Grafico;
}

using namespace Gerenciadores;

class Ente {

    protected:
        sf::RectangleShape figura;
        int id;
        static Gerenciador_Grafico* pGG;
        static int cont_id;
        sf::Texture texturaGeral;
        sf::Sprite sprite;
    public:
        Ente();
        virtual ~Ente();
        virtual void executar() = 0;
        int getID();
        void desenhar(sf::Vector2f posicao);
        static void setGG(Gerenciador_Grafico *pG);
        void setText(const char* caminhoTextura, sf::RectangleShape colisao);
        sf::Sprite getSprite();
        sf::RectangleShape getFigura();
        void setFigura(sf::Vector2f tam);
        sf::FloatRect getBounds();
};
