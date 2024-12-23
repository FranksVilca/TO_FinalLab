#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDate>
#include <QDoubleValidator>  // Para el validador de números
#include <QDir>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Cargar todas las transacciones al inicio
    cargarTransaccionesDesdeCSV();

    // Conectar señales
    connect(ui->lineCliente, &QLineEdit::textChanged, this, &MainWindow::cargarCuentasCliente);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onComboBoxChanged);

    // Conectar el botón Ver Total
    connect(ui->btnVerTotal, &QPushButton::clicked, this, &MainWindow::onVerTotalClicked);
    // Hacer los campos de totales de solo lectura
    ui->lineSaldoTotal->setReadOnly(true);
    ui->lineSalidaTotal->setReadOnly(true);

    ui->lineSaldo->setReadOnly(true);
    ui->lineSalida->setReadOnly(true);

    // Cargar datos iniciales
    cargarCuentasCliente();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarTransaccionesDesdeCSV() {
    QString currentPath = QCoreApplication::applicationDirPath();
    QDir dir(currentPath);
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString filePath = dir.absolutePath() + "/csvRepo/transaccion.csv";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para leer");
        return;
    }

    transacciones.clear();
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        if (fields.size() >= 6) {
            transacciones.append(Transaccion(
                fields[0], // idCliente
                fields[1], // idCuenta
                fields[2], // tipoOperacion
                fields[3], // monto
                fields[4], // fecha
                fields[5]  // descripcion
                ));
        }
    }

    file.close();
}

void MainWindow::mostrarTransaccionesFiltradas(const QString& idCliente, const QString& idCuenta) {
    ui->tableTransacciones->setRowCount(0);

    for (const Transaccion& trans : transacciones) {
        if (trans.getIdCliente() == idCliente &&
            (idCuenta == "Seleccionar" || trans.getIdCuenta() == idCuenta)) {

            int row = ui->tableTransacciones->rowCount();
            ui->tableTransacciones->insertRow(row);

            ui->tableTransacciones->setItem(row, 0, new QTableWidgetItem(trans.getTipoOperacion()));
            ui->tableTransacciones->setItem(row, 1, new QTableWidgetItem(trans.getMonto()));
            ui->tableTransacciones->setItem(row, 2, new QTableWidgetItem(trans.getIdCuenta()));
            ui->tableTransacciones->setItem(row, 3, new QTableWidgetItem(trans.getFecha()));
            ui->tableTransacciones->setItem(row, 4, new QTableWidgetItem(trans.getDescripcion()));
        }
    }


    ui->tableTransacciones->resizeColumnsToContents();
}

void MainWindow::cargarCuentasCliente() {
    QString idCliente = ui->lineCliente->text();
    QSet<QString> cuentasUnicas;

    ui->comboBox->clear();
    ui->comboBox->addItem("Seleccionar");

    for (const Transaccion& trans : transacciones) {
        if (trans.getIdCliente() == idCliente) {
            cuentasUnicas.insert(trans.getIdCuenta());
        }
    }

    foreach(const QString &cuenta, cuentasUnicas) {
        ui->comboBox->addItem(cuenta);
    }

    mostrarTransaccionesFiltradas(idCliente, "Seleccionar");
}

void MainWindow::onComboBoxChanged(int index) {
    QString idCliente = ui->lineCliente->text();
    QString idCuenta = ui->comboBox->currentText();
    mostrarTransaccionesFiltradas(idCliente, idCuenta);
    calcularEstadoCuenta();

}

void MainWindow::calcularTotales(const QString& idCliente) {
    double saldoTotal = 0.0;
    double salidasTotal = 0.0;

    for (const Transaccion& trans : transacciones) {
        if (trans.getIdCliente() == idCliente) {
            double monto = trans.getMonto().toDouble();

            if (trans.getTipoOperacion() == "Deposito") {
                saldoTotal += monto;
            } else if (trans.getTipoOperacion() == "Retiro") {
                saldoTotal -= monto;
                salidasTotal += monto;
            }
        }
    }

    // Actualizar los campos con formato de dos decimales
    ui->lineSaldoTotal->setText(QString::number(saldoTotal, 'f', 2));
    ui->lineSalidaTotal->setText(QString::number(salidasTotal, 'f', 2));
}

void MainWindow::onVerTotalClicked() {
    QString idCliente = ui->lineCliente->text();

    if (idCliente.isEmpty()) {
        QMessageBox::warning(this, "Error", "Por favor ingrese un ID de cliente");
        return;
    }

    // Mostrar el frame
    ui->frameGeneral->setVisible(true);

    // Calcular y mostrar los totales
    calcularTotales(idCliente);
}

void MainWindow::calcularEstadoCuenta() {
    double saldo= 0.0;
    double salidas= 0.0;
    QString estadoCuenta = ui->comboBox->currentText();
    QString idCliente = ui->lineCliente->text();


    for (const Transaccion& trans : transacciones) {
        if (trans.getIdCliente() == idCliente  && trans.getIdCuenta() == estadoCuenta) {
            double monto = trans.getMonto().toDouble();

            if (trans.getTipoOperacion() == "Deposito") {
                saldo+= monto;
            } else if (trans.getTipoOperacion() == "Retiro") {
                saldo-= monto;
                salidas += monto;
            }
        }
    }

    // Actualizar los campos con formato de dos decimales
    ui->lineSaldo->setText(QString::number(saldo, 'f', 2));
    ui->lineSalida->setText(QString::number(salidas, 'f', 2));
}
