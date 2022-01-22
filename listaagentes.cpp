#include "listaagentes.h"

using namespace std;

void ListaAgentes::intercambiar(NodoAgente*a, NodoAgente*b) {
    NodoAgente aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void ListaAgentes::copiarTodo(const ListaAgentes&l) {
    NodoAgente* aux1=l.ultimoInsertado;
    NodoAgente* aux2=nullptr;

    while(aux1 != nullptr) {
        NodoAgente* nuevoNodo=new NodoAgente();
        if(aux2==nullptr) {
            aux2 = nuevoNodo;
            primerInsertado = aux2;
        }
        nuevoNodo->setAgente(aux1->getAgente());
        nuevoNodo->setSiguiente(ultimoInsertado);
        ultimoInsertado->setAnterior(nuevoNodo);
        ultimoInsertado = nuevoNodo;
        aux1 = aux1->getSiguiente();
    }
}


ListaAgentes::ListaAgentes() : ultimoInsertado(nullptr), primerInsertado(nullptr), auxiliar1(nullptr), auxiliar2(nullptr) {

}

ListaAgentes::ListaAgentes(const ListaAgentes&l) {
    copiarTodo(l);
}

ListaAgentes::~ListaAgentes() {
    if(isEmpty() == false){
        eliminarTodo();
    }

}

bool ListaAgentes::isEmpty() {
    return ultimoInsertado == nullptr;
}

void ListaAgentes::insertar(const Agente&a) {
    NodoAgente* nuevo_nodo = new NodoAgente(a);

    if (primerInsertado == nullptr) {
        primerInsertado = nuevo_nodo;
        nuevo_nodo->setSiguiente(ultimoInsertado);
        ultimoInsertado = nuevo_nodo;
    } else {
        nuevo_nodo->setSiguiente(ultimoInsertado);
        ultimoInsertado->setAnterior(nuevo_nodo);
        ultimoInsertado = nuevo_nodo;
    }
}

void ListaAgentes::eliminar(const Agente&a) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->eliminar");
    }
    auxiliar1 = ultimoInsertado;
    if(ultimoInsertado->getAgente()==a) {
        ultimoInsertado=ultimoInsertado->getSiguiente();
        delete auxiliar1;
    } else {
        while(auxiliar1 != nullptr) {
            if(auxiliar1->getAgente() == a) {
                auxiliar2 = auxiliar1->getAnterior();
                auxiliar2->setSiguiente(auxiliar1->getSiguiente());
                delete auxiliar1;
            }
            auxiliar1=auxiliar1->getSiguiente();
        }
    }


}

NodoAgente* ListaAgentes::primerNodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->primerNodo");
    }
    return primerInsertado;
}

NodoAgente* ListaAgentes::ultimoNodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->ultimoNodo");
    }
    return ultimoInsertado;
}

NodoAgente* ListaAgentes::anterior(NodoAgente*a) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->anterior");
    }
    return a->getAnterior();
}

NodoAgente* ListaAgentes::siguiente(NodoAgente*a) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->siguiente");
    }
    return a->getSiguiente();
}

NodoAgente* ListaAgentes::localiza(const Agente&a) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->localiza");
    }
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        if(auxiliar1->getAgente() == a) {
            return auxiliar1;
        }
        auxiliar1= auxiliar1->getSiguiente();
    }
    throw ListException("No encontrado");
}

void ListaAgentes::ordenaPorNombre() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->ordenaPorNombre");
    }
    ordenaPorNombre(ultimoInsertado, primerInsertado);
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        if(auxiliar1->getAgente().getListaDeClientes()->isEmpty() == false) {
            auxiliar1->getAgente().getListaDeClientes()->ordena();
        }
        auxiliar1 = auxiliar1->getSiguiente();
    }
}

void ListaAgentes::ordenaPorNombre(NodoAgente*leftedge, NodoAgente*rightedge) {
    if(leftedge == rightedge) {
        return;
    }

    if(leftedge->getSiguiente() == rightedge) {

        if(leftedge->getAgente().getNombre() > rightedge->getAgente().getNombre()) {

            intercambiar(leftedge, rightedge);

        }
        return;
    }

    NodoAgente* i(leftedge);
    NodoAgente* j(rightedge);

    while(i != j) {
        while(i != j and i->getAgente().getNombre() <= rightedge->getAgente().getNombre()) {
            i = i->getSiguiente();
        }

        while(i != j and j->getAgente().getNombre() >= rightedge->getAgente().getNombre()) {
            j = j->getAnterior();
        }

        intercambiar(i, j);
    }
    intercambiar(i, rightedge);

    if( i!= leftedge) {
        ordenaPorNombre(leftedge, i->getAnterior());
    }

    if(i != rightedge) {
        ordenaPorNombre(i->getSiguiente(), rightedge);
    }

}

void ListaAgentes::ordenaPorEspecialidad() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->ordenaPorEspecialidad");
    }
    ordenaPorEspecialidad(ultimoInsertado,primerInsertado);
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        if(auxiliar1->getAgente().getListaDeClientes()->isEmpty() == false) {
            auxiliar1->getAgente().getListaDeClientes()->ordena();
        }
        auxiliar1 = auxiliar1->getSiguiente();
    }
}

void ListaAgentes::ordenaPorEspecialidad(NodoAgente*leftedge, NodoAgente*rightedge) {
    if(leftedge == rightedge) {
        return;
    }

    if(leftedge->getSiguiente() == rightedge) {

        if(leftedge->getAgente().getEspecialidad() > rightedge->getAgente().getEspecialidad()) {

            intercambiar(leftedge, rightedge);

        }
        return;
    }

    NodoAgente* i(leftedge);
    NodoAgente* j(rightedge);

    while(i != j) {
        while(i != j and i->getAgente().getEspecialidad() <= rightedge->getAgente().getEspecialidad()) {
            i = i->getSiguiente();
        }

        while(i != j and j->getAgente().getEspecialidad() >= rightedge->getAgente().getEspecialidad()) {
            j = j->getAnterior();
        }

        intercambiar(i, j);
    }
    intercambiar(i, rightedge);

    if( i!= leftedge) {
        ordenaPorEspecialidad(leftedge, i->getAnterior());
    }

    if(i != rightedge) {
        ordenaPorEspecialidad(i->getSiguiente(), rightedge);
    }

}


string ListaAgentes::recupera(const Agente&a) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->recupera");
    }
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        if(auxiliar1->getAgente() == a) {
            return auxiliar1->getAgente().toString();
        }
        auxiliar1 = auxiliar1->getSiguiente();
    }
    throw ListException("No encontrado");
}

string ListaAgentes::toString() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->toString");
    }
    string resultado;
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        resultado += auxiliar1->toString();
        resultado += "\n";
        auxiliar1 = auxiliar1->getSiguiente();
    }
    return resultado;
}

string ListaAgentes::toStringAgentes() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->toStringAgentes");
    }
    string resultado;
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        resultado += auxiliar1->getAgente().toString();
        resultado += "\n";
        auxiliar1 = auxiliar1->getSiguiente();
    }
    return resultado;
}

string ListaAgentes::toStringEspecialidad(const std::string& e) {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->toStringAgentes");
    }
    string resultado;
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        if(auxiliar1->getAgente().getEspecialidad() == e){
            resultado += auxiliar1->getAgente().toString();
            resultado += "\n";
        }
        auxiliar1 = auxiliar1->getSiguiente();
    }
    return resultado;
}

void ListaAgentes::guardarAlDisco(const string& fileName) {
    ofstream myFile;
    myFile.open("Archivos\\" + fileName, myFile.trunc);

    if(! myFile.is_open()) {
        string message;
        message = "Error al tratar de abrir el archivo";
        message += fileName;
        message += "para escritura";
        throw ListException(message);
    }

    NodoAgente* aux(ultimoInsertado);

    system("del Archivos\\*.clientes.txt");

    while(aux != nullptr) {
        myFile << aux->getAgente() << endl;

        try {
            aux->getAgente().getListaDeClientes()->guardarAlDisco(aux->getAgente().getNombre().toString() + ".clientes.txt");
        } catch(ListException ex) {
            cout<< ex.what() << endl;
        }
        aux = aux->getSiguiente();
    }
    myFile.close();
}

void ListaAgentes::leerDelDisco(const std::string& fileName) {
    ifstream myFile;

    myFile.open("Archivos\\" + fileName);
    if(!myFile.is_open()) {
        string message;
        message = "Error al tratar de abrir el archivo";
        message+=fileName;
        message+= "para lectura";
        throw ListException(message);
    }

    if(isEmpty() == false) {
        eliminarTodo();
    }

    Agente myAgente;

    while(myFile >> myAgente) {
        try {
            myAgente.getListaDeClientes()->leerDelDisco(myAgente.getNombre().toString() + ".clientes.txt");
        } catch(ListException ex) {
            cout<<ex.what()<<endl;
        }
        insertar(myAgente);
    }
    myFile.close();
}


void ListaAgentes::eliminarTodo() {
    if(isEmpty()) {
        throw ListException("La lista esta vacia, ListaAgentes->eliminarTodo");
    }
    auxiliar1 = ultimoInsertado;
    while(auxiliar1 != nullptr) {
        auxiliar2 = auxiliar1;
        auxiliar1 = auxiliar1->getSiguiente();
        delete auxiliar2;
    }
    ultimoInsertado = nullptr;
    primerInsertado = nullptr;
}

ListaAgentes& ListaAgentes::operator=(const ListaAgentes&l) {
    if(isEmpty()==false) {
        eliminarTodo();
    }
    copiarTodo(l);

    return *this;
}
