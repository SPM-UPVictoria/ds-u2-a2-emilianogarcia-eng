#include "Ruta.h"

// Constructor: al inicio, la ruta está completamente vacía
Ruta::Ruta() {
    inicio = nullptr;
    fin = nullptr;
}

void Ruta::agregarCiudad(Ciudad c) {
    NodoRuta* nuevoNodo = new NodoRuta(c);

    if (inicio == nullptr) { 
        // Si no hay ruta, esta ciudad es el inicio y el fin
        inicio = nuevoNodo;
        fin = nuevoNodo;
    } else {
        // Si ya hay ciudades, enganchamos al final
        fin->siguiente = nuevoNodo;
        fin = nuevoNodo;
    }
}

void Ruta::mostrarRuta() const {
    if (inicio == nullptr) {
        std::cout << "La ruta esta vacia.\n";
        return;
    }

    NodoRuta* actual = inicio; // Nuestro explorador
    std::cout << "Ruta actual: ";
    
    while (actual != nullptr) {
        std::cout << actual->ciudad.getNombre();
        if (actual->siguiente != nullptr) {
            std::cout << " -> ";
        }
        actual = actual->siguiente; // Avanzamos al siguiente vagón
    }
    std::cout << "\n";
}

void Ruta::eliminarCiudad(std::string nombre) {
    // La lógica de eliminación que vimos la dejaremos lista para usarla después
    if (inicio == nullptr) return; 

    NodoRuta* actual = inicio;
    NodoRuta* anterior = nullptr;

    if (actual->ciudad.getNombre() == nombre) {
        inicio = inicio->siguiente;
        if (inicio == nullptr) fin = nullptr; 
        delete actual;
        return;
    }

    while (actual != nullptr && actual->ciudad.getNombre() != nombre) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) return; // No se encontró

    anterior->siguiente = actual->siguiente;
    if (actual == fin) fin = anterior;
    delete actual;
}
