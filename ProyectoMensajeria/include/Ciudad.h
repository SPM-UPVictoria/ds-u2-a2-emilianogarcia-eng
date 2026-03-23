#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>

class Ciudad {
private:
    int id;
    std::string nombre;

public:
    Ciudad(int id, std::string nombre);
    
    int getId() const;
    std::string getNombre() const;
};

#endif
