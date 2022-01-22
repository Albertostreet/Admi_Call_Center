#ifndef DURACION_H_INCLUDED
#define DURACION_H_INCLUDED

#include <cstdio>
#include <string>
#include <iostream>

class Duracion{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Duracion();
    Duracion(const Duracion&);

    int getHora();
    int getMinuto();
    int getSegundo();

    std::string toString();

    void setHora(const int&);
    void setMinuto(const int&);
    void setSegundo(const int&);

    Duracion& operator = (const Duracion&);

    friend std::ostream& operator<<(std::ostream&,Duracion&);
    friend std::istream& operator>>(std::istream&,Duracion&);
};

#endif // DURACION_H_INCLUDED
