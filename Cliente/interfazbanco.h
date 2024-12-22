#ifndef INTERFAZBANCO_H
#define INTERFAZBANCO_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include "cuentabancaria.h"

class InterfazBanco : public QWidget {
    Q_OBJECT

public:
    InterfazBanco(QWidget *parent = nullptr);
    ~InterfazBanco();

private slots:
    void crearCuenta();
    void modificarCuenta();
    void eliminarCuenta();

private:
    QLineEdit *inputTitular;
    QLineEdit *inputTipoCuenta;
    QLineEdit *inputSaldo;
    QTableWidget *tablaCuentas;
    std::vector<CuentaBancaria> cuentas;

    void actualizarTabla();
};

#endif // INTERFAZBANCO_H
