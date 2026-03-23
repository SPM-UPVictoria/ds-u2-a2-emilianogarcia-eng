#include "SistemaMensajeria.h"
#include <iostream>

SistemaMensajeria::SistemaMensajeria() {
    // Inicializamos la matriz 1D con ceros
    for(int i=0; i<5; i++) distancias[i] = 0.0;
    inicializarTiempos();
}

void SistemaMensajeria::inicializarTiempos() {
    // Llenamos la matriz con 0 horas por defecto
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            tiempos[i][j] = 0;
        }
    }
    // Tiempos precargados de prueba (Origen -> Destino)
    tiempos[0][1] = 2; // 2 horas
    tiempos[1][2] = 4; // 4 horas
    tiempos[0][2] = 6; // 6 horas
}

void SistemaMensajeria::mostrarTiempo(int origen, int destino) {
    if(origen >= 5 || destino >= 5) {
        std::cout << "Error: ID de ciudad fuera de rango (Max 4).\n";
        return;
    }
    std::cout << "Tiempo estimado desde ID " << origen << " hasta ID " << destino 
              << ": " << tiempos[origen][destino] << " horas.\n";
}

void SistemaMensajeria::registrarDistancia(int id, float dist) {
    if(id < 5) {
        distancias[id] = dist;
    }
}
