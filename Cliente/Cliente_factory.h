#ifndef CLIENTEFACTORY_H
#define CLIENTEFACTORY_H

#include "Cliente.h"
#include <QString>

class ClienteFactory {
public:
    virtual Cliente* crearCliente(int id, const QString& nombre, const QString& direccion,
                                  const QString& telefono, const QString& email, const int& edad) = 0;
};

class ClienteConcreteFactory : public ClienteFactory {
public:
    Cliente* crearCliente(int id, const QString& nombre, const QString& direccion,
                          const QString& telefono, const QString& email, const int& edad) override;
};

#endif // CLIENTEFACTORY_H
