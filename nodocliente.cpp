#include "nodocliente.h"

using namespace std;

NodoCliente::NodoCliente() : siguiente(nullptr) { }

NodoCliente::NodoCliente(const Cliente&c)
{
    cliente = c;
}


Cliente& NodoCliente::getCliente() {
    return cliente;
}


NodoCliente* NodoCliente::getSiguiente() {
    return siguiente;
}

string NodoCliente::toString() {
    return cliente.toString();
}


void NodoCliente::setCliente(const Cliente&c) {
    cliente = c;
}

void NodoCliente::setSiguiente(NodoCliente*s) {
    siguiente = s;
}
