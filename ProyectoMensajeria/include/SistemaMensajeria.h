#ifndef SISTEMAMENSAJERIA_H
#define SISTEMAMENSAJERIA_H

#include <iostream>

class SistemaMensajeria {
private:
    float distancias[5];      
    int tiempos[5][5];        
    
public:
    SistemaMensajeria();
    
    void inicializarTiempos();
    void mostrarTiempo(int origen, int destino);
    void registrarDistancia(int id, float dist);
};

#endif
