#pragma once

#include "Ente.h"
#include <string>
#include <vector>
using namespace std;

class Jogo;
namespace Entidades {
	class BackGround;
	namespace EntidadesPertinentes {
		namespace Personagens {
			class Jogador;
		}
	}
}

class Menu : public Ente {
public:
	enum EstadoMenu {
		MENU_PRINCIPAL,
		MENU_MORTE,
		FASE_VENCIDA,
		SEL_RANKING,
		RANKING,
		SEL_FASE,
		SEL_JOGADORES,
		CONFIRMA_SAIR,
		JOGO_RODANDO,
		DIGITANDO_J1,
		DIGITANDO_J2,
		PAUSA
	};
private:
	Jogo* pJogo;
	EstadoMenu estadoAtual;
	EstadoMenu estadoAnterior;
	sf::Font fonte;
	Entidades::BackGround* bMenu;

	std::vector<Entidades::EntidadesPertinentes::Personagens::Jogador*> ranking;
	map<string, sf::Text> textos;

	int n_jogs;
	int fase_selecionada;
	const int MAX_RANKING;
	bool addJogador;

	void initText(const string& chave, const string& conteudo, unsigned int tamanho, sf::Vector2f posicao);
	void carregarRanking(const char* caminhoRanking);
	void gravarRanking(const char* caminhoRanking);
	void trataRanking(Entidades::EntidadesPertinentes::Personagens::Jogador* j, const char* caminhoRanking);
	void addJogadorRanking(const char* caminhoRanking);
public:
	Menu(Jogo* pJ = nullptr);
	~Menu();
	void executarMouse(const sf::Vector2f& mousePos);
	EstadoMenu getEstado() { return estadoAtual; }
	int getFase();
	int getQtdJogadores ();
	void executar();
	void desenhaRanking(const char* caminhoRanking);
	void limpaRanking();
};