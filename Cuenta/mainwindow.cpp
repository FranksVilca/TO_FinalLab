// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaJoven.h"
#include "CuentaPlus.h"
#include "CuentaEmpresarial.h"
#include "CuentaTarjetaCredito.h"
#include <QMessageBox>
#include <BancoSingleton.h>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar la lista de clientes
    clientes = Cliente::cargarClientesDesdeCSV("C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cliente/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/clientes.csv");

    // Agregar los clientes al QComboBox
    for (const Cliente &cliente : clientes) {
        ui->comboBoxClientes->addItem(cliente.getNombre(), cliente.getId());
    }
    cargarCuentasDesdeCSV("C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cuenta/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/cuentas.csv");

    // Conectar botones con sus acciones
    connect(ui->buttonCrear, &QPushButton::clicked, this, &MainWindow::crearCuenta);
    connect(ui->buttonEditar, &QPushButton::clicked, this, &MainWindow::editarCuenta);
    connect(ui->buttonEliminar, &QPushButton::clicked, this, &MainWindow::eliminarCuenta);
}

void MainWindow::cargarCuentasDesdeCSV(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo CSV de cuentas.");
        return;
    }

    QTextStream entrada(&archivo);
    while (!entrada.atEnd()) {
        QString linea = entrada.readLine();
        QStringList datos = linea.split(",");

        if (datos.size() >= 5) {
            int idCuenta = datos[0].toInt();
            int clienteId = datos[1].toInt();
            double saldo = datos[2].toDouble();
            double tasaInteres = datos[3].toDouble();
            QString tipoCuenta = datos[4];
            QString nombreCliente;

            // Buscar el nombre del cliente usando el ID
            for (const Cliente &cliente : clientes) {
                if (cliente.getId() == clienteId) {
                    nombreCliente = cliente.getNombre();
                    break;
                }
            }

            // Agregar una nueva fila y asignar los datos
            int row = ui->tableWidgetCuentas->rowCount();
            ui->tableWidgetCuentas->insertRow(row);

            ui->tableWidgetCuentas->setItem(row, 0, new QTableWidgetItem(QString::number(idCuenta)));
            ui->tableWidgetCuentas->setItem(row, 1, new QTableWidgetItem(nombreCliente));
            ui->tableWidgetCuentas->setItem(row, 2, new QTableWidgetItem(tipoCuenta));
            ui->tableWidgetCuentas->setItem(row, 3, new QTableWidgetItem(QString::number(saldo)));
            ui->tableWidgetCuentas->setItem(row, 4, new QTableWidgetItem(QString::number(tasaInteres, 'f', 2)));
        }
    }

    archivo.close();
}

void MainWindow::guardarTablaEnCSV(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para guardar los datos.");
        return;
    }

    QTextStream salida(&archivo);
    salida << "ID Cuenta,Cliente,Tipo Cuenta,Saldo,Tasa Interés,Fecha Creación\n";

    for (int row = 0; row < ui->tableWidgetCuentas->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidgetCuentas->columnCount(); ++col) {
            if (col > 0) salida << ",";
            salida << ui->tableWidgetCuentas->item(row, col)->text();
        }
        salida << "\n";
    }

    archivo.close();
    QMessageBox::information(this, "Éxito", "Datos guardados en CSV correctamente.");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::crearCuenta() {
    if (ui->comboBoxClientes->currentIndex() == -1) {
        QMessageBox::warning(this, "Error", "Debe seleccionar un cliente para crear la cuenta.");
        return;
    }

    int idCliente = ui->comboBoxClientes->currentData().toInt();
    QString tipoCuenta = ui->comboBoxTipoCuenta->currentText();
    double saldo = ui->lineEditSaldo->text().toDouble();

    QString nombreCliente;
    for (const Cliente &cliente : clientes) {
        if (cliente.getId() == idCliente) {
            nombreCliente = cliente.getNombre();
            break;
        }
    }

    double tasaInteres = 0.0;
    int idCuenta = BancoSingleton::obtenerInstancia()->generarIdCuenta();

    Cuenta *nuevaCuenta = nullptr;
    if (tipoCuenta == "Ahorro") {
        tasaInteres = 3.0;
        nuevaCuenta = new CuentaAhorro(idCuenta, idCliente, saldo, tasaInteres);
    } else if (tipoCuenta == "Joven") {
        tasaInteres = 5.0;
        nuevaCuenta = new CuentaJoven(idCuenta, idCliente, saldo, tasaInteres);
    } else if (tipoCuenta == "Plus") {
        tasaInteres = 6.0;
        nuevaCuenta = new CuentaPlus(idCuenta, idCliente, saldo, tasaInteres);
    } else if (tipoCuenta == "Empresarial") {
        tasaInteres = 4.5;
        nuevaCuenta = new CuentaEmpresarial(idCuenta, idCliente, saldo, tasaInteres);
    } else if (tipoCuenta == "Tarjeta de Crédito") {
        tasaInteres = 2.0;
        nuevaCuenta = new CuentaTarjetaCredito(idCuenta, idCliente, saldo, tasaInteres);
    }

    BancoSingleton::obtenerInstancia()->crearCuenta(nuevaCuenta);
    BancoSingleton::obtenerInstancia()->guardarCuentasEnCSV("cuentas.csv");

    QString fechaCreacion = QDate::currentDate().toString("dd/MM/yyyy");

    int row = ui->tableWidgetCuentas->rowCount();
    ui->tableWidgetCuentas->insertRow(row);
    ui->tableWidgetCuentas->setItem(row, 0, new QTableWidgetItem(QString::number(idCuenta)));
    ui->tableWidgetCuentas->setItem(row, 1, new QTableWidgetItem(nombreCliente));
    ui->tableWidgetCuentas->setItem(row, 2, new QTableWidgetItem(tipoCuenta));
    ui->tableWidgetCuentas->setItem(row, 3, new QTableWidgetItem(QString::number(saldo)));
    ui->tableWidgetCuentas->setItem(row, 4, new QTableWidgetItem(QString::number(tasaInteres, 'f', 2)));
    ui->tableWidgetCuentas->setItem(row, 5, new QTableWidgetItem(fechaCreacion));

    ui->comboBoxClientes->setCurrentIndex(-1);
    ui->comboBoxTipoCuenta->setCurrentIndex(0);
    ui->lineEditSaldo->clear();
}

void MainWindow::editarCuenta() {
    int row = ui->tableWidgetCuentas->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Error", "Debe seleccionar una cuenta para editar.");
        return;
    }

    // Obtén el ID de la cuenta seleccionada
    int idCuenta = ui->tableWidgetCuentas->item(row, 0)->text().toInt();

    // Abre un cuadro de diálogo o una forma para editar los datos (saldo, tasa de interés, etc.)
    // Actualiza la cuenta y guarda los cambios en el archivo CSV
}

void MainWindow::eliminarCuenta() {
    int row = ui->tableWidgetCuentas->currentRow();
    if (row != -1) {
        int idCuenta = ui->tableWidgetCuentas->item(row, 0)->text().toInt();

        // Eliminar la cuenta de la lista de cuentas en el BancoSingleton
        BancoSingleton::obtenerInstancia()->eliminarCuenta(idCuenta);

        // Eliminar la fila de la tabla
        ui->tableWidgetCuentas->removeRow(row);

        // Volver a guardar los datos en el archivo CSV después de eliminar
        BancoSingleton::obtenerInstancia()->guardarCuentasEnCSV("cuentas.csv");

        QMessageBox::information(this, "Éxito", "Cuenta eliminada correctamente.");
    } else {
        QMessageBox::warning(this, "Error", "Debe seleccionar una cuenta para eliminar.");
    }
}
