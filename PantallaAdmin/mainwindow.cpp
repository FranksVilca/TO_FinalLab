#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , process(new QProcess(this)) // Inicializa QProcess
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
    QString programPath = "C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cuenta/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/Cuenta.exe"; // Cambia esto a la ruta de tu proyecto

    // Inicia el otro proyecto
    process->start(programPath);

    // Verifica si el proceso se inició correctamente
    if (!process->waitForStarted()) {
        qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
    }
}

void MainWindow::onGestionarCuentasClicked()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "C:/Users/USER/OneDrive/Escritorio/TO_Lab09/Cliente/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/TO_lab09.exe"; // Cambia esto a la ruta de tu proyecto

    // Inicia el otro proyecto
    process->start(programPath);

    // Verifica si el proceso se inició correctamente
    if (!process->waitForStarted()) {
        qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
    }
}