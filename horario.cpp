#include "horario.h"

using namespace std;

int Horario::toInt() const {
    int a((hora*100)+minuto);
    return a;
}


Horario::Horario() {
    chrono::system_clock::time_point today = chrono::system_clock::now();
    std::time_t tt;
    tt = chrono::system_clock::to_time_t (today);
    struct tm* timeinfo;
    timeinfo = localtime(&tt);

    hora = timeinfo->tm_hour;
    minuto = timeinfo->tm_min;
}

Horario::Horario(const Horario&h) : hora(h.hora), minuto(h.minuto) {

}

int Horario::getHora() {
    while(hora>23) {
        hora%=24;
    }
    return hora;
}

int Horario::getMinuto() {
    hora+= minuto/60;
    while(minuto>59) {
        minuto%=60;
    }
    return minuto;
}

string Horario::toString() {
    char resultado[5];
    sprintf(resultado,"%02i:%02i",getHora(),getMinuto());
    return resultado;
}

void Horario::setHora(const int&h) {
    hora = h;
    while(hora>23) {
        hora%=24;
    }

}

void Horario::setMinuto(const int&m) {
    hora += m/60;
    minuto = m;
    while(minuto>59) {
        minuto%=60;
    }
}

Horario& Horario::operator=(const Horario&h) {
    setHora(h.hora);
    setMinuto(h.minuto);
    return *this;
}

bool Horario::operator==(const Horario&h) {
    return toInt() == h.toInt();
}

bool Horario::operator<(const Horario&h) {
    return toInt() < h.toInt();
}

bool Horario::operator<=(const Horario&h) {
    return toInt() <= h.toInt();
}

bool Horario::operator>(const Horario&h) {
    return toInt() > h.toInt();
}

bool Horario::operator>=(const Horario&h) {
    return toInt() >= h.toInt();
}

ostream& operator<<(ostream& os,Horario& h){
    os << h.toString() + "\n";
    return os;
}

istream& operator>>(istream& is,Horario& h){
    string cadena;
    getline(is,cadena,':');
    h.hora = atoi(cadena.c_str());
    getline(is,cadena,'\n');
    h.minuto = atoi(cadena.c_str());
    return is;
}
