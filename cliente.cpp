#include "cliente.h"

using namespace std;

Cliente::Cliente() {  }

Cliente::Cliente(const Cliente&c) : nombre(c.nombre), horaDeLlamada(c.horaDeLlamada), duracion(c.duracion) {   }

string Cliente::getNombre() {
    return nombre.toString();
}

string Cliente::gethoraDeLlamada() {
    return horaDeLlamada.toString();
}

string Cliente::getDuracion() {
    return duracion.toString();
}

string Cliente::toString() {
    string resultado;

    resultado = "Hora de llamada: ";
    resultado += horaDeLlamada.toString();
    resultado += " | ";
    resultado += "Duracion: ";
    resultado += duracion.toString();
    resultado += " | ";
    resultado += "Nombre: ";
    resultado += nombre.toString();

    return resultado;
}

void Cliente::setNombre(const Nombre&n) {
    nombre = n;
}

void Cliente::setHoraDeLlamada(const Horario&h) {
    horaDeLlamada = h;
}

void Cliente::setDuracion(const Duracion&d) {
    duracion = d;
}

Cliente& Cliente::operator=(const Cliente&c) {
    nombre = c.nombre;
    horaDeLlamada = c.horaDeLlamada;
    duracion = c.duracion;

    return *this;
}

bool Cliente::operator==(const Cliente&c) {
    if( nombre == c.nombre and horaDeLlamada == c.horaDeLlamada){
        return true;
    }
    return false;
}

bool Cliente::operator<(const Cliente&c) {
    return horaDeLlamada < c.horaDeLlamada;
}

bool Cliente::operator<=(const Cliente&c) {
    return horaDeLlamada <= c.horaDeLlamada;
}

bool Cliente::operator>(const Cliente&c) {
    return horaDeLlamada > c.horaDeLlamada;
}

bool Cliente::operator>=(const Cliente&c) {
    return horaDeLlamada >= c.horaDeLlamada;
}

ostream& operator<<(ostream& os,Cliente& c){
    os << c.nombre;
    os << c.horaDeLlamada;
    os << c.duracion;
    return os;
}

istream& operator>>(istream& is,Cliente& c){
    string cadena;
    is >> c.nombre;
    is >> c.horaDeLlamada;
    is >> c.duracion;
    getline(is,cadena,'\n');

    return is;
}
