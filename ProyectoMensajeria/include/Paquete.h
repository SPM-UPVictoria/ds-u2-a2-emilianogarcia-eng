#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

class Paquete {
private:
    int id;
    std::string destinatario;
    std::string direccion;
    float peso;

public:
    Paquete(int id, std::string dest, std::string dir, float peso);

    int getId() const;
    std::string getDestinatario() const;
    std::string getDireccion() const;
    float getPeso() const;
};

#endif

