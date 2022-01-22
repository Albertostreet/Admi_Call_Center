#include <iostream>

#include "listaagentes.h"
#include "menuagentes.h"
#include "listacliente.h"
#include "menucliente.h"

using namespace std;

int main()
{
    ListaAgentes a;
    MenuAgentes menu(&a);
    menu.menuPrincipal();

    return 0;
}
