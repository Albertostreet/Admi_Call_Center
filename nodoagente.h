#ifndef NODOAGENTE_H_INCLUDED
#define NODOAGENTE_H_INCLUDED

#include <string>

#include "agente.h"
class NodoAgente{
private:
    Agente miAgente;
    NodoAgente *siguiente;
    NodoAgente *anterior;
public:
    NodoAgente();
    NodoAgente(const Agente&);

    Agente& getAgente();
    NodoAgente *getSiguiente();
    NodoAgente *getAnterior();

    std::string toString();

    void setAgente(const Agente&);
    void setSiguiente(NodoAgente*);
    void setAnterior(NodoAgente*);

    NodoAgente& operator = (const NodoAgente&);
};

#endif // NODOAGENTE_H_INCLUDED
