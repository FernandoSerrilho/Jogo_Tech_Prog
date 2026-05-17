#pragma once

#include <iostream>
#include "Gerenciador_Grafico.h"

using namespace Gerenciadores;




class Ente {

    protected:
        int id;
        static Gerenciador_Grafico* pGG;
        static int cont_id;
    
    public:
        Ente();
        virtual ~Ente();

        virtual void executar() = 0;
        void desenhar();
        static void setGG(Gerenciador_Grafico *pG);


};
