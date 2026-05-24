#include "Principal.h"

Principal::Principal() :GG(GG->getGerenciadorGrafico()),j1(new Jogador()), d1(new Drone()) {
    d1->setJog(j1);
    GG->setFrames(60);
}

    Principal::~Principal(){}

    void Principal::executar() {
        while (GG->verificaJanelaAberta()) {
            sf::Event event;
            while (GG->getWindow()->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    GG->fecharJanela();
                else if (event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Escape)
                        GG->fecharJanela();
                }
            }
            GG->limpaJanela();
            j1->executar();
            d1->executar();

            GG->getWindow()->draw(j1->GetColisao());
            GG->getWindow()->draw(d1->getFigura());

            GG->janelaDisplay();
        }
    }