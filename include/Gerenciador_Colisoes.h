#pragma once

#include <list>
#include <vector>
#include "Inimigo.h"
#include "Jogador.h"
#include "Chao.h"
//#include "Obstaculo.h"

namespace Entidades {
    namespace Obstaculos {
        class Obstaculo;
    }
}
using namespace Entidades::Obstaculos;


using namespace Entidades;
using namespace Personagens;
using namespace Obstaculos;

namespace Gerenciadores {

    class Gerenciador_Colisoes {

    private:
        std::vector<Inimigo*> LIs;
        Jogador* pJog1;
        std::vector<Obstaculo*>LOs;
        Chao* pChao;
    private:
        const bool verificarColisao(Entidade* pe1, Entidade* pe2);
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimigs();
        void tratarColisoesObstacInimigos();
        void tratarColisoesJogsChao();
        void tratarColisoesInimsChao();
        void tratarColisoesJogsLims();
    public:
        Gerenciador_Colisoes(Jogador* pJ);
        ~Gerenciador_Colisoes();
        void setChao(Chao* pC);
        void incluirInimigo(Inimigo* pi);
        void incluirObstaculo(Obstaculo* po);
        void executar();
    };





}