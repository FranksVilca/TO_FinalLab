#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

 // Slot para manejar el cambio de selección en ambos combobox
private:
    Ui::MainWindow *ui;
    void cargarTransacciones();
    void cargarCuentasCliente();
};
#endif // MAINWINDOW_H
