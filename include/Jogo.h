#pragma once

#include "Gerenciador_Grafico.h"
#include "Gerenciador_Colisoes.h"
#include "Jogador.h"
#include "FaseUm.h"
#include "BackGround.h"
#include "Chao.h"
#include "Menu.h"
using namespace Gerenciadores;
using namespace Personagens;

class Jogo {
private:
	Gerenciador_Grafico* GG;
	Jogador* j1;
	FaseUm* f1;
	Menu* m;
public:
	Jogo();
	~Jogo();
	void executar();
	void executarf1();
	const Gerenciador_Grafico* getGG();
	void desenhar();
};
