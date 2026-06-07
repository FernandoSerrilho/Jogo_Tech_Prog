#pragma once

#include "Fase.h"
using namespace Fases;

class FaseUm : public Fase {
private:
	const int maxIniMed = 2;
protected:
	void criarInimigos(Jogador* j);
	void criarIniMed();
	void criarObsMed();
	void criarObstaculos();
	void criarCenario();
public:
	FaseUm(Jogador* j = nullptr);
	~FaseUm();
	void inicializar(Jogador* j1);
	void executar();
	void desenhar();
};