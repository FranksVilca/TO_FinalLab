#include "Cliente.h"

Cliente::Cliente(int id, QString nombre, QString direccion, QString telefono, QString email, int edad)
    : id(id), nombre(nombre), direccion(direccion), telefono(telefono), email(email), edad(edad) {}

int Cliente::getId() const { return id; }
QString Cliente::getNombre() const { return nombre; }
QString Cliente::getDireccion() const { return direccion; }
QString Cliente::getTelefono() const { return telefono; }
QString Cliente::getEmail() const { return email; }
int Cliente::getEdad() const { return edad; }

void Cliente::setNombre(const QString& nombre) { this->nombre = nombre; }
void Cliente::setDireccion(const QString& direccion) { this->direccion = direccion; }
void Cliente::setTelefono(const QString& telefono) { this->telefono = telefono; }
void Cliente::setEmail(const QString& email) { this->email = email; }
void Cliente::setEdad(const int& edad) { this->edad = edad; }
