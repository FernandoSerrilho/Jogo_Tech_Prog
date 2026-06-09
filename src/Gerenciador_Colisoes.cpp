#include "Gerenciador_Colisoes.h"
#include "Obstaculo.h"
#include <math.h>
#include <iostream>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Entidades::Personagens;



Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJ) : pJog1(pJ), pChao(NULL),LIs() {}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}


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
        std::vector<Inimigo*>::iterator it = LIs.begin();

        while (it != LIs.end()) {
            Inimigo* pIn = *it;
            if (*it) {
                if (pIn->getVivo()) {
                    if (verificarColisao(pJog1, pIn)) {
                        pJog1->colidir(pIn);
                    }
                    if (pJog1->getAtacando() && verificarColisao(pJog1->getFaca(), pIn)) {
                        pJog1->danificar(pIn);
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

void Gerenciador_Colisoes::tratarColisoesJogsChao() {
    if (pChao) {

        if (verificarColisao(pJog1,pChao)) {
            pChao->colidir(pJog1);

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

        std::vector<Obstaculo*>::iterator it;
        it = LOs.begin();
        while(it != LOs.end()) {

            Obstaculo* pOb = *it;

            if (pOb) {
                if (pOb->getVivo()) {
                    if (verificarColisao(pJog1, pOb)) {
                        pOb->obstaculizar(pJog1);
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

void Gerenciador_Colisoes::tratarColisoesJogsLims() {

    sf::Vector2f pos = pJog1->getPos();
    sf::FloatRect bounds = pJog1->getBounds();


    if (pos.x <= 0.0f) {

        pJog1->setPos(0.0f,pos.y);
    }
    if (pos.x + bounds.width >= 1920.0f) {

        pJog1->setPos(1920.0f - bounds.width, pos.y );

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