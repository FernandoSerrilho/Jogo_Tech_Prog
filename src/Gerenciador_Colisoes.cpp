#include "Gerenciador_Colisoes.h"
#include "Obstaculo.h"
#include "Chao.h"
#include "Inimigo.h"
#include "Jogador.h"
#include "Projetil.h"
#include "Faca.h"
#include <math.h>
#include <iostream>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;
using namespace Inimigos;

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJ1, Jogador* pJ2) :pChao(NULL), LIs() { pJog[0] = pJ1; pJog[1] = pJ2; }

Gerenciador_Colisoes::~Gerenciador_Colisoes() { LIs.clear(); LOs.clear(); pJog[0] = nullptr;pJog[1] = nullptr;pChao = nullptr; }

void Gerenciador_Colisoes::limparListas() {
    LIs.clear();
    LOs.clear();
    LPs.clear();
}

void Gerenciador_Colisoes::IncluirProjetil(Projetil* pP) {
    if (pP) {
        LPs.push_back(pP);
    }

}

void Gerenciador_Colisoes::incluirInimigo(Inimigo* pI) {
    if (pI) {
        LIs.push_back(pI);
    }

}

void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* pO) {
    if (pO) {
        LOs.push_back(pO);
    }

}

void Gerenciador_Colisoes::setChao(Chao* pC) {

    pChao = pC;

}

void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {
    if (!LPs.empty()) {
        std::vector<Projetil*>::iterator it;

        for (it = LPs.begin(); it != LPs.end(); it++) {
            
            Projetil* pP = *it;

                if (verificarColisao(pP, pJog[0])) {
                    pP->danificar(pJog[0]);
                }

        }
    }
}

void Gerenciador_Colisoes::tratarColisoesObstacInimigos() {
    if (!LIs.empty() && !LOs.empty()) {

        std::vector<Inimigo*>::iterator it;
        for (it = LIs.begin(); it != LIs.end(); it++) {

            Inimigo* pIn = *it;
            std::vector<Obstaculo*>::iterator it2;
            for (it2 = LOs.begin();it2 != LOs.end();it2++) {
                Obstaculo* pOb = *it2;

                if (verificarColisao(pOb, pIn)) {
                    pOb->obstaculizar(pIn);
                }
            }
        }

    }
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) {

    if (pe1 != NULL && pe2 != NULL) {

        return pe1->getBounds().intersects(pe2->getBounds());

    }
    else
        return false;
}

void Gerenciador_Colisoes::tratarColisoesJogsInimigs() {
    if (!LIs.empty()) {

        for (int i = 0;i < 2;i++) {
            if (pJog[i]) {
                std::vector<Inimigo*>::iterator it = LIs.begin();
                while (it != LIs.end()) {
                    Inimigo* pIn = *it;
                    if (*it) {
                        if (pIn->getVivo()) {
                            if (verificarColisao(pJog[i], pIn)) {
                                pJog[i]->colidir(pIn);
                            }
                            if (pJog[i]->getAtacando() && verificarColisao(pJog[i]->getFaca(), pIn)) {
                                pJog[i]->danificar(pIn);
                            }
                            it++;
                        }
                        else {
                            it = LIs.erase(it);
                        }
                    }
                    else {
                        it = LIs.erase(it);
                    }
                }
            }
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsChao() {
    if (pChao) {
        for (int i = 0;i < 2;i++) {
            if (pJog[i]) {
                if (verificarColisao(pJog[i], pChao)) {
                    pChao->colidir(pJog[i]);
                }
            }
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesInimsChao() {
    if (pChao && !LIs.empty()) {
        std::vector<Inimigo*>::iterator it;
        for (it = LIs.begin(); it != LIs.end(); it++) {
            Inimigo* pIn = *it;
            if (pIn && pIn->getVivo()) {
                if (verificarColisao(pIn, pChao)) {
                    pChao->colidir(pIn);
                }
            }
        }
    }
}
void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
    if (!LOs.empty()) {
        for (int i = 0;i < 2;i++) {
            if (pJog[i]) {
                std::vector<Obstaculo*>::iterator it;
                it = LOs.begin();
                while (it != LOs.end()) {

                    Obstaculo* pOb = *it;

                    if (pOb) {
                        if (pOb->getVivo()) {
                            if (verificarColisao(pJog[i], pOb)) {
                                pOb->obstaculizar(pJog[i]);
                            }
                            it++;
                        }
                        else
                            it = LOs.erase(it);
                    }
                    else
                        it = LOs.erase(it);
                }
            }
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsLims() {
    for (int i = 0;i < 2;i++) {
        if (pJog[i]) {
            sf::Vector2f pos = pJog[i]->getPos();
            sf::FloatRect bounds = pJog[i]->getBounds();


            if (pos.x <= 0.0f) {

                pJog[i]->setPos(0.0f, pos.y);
            }
            if (pos.x + bounds.width >= 1920.0f) {

                pJog[i]->setPos(1920.0f - bounds.width, pos.y);

            }
        }
    }
}

void Gerenciador_Colisoes::executar() {
    tratarColisoesJogsChao();
    tratarColisoesInimsChao();
    tratarColisoesJogsInimigs();
    tratarColisoesJogsObstacs();
    tratarColisoesObstacInimigos();
    tratarColisoesJogsLims();
}

bool Gerenciador_Colisoes::listaInimigosStatus() {
    return LIs.empty();
}