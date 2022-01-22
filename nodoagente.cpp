#include "nodoagente.h"

using namespace std;

NodoAgente::NodoAgente() : siguiente(nullptr), anterior(nullptr) {
}

NodoAgente::NodoAgente(const Agente&a)
{
    miAgente = a;
}


Agente& NodoAgente::getAgente() {
    return miAgente;
}

NodoAgente* NodoAgente::getSiguiente() {
    return siguiente;
}

NodoAgente* NodoAgente::getAnterior() {
    return anterior;
}

string NodoAgente::toString() {
    string resultado;
    resultado = miAgente.toString();
    resultado+= "\n";
    resultado += "Lista de clientes : \n";
    resultado+= miAgente.getListaDeClientes()->toString();
    resultado += "\n";

    return resultado;
}

void NodoAgente::setAgente(const Agente&a) {
    miAgente = a;
}

void NodoAgente::setSiguiente(NodoAgente*s) {
    siguiente = s;
}

void NodoAgente::setAnterior(NodoAgente*a) {
    anterior = a;
}

NodoAgente& NodoAgente::operator=(const NodoAgente&n)
{
    miAgente = n.miAgente;
    return *this;
}
