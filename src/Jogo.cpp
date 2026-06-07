#include "Jogo.h"

Jogo::Jogo() :GG(GG->getGerenciadorG()), j1(new Jogador("Texturas/Jogador/Soldado.png"))
,f1(new FaseUm(j1)),m(new Menu(this)) {
    GG->setFrame(60);
    j1->setGG(GG);
    f1->inicializar(j1);
}

Jogo::~Jogo() {}

const Gerenciador_Grafico* Jogo::getGG (){
    return GG;
}

void Jogo::executar() {
    m->executar();
}

void Jogo::executarf1() {
    GG->limpaJanela();
    f1->executar();
    j1->executar();
    GG->displayJanela();
}

void Jogo::desenhar() {
    f1->desenhar();
    j1->desenhar(j1->getPos());
}
