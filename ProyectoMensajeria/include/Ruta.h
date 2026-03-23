#ifndef RUTA_H
#define RUTA_H

#include "Ciudad.h"
#include <iostream>
#include <string>

// Estructura interna: el "vagón" de nuestro tren
struct NodoRuta {
    Ciudad ciudad;
    NodoRuta* siguiente;
    
    // Constructor del nodo
    NodoRuta(Ciudad c) : ciudad(c), siguiente(nullptr) {}
};

class Ruta {
private:
    NodoRuta* inicio;
    NodoRuta* fin; // ¡Tu excelente idea para no recorrer toda la lista!

public:
    Ruta(); // Constructor
    
    void agregarCiudad(Ciudad c);
    void mostrarRuta() const;
    void eliminarCiudad(std::string nombre);
};

#endif
