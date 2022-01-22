#include "menuagentes.h"

using namespace std;

MenuAgentes::MenuAgentes(): listaDeAgentes(nullptr) {

}

MenuAgentes::MenuAgentes(ListaAgentes*l) {
    listaDeAgentes = l;
}

void MenuAgentes::menuPrincipal() {
    char op;
    char op2;

    do {
        cout<<"Sistema de administracion call-center" << endl<<endl;
        cout<<"1)Agregar Agente" <<endl;
        cout<<"2)Borrar Agente"<<endl;
        cout<<"3)Modificar Agente" <<endl;
        cout<<"4)Ordenar la Lista"<<endl;
        cout<<"5)Mostrar Lista"<< endl;
        cout<<"6)Borrar Lista"<<endl;
        cout<<"7)Guardar o leer del disco"<<endl;
        cout<<"8)Mostrar datos del agente"<<endl;
        cout<<"9)Salir" <<endl<<endl;

        cout <<"Eliga una opcion: ";
        cin>>op;
        cin.ignore();
        cout<<endl;
        switch(op) {

        case '1':
            cout <<"Agregar Agente:" <<endl<<endl;
            agregarAgente();
            break;
        case '2':
            cout<<"Borrar Agente:"<<endl<<endl;
            borrarAgente();
            break;
        case '3':

            do {
                cout <<"Modificar Agente:" <<endl<<endl;
                cout <<"1)Modificar Agente" <<endl;
                cout<<"2)Modificar Lista de Clientes Del Agente"<<endl;
                cout<<"3)Salir"<<endl;
                cin>>op2;
                cin.ignore();
                switch(op2) {
                case '1':
                    cout <<"Modificar Agente:" <<endl<<endl;
                    modificarAgente();
                    break;
                case '2':
                    cout<<"Modificar Lista de Clientes Del Agente:"<<endl<<endl;
                    modificarListaDeClientesPorAgente();
                    break;
                case '3':
                    cout<<"Salir"<<endl;
                    break;
                default:
                    cout<<"Opcion invalida"<<endl;
                }
            } while(op2 != '3');
            break;
        case '4':
            do {
                cout <<"Ordenar la Lista:"<<endl<<endl;
                cout<<"1)Ordenar por nombre de los agentes"<<endl;
                cout<<"2)Ordenar por especialidad"<<endl;
                cout<<"3)Salir"<<endl;
                cin>>op2;
                cin.ignore();
                cout<<endl;
                switch(op2) {
                case '1':
                    ordenarPorNombre();
                    break;
                case '2':
                    ordenarPorEspecialidad();
                    break;
                case '3':
                    cout<<"Salir"<<endl;
                    break;
                default:
                    cout<<"Opcion Invalida"<<endl;
                }
            } while(op2 != '3');
            break;
        case '5':
            do {
                cout <<endl<<"Mostrar Lista:"<< endl<<endl;
                cout<<"1)Mostrar Lista de Agentes"<<endl;
                cout<<"2)Mostrar Lista de Clientes por Agente"<<endl;
                cout<<"3)Mostrar Lista de Clientes por Especialidad"<<endl;
                cout<<"4)Salir"<<endl;
                cin>>op2;
                cin.ignore();
                cout<<endl;
                switch(op2) {
                case '1':
                    cout<<"Mostrar Lista de Agentes:"<<endl<<endl;
                    mostrarListaDeAgentes();
                    break;
                case '2':
                    cout<<"Mostrar Lista de Clientes por Agente:"<<endl<<endl;
                    mostrarListaDeClientesPorAgente();
                    break;
                case '3':
                    cout<<"Mostrar Lista de Clientes por Especialidad"<<endl;
                    mostrarListaPorEspecialidad();
                    break;
                case '4':
                    cout<<"Salir"<<endl;
                    break;
                default:
                    cout<<"Opcion Invalida"<<endl;
                }
            } while(op2 != '4');

            break;
        case '6':
            cout <<"Borrar Lista"<<endl<<endl;
            borrarLista();
            break;
        case '7':
            cout<<"Guardar o leer del disco"<<endl<<endl;
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
            cout<<"Mostrar datos del agente"<<endl;
            mostrarAgente();
                break;
        case '9':
            cout <<"Salir" <<endl<<endl;
            getchar();
            break;

        default:
            cout <<"Opcion invalida"<<endl;
            cout <<"presione enter para continuar" <<endl;
            getchar();
        }
    } while(op!= '9');

}

void MenuAgentes::agregarAgente() {
    char opcion;
    Agente miAgente;
    Nombre miNombre;
    Horario miHorario;
    string cadena;
    int entero;

    cout<<"Ingresa el nombre del agente"<<endl;
    cout<<"Apellidos: ";
    getline(cin,cadena,'\n');
    miNombre.setApellido(cadena);
    cout<<"Nombre: ";
    getline(cin,cadena,'\n');
    miNombre.setNombre(cadena);
    miAgente.setNombre(miNombre);

    cout<<"Ingresa el horario de entrada del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioEntrada(miHorario);

    cout<<"Ingresa el horario de salida del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioSalida(miHorario);

    cout<<"Ingresa el numero de extencion:"<<endl;
    cin>>entero;
    cin.ignore();
    miAgente.setNumeroDeExtencion(entero);

    cout<<"Ingresa las horas extras:"<<endl;
    cin>>entero;
    cin.ignore();
    miAgente.setHorasExtras(entero);

    cout<<"Ingresa la especialidad"<<endl;
    getline(cin,cadena,'\n');
    miAgente.setEspecialidad(cadena);
    cout<<endl;


    cout<<"Quieres Agregar la lista de clientes ahora mismo? s/n"<<endl;
    cin>>opcion;
    cin.ignore();
    cout<<endl;
    switch(opcion) {
    case 's': case 'S':
        char op2;
        do{
            MenuCliente menu(miAgente.getListaDeClientes());
            menu.agregarCliente(miAgente.getHorarioEntrada(), miAgente.getHorarioSalida());
            cout<<"Quieres agregar otro cliente a la lista? s/n"<<endl;
            cin>>op2;
            cin.ignore();
            if(op2 == 'N'){
                op2 = 'n';
            }
        }while(op2 != 'n');

        break;
    }

    listaDeAgentes->insertar(miAgente);
}

void MenuAgentes::borrarAgente() {
    if(listaDeAgentes->isEmpty()) {
        cout<<"La lista esta vacia, borrarAgente"<<endl<<endl;
        return;
    }
    Agente miAgente;
    Nombre miNombre;
    Horario miHorario;
    string cadena;
    int entero;

    cout<<"Ingresa el nombre del agente"<<endl;
    cout<<"Apellidos: ";
    getline(cin,cadena,'\n');
    miNombre.setApellido(cadena);
    cout<<"Nombre: ";
    getline(cin,cadena,'\n');
    miNombre.setNombre(cadena);
    miAgente.setNombre(miNombre);
    cout<<endl;

    cout<<"Ingresa el horario de entrada del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioEntrada(miHorario);

    cout<<"Ingresa el horario de salida del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioSalida(miHorario);
    cout<<endl;

    try {
        listaDeAgentes->eliminar(miAgente);
    } catch(ListException ex) {
        cout<<ex.what()<<endl;
    }
}

void MenuAgentes::modificarAgente() {
    if(listaDeAgentes->isEmpty()) {
        cout<<"La lista esta vacia, modificarAgente"<<endl<<endl;
        return;
    }
    Agente miAgente;
    Nombre miNombre;
    Horario miHorario;
    string cadena;
    int entero;

    cout<<"Ingresa el nombre del agente"<<endl;
    cout<<"Apellidos: ";
    getline(cin,cadena,'\n');
    miNombre.setApellido(cadena);
    cout<<"Nombre: ";
    getline(cin,cadena,'\n');
    miNombre.setNombre(cadena);
    miAgente.setNombre(miNombre);
    cout<<endl;

    cout<<"Ingresa el horario de entrada del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioEntrada(miHorario);

    cout<<"Ingresa el horario de salida del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioSalida(miHorario);
    cout<<endl;

    try {
        NodoAgente* aux = listaDeAgentes->localiza(miAgente);
        cout<<aux->toString()<<endl<<endl;

        cout<<"Ingresa el nombre del agente"<<endl;
        cout<<"Apellidos: ";
        getline(cin,cadena,'\n');
        miNombre.setApellido(cadena);
        cout<<"Nombre: ";
        getline(cin,cadena,'\n');
        miNombre.setNombre(cadena);
        miAgente.setNombre(miNombre);

        cout<<"Ingresa el horario de entrada del agente"<<endl;
        cout<<"Hora:";
        cin>>entero;
        miHorario.setHora(entero);
        cout<<"Minuto/s: ";
        cin>>entero;
        cin.ignore();
        miHorario.setMinuto(entero);
        miAgente.setHorarioEntrada(miHorario);

        cout<<"Ingresa el horario de salida del agente"<<endl;
        cout<<"Hora:";
        cin>>entero;
        miHorario.setHora(entero);
        cout<<"Minuto/s: ";
        cin>>entero;
        cin.ignore();
        miHorario.setMinuto(entero);
        miAgente.setHorarioSalida(miHorario);
        cout<<endl;

        cout<<"Ingresa el numero de extencion:"<<endl;
        cin>>entero;
        miAgente.setNumeroDeExtencion(entero);

        cout<<"Ingresa las horas extras:"<<endl;
        cin>>entero;
        cin.ignore();
        miAgente.setHorasExtras(entero);

        cout<<"Ingresa la especialidad"<<endl;
        getline(cin,cadena,'\n');
        miAgente.setEspecialidad(cadena);

        ListaCliente* auxiliar = aux->getAgente().getListaDeClientes();

       miAgente.setListaDeClientes(*auxiliar);

        aux->setAgente(miAgente);
    } catch(ListException ex) {
        cout<<ex.what()<<endl;
    }

}

void MenuAgentes::modificarListaDeClientesPorAgente() {
    if(listaDeAgentes->isEmpty()) {
        cout<<"La lista esta vacia, modificarListaDeClientesPorAgente"<<endl<<endl;
        return;
    }
    Agente miAgente;
    Nombre miNombre;
    Horario miHorario;
    string cadena;
    int entero;

    cout<<"Ingresa el nombre del agente"<<endl;
    cout<<"Apellidos: ";
    getline(cin,cadena,'\n');
    miNombre.setApellido(cadena);
    cout<<"Nombre: ";
    getline(cin,cadena,'\n');
    miNombre.setNombre(cadena);
    miAgente.setNombre(miNombre);

    cout<<"Ingresa el horario de entrada del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioEntrada(miHorario);

    cout<<"Ingresa el horario de salida del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioSalida(miHorario);
    cout<<endl;
    try {
        NodoAgente *aux = listaDeAgentes->localiza(miAgente);
        menuClientes = aux->getAgente().getListaDeClientes();
        menuClientes.menuPrincipal();
    } catch(ListException ex) {
        cout<<ex.what()<<endl;
    }
}

void MenuAgentes::ordenarPorNombre() {
    try {
        listaDeAgentes->ordenaPorNombre();
        cout<<listaDeAgentes->toString()<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}

void MenuAgentes::ordenarPorEspecialidad() {
    try {
        listaDeAgentes->ordenaPorEspecialidad();
        cout<<listaDeAgentes->toString()<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}


void MenuAgentes::mostrarListaDeAgentes() {
    try {
        cout<<listaDeAgentes->toStringAgentes()<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}

void MenuAgentes::mostrarListaDeClientesPorAgente() {
    try {
        cout<<listaDeAgentes->toString()<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}

void MenuAgentes::mostrarListaPorEspecialidad() {
    if(listaDeAgentes->isEmpty()){
        cout<<"No hay datos"<<endl;
        return;
    }

    string cadena;

    cout<<"Ingresa la especialidad"<<endl;
    getline(cin,cadena,'\n');
    cout<<endl<<endl;
    try {
        cout<<listaDeAgentes->toStringEspecialidad(cadena)<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}

void MenuAgentes::mostrarAgente() {
    if(listaDeAgentes->isEmpty()){
        cout<<"No hay datos"<<endl;
        return;
    }

    Agente miAgente;
    Nombre miNombre;
    Horario miHorario;
    string cadena;
    int entero;

    cout<<"Ingresa el nombre del agente"<<endl;
    cout<<"Apellidos: ";
    getline(cin,cadena,'\n');
    miNombre.setApellido(cadena);
    cout<<"Nombre: ";
    getline(cin,cadena,'\n');
    miNombre.setNombre(cadena);
    miAgente.setNombre(miNombre);
    cout<<endl;

    cout<<"Ingresa el horario de entrada del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioEntrada(miHorario);

    cout<<"Ingresa el horario de salida del agente"<<endl;
    cout<<"Hora:";
    cin>>entero;
    miHorario.setHora(entero);
    cout<<"Minuto/s: ";
    cin>>entero;
    cin.ignore();
    miHorario.setMinuto(entero);
    miAgente.setHorarioSalida(miHorario);
    cout<<endl;

    try{
        cout<<listaDeAgentes->recupera(miAgente)<<endl;
    }catch(ListException ex){
        cout<<ex.what()<<endl;
    }
}


void MenuAgentes::guardarAlDisco() {
    if(listaDeAgentes->isEmpty()) {
        cout<<"La lista esta vacia, guardarAlDisco"<<endl;
        return;
    }
    cout<<"Guardando en el disco"<<endl;
    try {
        listaDeAgentes->guardarAlDisco("Lista de Agentes.txt");
        cout<<"Guardado exitosamente"<<endl<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }

}

void MenuAgentes::leerDelDisco() {
    cout<<"Leyendo del disco..."<<endl;
    try {
        listaDeAgentes->leerDelDisco("Lista de Agentes.txt");
        cout<<"Lectura exitosa"<<endl;
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}


void MenuAgentes::borrarLista() {
    try {
        listaDeAgentes->eliminarTodo();
    } catch(ListException ex) {
        cout<<ex.what()<<endl<<endl;
    }
}
