#include "Jogo.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "FaseUm.h"

using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;


Jogo::Jogo() :GG(GG->getGerenciadorG()), j1(new Jogador("Texturas/Jogador/Soldado.png"))
,f1(new FaseUm(j1)),m(new Menu(this)) {
    GG->setFrame(60);
    j1->setGG(GG);
    f1->inicializar(j1);
}

Jogo::~Jogo() { GG = nullptr;j1 = nullptr;f1 = nullptr;m = nullptr; }

const Gerenciador_Grafico* Jogo::getGG (){
    return GG;
}

bool Jogo::statusIni() {
    return f1->statusInimigos();
}

void Jogo::reiniciarFaseUm() {
    if (!f1)
        delete f1;
    f1 = new FaseUm(j1);
    f1->inicializar(j1);
}

void Jogo::reviveJogador(){
    if (!j1->getVivo()) {
        j1->setVidas(3);
        j1->setVivo(true);
        j1->setPos(100.0f,800.0f);
    }
}

bool Jogo::jogadorVivo() { return j1->getVivo(); }

void Jogo::executar() {
    m->executar();
}

void Jogo::executarf1() {
    if (j1->getVivo()) {
        GG->limpaJanela();
        f1->executar();
        j1->executar();
        GG->displayJanela();
    }
    return;
}

void Jogo::desenhar() {
    f1->desenhar();
    if(j1->getVivo())
        j1->desenhar(j1->getPos());
}
