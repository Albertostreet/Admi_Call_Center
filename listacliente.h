#ifndef LISTACLIENTE_H_INCLUDED
#define LISTACLIENTE_H_INCLUDED

#include <string>
#include <fstream>

#include "nodocliente.h"
#include "cliente.h"
#include "listexception.h"


class ListaCliente{
private:
    NodoCliente* ultimo;
    NodoCliente* primerInsertado;
    NodoCliente* auxiliar;
    NodoCliente* auxiliar2;

    void intercambiar(NodoCliente*,NodoCliente*);
    void copiarTodo(const ListaCliente&);
public:
    ListaCliente();
    ListaCliente(const ListaCliente&);
     ~ListaCliente();

    bool isEmpty();
    void insertar(const Cliente&);
    void eleminar(const Cliente&);
    NodoCliente* primerNodo();
    NodoCliente* ultimoNodo();
    NodoCliente* anterior(NodoCliente*);
    NodoCliente* siguiente(NodoCliente*);
    NodoCliente* localiza(const Cliente&);
    void ordena();
    void ordena(NodoCliente*,NodoCliente*);
    std::string recupera(const Cliente&);
    std::string toString();
    void guardarAlDisco(const std::string&);
    void leerDelDisco(const std::string&);
    void eliminarTodo();

    ListaCliente& operator = (const ListaCliente&);
};

#endif // LISTACLIENTE_H_INCLUDED
