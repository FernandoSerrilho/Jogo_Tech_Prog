#pragma once

#include <list>
#include <vector>

namespace Entidades {
    class Chao;
    class Entidade;
    class Projetil;
    namespace Personagens {
        namespace Inimigos {
            class Inimigo;
        }
        class Jogador;
    }
    namespace Obstaculos {
        class Obstaculo;
    }
}

namespace Gerenciadores {

    class Gerenciador_Colisoes {

    private:
        std::vector<Entidades::Personagens::Inimigos::Inimigo*> LIs;
        Entidades::Personagens::Jogador* pJog[2];
        std::vector<Entidades::Obstaculos::Obstaculo*>LOs;
        std::vector<Entidades::Projetil*>LPs;
        Entidades::Chao* pChao;
    private:
        const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
        void tratarColisoesJogsProjeteis();
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimigs();
        void tratarColisoesPlataformaInimigos();
        void tratarColisoesJogsChao();
        void tratarColisoesInimsChao();
        void tratarColisoesJogsLims();
    public:
        Gerenciador_Colisoes(Entidades::Personagens::Jogador* pJ1=nullptr, Entidades::Personagens::Jogador* pJ2=nullptr);
        ~Gerenciador_Colisoes();
        void setChao(Entidades::Chao* pC);
        void IncluirProjetil(Entidades::Projetil* pP);
        void incluirInimigo(Entidades::Personagens::Inimigos::Inimigo* pi);
        void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
        void executar();
        void limparListas();
        bool listaInimigosStatus();
    };





}