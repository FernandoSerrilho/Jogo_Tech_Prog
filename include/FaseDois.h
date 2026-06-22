#include "Fase.h"

namespace Entidades {
		namespace Personagens {
			class Jogador;
		}
}

namespace Fases {
	class FaseDois :public Fase {
	private:
		const int maxTanques;
		const int maxMinas;
	protected:
		void criarInimigos(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void criarTanques();
		void criarProjeteis();
		void gerenciarProjeteis();
		void criarMinasTerrestres();
		void criarObstaculos();
		void criarCenario();
	public:
		FaseDois(Entidades::Personagens::Jogador* j1=nullptr, Entidades::Personagens::Jogador* j2 = nullptr);
		~FaseDois();
		void inicializar(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void executar();
		void carregarFase(std::ifstream& arquivo, Entidades::Personagens::Jogador* j1,
				Entidades::Personagens::Jogador* j2, bool& j2Ativo);
		void desenhar();
		bool statusInimigos();
	};
}