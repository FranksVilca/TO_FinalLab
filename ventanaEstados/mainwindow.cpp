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

    connect(ui->lineCliente, &QLineEdit::textChanged, this, &MainWindow::cargarCuentasCliente);
    cargarTransacciones();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::cargarTransacciones() {
    // Obtener la ruta del archivo usando la misma lógica que usamos para escribir
    QString currentPath = QCoreApplication::applicationDirPath();
    QDir dir(currentPath);
    dir.cdUp(); // Subir cuatro niveles como antes
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString filePath = dir.absolutePath() + "/csvRepo/transaccion.csv";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para leer");
        return;
    }

    QTextStream in(&file);

    // Limpiar la tabla antes de cargar nuevos datos
    ui->tableTransacciones->setRowCount(0);

    // Leer el archivo línea por línea
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        // Verificar que tengamos todos los campos necesarios
        if (fields.size() >= 6) {
            int row = ui->tableTransacciones->rowCount();
            ui->tableTransacciones->insertRow(row);

            // Llenar la tabla con los datos
            // Tipo (operación)
            ui->tableTransacciones->setItem(row, 0, new QTableWidgetItem(fields[2]));
            // Monto
            ui->tableTransacciones->setItem(row, 1, new QTableWidgetItem(fields[3]));
            // ID Cliente
            ui->tableTransacciones->setItem(row, 2, new QTableWidgetItem(fields[0]));
            // Fecha
            ui->tableTransacciones->setItem(row, 3, new QTableWidgetItem(fields[4]));
            // Descripción
            ui->tableTransacciones->setItem(row, 4, new QTableWidgetItem(fields[5]));
        }
    }

    file.close();

    // Ajustar el tamaño de las columnas al contenido
    ui->tableTransacciones->resizeColumnsToContents();
}

void MainWindow::cargarCuentasCliente() {
    QString idCliente = ui->lineCliente->text();

    // Obtener la ruta del archivo
    QString currentPath = QCoreApplication::applicationDirPath();
    QDir dir(currentPath);
    dir.cdUp(); // Subir cuatro niveles
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    QString filePath = dir.absolutePath() + "/csvRepo/transaccion.csv";

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para leer");
        return;
    }

    QTextStream in(&file);
    QSet<QString> cuentasUnicas; // Usamos QSet para mantener cuentas únicas

    // Limpiar el ComboBox
    ui->comboBox->clear();
    ui->comboBox->addItem("Seleccionar");

    // Leer el archivo y filtrar por cliente
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        // Verificar que la línea tenga suficientes campos y que coincida el ID del cliente
        if (fields.size() >= 6 && fields[0] == idCliente) {
            cuentasUnicas.insert(fields[1]); // fields[1] es el ID de la cuenta
        }
    }

    file.close();

    // Agregar las cuentas únicas al ComboBox
    foreach(const QString &cuenta, cuentasUnicas) {
        ui->comboBox->addItem(cuenta);
    }
}
