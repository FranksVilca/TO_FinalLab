#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "transaccion.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void cargarCuentasCliente();
    void onComboBoxChanged(int index);
    void onVerTotalClicked();

 // Slot para manejar el cambio de selección en ambos combobox
private:
    Ui::MainWindow *ui;
    QVector<Transaccion> transacciones;
    void cargarTransaccionesDesdeCSV();
    void calcularTotales(const QString& idCliente);
    void calcularEstadoCuenta();
    void mostrarTransaccionesFiltradas(const QString& idCliente, const QString& idCuenta);

};
#endif // MAINWINDOW_H
