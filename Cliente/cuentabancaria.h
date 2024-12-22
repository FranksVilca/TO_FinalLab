#ifndef CUENTABANCARIA_H
#define CUENTABANCARIA_H

#include <QString>

class CuentaBancaria {
private:
    QString titular;
    QString tipoCuenta;
    double saldo;

public:
    CuentaBancaria(QString titular, QString tipoCuenta, double saldo)
        : titular(titular), tipoCuenta(tipoCuenta), saldo(saldo) {}

    QString getTitular() const { return titular; }
    QString getTipoCuenta() const { return tipoCuenta; }
    double getSaldo() const { return saldo; }

    void setTitular(QString nuevoTitular) { titular = nuevoTitular; }
    void setTipoCuenta(QString nuevoTipo) { tipoCuenta = nuevoTipo; }
    void setSaldo(double nuevoSaldo) { saldo = nuevoSaldo; }

    QString obtenerDatosCSV() const {
        return titular + "," + tipoCuenta + "," + QString::number(saldo);
    }
};

#endif // CUENTABANCARIA_H
