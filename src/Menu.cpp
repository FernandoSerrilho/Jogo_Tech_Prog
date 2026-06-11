#include "Menu.h"
#include "Jogo.h"
#include "BackGround.h"
#include "Gerenciador_Grafico.h"
#include <iostream>

Menu::Menu(Jogo* j):bMenu(new BackGround("Texturas/BackGround/Menu.png")), fonte(),n_jogs(0)
,fase_selecionada(0),estadoAtual(MENU_PRINCIPAL),estadoAnterior(MENU_PRINCIPAL),pJogo(j){
	if (!fonte.loadFromFile("Texturas/Fontes/FonteTexto.ttf")) {
		std::cout << "Erro ao carregar a fonte!" << std::endl;
	}
	initText("txtTituloJogo", "MILITARY ZONE", 90, { 960.f, 150.f });
	initText("btnJogar", "JOGAR", 40, { 960.f, 450.f });
	initText("btnSair", "SAIR", 40, { 960.f, 700.f });

	initText("txtFase", "Escolha a Fase:", 60, { 960.f, 450.f });
	initText("btnFase1", "Fase 1", 40, { 600.f, 700.f });
	initText("btnFase2", "Fase 2", 40, { 1320.f, 700.f });
	initText("btn1Player", "1 Jogador", 40, { 600.f, 500.f });
	initText("btn2Players", "2 Jogadores", 40, { 1320.f, 500.f });

	initText("txtCerteza", "Tem certeza que deseja sair?", 30, { 960.f, 300.f });
	initText("btnSim", "SIM", 40, { 750.f, 550.f });
	initText("btnNao", "NAO", 40, { 1170.f, 550.f });

	initText("txtMorte", "MORREU!", 60, { 960.f, 400.f });
	initText("txtFaseVencida", "INIMIGOS DERROTADOS!", 60, { 960.f, 300.f });
	initText("btnMenu", "MENU", 40, { 960.f, 550.f });
	initText("btnRestart", "RESTART", 40, { 960.f, 850.f });
	initText("btnSairMorte", "SAIR", 40, { 960.f, 700.f });
	initText("btnContinuar", "CONTINUAR", 40, { 960.f, 350.f });
	initText("btnProxFase", "PROXIMA FASE", 40, { 960.f, 450.f });
}

Menu::~Menu() { bMenu = nullptr; textos.clear(); }

int Menu::getFase() { return fase_selecionada; }

int Menu::getQtdJogadores() { return n_jogs; }

void Menu::initText(const string& chave, const string& conteudo, unsigned int tamanho, sf::Vector2f posicao) {
	textos[chave].setFont(fonte);
	textos[chave].setString(conteudo);
	textos[chave].setCharacterSize(tamanho);
	textos[chave].setFillColor(sf::Color::White);
	textos[chave].setPosition(posicao.x - textos[chave].getGlobalBounds().width / 2.f, posicao.y);
}

void Menu::executarMouse(const sf::Vector2f& mousePos) {
	if (estadoAtual == MENU_PRINCIPAL) {
		if (textos["btnJogar"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = SEL_FASE;
		}
		else if (textos["btnSair"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = CONFIRMA_SAIR;
		}
	}
	else if (estadoAtual == SEL_FASE) {
		if (textos["btnFase1"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 1;
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			pJogo->reiniciarFaseUm();
			estadoAnterior = SEL_FASE;
		}
		else if (textos["btnFase2"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 2;
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			pJogo->reiniciarFaseDois();
			estadoAnterior = SEL_FASE;
		}
	}
	else if (estadoAtual == CONFIRMA_SAIR) {
		if (textos["btnSim"].getGlobalBounds().contains(mousePos)) {
			pJogo->getGG()->getGerenciadorG()->fechaJanela();
		}
		else if (textos["btnNao"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = MENU_PRINCIPAL; 
		}
	}
	else if (estadoAtual == PAUSA) {
		if (textos["btnContinuar"].getGlobalBounds().contains(mousePos))
			estadoAtual = JOGO_RODANDO;
		else if (textos["btnSair"].getGlobalBounds().contains(mousePos))
			estadoAtual = CONFIRMA_SAIR;
		else if (textos["btnMenu"].getGlobalBounds().contains(mousePos))
			estadoAtual = MENU_PRINCIPAL;
	}
	else if (estadoAtual == MENU_MORTE) {
		if (textos["btnSairMorte"].getGlobalBounds().contains(mousePos))
			estadoAtual = CONFIRMA_SAIR;
		else if (textos["btnMenu"].getGlobalBounds().contains(mousePos))
			estadoAtual = MENU_PRINCIPAL;
		else if (textos["btnRestart"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			if(getFase()==1)
				pJogo->reiniciarFaseUm();
			else
				pJogo->reiniciarFaseDois();
		}
	}
	else if (estadoAtual == FASE_VENCIDA) {
		if (textos["btnSairMorte"].getGlobalBounds().contains(mousePos))
			estadoAtual = CONFIRMA_SAIR;
		else if (textos["btnMenu"].getGlobalBounds().contains(mousePos))
			estadoAtual = MENU_PRINCIPAL;
		else if (textos["btnProxFase"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			if (getFase() == 1)
				fase_selecionada++;
			else
				fase_selecionada--;
		}
		else if (textos["btnRestart"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			if (getFase() == 1)
				pJogo->reiniciarFaseUm();
			else
				pJogo->reiniciarFaseDois();
		}
	}
}

void Menu::executar() {
	while (pJogo->getGG()->getGerenciadorG()->VerificajanelaAberta()) {
		sf::Vector2i mousePosI = sf::Mouse::getPosition(*(pJogo->getGG()->getGerenciadorG()->getJanela()));
		sf::Vector2f mousePos(static_cast<float>(mousePosI.x), static_cast<float>(mousePosI.y));

		sf::Event event;
		while (pJogo->getGG()->getGerenciadorG()->getJanela()->pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					pJogo->getGG()->getGerenciadorG()->fechaJanela();
				}
				else if (event.type == sf::Event::KeyPressed) {
						if (event.key.code == sf::Keyboard::Escape) {
							if (estadoAtual == JOGO_RODANDO) {
								estadoAtual = PAUSA;
							}
							else if (estadoAtual == PAUSA) {
								estadoAtual = JOGO_RODANDO;
							}
							else if (estadoAtual == CONFIRMA_SAIR) {
								estadoAtual = estadoAnterior;
							}
					}
				}
				else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
					if (estadoAtual == MENU_PRINCIPAL && textos["btnSair"].getGlobalBounds().contains(mousePos)) {
						estadoAnterior = MENU_PRINCIPAL;
						estadoAtual = CONFIRMA_SAIR;
					}
					else if (estadoAtual == PAUSA && textos["btnSair"].getGlobalBounds().contains(mousePos)) {
						estadoAnterior = PAUSA; 
						estadoAtual = CONFIRMA_SAIR;
					}
					else if (estadoAtual == CONFIRMA_SAIR) {
						if (textos["btnSim"].getGlobalBounds().contains(mousePos)) {
							pJogo->getGG()->getGerenciadorG()->fechaJanela();
						}
						else if (textos["btnNao"].getGlobalBounds().contains(mousePos)) {
							estadoAtual = estadoAnterior; 
						}
					}
					else {
						executarMouse(mousePos); 
					}
				}
		}

		if (estadoAtual == JOGO_RODANDO) {
			if (pJogo->jogadorVivo()) {
				if (getFase() == 1) {
					pJogo->executarf1();
					if (pJogo->statusInif1()) {
						estadoAtual = FASE_VENCIDA;
					}
				}
				else if (getFase() == 2) {
					pJogo->executarf2();
					if (pJogo->statusInif2()) {
						estadoAtual = FASE_VENCIDA;
					}
				}
			}
			else {
				estadoAnterior = JOGO_RODANDO;
				estadoAtual = MENU_MORTE;
			}
		}

		else if (estadoAtual == MENU_PRINCIPAL) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			pJogo->reviveJogador();
			pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtTituloJogo"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnJogar"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSair"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}

		else if (estadoAtual == CONFIRMA_SAIR) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			if (estadoAnterior == PAUSA) {
				if (getFase() == 1)
					pJogo->desenharf1();
				else
					pJogo->desenharf2();
			}
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtCerteza"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSim"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnNao"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}

		else if (estadoAtual == PAUSA) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			if(getFase()==1)
				pJogo->desenharf1();
			else
				pJogo->desenharf2();
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnContinuar"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSair"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}
		else if (estadoAtual == MENU_MORTE) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtMorte"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnRestart"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSairMorte"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}
		else if (estadoAtual == SEL_FASE) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtFase"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase1"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase2"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}

		else if (estadoAtual == FASE_VENCIDA) {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			if(getFase()==1)
				pJogo->desenharf1();
			else
				pJogo->desenharf2();
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtFaseVencida"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnRestart"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnProxFase"]);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSairMorte"]);
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}
	}
}



