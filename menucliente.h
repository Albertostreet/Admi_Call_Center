#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED

#include <iostream>
#include <string>

#include "duracion.h"
#include "horario.h"
#include "nombre.h"
#include "cliente.h"
#include "nodocliente.h"
#include "listacliente.h"

class MenuCliente{
private:
    ListaCliente* MiLista;
public:
    MenuCliente();
    MenuCliente(ListaCliente*);

    void menuPrincipal();
    void agregarCliente();
    void agregarCliente(const Horario&, const Horario&);
    void borrarCliente();
    void modificarCliente();
    void ordenarLista();
    void mostrarLista();
    void guardarAlDisco();
    void leerDelDisco();
    void borrarLista();
};

#endif // MENUCLIENTE_H_INCLUDED
