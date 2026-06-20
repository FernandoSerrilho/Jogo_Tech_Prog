#include "Jogo.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "FaseUm.h"
#include "FaseDois.h"

using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades::EntidadesPertinentes;
using namespace Personagens;


Jogo::Jogo() :GG(GG->getGerenciadorG()), j1(new Jogador("Texturas/Jogador/Soldado.png", "Texturas/Jogador/CoracaoVermelho.png",1)),
j2(new Jogador("Texturas/Jogador/SoldadoDois.png", "Texturas/Jogador/CoracaoAzul.png", 2))
,f1(new FaseUm(j1,j2)),f2(new FaseDois(j1,j2)), m(new Menu(this)),j2Ativo(false) , faseatual(0) {
    std::cout << "id j1:" << j1->getID() << std::endl;
    GG->setFrame(60);
    j1->setGG(GG);
}

Jogo::~Jogo() { GG = nullptr;j1 = nullptr;j2 = nullptr;f1 = nullptr;m = nullptr; f2 = nullptr; }

void Jogo::usarJ2() {
    j2Ativo = true;
}

void Jogo::desativarJ2() {
    j2Ativo = false;
    j2->setVivo(false);
}

int Jogo::getFase() {return faseatual;}

Jogador* Jogo::getj1() { return j1; }

Jogador* Jogo::getj2() { return j2; }

const Gerenciador_Grafico* Jogo::getGG (){
    return GG;
}

bool Jogo::statusInif1() {
    return f1->statusInimigos();
}

bool Jogo::statusInif2() {
    return f2->statusInimigos();
}

void Jogo::reiniciarFaseUm() {
    if (!f1)
        delete f1;
    if(j2Ativo && j2)
        f1 = new FaseUm(j1,j2);
    else
        f1 = new FaseUm(j1,nullptr);
    
    faseatual = 1;
}

void Jogo::reiniciarFaseDois() {
    if (!f2)
        delete f2;
    if(j2Ativo && j2)
        f2 = new FaseDois(j1,j2);
    else
        f2 = new FaseDois(j1,nullptr);
    faseatual = 2;

}

void Jogo::reviveJogador(){
        j1->setVidas(3);
        j1->setVivo(true);
        j1->setPos(130.0f,800.0f);
        if (j2Ativo && j2) {
            j2->setVidas(3);
            j2->setVivo(true);
            j2->setPos(65.0f, 800.0f);
        }
}

bool Jogo::jogadorVivo() {
    if (j2Ativo && j2)
        return j1->getVivo() || j2->getVivo();
    else
        return j1->getVivo();
}

void Jogo::executar() {
    m->executar();
}

void Jogo::executarf1() {
    GG->limpaJanela();
    f1->executar();
    if (j1->getVivo()) 
        //j1->executar();
    if(j2Ativo && j2)
        //j2->executar();
    if (!j2Ativo)
        j2->setVivo(false);
    GG->displayJanela();
}

void Jogo::executarf2() {
    GG->limpaJanela();
    f2->executar();
    if (j1->getVivo()) 
        //j1->executar();
    if(j2Ativo && j2)
        //j2->executar();
    if (!j2Ativo)
        j2->setVivo(false);
    GG->displayJanela();
}

void Jogo::desenharf1() {
    f1->desenhar();
    if(j1->getVivo())
        j1->desenhar(j1->getPos());
    if (j2Ativo && j2) {
        if (j2->getVivo())
            j2->desenhar(j2->getPos());
    }
}

void Jogo::desenharf2() {
    f2->desenhar();
    if (j1->getVivo())
        j1->desenhar(j1->getPos());
    if (j2Ativo && j2) {
        if (j2->getVivo())
            j2->desenhar(j2->getPos());
    }
}

void Jogo::salvarJogo() {

    if (faseatual == 1 && f1) {
        f1->salvarFase();
    }
    if (faseatual == 2 && f2) {
        f2->salvarFase();
    }
}

void Jogo::carregarJogo() {
/*    std::ifstream arquivoSave("save.txt");
    if (!arquivoSave.is_open()) {
        std:: cerr << "Sem save encontrado \n";
        return;
    }


    int faseID;

    arquivoSave >> faseID;
    Fase* faseativa = nullptr;

    if (faseID == 1 ) { faseatual = 1; faseativa = f1;}
    else if (faseID == 2) {faseatual = 2; faseativa = f2;}

    if (faseativa) {
        faseativa->limparListEnts();

        int id;

        while (arquivoSave >> id) {
            float px, py , vx , vy;
            bool vivo;

            arquivoSave>> px >> py >> vx >> vy >> vivo;

            if (id == 0 || id == 5) {
                Jogador* j = (id == 0) ? j1 : j2;

                std::string nomeLido;
                int num_jog, pontos;
                bool pulavel, atacando, podeAtacar, lento, invulneravel, olhandoEsquerda;

                arquivoSave >> nomeLido >> num_jog >> pontos >> pulavel >> atacando >> podeAtacar >> lento >> invulneravel >> olhandoEsquerda;

                if (j) {

                j->setPos(px, py);
                j->setVel(vx, vy);
                j->setVivo(vivo);

                j->setNome(nomeLido);

                faseativa->incluirEntidade(j);

                }
            }

            else {}

        }

        arquivoSave.close();

    }


*/

}