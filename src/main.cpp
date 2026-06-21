#include "Jogo.h"
#include "Inimigo.h"

using namespace Gerenciadores;
using namespace Entidades::EntidadesPertinentes::Personagens::Inimigos;

int main() {

    Inimigo::sementear();

    Jogo j;
    j.executar();

    return 0;
}
