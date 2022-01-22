#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <string>
#include <iostream>

#include "nombre.h"
#include "horario.h"
#include "duracion.h"


class Cliente{
private:
    Nombre nombre;
    Horario horaDeLlamada;
    Duracion duracion;
public:
    Cliente();
    Cliente(const Cliente&);

    std::string getNombre();
    std::string gethoraDeLlamada();
    std::string getDuracion();

    std::string toString();

    void setNombre(const Nombre&);
    void setHoraDeLlamada(const Horario&);
    void setDuracion(const Duracion&);

    Cliente& operator = (const Cliente&);
    bool operator == (const Cliente&);
    bool operator < (const Cliente&);
    bool operator <= (const Cliente&);
    bool operator > (const Cliente&);
    bool operator >= (const Cliente&);

    friend std::ostream& operator<<(std::ostream&,Cliente&);
    friend std::istream& operator>>(std::istream&,Cliente&);
};

#endif // CLIENTE_H_INCLUDED
