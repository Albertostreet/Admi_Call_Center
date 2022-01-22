#include "duracion.h"

using namespace std;

Duracion::Duracion() : hora(0), minuto(0), segundo(0) {

}

Duracion::Duracion(const Duracion&d) : hora(d.hora), minuto(d.minuto), segundo(d.segundo) {

}

int Duracion::getHora() {
    if(hora>24) {
        hora/=24;
        while(hora>24) {
            hora/=24;
        }
        return hora;
    }
    return hora;
}


int Duracion::getMinuto() {
    hora += minuto/60;
    while(minuto>59) {
        minuto%=60;
    }
    return minuto;
}

int Duracion::getSegundo() {
    minuto += segundo/60;
    while(segundo>59) {
        segundo%=60;
    }
    return segundo;
}

string Duracion::toString() {
    char a[8];
    sprintf(a,"%02i:%02i:%02i",getHora(),getMinuto(),getSegundo());
    return a;
}

void Duracion::setHora(const int&h) {
    hora=h;
    while(hora>23) {
        hora%=24;
    }
}


void Duracion::setMinuto(const int&m) {
    hora += m/60;
    minuto = m;
    while(minuto>59) {
        minuto%=60;
    }
}

void Duracion::setSegundo(const int&s) {
    minuto += s/60;
    segundo = s;
    while(segundo>59) {
        segundo%=60;
    }

}

Duracion& Duracion::operator=(const Duracion&d) {
    setHora(d.hora);
    setMinuto(d.minuto);
    setSegundo(d.segundo);
    return *this;
}

ostream& operator<<(ostream& os,Duracion& d){
    os << d.toString() <<endl;
    return os;
}

istream& operator>>(istream& is,Duracion& d){
    string cadena;
    getline(is,cadena,':');
    d.hora = atoi(cadena.c_str());
    getline(is,cadena,':');
    d.minuto = atoi(cadena.c_str());
    getline(is,cadena,'\n');
    d.segundo = atoi(cadena.c_str());

    return is;
}
