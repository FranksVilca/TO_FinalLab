#include "VentanaPrincipal.h"
#include "ui_VentanaPrincipal.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>

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
    QFile file("C:/Users/USER/OneDrive/Escritorio/TO_Lab09/csvRepo/clientes.csv");

    // Verificar que el archivo se puede abrir
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");
            if (fields.size() == 6) {  // Se espera un campo más para la edad
                int row = tablaClientes->rowCount();
                tablaClientes->insertRow(row);
                tablaClientes->setItem(row, 0, new QTableWidgetItem(fields[0]));  // ID
                tablaClientes->setItem(row, 1, new QTableWidgetItem(fields[1]));  // Nombre
                tablaClientes->setItem(row, 2, new QTableWidgetItem(fields[2]));  // Dirección
                tablaClientes->setItem(row, 3, new QTableWidgetItem(fields[3]));  // Teléfono
                tablaClientes->setItem(row, 4, new QTableWidgetItem(fields[4]));  // Correo
                tablaClientes->setItem(row, 5, new QTableWidgetItem(fields[5]));  // Edad
            }
        }
        file.close();
    } else {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo CSV para cargar los datos.");
    }
}

void VentanaPrincipal::guardarDatosEnCSV()
{
    QFile file("C:/Users/USER/OneDrive/Escritorio/TO_Lab09/csvRepo/clientes.csv");

    // Verificar que se pueda abrir el archivo
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "No se pudo abrir el archivo para guardar los datos.");
        return;
    }

    QTextStream out(&file);
    for (int row = 0; row < tablaClientes->rowCount(); ++row) {
        QString id = tablaClientes->item(row, 0)->text();
        QString nombre = tablaClientes->item(row, 1)->text();
        QString direccion = tablaClientes->item(row, 2)->text();
        QString telefono = tablaClientes->item(row, 3)->text();
        QString correo = tablaClientes->item(row, 4)->text();
        QString edad = tablaClientes->item(row, 5)->text();
        out << id << "," << nombre << "," << direccion << "," << telefono << "," << correo << "," << edad << "\n";
    }
    file.close();
}

void VentanaPrincipal::onAgregarCliente()
{
    QString nombre = lineEditNombre->text();
    QString direccion = lineEditDireccion->text();
    QString telefono = lineEditTelefono->text();
    QString correo = lineEditCorreo->text();
    QString edad = lineEditEdad->text();

    if (nombre.isEmpty() || direccion.isEmpty() || telefono.isEmpty() || correo.isEmpty() || edad.isEmpty()) {
        QMessageBox::warning(this, "Advertencia", "Todos los campos deben ser completos.");
        return;
    }

    // Generar el ID automáticamente (se asigna el siguiente número disponible)
    int id = generarNuevoId();

    // Agregar el cliente a la tabla
    int row = tablaClientes->rowCount();
    tablaClientes->insertRow(row);
    tablaClientes->setItem(row, 0, new QTableWidgetItem(QString::number(id)));  // Mostrar ID
    tablaClientes->setItem(row, 1, new QTableWidgetItem(nombre));              // Nombre
    tablaClientes->setItem(row, 2, new QTableWidgetItem(direccion));           // Dirección
    tablaClientes->setItem(row, 3, new QTableWidgetItem(telefono));           // Teléfono
    tablaClientes->setItem(row, 4, new QTableWidgetItem(correo));             // Correo
    tablaClientes->setItem(row, 5, new QTableWidgetItem(edad));               // Edad

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
    tablaClientes->item(row, 1)->setText(nombre);     // Nombre
    tablaClientes->item(row, 2)->setText(direccion);  // Dirección
    tablaClientes->item(row, 3)->setText(telefono);   // Teléfono
    tablaClientes->item(row, 4)->setText(correo);     // Correo
    tablaClientes->item(row, 5)->setText(edad);       // Edad

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

int VentanaPrincipal::generarNuevoId()
{
    int id = 1;
    if (tablaClientes->rowCount() > 0) {
        id = tablaClientes->item(tablaClientes->rowCount() - 1, 0)->text().toInt() + 1;  // Incrementar el último ID
    }
    return id;
}
