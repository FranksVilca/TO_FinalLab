#ifndef CUENTA_JOVEN_H
#define CUENTA_JOVEN_H

#include "Cuenta.h"

class CuentaJoven : public Cuenta {
public:
    // Constructor modificado
    CuentaJoven(int idCuenta, int idCliente, double saldo, double tasaInteres);
    double calcularIntereses() const override;
};

#endif // CUENTA_JOVEN_H
