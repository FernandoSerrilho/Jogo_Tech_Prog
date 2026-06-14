#pragma once
#include "Inimigo.h"
#include <vector>


namespace Entidades {
        class Bala;
    namespace Personagens {
            class Jogador;
        namespace Inimigos {

            class Tanque : public Inimigo {

                private: 
                    Jogador* pJ;
                    //Bala* pB;
                    std::vector<Bala*> balas;
                    sf::Clock relogiocooldown;
                    bool podeAtirar;
                    float cooldown;
                    float raio;
                    int vidas;
                    sf::RectangleShape figura;
                public:
                    Tanque(const char* caminhoTextura = "", Jogador* pJ = nullptr);
                    ~Tanque();
                    
                    bool getpodeAtirar();
                    void setPodeAtirar(bool p);

                    void resetClock();
                    void adicionarBala(Bala* b);
                    void atirar();

                    void setVidas(int v);
                    int getVidas();

                    sf::RectangleShape getFigura();
                    void initFigura();
                    sf::FloatRect getBounds() const;

                    void danificar(Jogador* pJ);
                    void colidir(Jogador* pJ);       
                    void mover();
                    void executar();

            };
        }
    }
}