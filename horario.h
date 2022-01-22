#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

#include <string>
#include <chrono>
#include <time.h>
#include <cstdio>
#include <cstdlib>

class Horario{
private:
    int hora;
    int minuto;

public:
    Horario();
    Horario(const Horario&);

    int getHora();
    int getMinuto();

    std::string toString();
    int toInt()const ;

    void setHora(const int&);
    void setMinuto(const int&);

    Horario& operator = (const Horario&);
    bool operator ==(const Horario&);
    bool operator <(const Horario&);
    bool operator <=(const Horario&);
    bool operator >(const Horario&);
    bool operator >=(const Horario&);

    friend std::ostream& operator<<(std::ostream&,Horario&);
    friend std::istream& operator>>(std::istream&,Horario&);
};


#endif // HORARIO_H_INCLUDED
