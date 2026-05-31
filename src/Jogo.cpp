#include "Jogo.h"

Jogo::Jogo() :GG(GG->getGerenciadorG()), j1(new Jogador("Texturas/Jogador/Soldado_Parado.png")), 
d1(new Drone(NULL,"Texturas/Drone/drone_somente.png")),
p1(new Plataforma(sf::Vector2f(400.0f, 420.0f), sf::Vector2f(400.0f, 42.0f))),
chao("Texturas/Grama/Grama_QuadradoSemBorda.png"), pGC(NULL) {
    d1->setJog(j1);
    GG->setFrame(60);
    pGC = new Gerenciador_Colisoes(j1);
    p1->setGG(GG);
    //pGC->incluirObstaculo(static_cast<Obstaculo*> (p1));
}

    Jogo::~Jogo(){}

    void Jogo::executar() {
        pGC->incluirInimigo(static_cast<Inimigo*>(d1));
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
            j1->executar();
            pGC->executar();
            d1->executar();
            p1->executar();
            chao.executar();

            GG->displayJanela();
        }
    }