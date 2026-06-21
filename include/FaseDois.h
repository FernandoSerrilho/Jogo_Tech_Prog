#include "Fase.h"

namespace Entidades {
	namespace EntidadesPertinentes {
		namespace Personagens {
			class Jogador;
		}
	}
}

namespace Fases {
	class FaseDois :public Fase {
	private:
		const int maxTanques;
		const int maxMinas;
	protected:
		void criarInimigos(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2);
		void criarTanques();
		void criarProjeteis();
		void gerenciarProjeteis();
		void criarMinasTerrestres();
		void criarObstaculos();
		void criarCenario();
	public:
		FaseDois(Entidades::EntidadesPertinentes::Personagens::Jogador* j1=nullptr, Entidades::EntidadesPertinentes::Personagens::Jogador* j2 = nullptr);
		~FaseDois();
		void inicializar(Entidades::EntidadesPertinentes::Personagens::Jogador* j1, Entidades::EntidadesPertinentes::Personagens::Jogador* j2);
		void executar();
		void carregarFase(std::ifstream& arquivo, Entidades::EntidadesPertinentes::Personagens::Jogador* j1,
				Entidades::EntidadesPertinentes::Personagens::Jogador* j2, bool& j2Ativo);
		void desenhar();
		bool statusInimigos();
	};
}