#include "CuentaPlus.h"

CuentaPlus::CuentaPlus(int idCuenta, int idCliente, double saldo, double tasaInteres)
    : Cuenta(idCuenta, idCliente, saldo, tasaInteres) { // Constructor de la clase base
    this->tipo = "Plus";
}

double CuentaPlus::calcularIntereses() const {
    return saldo * tasaInteres; // Utiliza la tasa de interés proporcionada
}
