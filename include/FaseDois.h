#include "Fase.h"

namespace Entidades {
	namespace Personagens{
		class Jogador;
	}
}

namespace Fases {
	class FaseDois :public Fase {
	private:
		const int maxTanques;
	protected:
		void criarInimigos(Entidades::Personagens::Jogador* j1, Entidades::Personagens::Jogador* j2);
		void criarTanques(Entidades::Personagens::Jogador* j1);
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
		void desenhar();
		bool statusInimigos();
	};
}