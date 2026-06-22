#pragma once
#include "Entidade.h"
#include <fstream>

namespace Entidades {
        class EntidadePertinente : public Entidade {

        protected:
            sf::Vector2f vel;
            static std::ofstream buffer;
            float gravidade;
            float contraGravidade;
        public:
            EntidadePertinente();
            virtual ~EntidadePertinente();

            static void abrirArquivo(const std::string& caminho);
            static void fecharArquivo();
            static std::ofstream& getArquivo();
        protected:
            void salvarDataBuffer();
        public:
            virtual void executar() = 0;
            sf::Vector2f getVel();
            void setVel(float vx, float vy);
            void gravitar();
            virtual void salvar() = 0;
        };
}
