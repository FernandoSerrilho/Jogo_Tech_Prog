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

void Gerenciador_Colisoes::tratarColisoesJogsChao() {

    if (pChao) {


            if (verificarColisao(pJog1,pChao)) {
                pChao->colidir(pJog1);

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
    tratarColisoesJogsChao();
    tratarColisoesJogsInimigs();
    tratarColisoesJogsObstacs();
    tratarColisoesObstacInimigos();
}