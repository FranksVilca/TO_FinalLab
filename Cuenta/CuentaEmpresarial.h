#ifndef CUENTA_EMPRESARIAL_H
#define CUENTA_EMPRESARIAL_H

#include "Cuenta.h"

class CuentaEmpresarial : public Cuenta {
public:
    // Constructor modificado
    CuentaEmpresarial(int idCuenta, int idCliente, double saldo, double tasaInteres);
    double calcularIntereses() const override;
};

#endif // CUENTA_EMPRESARIAL_H
