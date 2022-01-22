#include "agente.h"

using namespace std;

Agente::Agente() : horasExtras(0), numeroDeExtencion(0) {

}

Agente::Agente(const Agente&a): miNombre(a.miNombre), horarioEntrada(a.horarioEntrada), horasExtras(a.horasExtras), numeroDeExtencion(a.numeroDeExtencion), especialidad(a.especialidad), miListaDeClientes(a.miListaDeClientes) {

}

Nombre Agente::getNombre() {
    return miNombre;
}

Horario Agente::getHorarioEntrada() {
    return horarioEntrada;
}

Horario Agente::getHorarioSalida()
{
    return horarioSalida;
}

string Agente::getNumeroDeExtencion() {
    char resultado[4];
    sprintf(resultado,"+%i",numeroDeExtencion);
    return resultado;
}

string Agente::getHorasExtras() {
    char resultado[10];
    sprintf(resultado,"%i",horasExtras);
    return resultado;
}

string Agente::getEspecialidad() {
    return especialidad;
}

ListaCliente* Agente::getListaDeClientes() {
    return &miListaDeClientes;
}

string Agente::toString() {
    string toString;

    toString = "Nombre del agente : ";
    toString +=  miNombre.toString();
    toString += "\n";
    toString += "Horario de atencion : ";
    toString += horarioEntrada.toString() + " - ";
    toString += horarioSalida.toString();
    toString += "\n";
    toString += "Numero de extencion : ";
    toString += getNumeroDeExtencion();
    toString += "\n";
    toString += "Horas extras trabajadas : ";
    toString += getHorasExtras();
    toString += "\n";
    toString += "Especialidad : ";
    toString += getEspecialidad();
    toString += "\n";
    return toString;
}

void Agente::setNombre(const Nombre&n) {
    miNombre = n;
}

void Agente::setHorarioEntrada(const Horario&h) {
    horarioEntrada = h;
}
void Agente::setHorarioSalida(const Horario&h)
{
    horarioSalida = h;
}

void Agente::setNumeroDeExtencion(const int&n) {
    numeroDeExtencion = n;
}

void Agente::setHorasExtras(const int&h) {
    horasExtras = h;
}

void Agente::setEspecialidad(const std::string&e) {
    especialidad = e;
}

void Agente::setListaDeClientes(ListaCliente&l) {
    miListaDeClientes = l;
}

Agente& Agente::operator=(const Agente&a) {
    miNombre = a.miNombre;
    horarioEntrada = a.horarioEntrada;
    horarioSalida = a.horarioSalida;
    numeroDeExtencion = a.numeroDeExtencion;
    horasExtras = a.horasExtras;
    especialidad = a.especialidad;
    miListaDeClientes = a.miListaDeClientes;

    return *this;
}

bool Agente::operator==(const Agente&a) {
    if(miNombre == a.miNombre and horarioEntrada == a.horarioEntrada and horarioSalida == a.horarioSalida) {
        return true;
    } else {
        return false;
    }
}

bool Agente::operator<(const Agente&a) {
    return miNombre < a.miNombre;
}

bool Agente::operator<=(const Agente&a) {
    return miNombre <= a.miNombre;
}

bool Agente::operator>(const Agente&a) {
    return miNombre > a.miNombre;
}

bool Agente::operator>=(const Agente&a) {
    return miNombre >= a.miNombre;
}

ostream& operator<<(ostream& os, Agente& a){
    os << a.miNombre;
    os << a.horarioEntrada;
    os << a.horarioSalida;
    os << a.numeroDeExtencion <<endl;
    os << a.getHorasExtras() <<endl;
    os << a.especialidad <<endl;
    return os;
}
istream& operator>>(istream& is,Agente& a){
    string cadena;

    is >> a.miNombre;
    is >> a.horarioEntrada;
    is >> a.horarioSalida;
    getline(is,cadena,'\n');
    a.numeroDeExtencion= atoi(cadena.c_str());
    getline(is,cadena,'\n');
    a.horasExtras = atoi(cadena.c_str());
    getline(is,a.especialidad,'\n');
    getline(is,cadena,'\n');

    return is;
}
