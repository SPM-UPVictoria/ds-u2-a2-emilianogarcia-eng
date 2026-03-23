#ifndef GESTORRUTAS_H
#define GESTORRUTAS_H

#include <string>

class GestorRutas {
private:
    std::string puntosControl[5]; // Nuestro arreglo tradicional
    int cantidadPuntos;
    int posicionActual;

public:
    GestorRutas(); // Constructor
    
    void agregarPuntoControl(std::string nombre);
    void simularAvance();
};

#endif
