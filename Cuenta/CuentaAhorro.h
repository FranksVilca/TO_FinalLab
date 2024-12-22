#ifndef CUENTA_AHORRO_H
#define CUENTA_AHORRO_H

#include "Cuenta.h"

class CuentaAhorro : public Cuenta {
public:
    CuentaAhorro(int idCuenta, int idCliente, double saldo, double tasaInteres);
    double calcularIntereses() const override;
};

#endif // CUENTA_AHORRO_H
