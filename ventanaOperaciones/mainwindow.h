#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transaccion.h"

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
    void onComboBoxChanged(); // Slot para manejar el cambio de selección en ambos combobox
    void onCancel(); // cancel
    void onConfirmarClicked(); // confrimar
    bool verificarSaldo();
    void cargarTransaccionesDesdeCSV();

private:
    QVector<Transaccion> transacciones;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
