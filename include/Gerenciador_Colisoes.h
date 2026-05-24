#pragma once

#include <list>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Jogador.h"
#include "Inimigo.h"
#include "Entidade.h"




namespace Gerenciadores {

    using namespace Entidades;
    using namespace Entidades::Personagens;

    class Gerenciador_Colisoes {

        private:
            std::vector<Inimigo*> LIs;
            Jogador* pJog1;
        private:
            const bool verificarColisao(Entidade* pe1, Entidade* pe2);
            void tratarColisoesJogsObstacs();
            void tratarColisoesJogsInimigs();
            void tratarColisoesJogsLims();
        public:
            Gerenciador_Colisoes(Jogador* pJ);
            ~Gerenciador_Colisoes();
            void incluirInimigo(Inimigo* pi);
            void executar();
    };





}