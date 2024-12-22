#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

VentanaPrincipal::VentanaPrincipal(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);

    // Inicializar widgets
    tablaClientes = ui->tablaClientes;
    lineEditNombre = ui->lineEditNombre;
    lineEditDireccion = ui->lineEditDireccion;
    lineEditTelefono = ui->lineEditTelefono;
    lineEditCorreo = ui->lineEditCorreo;
    lineEditEdad = ui->lineEditEdad;

    // Cargar datos desde el archivo CSV
    cargarDatosDesdeCSV();

    // Conectar los botones a las funciones correspondientes
    connect(ui->btnAgregarCliente, &QPushButton::clicked, this, &VentanaPrincipal::onAgregarCliente);
    connect(ui->btnModificarCliente, &QPushButton::clicked, this, &VentanaPrincipal::onModificarCliente);
    connect(ui->btnEliminarCliente, &QPushButton::clicked, this, &VentanaPrincipal::onEliminarCliente);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::cargarDatosDesdeCSV()
{
    QFile file("clientes.csv");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 5) {  // Se espera un campo más para la edad
                int row = tablaClientes->rowCount();
                tablaClientes->insertRow(row);
                tablaClientes->setItem(row, 0, new QTableWidgetItem(fields[0]));
                tablaClientes->setItem(row, 1, new QTableWidgetItem(fields[1]));
                tablaClientes->setItem(row, 2, new QTableWidgetItem(fields[2]));
                tablaClientes->setItem(row, 3, new QTableWidgetItem(fields[3]));
                tablaClientes->setItem(row, 4, new QTableWidgetItem(fields[4])); // Mostrar edad
            }
        }
        file.close();
    }
}

void VentanaPrincipal::guardarDatosEnCSV()
{
    QFile file("clientes.csv");
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QTextStream out(&file);
        for (int row = 0; row < tablaClientes->rowCount(); ++row) {
            QString nombre = tablaClientes->item(row, 0)->text();
            QString direccion = tablaClientes->item(row, 1)->text();
            QString telefono = tablaClientes->item(row, 2)->text();
            QString correo = tablaClientes->item(row, 3)->text();
            QString edad = tablaClientes->item(row, 4)->text(); // Obtener edad
            out << nombre << "," << direccion << "," << telefono << "," << correo << "," << edad << "\n";
        }
        file.close();
    }
}

void VentanaPrincipal::onAgregarCliente()
{
    QString nombre = lineEditNombre->text();
    QString direccion = lineEditDireccion->text();
    QString telefono = lineEditTelefono->text();
    QString correo = lineEditCorreo->text();
    QString edad = lineEditEdad->text(); // Obtener la edad

    if (nombre.isEmpty() || direccion.isEmpty() || telefono.isEmpty() || correo.isEmpty() || edad.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Todos los campos deben ser completos.");
        return;
    }

    // Agregar el cliente a la tabla
    int row = tablaClientes->rowCount();
    tablaClientes->insertRow(row);
    tablaClientes->setItem(row, 0, new QTableWidgetItem(nombre));
    tablaClientes->setItem(row, 1, new QTableWidgetItem(direccion));
    tablaClientes->setItem(row, 2, new QTableWidgetItem(telefono));
    tablaClientes->setItem(row, 3, new QTableWidgetItem(correo));
    tablaClientes->setItem(row, 4, new QTableWidgetItem(edad)); // Insertar la edad

    // Guardar los cambios en el archivo CSV
    guardarDatosEnCSV();

    // Limpiar los campos después de agregar
    limpiarCampos();
}


void VentanaPrincipal::onModificarCliente()
{
    int row = tablaClientes->currentRow();  // Obtener la fila seleccionada
    if (row == -1) {  // Validar si no se ha seleccionado ninguna fila
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar un cliente para modificar.");
        return;
    }

    // Obtener los nuevos valores desde los campos de texto
    QString nombre = lineEditNombre->text();
    QString direccion = lineEditDireccion->text();
    QString telefono = lineEditTelefono->text();
    QString correo = lineEditCorreo->text();
    QString edad = lineEditEdad->text();

    // Validar que los campos no estén vacíos
    if (nombre.isEmpty() || direccion.isEmpty() || telefono.isEmpty() || correo.isEmpty() || edad.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Todos los campos deben ser completos.");
        return;
    }

    // Actualizar la fila seleccionada con los nuevos valores
    tablaClientes->item(row, 0)->setText(nombre);     // Nombre
    tablaClientes->item(row, 1)->setText(direccion);  // Dirección
    tablaClientes->item(row, 2)->setText(telefono);   // Teléfono
    tablaClientes->item(row, 3)->setText(correo);     // Correo
    tablaClientes->item(row, 4)->setText(edad);       // Edad

    // Guardar los cambios en el archivo CSV
    guardarDatosEnCSV();

    // Limpiar los campos después de modificar
    limpiarCampos();
}


void VentanaPrincipal::onEliminarCliente()
{
    int row = tablaClientes->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Advertencia", "Debe seleccionar un cliente para eliminar.");
        return;
    }

    tablaClientes->removeRow(row);

    // Guardar los cambios en el archivo CSV
    guardarDatosEnCSV();
}

void VentanaPrincipal::limpiarCampos()
{
    lineEditNombre->clear();
    lineEditDireccion->clear();
    lineEditTelefono->clear();
    lineEditCorreo->clear();
    lineEditEdad->clear();
}
