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
}

class Jogo {
private:
	Gerenciadores::Gerenciador_Grafico* GG;
	Entidades::Personagens::Jogador* j1;
	Fases::FaseUm* f1;
	Menu* m;
public:
	Jogo();
	~Jogo();
	void executar();
	void executarf1();
	const Gerenciadores::Gerenciador_Grafico* getGG();
	void desenhar();
	void reviveJogador();
	bool jogadorVivo();
	bool statusIni();
};
