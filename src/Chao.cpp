#include "Chao.h"

using namespace Entidades::Personagens;

Chao::Chao(const char* caminhoTextura) {
	colisao.setPosition(0.0f, 1080.0f - 50.0f);
	setPos(0.0f, 1080.0f - 50.0f);
	sf::Vector2f tam(1920.0f, 50.0f);
	colisao.setSize(tam);
	setText(caminhoTextura, colisao);

	contraGravidade = -0.3f;
}

Chao::~Chao() {}

void Chao::executar() {

	setPos(pos.x,pos.y + gravidade + contraGravidade);

	desenhar(colisao.getPosition());
}

sf::FloatRect Chao::getBounds() const {
	return colisao.getGlobalBounds();
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