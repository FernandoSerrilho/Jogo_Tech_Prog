#include "Jogo.h"
#include "Menu.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Drone.h"
#include "Arbusto.h"
#include "Plataforma.h"
#include "Tanque.h"
#include "Projetil.h"
#include "Soldado.h"
#include "MinaTerrestre.h"
#include "FaseUm.h"
#include "FaseDois.h"

using namespace Fases;
using namespace Gerenciadores;
using namespace Entidades::EntidadesPertinentes;
using namespace Personagens;
using namespace Personagens::Inimigos;
using namespace Obstaculos;


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
    if (!j2Ativo)
        j2->setVivo(false);
    GG->displayJanela();
}

void Jogo::executarf2() {
    GG->limpaJanela();
    f2->executar();
    if (!j2Ativo)
        j2->setVivo(false);
    GG->displayJanela();
}

void Jogo::desenharf1() {
    f1->desenhar();
}

void Jogo::desenharf2() {
    f2->desenhar();
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
    std::ifstream arquivoSave("save.txt");
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
        faseativa->carregarFase(arquivoSave, j1 , j2 , j2Ativo);
    }

    arquivoSave.close();

  /*   if (!faseativa) { arquivoSave.close(); return;}

        faseativa->limparGC();
        faseativa->limparListEnts();

        std::vector<int> idsTanquesSave;
        std::vector<Tanque*> tanquesNovos;

        std::vector<int> idsTanqueDaBala;
        std::vector<Projetil*> balasPendentes;

        std::string tipoLido;

        while (arquivoSave >> tipoLido) {
            int id; 
            float px, py , vx , vy;
            bool vivo;

            arquivoSave>> id >> px >> py >> vx >> vy >> vivo;

            if (tipoLido == "Jogador") {
                int vidas, num_jog, pontos;
                bool pulavel, atacando, podeAtacar, lento, invulneravel, olhandoEsquerda;
                std::string nomeLido;

                arquivoSave >> vidas;
                arquivoSave >> nomeLido >> num_jog >> pontos >> pulavel >> atacando >> podeAtacar >> lento >> invulneravel >> olhandoEsquerda;

                Jogador* j = (num_jog == 1) ? j1 : j2;

                if (j) {
                j->setPos(px, py); 
                j->setVel(vx, vy);  
                j->setVivo(vivo);
                j->setVidas(vidas);
                j->setNome(nomeLido);
                j->setPontos(pontos);
                j->setPulavel(pulavel);
                j->setLent(lento);
                faseativa->incluirEntidade(j);
                
                if (num_jog == 2) {j2Ativo = true;}
                }
            }

            else if (tipoLido == "Drone") {
                int vidas, nivel; bool inv, emKnock;
                arquivoSave >> vidas >> nivel >> inv >> emKnock;

                Drone* d = new Drone(j1, j2, "Texturas/Drone/drone_somente.png");
                d->setPos(px, py);
                d->setVel(vx, vy);
                d->setVivo(vivo);
                d->setVidas(vidas);
                d->setNivelMaldade(nivel);
                d->setInvulneravel(inv);
                d->setEmKnockback(emKnock);
                faseativa->incluirInimigo(d);
        }
            else if (tipoLido == "Soldado") {
                int vidas, nivel; bool inv, parado; float tempoParado;
                arquivoSave >> vidas >> nivel >> inv >> parado >> tempoParado;

                Soldado* s = new Soldado(sf::Vector2f(px, py), "Texturas/Soldado/SoldadoInimigo.png");
                s->setPos(px, py);
                s->setVel(vx, vy);
                s->setVivo(vivo);
                s->setVidas(vidas);
                s->setNivelMaldade(nivel);
                s->setInvulneravel(inv);
                s->setParado(parado);
                faseativa->incluirInimigo(s);
        }
            else if (tipoLido == "Tanque") {
                int vidas, nivel; bool inv, podeAtirar; float cooldown;
                arquivoSave >> vidas >> nivel >> inv >> podeAtirar >> cooldown;

                Tanque* t = new Tanque("Texturas/Tanque/tanque.png");
                t->setPos(px, py);
                t->setVel(vx, vy);
                t->setVivo(vivo);
                t->setVidas(vidas);
                t->setNivelMaldade(nivel);
                t->setInvulneravel(inv);
                t->setPodeAtirar(podeAtirar);
                faseativa->incluirInimigo(t);

               
                idsTanquesSave.push_back(id);
                tanquesNovos.push_back(t);
        }
        else if (tipoLido == "Projetil") {
            bool ativo; int idTanqueSalvo;
            arquivoSave >> ativo >> idTanqueSalvo;

            Projetil* b = new Projetil(sf::Vector2f(px, py), "Texturas/Tanque/Bala.png");
            b->setPos(px, py);
            b->setVel(vx, vy);
            b->setVivo(vivo);
            b->setAtivo(ativo);
            faseativa->incluirProjetil(b);

            if (idTanqueSalvo != -1) {
                idsTanqueDaBala.push_back(idTanqueSalvo);
              balasPendentes.push_back(b);
            }
        }
        else if (tipoLido == "Arbusto") {
            bool danoso;
            float lentidao;
            arquivoSave >> danoso >> lentidao;

            Arbusto* a = new Arbusto(sf::Vector2f(px, py), sf::Vector2f(29.0f, 17.0f));
            a->setPos(px, py);
            a->setVel(vx, vy);
            a->setVivo(vivo);
            faseativa->incluirObstaculo(a);
        }
        else if (tipoLido == "Plataforma") {
            bool danoso; int altura;
            arquivoSave >> danoso >> altura;

            Plataforma* p = new Plataforma(sf::Vector2f(px, py), sf::Vector2f(300.0f, 42.0f));
            p->setPos(px, py);
            p->setVel(vx, vy);
            p->setVivo(vivo);
            faseativa->incluirObstaculo(p);
        }
        else if (tipoLido == "MinaTerrestre") {
            bool danoso; float tempoAtivacao, raio; bool tempoAtivo;
            arquivoSave >> danoso >> tempoAtivacao >> raio >> tempoAtivo;

            MinaTerrestre* m = new MinaTerrestre(sf::Vector2f(px, py), sf::Vector2f(29.0f, 10.0f));
            m->setPos(px, py);
            m->setVel(vx, vy);
            m->setVivo(vivo);
            m->setTempoAtivo(tempoAtivo);
            m->setraio(raio);
            faseativa->incluirObstaculo(m);
        }
        else {
            std::string lixo;
            std::getline(arquivoSave, lixo);
        }

        for (size_t i = 0; i < balasPendentes.size(); i++) {
        int idProcurado = idsTanqueDaBala[i];
        Tanque* tanqueEncontrado = nullptr;

        for (size_t j = 0; j < idsTanquesSave.size(); j++) {
            if (idsTanquesSave[j] == idProcurado) {
                tanqueEncontrado = tanquesNovos[j];
                break;
            }
        }

        if (tanqueEncontrado) {
            tanqueEncontrado->setPodeAtirar(false); 
            tanqueEncontrado->adicionarBala(balasPendentes[i]);
            balasPendentes[i]->setTanque(tanqueEncontrado);
        }
}




        }

        arquivoSave.close();
 */
 }
