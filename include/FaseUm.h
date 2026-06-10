#pragma once

#include "Fase.h"

namespace Entidades {
	namespace Personagens {
		class Jogador;
	}
}

namespace Fases {
	class FaseUm : public Fase {
	private:
		const int maxIniMed = 2;
	protected:
		void criarInimigos(Entidades::Personagens::Jogador* j);
		void criarSoldados();
		void criarArbustos();
		void criarObstaculos();
		void criarCenario();
	public:
		FaseUm(Entidades::Personagens::Jogador* j = nullptr);
		~FaseUm();
		void inicializar(Entidades::Personagens::Jogador* j1);
		void executar();
		void desenhar();
		bool statusInimigos();
	};
}