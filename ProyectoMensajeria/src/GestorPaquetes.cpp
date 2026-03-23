#include "GestorPaquetes.h"
#include <iostream>

// --- PAQUETES NORMALES (COLA / FIFO) ---
void GestorPaquetes::agregarPendiente(Paquete p) {
    pendientes.push(p);
    std::cout << "Paquete normal (ID: " << p.getId() << ") agregado a la fila.\n";
}

void GestorPaquetes::procesarPendiente() {
    if (pendientes.empty()) {
        std::cout << "No hay paquetes normales pendientes.\n";
        return;
    }
    Paquete p = pendientes.front(); // Miramos al primero
    pendientes.pop();               // Lo sacamos de la fila
    std::cout << "Procesando paquete NORMAL ID: " << p.getId() << " para " << p.getDestinatario() << "\n";
}

// --- PAQUETES URGENTES (PILA / LIFO) ---
void GestorPaquetes::agregarUrgente(Paquete p) {
    urgentes.push(p);
    std::cout << "Paquete URGENTE (ID: " << p.getId() << ") puesto en la cima.\n";
}

void GestorPaquetes::procesarUrgente() {
    if (urgentes.empty()) {
        std::cout << "No hay paquetes urgentes.\n";
        return;
    }
    Paquete p = urgentes.top(); // Miramos al de hasta arriba
    urgentes.pop();             // Lo sacamos de la pila
    std::cout << "Procesando paquete URGENTE ID: " << p.getId() << " para " << p.getDestinatario() << "\n";
}
