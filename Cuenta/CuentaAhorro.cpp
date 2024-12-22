#include "CuentaAhorro.h"

// Llamada al constructor de la clase base en la lista de inicialización
CuentaAhorro::CuentaAhorro(int idCuenta, int idCliente, double saldo, double tasaInteres)
    : Cuenta(idCuenta, idCliente, saldo, tasaInteres) { // Constructor de la clase base
    this->tipo = "Ahorro"; // Inicialización específica de CuentaAhorro
}

double CuentaAhorro::calcularIntereses() const {
    return saldo * tasaInteres; // Implementación del cálculo de intereses
}
