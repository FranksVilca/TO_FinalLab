#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTableWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = nullptr);
    ~VentanaPrincipal();

private slots:
    void onAgregarCliente();
    void onModificarCliente();
    void onEliminarCliente();

private:
    Ui::VentanaPrincipal *ui;
    QTableWidget *tablaClientes;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditDireccion;
    QLineEdit *lineEditTelefono;
    QLineEdit *lineEditCorreo;
    QLineEdit *lineEditEdad;

    void cargarDatosDesdeCSV();
    void guardarDatosEnCSV();
    void limpiarCampos();  // Definir la función para limpiar los campos
};

#endif // VENTANAPRINCIPAL_H
