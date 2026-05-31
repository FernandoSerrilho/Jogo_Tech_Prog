#pragma once

#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Chao.h"
#include <list>
using namespace std;
using namespace Gerenciadores;
using namespace Personagens;

class Jogo {
	private:
		Gerenciador_Grafico* GG;
		Gerenciador_Colisoes* pGC;
		Jogador* j1;
		Drone* d1;
		Plataforma* p1;
		Chao chao;
		list<Ente*> entidades;
	public:
		Jogo();
		~Jogo();
		void executar();
};