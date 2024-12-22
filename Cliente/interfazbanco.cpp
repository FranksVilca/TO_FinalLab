#include "interfazbanco.h"
#include <QMessageBox>

InterfazBanco::InterfazBanco(QWidget *parent)
    : QWidget(parent)
{
    // Configurar los widgets de la interfaz
    QLabel *labelTitular = new QLabel("Titular:");
    inputTitular = new QLineEdit();

    QLabel *labelTipoCuenta = new QLabel("Tipo de Cuenta:");
    inputTipoCuenta = new QLineEdit();

    QLabel *labelSaldo = new QLabel("Saldo:");
    inputSaldo = new QLineEdit();

    QPushButton *botonCrear = new QPushButton("Crear Cuenta");
    QPushButton *botonModificar = new QPushButton("Modificar Cuenta");
    QPushButton *botonEliminar = new QPushButton("Eliminar Cuenta");

    // Configurar la tabla de cuentas
    tablaCuentas = new QTableWidget(0, 3);
    QStringList headers = {"Titular", "Tipo de Cuenta", "Saldo"};
    tablaCuentas->setHorizontalHeaderLabels(headers);

    // Conectar los botones con los slots
    connect(botonCrear, &QPushButton::clicked, this, &InterfazBanco::crearCuenta);
    connect(botonModificar, &QPushButton::clicked, this, &InterfazBanco::modificarCuenta);
    connect(botonEliminar, &QPushButton::clicked, this, &InterfazBanco::eliminarCuenta);

    // Disposición del diseño
    QVBoxLayout *layoutPrincipal = new QVBoxLayout();
    QHBoxLayout *layoutFormulario = new QHBoxLayout();
    QVBoxLayout *layoutBotones = new QVBoxLayout();

    layoutFormulario->addWidget(labelTitular);
    layoutFormulario->addWidget(inputTitular);
    layoutFormulario->addWidget(labelTipoCuenta);
    layoutFormulario->addWidget(inputTipoCuenta);
    layoutFormulario->addWidget(labelSaldo);
    layoutFormulario->addWidget(inputSaldo);

    layoutBotones->addWidget(botonCrear);
    layoutBotones->addWidget(botonModificar);
    layoutBotones->addWidget(botonEliminar);

    layoutPrincipal->addLayout(layoutFormulario);
    layoutPrincipal->addLayout(layoutBotones);
    layoutPrincipal->addWidget(tablaCuentas);

    setLayout(layoutPrincipal);
}

InterfazBanco::~InterfazBanco() {}

void InterfazBanco::crearCuenta() {
    QString titular = inputTitular->text();
    QString tipoCuenta = inputTipoCuenta->text();
    double saldo = inputSaldo->text().toDouble();

    if (titular.isEmpty() || tipoCuenta.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor, completa todos los campos.");
        return;
    }

    CuentaBancaria nuevaCuenta(titular, tipoCuenta, saldo);
    cuentas.push_back(nuevaCuenta);
    actualizarTabla();
}

void InterfazBanco::modificarCuenta() {
    int filaSeleccionada = tablaCuentas->currentRow();
    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Error", "Seleccione una cuenta para modificar.");
        return;
    }

    QString titular = inputTitular->text();
    QString tipoCuenta = inputTipoCuenta->text();
    double saldo = inputSaldo->text().toDouble();

    cuentas[filaSeleccionada].setTitular(titular);
    cuentas[filaSeleccionada].setTipoCuenta(tipoCuenta);
    cuentas[filaSeleccionada].setSaldo(saldo);
    actualizarTabla();
}

void InterfazBanco::eliminarCuenta() {
    int filaSeleccionada = tablaCuentas->currentRow();
    if (filaSeleccionada < 0) {
        QMessageBox::warning(this, "Error", "Seleccione una cuenta para eliminar.");
        return;
    }

    cuentas.erase(cuentas.begin() + filaSeleccionada);
    actualizarTabla();
}

void InterfazBanco::actualizarTabla() {
    tablaCuentas->setRowCount(0);
    for (size_t i = 0; i < cuentas.size(); ++i) {
        tablaCuentas->insertRow(i);
        tablaCuentas->setItem(i, 0, new QTableWidgetItem(cuentas[i].getTitular()));
        tablaCuentas->setItem(i, 1, new QTableWidgetItem(cuentas[i].getTipoCuenta()));
        tablaCuentas->setItem(i, 2, new QTableWidgetItem(QString::number(cuentas[i].getSaldo())));
    }
}
