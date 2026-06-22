#include "EntidadePertinente.h"
#include <iostream>

using namespace Entidades;


std::ofstream EntidadePertinente::buffer;


EntidadePertinente::EntidadePertinente() : Entidade(),vel(5.0f, 5.0f),gravidade(0.3f),contraGravidade(0.0f) {}
EntidadePertinente::~EntidadePertinente() { vivo = false; }

void EntidadePertinente::abrirArquivo(const std::string& caminho) {
    if (!buffer.is_open()) {
        buffer.open(caminho);
        if (!buffer.is_open()) {
            std::cerr << "Erro ao abrir save em : " << caminho << "\n";
        }
    }
}

void EntidadePertinente::fecharArquivo() {
    if (buffer.is_open()) {
        buffer.close();
    }
}

std::ofstream& EntidadePertinente::getArquivo() {
    return buffer;
}


sf::Vector2f EntidadePertinente::getVel() {return vel;}

void EntidadePertinente::setVel(float vx, float vy) {

    vel.x = vx;
    vel.y = vy;

}


void EntidadePertinente::gravitar() {

    float acel_resultante = gravidade + contraGravidade;

    // t = 1.0f
     // y = y0 + v0t + (at²)/2
    pos.y += vel.y + (acel_resultante/2.0f);
    // v = v0 + at
    vel.y += acel_resultante;


}


void EntidadePertinente::salvarDataBuffer() {
    if (buffer) {

        buffer << id << " " << pos.x << " " << pos.y << " " << vel.x << " " << vel.y << " " << vivo << " ";
    }

}



