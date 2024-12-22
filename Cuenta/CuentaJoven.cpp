#include "CuentaJoven.h"

CuentaJoven::CuentaJoven(int idCuenta, int idCliente, double saldo, double tasaInteres)
    : Cuenta(idCuenta, idCliente, saldo, tasaInteres) { // Constructor de la clase base
    this->tipo = "Joven";
}
double CuentaJoven::calcularIntereses() const {
    return saldo * tasaInteres;
}
