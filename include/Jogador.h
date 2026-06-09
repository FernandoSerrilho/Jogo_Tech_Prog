#pragma once
#include "Personagem.h"
#include "Faca.h"

namespace Entidades {
    namespace Personagens {
        class Inimigo;
        class Jogador : public Personagem {

        protected:
            int pontos;
            int vidas;
            sf::RectangleShape figura;
            Faca* faca;
            bool pulavel;
            bool atacando;
            bool podeAtacar;
            float modifiVelo;
            float velBase;
            bool lento;
            bool invulneravel;
            bool olhandoEsquerda;
            sf::Clock relogioInv;
            sf::Clock relogioatq;
            sf::Clock cooldownatq;
            float temp_inv;
        public:
            Jogador(const char* caminhoTextura = "");
            ~Jogador();

            void initFigura();
            Faca* getFaca();
            bool getDirecao();
            bool getAtacando();
            int getVidas();
            void setVidas(int v);
            void setPulavel(bool p);
            void setmodifiVelo(float v);
            bool verificaLent() const;
            void setLent(bool v);
            bool getInvulneravel();
            void initInv();
            void attInv();

            void danificar(Inimigo* pIn);
            void colidir(Inimigo* pIn);
            void atacar();
            void executar();
            //void salvar();                TODO
            void mover();

            void setPos(float x,float y);
            sf::RectangleShape getFigura();
            sf::Vector2f getTam();
            sf::FloatRect getBounds() const;
        };
    }
}