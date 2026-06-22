#pragma once
#include "Personagem.h"
#include <string>

namespace Entidades {
    class Coracao;
    class Faca;
        namespace Personagens {
            namespace Inimigos {
                class Inimigo;
            }
            class Jogador : public Personagem {

            protected:
                int pontos;
                int num_jog;
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
                Entidades::Coracao* Coracoes[3];
                sf::Keyboard::Key keys[4];
                std::string nome;
            public:
                Jogador(const char* caminhoTextura = "", const char* caminhoTexturaCoracao = "", int n = -1);
                ~Jogador();
                Faca* getFaca();
                bool getDirecao();
                bool getAtacando();
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
                void salvar();
                void mover();
                void setNome(std::string s);
                std::string getNome() const;
                int getPontos();
                void setPontos(int n);
            };
        }
    
}