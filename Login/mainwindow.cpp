#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , process(new QProcess(this)) // Initialize QProcess
{
    ui->setupUi(this);

    // Configurar labelMessage vacío al inicio
    ui->labelMessage->setText("");

    // Conectar el botón de login al slot
    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &MainWindow::onLoginClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    // Obtener los valores ingresados por el usuario
    QString username = ui->lineEditUser->text();
    QString password = ui->lineEditPassword->text();

    // Verificar credenciales
    if (username == "admin" && password == "admin") {
        ui->labelMessage->setStyleSheet("color: green;");
        ui->labelMessage->setText("Inicio de sesión exitoso.");
        onVistaAdmin();
    } else {
        ui->labelMessage->setStyleSheet("color: red;");
        ui->labelMessage->setText("Usuario o contraseña incorrectos.");
    }
}

// Slot que se ejecuta al hacer clic en "Gestionar Usuarios"
void MainWindow::onVistaAdmin()
{
    // Ruta al ejecutable del otro proyecto
    QString programPath = "C:/Users/USER/OneDrive/Escritorio/TO_Lab09/PantallaAdmin/build/Desktop_Qt_6_5_3_MinGW_64_bit-Debug/debug/PantallaAdmin.exe";

    // Verifica si el archivo ejecutable existe
    if (QFile::exists(programPath)) {
        process->start(programPath);

        // Verifica si el proceso se inició correctamente
        if (!process->waitForStarted()) {
            qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
        }
    } else {
        qDebug() << "El archivo ejecutable no existe en la ruta proporcionada.";
    }
}
