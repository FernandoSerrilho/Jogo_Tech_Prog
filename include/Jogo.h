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
	Fases::FaseUm* f1;
	Fases::FaseDois* f2;
	Menu* m;
public:
	Jogo();
	~Jogo();
	void executar();
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
