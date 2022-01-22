#ifndef LISTAAGENTES_H_INCLUDED
#define LISTAAGENTES_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

#include "nodoagente.h"
#include "agente.h"
#include "listexception.h"
#include "menucliente.h"
class ListaAgentes{
private:
    NodoAgente *ultimoInsertado;
    NodoAgente *primerInsertado;
    NodoAgente *auxiliar1;
    NodoAgente *auxiliar2;

    void intercambiar(NodoAgente*,NodoAgente*);
    void copiarTodo(const ListaAgentes&);
public:
    ListaAgentes();
    ListaAgentes(const ListaAgentes&);
    ~ListaAgentes();

    bool isEmpty();
    void insertar(const Agente&);
    void eliminar(const Agente&);
    NodoAgente* primerNodo();
    NodoAgente* ultimoNodo();
    NodoAgente* anterior(NodoAgente*);
    NodoAgente* siguiente(NodoAgente*);
    NodoAgente* localiza(const Agente&);
    void ordenaPorNombre();
    void ordenaPorNombre(NodoAgente*,NodoAgente*);
    void ordenaPorEspecialidad();
    void ordenaPorEspecialidad(NodoAgente*,NodoAgente*);
    std::string recupera(const Agente&);
    std::string toString();
    std::string toStringAgentes();
    std::string toStringEspecialidad(const std::string&);
    void guardarAlDisco(const std::string&);
    void leerDelDisco(const std::string&);
    void eliminarTodo();

    ListaAgentes& operator = (const ListaAgentes&);
};

#endif // LISTAAGENTES_H_INCLUDED
