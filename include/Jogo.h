#pragma once

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "FaseUm.h"
#include "BackGround.h"
#include "Chao.h"
using namespace Gerenciadores;
using namespace Personagens;

class Jogo {
private:
	Gerenciador_Grafico* GG;
	Jogador* j1;
	FaseUm* f1;
public:
	Jogo();
	~Jogo();
	void executar();
	const Gerenciador_Grafico* getGG();
	void desenhar();
};

/*#pragma once

#include "Gerenciador_Colisoes.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include "Drone.h"
#include "Plataforma.h"
#include "Chao.h"
#include "BackGround.h"
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
	BackGround b;
	list<Ente*> entidades;
public:
	Jogo();
	~Jogo();
	void executar();
};*/