#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Drone.h"

using namespace Personagens;

using namespace Gerenciadores;


Gerenciador_Grafico::Gerenciador_Grafico() : janela(sf::VideoMode(800, 600), "Teste SFML - UTFPR") 
{    
    executar();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {}

void Gerenciador_Grafico::executar() {

    Jogador* j1 = new Jogador();
    Drone* d1 = new Drone();
    d1->setJog(j1);
    janela.setFramerateLimit(60);

     while (janela.isOpen()) {
        sf::Event event;
        while (janela.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                janela.close();
            else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                janela.close();
        }
    }
        janela.clear();
        j1->executar();
        d1->executar();

        janela.draw(j1->getFigura());
        janela.draw(d1->getFigura());

        janela.display();
    }

}

void Gerenciador_Grafico::desenharEnte(Ente* pE) {

    

}