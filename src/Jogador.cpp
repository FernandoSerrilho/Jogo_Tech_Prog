#include "Jogador.h"
#include "Inimigo.h"
#include "Faca.h"
#include "Coracao.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades;
using namespace Personagens;
using namespace Inimigos;

Jogador::Jogador(const char* caminhoTextura, const char* caminhoTexturaCoracao, int n) : nome(""), Personagem(), pontos(0), atacando(false), podeAtacar(true),
modifiVelo(1.0f),lento(false),velBase(5.0f),pulavel(false), invulneravel(false) , 
olhandoEsquerda(false), temp_inv(1.5f),faca(new Faca(this)){
    setFigura(sf::Vector2f(58.0f, 75.0f));
    setText(caminhoTextura, figura);
    setPos(100.0f,800.0f);
    figura.setPosition(pos);
    setVidas(3);
    float inicio;
    if (n == 2) {
        keys[0] = sf::Keyboard::Enter;
        keys[1] = sf::Keyboard::Left;
        keys[2] = sf::Keyboard::Right;
        keys[3] = sf::Keyboard::Up;
        inicio = 1725.0f;
    }
    else {
        keys[0] = sf::Keyboard::E;
        keys[1] = sf::Keyboard::A;
        keys[2] = sf::Keyboard::D;
        keys[3] = sf::Keyboard::W;
        inicio = 25.0f;
    }

    for (int i = 0;i < 3;i++) {
        sf::Vector2f posi(inicio + 60.0f * (float)i, 50.0f);
        Coracoes[i] = new Coracao(posi, caminhoTexturaCoracao);
    }
}

Jogador::~Jogador() { faca = nullptr;delete faca;pontos = -1;for (int i = 0;i < 3;i++) {Coracoes[i] = nullptr;}}

bool Jogador::getDirecao() {return olhandoEsquerda;};

Faca* Jogador::getFaca()  { return faca;}

void Jogador::setNome(std::string s) {nome = s;}

std::string Jogador::getNome() const { return nome; }

void Jogador::setPulavel(bool p) { pulavel = p; }

bool Jogador::getInvulneravel() { return invulneravel;}

void Jogador::initInv() {

    invulneravel = true;
    relogioInv.restart();

}

void Jogador::attInv() {

    if (invulneravel && relogioInv.getElapsedTime().asSeconds() >= temp_inv) {
        invulneravel = false;
    }
}

bool Jogador::getAtacando() { return atacando;}

void Jogador::setmodifiVelo(float v) { modifiVelo = v; }

void Jogador::colidir(Inimigo* pIn) {

    pIn->danificar(this);
}

void Jogador::danificar(Inimigo* pIn) {
    try {
        if (pIn == nullptr) 
            throw nullptr;
       
        if (pIn->getInvulneravel())
            return;

        int v = pIn->getVidas();
        v -= 1;
        pIn->setVidas(v);

        pIn->setInvulneravel(true);
        pIn->getRelogioInv().restart();

        if (v <= 0) {
            pIn->setVivo(false);
            pIn->setPos(2500.0f, 2500.0f);
            std::cout << "morreu" << std::endl;
            return;
        }
        std::cout << "vidas:" << v << std::endl;

    }
    catch (...) {
        std::cerr << "Erro: Ponteiro pra inimigo eh nulo "<< std::endl;
    }
}




void Jogador::atacar() {

    if (sf::Keyboard::isKeyPressed(keys[0]) && !atacando && podeAtacar) {
        atacando = true;
        podeAtacar = false;
        relogioatq.restart();
    }
        faca->initFigura();
      
    if (atacando && relogioatq.getElapsedTime().asSeconds() >= 0.2f) {
        atacando = false;
        cooldownatq.restart();
    }

    if (!atacando && !podeAtacar) {
        if (cooldownatq.getElapsedTime().asSeconds() >= 0.5f) {
            podeAtacar = true;
        }
    }
 }

void Jogador::executar() {
    if (getVidas() > 0) {
        mover();
        attInv();
        atacar();

        desenhar(getPos());

        if (atacando && faca) {
            faca->executar();
        }
        for (int i = 0;i < getVidas();i++) {
            Coracoes[i]->executar();
        }
    }
    else {
        setVivo(false);
        setPos(2500.f, 2500.f);
    }
}

bool Jogador::verificaLent() const {
    return (lento);
}

void Jogador::setLent(bool v) {
    lento = v;
}


void Jogador::mover() {

    float velpulo = 10.0f;
    float tam = 1080.0f -50.0f;

    vel.y += gravidade + contraGravidade;

    if (verificaLent())
        vel.x = velBase * modifiVelo;
    else
        vel.x = velBase;

    if (sf::Keyboard::isKeyPressed(keys[2])) {
        pos.x += vel.x;

        olhandoEsquerda = false;
    }
    if (sf::Keyboard::isKeyPressed(keys[1])) {
        pos.x -= vel.x;

        olhandoEsquerda = true;
    }
    if (sf::Keyboard::isKeyPressed(keys[3]) && pulavel) {
        vel.y -= velpulo;
        setPulavel(false);
    }

    pos.y += vel.y;

    setPos(pos.x,pos.y);
    figura.setPosition(pos);
    modifiVelo = 1.0f;
}