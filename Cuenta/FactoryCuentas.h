#ifndef FACTORYCUENTAS_H
#define FACTORYCUENTAS_H

#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaJoven.h"
#include "CuentaPlus.h"
#include "CuentaEmpresarial.h"
#include "CuentaTarjetaCredito.h"

class FactoryCuentas {
public:
    virtual Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) = 0;
};

class FactoryCuentaAhorro : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaAhorro(idCuenta, idCliente, saldo, tasaInteres);
    }
};

class FactoryCuentaJoven : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaJoven(idCuenta, idCliente, saldo, tasaInteres);
    }
};

class FactoryCuentaPlus : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaPlus(idCuenta, idCliente, saldo, tasaInteres);
    }
};

class FactoryCuentaEmpresarial : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaEmpresarial(idCuenta, idCliente, saldo, tasaInteres);
    }
};

class FactoryCuentaTarjetaCredito : public FactoryCuentas {
public:
    Cuenta* crearCuenta(int idCuenta, int idCliente, double saldo, double tasaInteres) override {
        return new CuentaTarjetaCredito(idCuenta, idCliente, saldo, tasaInteres);
    }
};

#endif // FACTORYCUENTAS_H
