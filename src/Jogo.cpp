#include "Jogo.h"

Jogo::Jogo() :GG(GG->getGerenciadorG()), j1(new Jogador("Texturas/Jogador/Soldado_Parado.png"))
,f1(new FaseUm(j1)) {
    GG->setFrame(60);
    j1->setGG(GG);
    f1->inicializar(j1);
}

Jogo::~Jogo() {}

void Jogo::executar() {
    while (GG->VerificajanelaAberta()) {
        sf::Event event;
        while (GG->getJanela()->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                GG->fechaJanela();
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    GG->fechaJanela();
            }
        }
        GG->limpaJanela();
        f1->executar();
        j1->executar();
        GG->displayJanela();
    }
}
