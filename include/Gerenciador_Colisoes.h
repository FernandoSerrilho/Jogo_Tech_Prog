#pragma once

#include <list>
#include <vector>
#include <set>

namespace Entidades {
    class Entidade;
    class Chao;
    namespace EntidadesPertinentes {
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
}

namespace Gerenciadores {

    class Gerenciador_Colisoes {

    private:
        std::list<Entidades::EntidadesPertinentes::Personagens::Inimigos::Inimigo*> LIs;
        Entidades::EntidadesPertinentes::Personagens::Jogador* pJog[2];
        std::vector<Entidades::EntidadesPertinentes::Obstaculos::Obstaculo*>LOs;
        std::set<Entidades::EntidadesPertinentes::Projetil*>LPs;
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
        Gerenciador_Colisoes(Entidades::EntidadesPertinentes::Personagens::Jogador* pJ1=nullptr, Entidades::EntidadesPertinentes::Personagens::Jogador* pJ2=nullptr);
        ~Gerenciador_Colisoes();
        void setChao(Entidades::Chao* pC);
        void IncluirProjetil(Entidades::EntidadesPertinentes::Projetil* pP);
        void incluirInimigo(Entidades::EntidadesPertinentes::Personagens::Inimigos::Inimigo* pi);
        void incluirObstaculo(Entidades::EntidadesPertinentes::Obstaculos::Obstaculo* po);
        void executar();
        void limparListas();
        bool listaInimigosStatus();
    };





}