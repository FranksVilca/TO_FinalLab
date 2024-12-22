#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess> // Incluye QProcess para ejecutar aplicaciones externas

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onGestionarUsuariosClicked();
    void onGestionarCuentasClicked();

private:
    Ui::MainWindow *ui;
    QProcess *process; // QProcess para ejecutar el otro proyecto
};

#endif // MAINWINDOW_H
