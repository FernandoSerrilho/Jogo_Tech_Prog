    #include "Faca.h"
    #include "Jogador.h"

    using namespace Entidades;
    using namespace Entidades::Personagens;

    Faca::Faca(Jogador* pJ): Entidade(), pJog(pJ) {
        setFigura(sf::Vector2f(70.0f, 58.0f));
        setText("Texturas/Faca/FacaDeitada.png", figura);
    }


    Faca::~Faca() { pJog = nullptr; }

    void Faca::initFigura() {

        bool olhandoesquerda = pJog->getDirecao();

       sf::Vector2f posj = pJog->getPos();
       sf::FloatRect boundsj = pJog->getBounds();

       if (olhandoesquerda) {

            figura.setPosition(boundsj.left - 58.0f - 10.0f, boundsj.top);
            sf::Vector2f posF(figura.getPosition());
            figura.setPosition(posF.x,posF.y);
       }

       else {
           figura.setPosition(boundsj.left + boundsj.width + 10.0f, boundsj.top);
           sf::Vector2f posF(figura.getPosition());
           figura.setPosition(posF.x, posF.y);
       }

    }

    void Faca::executar() {
        desenhar(getFigura().getPosition());
    }