#pragma once
#include "Personagem.h"

namespace Entidades {
    class Faca;
    class Coracao;
    namespace Personagens {
        namespace Inimigos {
            class Inimigo;
        }
    }
}

namespace Entidades {
    namespace Personagens {
        class Jogador : public Personagem {

        protected:
            int pontos;
            int vidas;
            sf::RectangleShape figura;
            Entidades::Faca* faca;
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
            Coracao* Coracoes[3];
            sf::Keyboard::Key keys[4];
        public:
            Jogador(const char* caminhoTextura = "", const char* caminhoTexturaCoracao = "",int n =-1);
            ~Jogador();

            void initFigura();
            Entidades::Faca* getFaca();
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

            void danificar(Entidades::Personagens::Inimigos::Inimigo* pIn);
            void colidir(Entidades::Personagens::Inimigos::Inimigo* pIn);
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