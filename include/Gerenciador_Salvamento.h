#pragma once
#include <fstream>
#include <string>

namespace Gerenciadores {

class Gerenciador_Salvamento {

    private:
        static std::ofstream save;
    public:
        Gerenciador_Salvamento();
        ~Gerenciador_Salvamento();

        void abrirArquivo(const std::string& caminho);
        void fecharArquivo();

        static std::ofstream& getArquivo();
};


}