#include "Gerenciador_Salvamento.h"
#include <iostream>

using namespace Gerenciadores;


std::ofstream Gerenciador_Salvamento::save;

Gerenciador_Salvamento::Gerenciador_Salvamento() {}
Gerenciador_Salvamento::~Gerenciador_Salvamento() {
    fecharArquivo();
}

void Gerenciador_Salvamento::abrirArquivo(const std::string& caminho) {

    if (!save.is_open()) {
        save.open(caminho);

        if (!save.is_open()) {
            std::cerr << "Erro ao abrir save em : " << caminho << "\n";
        }
    }
}

void Gerenciador_Salvamento::fecharArquivo() {
    if (save.is_open()) {
        save.close();
    }

}

std::ofstream& Gerenciador_Salvamento::getArquivo() {
    return save;
}