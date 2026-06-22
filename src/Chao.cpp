#include "Chao.h"
#include "EntidadePertinente.h"
#include "Jogador.h"

using namespace Entidades;
using namespace Personagens;

Chao::Chao(const char* caminhoTextura):Entidade() {
	sf::Vector2f tam(1920.0f, 50.0f);
	setFigura(tam);
	figura.setPosition(0.0f, 1080.0f - 50.0f);
	setPos(0.0f, 1080.0f - 50.0f);
	setText(caminhoTextura, getFigura());
}

Chao::~Chao() {}

void Chao::executar() {
	desenhar(figura.getPosition());
}

void Chao::colidir(EntidadePertinente* pE) {

	sf::FloatRect boundsc = this->getBounds();
	sf::FloatRect boundse = pE->getBounds();

	if (boundse.top < boundsc.top + boundsc.height && boundse.top + boundse.height > boundsc.top) {

		pE->setPos(pE->getPos().x,boundsc.top - boundse.height);

		pE->setVel(pE->getVel().x,0.0f);

		Jogador* pJ = dynamic_cast<Jogador*>(pE);

		if (pJ != nullptr) {
			pJ->setPulavel(true);
		}

	}

}