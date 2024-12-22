#ifndef CUENTA_PLUS_H
#define CUENTA_PLUS_H

#include "Cuenta.h"

class CuentaPlus : public Cuenta {
public:
    // Constructor modificado
    CuentaPlus(int idCuenta, int idCliente, double saldo, double tasaInteres);
    double calcularIntereses() const override;
};

#endif // CUENTA_PLUS_H
