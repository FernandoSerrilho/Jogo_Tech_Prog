#pragma once

class Menu;

namespace Gerenciadores {
	class Gerenciador_Grafico;
}

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}

namespace Fases {
	class FaseUm;
	class FaseDois;
}

class Jogo {
private:
	Gerenciadores::Gerenciador_Grafico* GG;
	Entidades::Personagens::Jogador* j1;
	Entidades::Personagens::Jogador* j2;
	Fases::FaseUm* f1;
	Fases::FaseDois* f2;
	int faseatual;
	Menu* m;
	bool j2Ativo;
public:
	Jogo();
	~Jogo();
	void usarJ2();
	void desativarJ2();
	int getFase();
	void salvarJogo();
	void carregarJogo();
	void executar();
	Entidades::Personagens::Jogador* getj1();
	Entidades::Personagens::Jogador* getj2();
	void executarf1();
	void executarf2();
	const Gerenciadores::Gerenciador_Grafico* getGG();
	void desenharf1();
	void desenharf2();
	void reiniciarFaseUm();
	void reiniciarFaseDois();
	void reviveJogador();
	bool jogadorVivo();
	bool statusInif1();
	bool statusInif2();
};
