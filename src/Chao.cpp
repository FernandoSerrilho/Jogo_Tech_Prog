#include "Chao.h"
#include "Jogador.h"
using namespace Entidades;

using namespace Entidades::Personagens;

Chao::Chao(const char* caminhoTextura) {
	sf::Vector2f tam(1920.0f, 50.0f);
	setFigura(tam);
	figura.setPosition(0.0f, 1080.0f - 50.0f);
	setPos(0.0f, 1080.0f - 50.0f);
	setText(caminhoTextura, getFigura());
	contraGravidade = -0.3f;
}

Chao::~Chao() {}

void Chao::executar() {
	setPos(pos.x,pos.y + gravidade + contraGravidade);
	desenhar(figura.getPosition());
}

void Chao::colidir(Entidade* pE) {

	sf::FloatRect boundsc = getBounds();
	sf::FloatRect boundse = pE->getBounds();

	if (boundse.top < boundsc.top + boundsc.height && boundse.top + boundse.height > boundsc.top) {

		pE->setPos(pE->getPos().x,boundsc.top - boundse.height);

		pE->setVel(pE->getVel().x,0.0f);

		Jogador* pJ = dynamic_cast<Jogador*>(pE);

		if (pJ != nullptr) {{
			pJ->setPulavel(true);
		}}

	}

}