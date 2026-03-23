#ifndef GESTORPAQUETES_H
#define GESTORPAQUETES_H

#include <queue>
#include <stack>
#include "Paquete.h"

class GestorPaquetes {
private:
    std::queue<Paquete> pendientes; // Fila normal (FIFO)
    std::stack<Paquete> urgentes;   // Pila de prioridad (LIFO)

public:
    void agregarPendiente(Paquete p);
    void procesarPendiente();
    
    void agregarUrgente(Paquete p);
    void procesarUrgente();
};

#endif
