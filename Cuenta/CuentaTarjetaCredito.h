#ifndef CUENTA_TARJETA_CREDITO_H
#define CUENTA_TARJETA_CREDITO_H

#include "Cuenta.h"

class CuentaTarjetaCredito : public Cuenta {
public:
    // Constructor modificado
    CuentaTarjetaCredito(int idCuenta, int idCliente, double saldo, double tasaInteres);
    double calcularIntereses() const override;

};

#endif // CUENTA_TARJETA_CREDITO_H
