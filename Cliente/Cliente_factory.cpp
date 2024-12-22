#include "Cliente_factory.h"

Cliente* ClienteConcreteFactory::crearCliente(int id, const QString& nombre, const QString& direccion,
                                              const QString& telefono, const QString& email, const int& edad) {
    return new Cliente(id, nombre, direccion, telefono, email, edad);
}
