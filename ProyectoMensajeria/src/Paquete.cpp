#include "Paquete.h"

Paquete::Paquete(int id, std::string dest, std::string dir, float peso) {
    this->id = id;
    this->destinatario = dest;
    this->direccion = dir;
    this->peso = peso;
}

int Paquete::getId() const { return id; }
std::string Paquete::getDestinatario() const { return destinatario; }
std::string Paquete::getDireccion() const { return direccion; }
float Paquete::getPeso() const { return peso; }
