#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conecta el botón "Gestionar Usuarios" al slot correspondiente
    connect(ui->GestionaUsuarios, &QPushButton::clicked, this, &MainWindow::onGestionarUsuariosClicked);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onGestionarCuentasClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot que se ejecuta al hacer clic en "Gestionar Usuarios"
void MainWindow::onGestionarUsuariosClicked()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cuenta/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/Cuenta.exe";

    // Verificar si el archivo existe antes de intentar ejecutarlo
    if (QFile::exists(programPath)) {
        QProcess *process = new QProcess(this); // Crear un nuevo QProcess para este proceso
        process->start(programPath);

        // Verificar si el proceso se inició correctamente
        if (!process->waitForStarted()) {
            qDebug() << "No se pudo iniciar el proyecto Cuenta:" << process->errorString();
        } else {
            qDebug() << "Iniciando Cuenta...";
        }
    } else {
        qDebug() << "El archivo ejecutable de Cuenta no existe.";
    }
}

void MainWindow::onGestionarCuentasClicked()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cliente/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/TO_lab09.exe";

    // Verificar si el archivo existe antes de intentar ejecutarlo
    if (QFile::exists(programPath)) {
        QProcess *process = new QProcess(this); // Crear un nuevo QProcess para este proceso
        process->start(programPath);

        // Verificar si el proceso se inició correctamente
        if (!process->waitForStarted()) {
            qDebug() << "No se pudo iniciar el proyecto Cliente:" << process->errorString();
        } else {
            qDebug() << "Iniciando Cliente...";
        }
    } else {
        qDebug() << "El archivo ejecutable de Cliente no existe.";
    }
}
