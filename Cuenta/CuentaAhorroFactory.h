#ifndef CUENTA_AHORRO_FACTORY_H
#define CUENTA_AHORRO_FACTORY_H

#include "FactoryCuentas.h"
#include "CuentaAhorro.h"

class CuentaAhorroFactory : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaAhorro(idCuenta, idCliente, saldo, tasaInteres);
    }
};

#endif // CUENTA_AHORRO_FACTORY_H
