#ifndef CUENTA_H
#define CUENTA_H

#include <QString>

class Cuenta {
public:
    // Constructor modificado
    Cuenta(int idCuenta, int idCliente, double saldo, double tasaInteres)
        : id(idCuenta), clienteId(idCliente), saldo(saldo), tasaInteres(tasaInteres) {}

    // Destructor virtual
    virtual ~Cuenta() {}

    // Método virtual puro para calcular intereses
    virtual double calcularIntereses() const = 0;

    // Métodos setters
    void setSaldo(double nuevoSaldo) {
        saldo = nuevoSaldo;
    }

    void setTasaInteres(double nuevaTasa) {
        tasaInteres = nuevaTasa;
    }

    // Miembros de datos
    int id;                // ID de la cuenta
    int clienteId;         // ID del cliente propietario de la cuenta
    double saldo;          // Saldo de la cuenta
    double tasaInteres;    // Tasa de interés de la cuenta
    QString tipo;          // Tipo de cuenta (Ahorro, Joven, etc.)
};

#endif // CUENTA_H
