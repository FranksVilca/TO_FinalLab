#include "CuentaEmpresarial.h"

CuentaEmpresarial::CuentaEmpresarial(int idCuenta, int idCliente, double saldo, double tasaInteres)
    : Cuenta(idCuenta, idCliente, saldo, tasaInteres) { // Constructor de la clase base
    this->tipo = "Empresarial";
}

double CuentaEmpresarial::calcularIntereses() const {
    return saldo * tasaInteres; // Utiliza la tasa de interés proporcionada
}
