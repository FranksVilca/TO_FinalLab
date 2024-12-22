#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QComboBox>
#include <QPushButton>
#include <QTableWidget>
#include <QTableWidgetItem>

#include "Cliente.h"
#include "Cuenta.h"
#include "CuentaAhorro.h"
#include "CuentaJoven.h"
#include "CuentaPlus.h"
#include "CuentaEmpresarial.h"
#include "CuentaTarjetaCredito.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void crearCuenta();
    void editarCuenta();
    void eliminarCuenta();
    void guardarTablaEnCSV(const QString &rutaArchivo);
    void cargarCuentasDesdeCSV(const QString &rutaArchivo);


private:
    Ui::MainWindow *ui;
    QList<Cliente> clientes;

    // Método para cargar clientes en el comboBox
    void cargarClientes();
};

#endif // MAINWINDOW_H
