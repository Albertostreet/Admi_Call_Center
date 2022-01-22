#ifndef NODOCLIENTE_H_INCLUDED
#define NODOCLIENTE_H_INCLUDED

#include <string>

#include "cliente.h"

class NodoCliente{
private:
    Cliente cliente;
    NodoCliente *siguiente;
public:
    NodoCliente();
    NodoCliente(const Cliente&);

    Cliente& getCliente();
    NodoCliente *getSiguiente();

    std::string toString();

    void setCliente(const Cliente&);
    void setSiguiente(NodoCliente *);
};

#endif // NODOCLIENTE_H_INCLUDED
