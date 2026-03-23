#include "GestorRutas.h"
#include <iostream>

GestorRutas::GestorRutas() {
    cantidadPuntos = 0;
    posicionActual = 0;
}

void GestorRutas::agregarPuntoControl(std::string nombre) {
    if (cantidadPuntos < 5) {
        puntosControl[cantidadPuntos] = nombre;
        cantidadPuntos++;
    }
}

void GestorRutas::simularAvance() {
    if (cantidadPuntos == 0) return;
    posicionActual = (posicionActual + 1) % cantidadPuntos;
    std::cout << "El camion avanzo. Siguiente parada: " << puntosControl[posicionActual] << "\n";
}
