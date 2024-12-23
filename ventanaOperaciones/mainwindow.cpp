#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QDate>
#include <QDoubleValidator>  // Para el validador de números
#include <QDir>
#include <QDebug>
#include <QTextStream>
#include "transaccion.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //CargaDatos
    cargarTransaccionesDesdeCSV();

    // Inicializar el frame como oculto
    ui->frame->setVisible(false);
    ui->Fecha->setReadOnly(true);

    // Conectar los cambios en ambos QComboBox al mismo slot
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);

    // Establecer el validador para el campo txtMonto (solo números)
    QDoubleValidator *montoValidator = new QDoubleValidator(0.0, 999999.99, 2, this); // Limite de dos decimales
    ui->txtMonto->setValidator(montoValidator); // Asignar el validador al QLineEdit de monto

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onConfirmarClicked);  // Conectar el botón "Confirmar"
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onCancel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onComboBoxChanged() {
    // Obtener los valores seleccionados de ambos QComboBox
    QString cuentaSeleccionada = ui->comboBox->currentText();
    QString tipoOperacionSeleccionado = ui->comboBox_2->currentText();

    // Verificar que ambos combobox tengan valores distintos de "Seleccionar"
    if (cuentaSeleccionada != "Seleccionar" && tipoOperacionSeleccionado != "Seleccionar") {
        // Mostrar el QFrame si ambos combobox están seleccionados correctamente
        ui->frame->setVisible(true);

        // Obtener la fecha actual y actualizar el campo Fecha
        QDate fechaActual = QDate::currentDate();
        ui->Fecha->setText(fechaActual.toString("yyyy-MM-dd"));
    } else {
        // Si no se seleccionan valores válidos, ocultar el QFrame
        ui->frame->setVisible(false);
    }
}

void MainWindow::onCancel() {
    // Limpiar los campos
    ui->comboBox->setCurrentIndex(0);  // Restaurar al primer valor (Seleccionar)
    ui->comboBox_2->setCurrentIndex(0); // Restaurar al primer valor (Seleccionar)
    ui->txtMonto->clear();              // Limpiar el campo de monto
    ui->txtDesc->clear();               // Limpiar la descripción
    ui->Fecha->clear();                 // Limpiar el campo de fecha

    // Ocultar el frame si es necesario
    ui->frame->setVisible(false);
}

void MainWindow::onConfirmarClicked() {

    // Obtener y mostrar la ruta actual
    QString currentPath = QCoreApplication::applicationDirPath();
    // Verificar si algún campo está vacío
    QString cuentaSeleccionada = ui->comboBox->currentText();
    QString tipoOperacionSeleccionado = ui->comboBox_2->currentText();
    QString monto = ui->txtMonto->text();
    QString fecha = ui->Fecha->text();
    QString descripcion = ui->txtDesc->toPlainText();

    if (cuentaSeleccionada == "Seleccionar" || tipoOperacionSeleccionado == "Seleccionar" ||
        monto.isEmpty() || fecha.isEmpty() || descripcion.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Por favor complete todos los campos.");
        return; // No continuar si algún campo está vacío
    }

    if(tipoOperacionSeleccionado == "Retiro" && verificarSaldo()){
        QMessageBox::warning(this, "Advertencia", "No Cuenta con ese Saldo Disponible.");
        return; // No continuar
    }


    // Definir la ruta del archivo CSV en la carpeta 'csvRepo'
    QDir dir(currentPath);
    dir.cdUp(); // Subir un nivel
    dir.cdUp(); // Subir otro nivel
    dir.cdUp(); // Subir otro nivel
    dir.cdUp(); // Subir otro nivel
    QString filePath = dir.absolutePath() + "/csvRepo/transaccion.csv";

    QFile file(filePath);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);

        // Escribir los datos en el archivo CSV
        out << ui->lineEdit->text() << ","        // id_cliente
            << ui->comboBox->currentText() << ","  // id_cuenta
            << ui->comboBox_2->currentText() << "," // operacion
            << monto << ","                         // monto
            << fecha << ","                         // fecha
            << descripcion << "\n";                 // descripcion

        file.close();
        QMessageBox::information(this, "Éxito", "Transacción registrada correctamente.");

    } else {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir.");
    }
    onCancel();
}

bool MainWindow::verificarSaldo() {
    double saldo= 0.0;
    double salidas= 0.0;
    QString idCuenta = ui->comboBox->currentText();
    QString idCliente = ui->lineEdit->text();
    QString montoRetirarStr = ui->txtMonto->text(); // Obtén el texto del QLineEdit
    bool ok; // Variable para verificar si la conversión fue exitosa
    double montoRetirar = montoRetirarStr.toDouble(&ok);

    for (const Transaccion& trans : transacciones) {



        if (trans.getIdCliente() == idCliente  && trans.getIdCuenta() == idCuenta) {
            double monto = trans.getMonto().toDouble();

            if (trans.getTipoOperacion() == "Deposito") {
                saldo+= monto;
            } else if (trans.getTipoOperacion() == "Retiro") {
                saldo-= monto;
                salidas += monto;
            }

            qDebug() << "idCliente" <<trans.getIdCliente();
            qDebug() << "idCuenta" <<trans.getIdCuenta();
            qDebug() << "Monto" <<trans.getMonto();
            qDebug() << "Operacion" <<trans.getTipoOperacion()<<"\n\n";
        }

        qDebug() << "saldo" <<saldo<<"\n";
        qDebug() << "Salida" <<salidas<<"\n\n";


    }

    montoRetirar+=salidas;
    return saldo<montoRetirar;
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

