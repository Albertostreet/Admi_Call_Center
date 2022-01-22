#ifndef MENUAGENTES_H_INCLUDED
#define MENUAGENTES_H_INCLUDED

#include <iostream>
#include <string>

#include "listaagentes.h"
#include "menucliente.h"
#include "listexception.h"
#include "nombre.h"
#include "horario.h"
#include "cliente.h"

class MenuAgentes{
private:
    ListaAgentes* listaDeAgentes;
    MenuCliente menuClientes;
public:
    MenuAgentes();
    MenuAgentes(ListaAgentes*);

    void menuPrincipal();
    void agregarAgente();
    void borrarAgente();
    void modificarAgente();
    void modificarListaDeClientesPorAgente();
    void ordenarPorNombre();
    void ordenarPorEspecialidad();
    void mostrarListaDeAgentes();
    void mostrarListaDeClientesPorAgente();
    void mostrarListaPorEspecialidad();
    void mostrarAgente();
    void guardarAlDisco();
    void leerDelDisco();
    void borrarLista();

};

#endif // MENUAGENTES_H_INCLUDED
