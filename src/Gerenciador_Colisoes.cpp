#include "Gerenciador_Colisoes.h"
#include "Obstaculo.h"
#include <math.h>

using namespace Gerenciadores;
using namespace Entidades;
using namespace Entidades::Personagens;



Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJ) : pJog1(pJ), LIs() {}

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

        std::vector<Inimigo*>::iterator it;
        for (it = LIs.begin(); it != LIs.end(); it++) {

            Inimigo* pIn = *it;

            if (verificarColisao(pJog1, pIn)) {

                pJog1->colidir(pIn);
                pIn->danificar(pJog1);

            }
        }

    }


}

void Gerenciador_Colisoes::tratarColisoesJogsLims() {
    sf::Vector2f lims_sup(0.0f, 0.0f);
    sf::Vector2f lims_inf(800.0f, 550.0f);
    float tam = 24.0f;

    if (pJog1) {

        bool colisao = false;

        sf::Vector2f posJ = pJog1->getPos();

        if (posJ.x <= lims_sup.x) {
            posJ.x = lims_sup.x;
            colisao = true;
        }
        if (posJ.y <= lims_sup.y) {
            posJ.y = lims_sup.y;
            colisao = true;
        }

        else if (posJ.x >= lims_inf.x - tam) {
            posJ.x = lims_inf.x - tam;
            colisao = true;

        }
        else if (posJ.y >= lims_inf.y - tam) {
            posJ.y = lims_inf.y - tam;
            colisao = true;

        }
        if (colisao) {
            pJog1->setPos(posJ);
        }
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
    if (!LOs.empty()) {

        std::vector<Obstaculo*>::iterator it;
        for (it = LOs.begin(); it != LOs.end(); it++) {

            Obstaculo* pOb = *it;

            if (verificarColisao(pJog1, pOb)) {

                pOb->obstaculizar(pJog1);

            }
        }

    }
}

void Gerenciador_Colisoes::executar() {
    tratarColisoesJogsLims();
    tratarColisoesJogsInimigs();
    tratarColisoesJogsObstacs();
    tratarColisoesObstacInimigos();
}