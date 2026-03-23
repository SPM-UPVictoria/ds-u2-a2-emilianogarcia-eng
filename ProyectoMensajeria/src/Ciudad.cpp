#include "Ciudad.h"

// Constructor: asigna los valores cuando creamos la ciudad
Ciudad::Ciudad(int id, std::string nombre) {
    this->id = id;
    this->nombre = nombre;
}

// Getters: nos devuelven la información
int Ciudad::getId() const {
    return id;
}

std::string Ciudad::getNombre() const {
    return nombre;
}
