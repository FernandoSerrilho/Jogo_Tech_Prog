#include "Jogador.h"
#include "Inimigo.h"
#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace Entidades;
using namespace Personagens;

Jogador::Jogador(const char* caminhoTextura) : Personagem(), pontos(0), vidas(3), figura(sf::Vector2f(58.0f, 75.0f)), atacando(false) ,podeAtacar(true), 
modifiVelo(1.0f),lento(false),velBase(5.0f),pulavel(false), invulneravel(false) , olhandoEsquerda(false), temp_inv(1.5f),faca(new Faca()) {
    initFigura();
    setText(caminhoTextura, figura);
    setPos(100.0f,800.0f);
}

Jogador::~Jogador() {

    delete faca;
}

void Jogador::initFigura() {

    figura.setFillColor(sf::Color::Blue);
    figura.setPosition(pos);
}

int Jogador::getVidas() { return vidas; }

Faca* Jogador::getFaca()  { return faca;}

void Jogador::setVidas(int v) { vidas = v; if (v <= 0) setVivo(false); std::cout << vidas << std::endl; }

void Jogador::setPos(float x, float y){
    pos.x = x;
    pos.y = y;
    figura.setPosition(x, y);
}

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

sf::RectangleShape Jogador::getFigura() { return figura; }

sf::Vector2f Jogador::getTam() { return figura.getSize(); }

bool Jogador::getAtacando() { return atacando;}

void Jogador::setmodifiVelo(float v) { modifiVelo = v; }


sf::FloatRect Jogador::getBounds() const {

    return figura.getGlobalBounds();

}

void Jogador::colidir(Inimigo* pIn) {

    pIn->danificar(this);
}


void Jogador::danificar(Inimigo* pIn) {


    if (pIn->getInvulneravel()) {
        return;
    }

    int v = pIn->getVidas();

    v -= 1;

    pIn->setInvulneravel(true);
    pIn->getRelogioInv().restart();

    if (v <= 0) {

        pIn->setVivo(false);

        pIn->setPos(2500.0f,2500.0f);

        std::cout << "morreu" << std::endl;

        return;
    }

    pIn->setVidas(v);

    std::cout << "vidas:" << v << std::endl;

}




void Jogador::atacar() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !atacando && podeAtacar) {
        atacando = true;
        podeAtacar = false;
        relogioatq.restart();

    }

        faca->initFigura(this, olhandoEsquerda);
        

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


    mover();
    attInv();
    atacar();

    desenhar(getPos());

    if (atacando && faca) {
        faca->executar();
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        pos.x += vel.x;

        olhandoEsquerda = false;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        pos.x -= vel.x;

        olhandoEsquerda = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && pulavel) {
        vel.y -= velpulo;
        setPulavel(false);
    }

    pos.y += vel.y;

    setPos(pos.x,pos.y);
    modifiVelo = 1.0f;
}