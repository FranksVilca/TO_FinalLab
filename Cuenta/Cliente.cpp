// Cliente.cpp
#include "Cliente.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
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

QList<Cliente> Cliente::cargarClientesDesdeCSV(const QString &archivo) {
    QList<Cliente> clientes;

    QFile file(archivo);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString linea = in.readLine();
            QStringList campos = linea.split(',');

            if (campos.size() == 6) {
                int id = campos[0].toInt();
                QString nombre = campos[1];
                QString direccion = campos[2];
                QString telefono = campos[3];
                QString correo = campos[4];
                int edad = campos[5].toInt();

                Cliente cliente(id, nombre, direccion, telefono, correo, edad);
                clientes.append(cliente);
            }
        }
    }
    return clientes;
}
