#include "BackGround.h"
using namespace Entidades;

BackGround::BackGround(const char* caminhoTextura):Entidade() {
	setFigura(sf::Vector2f(1920.0f, 1080.0f));
	setPos(0.0f, 0.0f);
	Ente::setText(caminhoTextura, figura);
}

BackGround::~BackGround() {}

void BackGround::executar() {
	desenhar(figura.getPosition());
}