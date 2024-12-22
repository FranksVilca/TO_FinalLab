#ifndef BANCO_SINGLETON_H
#define BANCO_SINGLETON_H

#include <QString>
#include <QList>
#include "Cuenta.h"
#include "Cliente.h"

class BancoSingleton {
public:
    static BancoSingleton* obtenerInstancia();
    int generarIdCuenta();
    void crearCuenta(Cuenta* cuenta);
    void eliminarCuenta(int idCuenta);
    QList<Cuenta*> obtenerCuentas() const;
    void guardarCuentasEnCSV(const QString& archivo);

private:
    BancoSingleton() {}
    static BancoSingleton* instancia;
    QList<Cuenta*> cuentas;
};

#endif // BANCO_SINGLETON_H
