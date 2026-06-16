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
		const int maxSoldados;
		const int maxArbustos;
	protected:
		void criarInimigos(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void criarSoldados();
		void criarArbustos();
		void criarObstaculos();
		void criarCenario();
	public:
		FaseUm(Entidades::Personagens::Jogador* j1 = nullptr, Entidades::Personagens::Jogador* j2 = nullptr);
		~FaseUm();
		void inicializar(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void executar();
		void desenhar();
		bool statusInimigos();
	};
}