#pragma once

#include "Obstaculo.h"
namespace Entidades {
	namespace Personagens {
		class Jogador;
		class Inimigo;
	}
}
using namespace Obstaculos;

class Arbusto : public Obstaculo {
private:
	sf::RectangleShape colisao;
	sf::Texture textura;
	sf::Sprite sprites;
	float lentidao;
public:
	Arbusto();
	Arbusto(sf::Vector2f pos, sf::Vector2f tam);
	~Arbusto();
	void executar();
	void obstaculizar(Jogador* j1);
	void obstaculizar(Inimigo* i1);
	sf::FloatRect getBounds() const;
};