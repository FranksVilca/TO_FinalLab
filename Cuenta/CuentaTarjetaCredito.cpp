#include "CuentaTarjetaCredito.h"

CuentaTarjetaCredito::CuentaTarjetaCredito(int idCuenta, int idCliente, double saldo, double tasaInteres)
    : Cuenta(idCuenta, idCliente, saldo, tasaInteres) { // Constructor de la clase base
    this->tipo = "TarjetaCredito";
}

double CuentaTarjetaCredito::calcularIntereses() const {
    return saldo * tasaInteres; // Utiliza la tasa de interés proporcionada
}
