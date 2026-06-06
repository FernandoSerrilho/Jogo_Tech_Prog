#pragma once

#include "Ente.h"
#include "BackGround.h"
#include <string>
using namespace std;

class Jogo;

class Menu : public Ente {
public:
	enum EstadoMenu {
		MENU_PRINCIPAL,
		SEL_FASE,
		SEL_JOGADORES,
		CONFIRMA_SAIR,
		JOGO_RODANDO,
		PAUSA
	};
private:
	Jogo* pJogo;
	EstadoMenu estadoAtual;
	EstadoMenu estadoAnterior;
	sf::Font fonte;
	BackGround* bMenu;

	map<string, sf::Text> textos;

	int n_jogs;
	int fase_selecionada;

	void initText(const string& chave, const string& conteudo, unsigned int tamanho, sf::Vector2f posicao);
public:
	Menu();
	~Menu();
	void executarMouse(const sf::Vector2f& mousePos);
	EstadoMenu getEstado() { return estadoAtual; }
	int getFase();
	int getQtdJogadores ();
	void executar();
};