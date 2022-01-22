#include "menucliente.h"

using namespace std;

MenuCliente::MenuCliente(): MiLista(new ListaCliente) {
}

MenuCliente::MenuCliente(ListaCliente*l) {
    MiLista = l;
}

void MenuCliente::menuPrincipal() {
    char op;
    char op2;
    do {

        cout <<"Sistema de administracion call-center" << endl;

        cout <<"1)Agregar Cliente" <<endl;
        cout <<"2)Eliminar Cliente" <<endl;
        cout <<"3)Modificar Cliente" <<endl;
        cout <<"4)Mostrar Lista"<< endl;
        cout <<"5)Ordenar la Lista"<<endl;
        cout <<"6)Borrar Lista"<<endl;
        cout <<"7)Guardar o leer del disco"<<endl;
        cout <<"8)Salir" <<endl<<endl;
        cout <<"Eliga una opcion: ";

        cin >> op;
        cin.ignore();
        cout<<endl;
        switch(op) {

        case '1':
            agregarCliente();
            break;
        case '2':
            borrarCliente();
            break;
        case '3':
            modificarCliente();
            break;
        case '4':
            mostrarLista();
            break;
        case '5':
            ordenarLista();
            break;
        case '6':
            borrarLista();
            break;
        case '7':
            cout<<"1)Guardar al disco"<<endl;
            cout<<"2)Leer del disco"<<endl;
            cin>>op2;
            cin.ignore();
            cout<<endl;
            switch(op2) {
            case '1':
                guardarAlDisco();
                break;
            case '2':
                leerDelDisco();
                break;
            }
            break;
        case '8':
            cout <<"Salir" <<endl;
            break;

        default:
            cout <<"Opcion invalida"<<endl;
        }
    } while(op!= '8');

}

void MenuCliente::agregarCliente() {
    Cliente miCliente;
    Nombre miNombre;
    Horario miHorario;
    Duracion miDuracion;
    string miCadena;
    int miEntero;

    cout<<"Agregar Cliente"<<endl<<endl;

    cout<<"Nombre de la persona"<<endl;
    cout<<"Apellidos:";
    getline(cin,miCadena,'\n');
    miNombre.setApellido(miCadena);
    cout<<"Nombre:";
    getline(cin,miCadena,'\n');
    miNombre.setNombre(miCadena);

    cout<<"Hora de atencion"<<endl<<"hora: ";
    cin>>miEntero;
    miHorario.setHora(miEntero);
    cout<<"Minuto/s: ";
    cin>>miEntero;
    miHorario.setMinuto(miEntero);

    cout<<"Duracion de la llamada:"<<endl;
    cout<<"Minutos: ";
    cin>>miEntero;
    miDuracion.setMinuto(miEntero);
    cout<<"Segundo/s: ";
    cin>>miEntero;
    miDuracion.setSegundo(miEntero);
    cout<<endl<<endl;

    miCliente.setNombre(miNombre);
    miCliente.setHoraDeLlamada(miHorario);
    miCliente.setDuracion(miDuracion);

    MiLista->insertar(miCliente);
}

void MenuCliente::agregarCliente(const Horario& e, const Horario& s) {
    Cliente miCliente;
    Nombre miNombre;
    Horario miHorario;
    Duracion miDuracion;
    string miCadena;
    int miEntero;

    cout<<"Agregar Cliente"<<endl<<endl;

    cout<<"Nombre de la persona"<<endl;
    cout<<"Apellidos:";
    getline(cin,miCadena,'\n');
    miNombre.setApellido(miCadena);
    cout<<"Nombre:";
    getline(cin,miCadena,'\n');
    miNombre.setNombre(miCadena);

    miCliente.setNombre(miNombre);

    cout<<"Hora de atencion"<<endl<<"hora: ";
    cin>>miEntero;
    miHorario.setHora(miEntero);
    cout<<"Minuto/s: ";
    cin>>miEntero;
    miHorario.setMinuto(miEntero);

    if(miHorario.toInt() < e.toInt() or miHorario.toInt() > s.toInt()){
        miHorario = e;
    }

    miCliente.setHoraDeLlamada(miHorario);

    cout<<"Duracion de la llamada:"<<endl;
    cout<<"Minutos: ";
    cin>>miEntero;
    miDuracion.setMinuto(miEntero);
    cout<<"Segundo/s: ";
    cin>>miEntero;
    miDuracion.setSegundo(miEntero);

    miCliente.setDuracion(miDuracion);

     cout<<endl<<endl;

    MiLista->insertar(miCliente);
}

void MenuCliente::borrarCliente() {
    if(MiLista->isEmpty()) {
        cout<<"La lista esta vacia, borrarCliente"<<endl<<endl;
        return;
    }
    Cliente miCliente;
    Nombre miNombre;
    Horario miHorario;
    string miCadena;
    int miEntero;
    cout<<"Borrar Cliente"<<endl<<endl;

    cout<<"Ingresa el nombre del cliente"<<endl;
    cout<<"Apellidos:";
    getline(cin,miCadena,'\n');
    miNombre.setApellido(miCadena);
    cout<<"Nombre:";
    getline(cin,miCadena,'\n');
    miNombre.setNombre(miCadena);
    miCliente.setNombre(miNombre);

    cout<<"Hora de atencion"<<endl<<"hora: ";
    cin>>miEntero;
    miHorario.setHora(miEntero);
    cout<<"Minuto/s: ";
    cin>>miEntero;
    miHorario.setMinuto(miEntero);
    miCliente.setHoraDeLlamada(miHorario);

    cout<<endl<<endl;
    try {
        MiLista->eleminar(miCliente);
    } catch(ListException ex) {
        cout<<ex.what()<<endl;
    }
    cout<<endl<<endl;
}

void MenuCliente::modificarCliente() {
    if(MiLista->isEmpty()) {
        cout<<"La lista esta vacia, modificarCliente"<<endl<<endl;
        return;
    }

    Cliente miCliente;
    Nombre miNombre;
    Horario miHorario;
    Duracion miDuracion;
    string miCadena;
    int miEntero;
    NodoCliente *aux;

    cout<<"Modificar Cliente"<<endl<<endl;

    cout<<"Ingresa el nombre del cliente"<<endl;
    cout<<"Apellidos:";
    getline(cin,miCadena,'\n');
    miNombre.setApellido(miCadena);
    cout<<endl<<"Nombre:";
    getline(cin,miCadena,'\n');
    miNombre.setNombre(miCadena);
    miCliente.setNombre(miNombre);

    cout<<"Hora de atencion"<<endl<<"hora: ";
    cin>>miEntero;
    miHorario.setHora(miEntero);
    cout<<"Minuto/s: ";
    cin>>miEntero;
    miHorario.setMinuto(miEntero);
    miCliente.setHoraDeLlamada(miHorario);

    cout<<endl<<endl;

    try {
        aux = MiLista->localiza(miCliente);

        miCliente = aux->getCliente();
        cout<<"Modificacion de la duracion de la llamada del cliente:"<<endl<< miCliente.getNombre()<<endl<<endl;

        cout<<"Duracion de la llamada:"<<endl;
        cout<<"Minutos: ";
        cin>>miEntero;
        miDuracion.setMinuto(miEntero);
        cout<<"Segundo/s: ";
        cin>>miEntero;
        miDuracion.setSegundo(miEntero);
        cout<<endl;
        miCliente.setDuracion(miDuracion);
        aux->setCliente(miCliente);
        cout<<endl<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl;
    }


}

void MenuCliente::ordenarLista() {
    try {
        MiLista->ordena();
        cout<<MiLista->toString()<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}

void MenuCliente::mostrarLista() {
    cout<<"Mostrar lista"<<endl;
    cout<<MiLista->toString()<<endl<<endl;
}

void MenuCliente::guardarAlDisco() {
    if(MiLista->isEmpty()) {
        cout<<"La lista esta vacia, guardarAlDisco"<<endl<<endl;
        return;
    }
    cout<<"Guardando en el disco"<<endl<<endl;
    try {
        MiLista->guardarAlDisco(";clientes.txt"); /// falta ponerle el nombre del agente
        cout<<"Guardado exitosamente"<<endl;
    } catch(ListException ex) {
        cout<< ex.what()<<endl;
    }
}

void MenuCliente::leerDelDisco() {

}


void MenuCliente::borrarLista() {
    cout<<"Borrando la lista"<<endl;
    try {
        MiLista->eliminarTodo();

        cout<<"Borrada"<<endl<<endl;
    } catch( ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}
