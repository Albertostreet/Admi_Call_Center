#ifndef AGENTE_H_INCLUDED
#define AGENTE_H_INCLUDED

#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "nombre.h"
#include "horario.h"
#include "listacliente.h"

class Agente{
private:
    Nombre miNombre;
    Horario horarioEntrada;
    Horario horarioSalida;
    int numeroDeExtencion;
    int horasExtras;
    std::string especialidad;

    ListaCliente miListaDeClientes;
public:
    Agente();
    Agente(const Agente&);

    Nombre getNombre();
    Horario getHorarioEntrada();
    Horario getHorarioSalida();
    std::string getNumeroDeExtencion();
    std::string getHorasExtras();
    std::string getEspecialidad();
    ListaCliente* getListaDeClientes();

    std::string toString();

    void setNombre(const Nombre&);
    void setHorarioEntrada(const Horario&);
    void setHorarioSalida(const Horario&);
    void setNumeroDeExtencion(const int&);
    void setHorasExtras(const int&);
    void setEspecialidad(const std::string&);
    void setListaDeClientes(ListaCliente&);

    Agente& operator = (const Agente&);
    bool operator == (const Agente&);
    bool operator < (const Agente&);
    bool operator <= (const Agente&);
    bool operator > (const Agente&);
    bool operator >= (const Agente&);

    friend std::ostream& operator<<(std::ostream&, Agente&);
    friend std::istream& operator>>(std::istream&, Agente&);
};

#endif // AGENTE_H_INCLUDED
