#pragma once

#include "Fase.h"

namespace Entidades {
	namespace EntidadesPertinentes {
		namespace Personagens {
			class Jogador;
		}
	}
}

namespace Fases {
	class FaseUm : public Fase {
	private:
		const int maxSoldados;
		const int maxArbustos;
	protected:
		void criarInimigos(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2);
		void criarSoldados();
		void criarArbustos();
		void criarObstaculos();
		void criarCenario();
	public:
		FaseUm(Entidades::EntidadesPertinentes::Personagens::Jogador* j1 = nullptr, Entidades::EntidadesPertinentes::Personagens::Jogador* j2 = nullptr);
		~FaseUm();
		void inicializar(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2);
		void executar();
		void carregarFase(std::ifstream& arquivo, Entidades::EntidadesPertinentes::Personagens::Jogador* j1,
				Entidades::EntidadesPertinentes::Personagens::Jogador* j2, bool& j2Ativo);
		void desenhar();
		bool statusInimigos();
	};
}