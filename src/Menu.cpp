//Agradecimentos ao canal Dev Felipe do Youtube, por fornecer uma base para o respectivo arquivo: https://www.youtube.com/@devfelipe8214

#include "Menu.h"
#include "Jogo.h"
#include "BackGround.h"
#include "Gerenciador_Grafico.h"
#include "Jogador.h"
#include <iostream>
#include <algorithm>

using namespace Entidades::Personagens;
Menu::Menu(Jogo* j):bMenu(new Entidades::BackGround("Texturas/BackGround/Menu.png")), fonte(),n_jogs(0)
,fase_selecionada(0),estadoAtual(MENU_PRINCIPAL),estadoAnterior(MENU_PRINCIPAL),pJogo(j),MAX_RANKING(10),addJogador(true){
	limpaRanking();
	if (!fonte.loadFromFile("Texturas/Fontes/FonteTexto.ttf")) {
		std::cout << "Erro ao carregar a fonte!" << std::endl;
	}
	initText("txtTituloJogo", "MILITARY ZONE", 90, { 960.f, 150.f });
	initText("btnJogar", "JOGAR", 40, { 960.f, 400.f });
	initText("btnRanking", "RANKING", 40, { 960.f, 660.f });
	initText("btnCarregar", "CARREGAR JOGO", 40, {960.f , 530.f});
	initText("btnSair", "SAIR", 40, { 960.f, 790.f });
	initText("btnSairRanking", "SAIR", 40, { 960.f, 900.f });

	initText("txtFase", "Escolha a Fase:", 60, { 960.f, 450.f });
	initText("btnFase1", "Fase 1", 40, { 600.f, 700.f });
	initText("btnFase2", "Fase 2", 40, { 1320.f, 700.f });
	initText("btnUmJogador", "1 Jogador", 40, { 600.f, 500.f });
	initText("btnDoisJogadores", "2 Jogadores", 40, { 1320.f, 500.f });
	initText("txtJ1", "Digite o nome do Jogador 1:", 60, { 960.f, 450.f });
	initText("txtJ2", "Digite o nome do Jogador 2:", 60, { 960.f, 450.f });
	initText("txtNomeAtual", "", 40, { 960.f, 550.f });

	initText("txtCerteza", "Tem certeza que deseja sair?", 30, { 960.f, 300.f });
	initText("btnSim", "SIM", 40, { 750.f, 550.f });
	initText("btnNao", "NAO", 40, { 1170.f, 550.f });

	initText("txtDerrota", "JOGADOR(ES) DERROTADO(S)!", 60, { 960.f, 400.f });
	initText("txtFaseVencida", "INIMIGOS DERROTADOS!", 60, { 960.f, 300.f });
	initText("btnMenu", "MENU", 40, { 960.f, 550.f });
	initText("btnRestart", "RESTART", 40, { 960.f, 850.f });
	initText("btnSairDerrota", "SAIR", 40, { 960.f, 700.f });
	initText("btnContinuar", "CONTINUAR", 40, { 960.f, 350.f });
	initText("btnSalvar", "SALVAR JOGO", 40 , {960.f , 450.f});
	initText("btnProxFase", "PROXIMA FASE", 40, { 960.f, 450.f });
}

Menu::~Menu() { bMenu = nullptr; textos.clear();limpaRanking();
}

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
			estadoAtual = SEL_JOGADORES;
		}
		else if (textos["btnCarregar"].getGlobalBounds().contains(mousePos)) {
			pJogo->carregarJogo();

			estadoAtual = JOGO_RODANDO;

			fase_selecionada = pJogo->getFase();

			estadoAnterior = MENU_PRINCIPAL;
		}
		else if (textos["btnSair"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = CONFIRMA_SAIR;
		}
		else if (textos["btnRanking"].getGlobalBounds().contains(mousePos)) {
			limpaRanking();
			estadoAtual = SEL_RANKING;
		}
	}
	else if (estadoAtual == SEL_RANKING) {
		if (textos["btnFase1"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 1;
			carregarRanking("rankingFase1.txt");
			estadoAnterior = SEL_RANKING;
			estadoAtual = RANKING;
		}
		else if (textos["btnFase2"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 2;
			carregarRanking("rankingFase2.txt");
			estadoAnterior = SEL_RANKING;
			estadoAtual = RANKING;
		}
	}
	else if (estadoAtual == SEL_FASE) {
		if (textos["btnFase1"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 1;
			estadoAtual = JOGO_RODANDO;
			pJogo->reiniciarFaseUm();
			estadoAnterior = SEL_FASE;
		}
		else if (textos["btnFase2"].getGlobalBounds().contains(mousePos)) {
			fase_selecionada = 2;
			estadoAtual = JOGO_RODANDO;
			pJogo->reiniciarFaseDois();
			estadoAnterior = SEL_FASE;
		}
	}
	else if (estadoAtual == SEL_JOGADORES) {
		if (textos["btnUmJogador"].getGlobalBounds().contains(mousePos)) {
			n_jogs = 1;
			pJogo->desativarJ2();
			pJogo->reviveJogador();
			pJogo->getj1()->setNome("");
			textos["txtNomeAtual"].setString("");

			estadoAtual = DIGITANDO_J1;
			estadoAnterior = SEL_JOGADORES;
		}
		else if (textos["btnDoisJogadores"].getGlobalBounds().contains(mousePos)) {
			n_jogs = 2;
			pJogo->usarJ2();
			pJogo->reviveJogador();
			pJogo->getj1()->setNome("");
			pJogo->getj2()->setNome("");
			textos["txtNomeAtual"].setString("");

			estadoAtual = DIGITANDO_J1;
			estadoAnterior = SEL_JOGADORES;
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
	else if (estadoAtual == RANKING) {
		if (textos["btnSairRanking"].getGlobalBounds().contains(mousePos)) {
			limpaRanking();
			estadoAtual = MENU_PRINCIPAL;
		}
	}
	else if (estadoAtual == PAUSA) {
		if (textos["btnContinuar"].getGlobalBounds().contains(mousePos))
			estadoAtual = JOGO_RODANDO;
		else if (textos["btnSalvar"].getGlobalBounds().contains(mousePos)) {
			pJogo->salvarJogo();

			textos["btnSalvar"].setFillColor(sf::Color::Green);
		}
		else if (textos["btnSair"].getGlobalBounds().contains(mousePos))
			estadoAtual = CONFIRMA_SAIR;
		else if (textos["btnMenu"].getGlobalBounds().contains(mousePos))
			estadoAtual = MENU_PRINCIPAL;
	}
	else if (estadoAtual == MENU_DERROTA) {
		if (textos["btnSairDerrota"].getGlobalBounds().contains(mousePos))
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
		if (textos["btnSairDerrota"].getGlobalBounds().contains(mousePos))
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
			addJogador = true;
		}
		else if (textos["btnRestart"].getGlobalBounds().contains(mousePos)) {
			estadoAtual = JOGO_RODANDO;
			pJogo->reviveJogador();
			if (getFase() == 1)
				pJogo->reiniciarFaseUm();
			else
				pJogo->reiniciarFaseDois();
			addJogador = true;
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
			else if (event.type == sf::Event::TextEntered) {
				if (estadoAtual == DIGITANDO_J1) {
					Jogador* pJ = pJogo->getj1();
					if (pJ) {
						std::string nomeAtual = pJ->getNome();

						if (event.text.unicode == 8) {
							if (!nomeAtual.empty()) {
								nomeAtual.pop_back();
							}
						}
						else if (event.text.unicode == 13) {
							if (nomeAtual.size() >= 1) {
								pJ->setNome(nomeAtual);
								if (n_jogs == 2) {
									textos["txtNomeAtual"].setString("");
									estadoAtual = DIGITANDO_J2;
								}
								else {
									textos["txtNomeAtual"].setString("");
									estadoAtual = SEL_FASE;
								}
								textos["txtNomeAtual"].setPosition(960.f - textos["txtNomeAtual"].getGlobalBounds().width / 2.f, 600.f);
								continue;
							}
						}
						else if (event.text.unicode < 128 && nomeAtual.size() < 15) {
							char c = static_cast<char>(event.text.unicode);
							if (std::isalnum(c) || c == ' ') {
								nomeAtual += c;
							}
						}

						pJ->setNome(nomeAtual);
						textos["txtNomeAtual"].setString(nomeAtual);
						textos["txtNomeAtual"].setPosition(960.f - textos["txtNomeAtual"].getGlobalBounds().width / 2.f, 600.f);
					}
				}
				else if (estadoAtual == DIGITANDO_J2) {
					Jogador* pJ = pJogo->getj2();
					if (pJ) {
						std::string nomeAtual = pJ->getNome();

						if (event.text.unicode == 8) {
							if (!nomeAtual.empty()) {
								nomeAtual.pop_back();
							}
						}
						else if (event.text.unicode == 13) {
							if (nomeAtual.size() >= 1) {
								pJ->setNome(nomeAtual);
								textos["txtNomeAtual"].setString("");
								estadoAtual = SEL_FASE;
								textos["txtNomeAtual"].setPosition(960.f - textos["txtNomeAtual"].getGlobalBounds().width / 2.f, 600.f);
								continue;
							}
						}
						else if (event.text.unicode < 128 && nomeAtual.size() < 15) {
							char c = static_cast<char>(event.text.unicode);
							if (std::isalnum(c) || c == ' ') {
								nomeAtual += c;
							}
						}

						pJ->setNome(nomeAtual);
						textos["txtNomeAtual"].setString(nomeAtual);
						textos["txtNomeAtual"].setPosition(960.f - textos["txtNomeAtual"].getGlobalBounds().width / 2.f, 600.f);
					}
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
				estadoAtual = MENU_DERROTA;
			}
		}
		else {
			pJogo->getGG()->getGerenciadorG()->limpaJanela();
			if (estadoAtual == MENU_PRINCIPAL) {
				limpaRanking();
				addJogador = true;
				pJogo->reviveJogador();
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtTituloJogo"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnJogar"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnCarregar"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnRanking"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSair"]);
			}

			else if (estadoAtual == CONFIRMA_SAIR) {
				if (estadoAnterior == PAUSA) {
					if (getFase() == 1)
						pJogo->desenharf1();
					else
						pJogo->desenharf2();
				}
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtCerteza"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSim"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnNao"]);
			}

			else if (estadoAtual == PAUSA) {
				if (getFase() == 1)
					pJogo->desenharf1();
				else
					pJogo->desenharf2();
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnContinuar"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSalvar"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSair"]);
			}
			else if (estadoAtual == MENU_DERROTA) {
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtDerrota"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnRestart"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSairDerrota"]);
			}
			else if (estadoAtual == SEL_RANKING) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase1"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase2"]);
			}
			else if (estadoAtual == RANKING) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				if(fase_selecionada == 1)
					desenhaRanking("rankingFase1.txt");
				else if (fase_selecionada == 2)
					desenhaRanking("rankingFase2.txt");
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSairRanking"]);
			}
			else if (estadoAtual == SEL_FASE) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtFase"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase1"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnFase2"]);
			}

			else if (estadoAtual == SEL_JOGADORES) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnUmJogador"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnDoisJogadores"]);
			}

			else if (estadoAtual == FASE_VENCIDA) {
				if (getFase() == 1)
					pJogo->desenharf1();
				else
					pJogo->desenharf2();
				if (addJogador) {
					if(fase_selecionada==1)
						addJogadorRanking("rankingFase1.txt");
					else if (fase_selecionada==2)
						addJogadorRanking("rankingFase2.txt");
					addJogador = false;
				}
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtFaseVencida"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnMenu"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnRestart"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnProxFase"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["btnSairDerrota"]);
			}
			else if (estadoAtual == DIGITANDO_J1) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtJ1"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtNomeAtual"]);
			}
			else if (estadoAtual == DIGITANDO_J2) {
				pJogo->getGG()->getGerenciadorG()->desenharEnte(bMenu);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtJ2"]);
				pJogo->getGG()->getGerenciadorG()->desenharTexto(textos["txtNomeAtual"]);
			}
			pJogo->getGG()->getGerenciadorG()->displayJanela();
		}
	}
}

void Menu::gravarRanking(const char* caminhoRanking) {
	std::ofstream arquivo(caminhoRanking);

	if (!arquivo.is_open()) {
		std::cerr << "Erro ao abrir o arquivo para salvar o ranking!" << std::endl;
		return;
	}

	for (int i = 0;i < ranking.size();i++) {
		Jogador* j = ranking[i];
		arquivo << j->getNome() << " " << j->getPontos() << "\n";
	}

	arquivo.close();
}

void Menu::carregarRanking(const char* caminhoRanking) {
	limpaRanking();
	std::string nome;
	int pontos;
	std::ifstream arquivo(caminhoRanking);

	if (!arquivo.is_open())
		return;

	while (arquivo >> nome >> pontos) {
		Jogador* j = new Jogador();
		j->setNome(nome);
		j->setPontos(pontos);
		ranking.push_back(j);
	}
	arquivo.close();
}

void Menu::trataRanking(Jogador* j, const char* caminhoRanking) {
	carregarRanking(caminhoRanking);

	if (ranking.size() >= MAX_RANKING && j->getPontos() <= ranking.back()->getPontos())
		return;
	
	Jogador* novoElemento = new Jogador();
	novoElemento->setNome(j->getNome());
	novoElemento->setPontos(j->getPontos());

	ranking.push_back(novoElemento);
	std::sort(ranking.begin(), ranking.end(), [](Jogador* a, Jogador* b) {return a->getPontos() > b->getPontos();});

	if (ranking.size() > MAX_RANKING) {
		delete ranking.back();
		ranking.pop_back();
	}
	gravarRanking(caminhoRanking);
}

void Menu::addJogadorRanking(const char* caminhoRanking) {
	if (pJogo->getj1()) {
		if (pJogo->getj1()->getVivo()) {
			trataRanking(pJogo->getj1(),caminhoRanking);
		}
	}
	if (pJogo->getj2()) {
		if (pJogo->getj2()->getVivo()) {
			trataRanking(pJogo->getj2(),caminhoRanking);
		}
	}
}

void Menu::desenhaRanking(const char* caminhoRanking) {
	sf::Text textoRanking;
	textoRanking.setFont(fonte);
	textoRanking.setFillColor(sf::Color::White);

	textoRanking.setCharacterSize(35);
	float posYini = 280.f;
	float espaco = 50.f;

	for (size_t i = 0; i < ranking.size(); i++) {
		if (ranking[i] != nullptr) {
			std::string conteudo = std::to_string(i + 1) + ". " +
				ranking[i]->getNome() + " ...... " +
				std::to_string(ranking[i]->getPontos()) + " pts";

			textoRanking.setString(conteudo);
			float posX = 960.f - textoRanking.getGlobalBounds().width / 2.f;
			float posY = posYini + (i * espaco);
			textoRanking.setPosition(posX, posY);
			pJogo->getGG()->getGerenciadorG()->desenharTexto(textoRanking);
		}
	}
}

void Menu::limpaRanking() {
	std::vector<Jogador*>::iterator it = ranking.begin();
	while (it != ranking.end()) {
		delete* it;
		it++;
	}
	ranking.clear();
}