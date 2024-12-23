#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , process(new QProcess(this)) // Inicializa QProcess
{
    ui->setupUi(this);
    // Conecta el botón "Gestionar Usuarios" al slot correspondiente
    connect(ui->btnOperaciones, &QPushButton::clicked, this, &MainWindow::on_btnSolicitar_clicked);
    connect(ui->btnSolicitar, &QPushButton::clicked, this, &MainWindow::on_btnSolicitar_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSolicitar_clicked()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "D:/lab09/TO_FinalLab/Cuenta/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/Cuenta.exe"; // Cambia esto a la ruta de tu proyecto

    // Inicia el otro proyecto
    process->start(programPath);

    // Verifica si el proceso se inició correctamente
    if (!process->waitForStarted()) {
        qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
    }
}


void MainWindow::on_btnOperaciones_clicked()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "D:/lab09/TO_FinalLab/Cliente/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/TO_lab09.exe"; // Cambia esto a la ruta de tu proyecto

    // Inicia el otro proyecto
    process->start(programPath);

    // Verifica si el proceso se inició correctamente
    if (!process->waitForStarted()) {
        qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
    }
}

