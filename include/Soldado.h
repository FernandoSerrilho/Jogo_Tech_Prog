#pragma once

#include "Inimigo.h"

namespace Entidades {
	namespace EntidadesPertinentes{
		namespace Personagens {
			namespace Inimigos {
				class Soldado : public Inimigo {
				private:
					sf::Clock relogioParado;
					float temp_parado;
					sf::Vector2f vetorParado;
					bool parado;
				public:
					Soldado(sf::Vector2f pos, const char* caminhoTextura = "");
					~Soldado();
					void setParado(bool p);
					void executar();
					void danificar(Jogador* j);
					void mover();
					void salvar();
				};
			}
		}
	}
}