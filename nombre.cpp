#include "nombre.h"

using namespace std;

Nombre::Nombre() {

}

Nombre::Nombre(const Nombre&n) : nombre(n.nombre),apellido(n.apellido) {

}

string Nombre::getNombre() {
    return nombre;
}

string Nombre::getApellido() {
    return apellido;
}

string Nombre::toString() const {
    string resultado;

    resultado = apellido;
    resultado += " ";
    resultado += nombre;
    return resultado;
}

void Nombre::setNombre(const std::string&n) {
    nombre = n;
}

void Nombre::setApellido(const std::string&a) {
    apellido = a;
}

Nombre& Nombre::operator=(const Nombre&n) {
    nombre = n.nombre;
    apellido = n.apellido;
    return *this;
}

bool Nombre::operator==(const Nombre&n) {
    return toString() == n.toString();
}

bool Nombre::operator<(const Nombre&n) {
    return toString() < n.toString();
}

bool Nombre::operator<=(const Nombre&n) {
    return toString() <= n.toString();
}

bool Nombre::operator>(const Nombre&n) {
    return toString() > n.toString();
}

bool Nombre::operator>=(const Nombre&n) {
    return toString() >= n.toString();
}

ostream& operator<<(ostream& os,Nombre& n){
    os << n.apellido + "\n";
    os << n.nombre + "\n";
    return os;
}

istream& operator>>(istream& is,Nombre& n){
    getline(is,n.apellido,'\n');
    getline(is,n.nombre,'\n');

    return is;
}
