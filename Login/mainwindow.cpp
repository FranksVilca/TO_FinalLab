#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
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
        // Aquí puedes agregar la lógica para abrir una nueva ventana o continuar
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

    // Inicia el otro proyecto
    process->start(programPath);

    // Verifica si el proceso se inició correctamente
    if (!process->waitForStarted()) {
        qDebug() << "No se pudo iniciar el proyecto:" << process->errorString();
    }
}
