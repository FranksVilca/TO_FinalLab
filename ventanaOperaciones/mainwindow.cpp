#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox> // Incluir para mostrar el mensaje de advertencia

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicializar el frame como oculto
    ui->frame->setVisible(false);
    ui->lineEdit->setReadOnly(true);


    // Conectar los cambios en ambos QComboBox al mismo slot
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
    connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onComboBoxChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onComboBoxChanged() {
    // Obtener los valores seleccionados de ambos QComboBox
    QString cuentaSeleccionada = ui->comboBox->currentText();
    QString tipoOperacionSeleccionado = ui->comboBox_2->currentText();

    // Verificar que ambos combobox tengan valores distintos de "Seleccionar"
    if (cuentaSeleccionada != "Seleccionar" && tipoOperacionSeleccionado != "Seleccionar") {
        // Mostrar el QFrame si ambos combobox están seleccionados correctamente
        ui->frame->setVisible(true);
    } else {
        // Si no se seleccionan valores válidos, ocultar el QFrame
        ui->frame->setVisible(false);
    }
}
