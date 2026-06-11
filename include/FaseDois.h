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
		void criarInimigos(Entidades::Personagens::Jogador* j);
		void criarTanques();
		void criarMinasTerrestres(Entidades::Personagens::Jogador* j);
		void criarObstaculos(Entidades::Personagens::Jogador* j);
		void criarCenario();
	public:
		FaseDois(Entidades::Personagens::Jogador* j1=nullptr);
		~FaseDois();
		void inicializar(Entidades::Personagens::Jogador* j1);
		void executar();
		void desenhar();
		bool statusInimigos();
	};
}