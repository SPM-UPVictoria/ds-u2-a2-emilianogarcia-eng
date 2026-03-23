#include <iostream>
#include <string>
#include "Ruta.h"
#include "GestorPaquetes.h"
#include "GestorRutas.h"
#include "SistemaMensajeria.h"

int main() {
    Ruta miRuta;
    GestorPaquetes misPaquetes;
    GestorRutas miCamion;
    SistemaMensajeria motorCalculo;

    // Puntos de control por defecto para el camion
    miCamion.agregarPuntoControl("Base Monterrey");
    miCamion.agregarPuntoControl("Aduana Saltillo");
    miCamion.agregarPuntoControl("Distribucion Torreon");

    int opcion, idTemp, idDest;
    std::string nombreTemp, destTemp, dirTemp;
    float pesoTemp;

    do {
        std::cout << "\n=== SISTEMA LOGISTICO INTEGRAL ===\n";
        std::cout << "1. Agregar ciudad a la ruta (Lista Enlazada)\n";
        std::cout << "2. Mostrar ruta completa\n";
        std::cout << "3. Agregar paquete normal (Cola FIFO)\n";
        std::cout << "4. Agregar paquete URGENTE (Pila LIFO)\n";
        std::cout << "5. Despachar paquete normal\n";
        std::cout << "6. Despachar paquete URGENTE\n";
        std::cout << "7. Simular avance camion (Cola Circular)\n";
        std::cout << "8. Consultar tiempo entre ciudades (Matriz 2D)\n";
        std::cout << "0. Salir\n";
        std::cout << "==================================\n";
        std::cout << "Elige una opcion: ";
        std::cin >> opcion;

        switch(opcion) {
            case 1: 
                std::cout << "ID Ciudad: "; std::cin >> idTemp;
                std::cout << "Nombre: "; std::getline(std::cin >> std::ws, nombreTemp); 
                miRuta.agregarCiudad(Ciudad(idTemp, nombreTemp));
                break;
            case 2: miRuta.mostrarRuta(); break;
            case 3: 
                std::cout << "ID Paquete: "; std::cin >> idTemp;
                std::cout << "Destinatario: "; std::getline(std::cin >> std::ws, destTemp);
                std::cout << "Direccion: "; std::getline(std::cin >> std::ws, dirTemp);
                std::cout << "Peso: "; std::cin >> pesoTemp;
                misPaquetes.agregarPendiente(Paquete(idTemp, destTemp, dirTemp, pesoTemp));
                break;
            case 4: 
                std::cout << "ID Urgente: "; std::cin >> idTemp;
                std::cout << "Destinatario: "; std::getline(std::cin >> std::ws, destTemp);
                std::cout << "Direccion: "; std::getline(std::cin >> std::ws, dirTemp);
                std::cout << "Peso: "; std::cin >> pesoTemp;
                misPaquetes.agregarUrgente(Paquete(idTemp, destTemp, dirTemp, pesoTemp));
                break;
            case 5: misPaquetes.procesarPendiente(); break;
            case 6: misPaquetes.procesarUrgente(); break;
            case 7: miCamion.simularAvance(); break;
            case 8: 
                std::cout << "ID Origen (0 a 4): "; std::cin >> idTemp;
                std::cout << "ID Destino (0 a 4): "; std::cin >> idDest;
                motorCalculo.mostrarTiempo(idTemp, idDest);
                break;
            case 0: std::cout << "Saliendo del sistema...\n"; break;
            default: std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 0);

    return 0;
}
