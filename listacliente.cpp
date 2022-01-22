#include "listacliente.h"
#include <iostream>
using namespace std;

void ListaCliente::intercambiar(NodoCliente*a, NodoCliente*b) {
    Cliente aux(a->getCliente());
    a->setCliente(b->getCliente());
    b->setCliente(aux);
}

void ListaCliente::copiarTodo(const ListaCliente&l) {
    NodoCliente* aux1=l.ultimo;
    NodoCliente* aux2=nullptr;

    while(aux1 != nullptr) {
        NodoCliente* nuevoNodo=new NodoCliente();
        if(aux2==nullptr) {
            aux2 = nuevoNodo;
            primerInsertado = aux2;
        }
        nuevoNodo->setCliente(aux1->getCliente());
        nuevoNodo->setSiguiente(ultimo);
        ultimo = nuevoNodo;
        aux1 = aux1->getSiguiente();
    }
}

ListaCliente::ListaCliente() : ultimo(nullptr), auxiliar(nullptr), auxiliar2(nullptr), primerInsertado(nullptr) {
}

ListaCliente::ListaCliente(const ListaCliente&l) {
    if(isEmpty()==false) {
        eliminarTodo();
    }

    copiarTodo(l);
}

ListaCliente::~ListaCliente() {
    if(isEmpty() == false){
        eliminarTodo();
    }
}

bool ListaCliente::isEmpty() {
    return ultimo == nullptr;
}

void ListaCliente::insertar(const Cliente&c) {
    NodoCliente* nuevo_nodo = new NodoCliente(c);
    if (primerInsertado == nullptr) {
        primerInsertado = nuevo_nodo;
    }
    nuevo_nodo->setSiguiente(ultimo);
    ultimo = nuevo_nodo;
}

void ListaCliente::eleminar(const Cliente&c) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia,ListaCliente->eliminar");
    }
    auxiliar = ultimo;
    if(ultimo->getCliente()==c) {
        ultimo=ultimo->getSiguiente();
        delete auxiliar;
    } else {
        auxiliar = auxiliar->getSiguiente();
        while(auxiliar != nullptr) {
            if(auxiliar->getCliente() == c) {
                auxiliar2 = anterior(auxiliar);
                auxiliar2->setSiguiente(auxiliar->getSiguiente());
                delete auxiliar;
            }
            auxiliar=auxiliar->getSiguiente();
        }
    }


}

NodoCliente* ListaCliente::primerNodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia,ListaCliente->primerNodo");
    }
    return primerInsertado;
}

NodoCliente* ListaCliente::ultimoNodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia,ListaCliente->ultimoNodo");
    }
    return ultimo;
}

NodoCliente* ListaCliente::siguiente(NodoCliente*c) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia,ListaCliente->siguiente");
    }
    return c->getSiguiente();
}

NodoCliente* ListaCliente::anterior(NodoCliente*c) {
    if(ultimo == c) {
        throw ListException("No hay anterior del ultimo insertado, ListaCliente->anterior");
    }
    auxiliar = ultimo;
    while(auxiliar != nullptr) {
        if(auxiliar->getSiguiente() == c) {
            return auxiliar;
        }
        auxiliar= auxiliar->getSiguiente();
    }

}

NodoCliente* ListaCliente::localiza(const Cliente&c) {
    if(isEmpty() == true) {
        throw ListException("La lista esta vacia,ListaCliente->localiza");
    }
    auxiliar = ultimo;
    while(auxiliar != nullptr) {
        if(auxiliar->getCliente() == c) {
            return auxiliar;
        }
        auxiliar= auxiliar->getSiguiente();
    }
    if(auxiliar == nullptr) {
        throw ListException("No encontrado,ListaCliente->localiza");
    }
}

void ListaCliente::ordena() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaClientes->ordena");
    }
    ordena(ultimo,primerInsertado);
}


void ListaCliente::ordena(NodoCliente*leftedge, NodoCliente*rightedge) {
    if(leftedge == rightedge) {
        return;
    }

    if(leftedge->getSiguiente() == rightedge) {

        if(leftedge->getCliente() > rightedge->getCliente()) {

            intercambiar(leftedge, rightedge);

        }
        return;
    }

    NodoCliente* i(leftedge);
    NodoCliente* j(rightedge);

    while(i != j) {
        while(i != j and i->getCliente() <= rightedge->getCliente()) {
            i = i->getSiguiente();
        }

        while(i != j and j->getCliente() >= rightedge->getCliente()) {
            j = anterior(j);
        }

        intercambiar(i, j);
    }
    intercambiar(i, rightedge);

    if( i!= leftedge) {
        ordena(leftedge, anterior(i));
    }

    if(i != rightedge) {
        ordena(i->getSiguiente(), rightedge);
    }

}

string ListaCliente::recupera(const Cliente&c) {
    auxiliar = ultimo;
    while(auxiliar != nullptr) {
        if(auxiliar->getCliente() == c) {
            Cliente aux(auxiliar->getCliente());
            return aux.toString();
        }
        auxiliar = auxiliar->getSiguiente();
    }
    throw ListException("No encontrado,ListaCliente->recupera");
}

string ListaCliente::toString() {
    string resultado;
    if(isEmpty()) {
        resultado = "La lista esta vacia";
        return resultado;
    }

    auxiliar = ultimo;
    while(auxiliar != nullptr) {
        resultado += auxiliar->toString();
        resultado += "\n";
        auxiliar = auxiliar->getSiguiente();
    }
    return resultado;
}

void ListaCliente::guardarAlDisco(const string& fileName) {
    ofstream myFile;
    myFile.open("Archivos\\" + fileName, myFile.trunc);

    if(! myFile.is_open()) {
        string message;
        message = "Error al tratar de abrir el archivo ";
        message += fileName;
        message += " para escritura";
        throw ListException(message);
    }
    NodoCliente* aux(ultimo);
    while(aux != nullptr) {
        myFile << aux->getCliente() << endl;
        aux = aux->getSiguiente();
    }
    myFile.close();
}

void ListaCliente::leerDelDisco(const string& fileName) {
    ifstream myFile;

    myFile.open("Archivos\\" + fileName);

    if(!myFile.is_open()) {
        string message;
        message = "Error al tratar de abrir el archivo";
        message+= fileName;
        message+= "para escritura";
        throw ListException(message);
    }
    if(isEmpty() == false) {
        eliminarTodo();
    }

    Cliente myCliente;

    while(myFile >> myCliente) {
        insertar(myCliente);
    }

    myFile.close();
}


void ListaCliente::eliminarTodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia,ListaCliente->eliminarTodo");
    }
    auxiliar = ultimo;
    while(auxiliar != nullptr) {
        auxiliar2 = auxiliar;
        auxiliar = auxiliar->getSiguiente();
        delete auxiliar2;
    }
    ultimo = nullptr;
    primerInsertado = nullptr;
}

ListaCliente& ListaCliente::operator=(const ListaCliente&l) {
    if(isEmpty()==false) {
        eliminarTodo();
    }
    copiarTodo(l);
    return *this;
}
