#ifndef NOMBRE_H_INCLUDED
#define NOMBRE_H_INCLUDED

#include <string>

class Nombre {
private:
    std::string nombre;
    std::string apellido;
public:
    Nombre();
    Nombre(const Nombre&);

    std::string getNombre();
    std::string getApellido();

    std::string toString() const;

    void setNombre(const std::string&);
    void setApellido(const std::string&);

    Nombre& operator = (const Nombre&);
    bool operator == (const Nombre&);
    bool operator < (const Nombre&);
    bool operator <= (const Nombre&);
    bool operator > (const Nombre&);
    bool operator >= (const Nombre&);

    friend std::ostream& operator<<(std::ostream&,Nombre&);
    friend std::istream& operator>>(std::istream&,Nombre&);
};

#endif // NOMBRE_H_INCLUDED
