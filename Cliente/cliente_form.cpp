// cliente_form.cpp
#include "cliente_form.h"
#include "ui_cliente_form.h"
#include "BaseDeDatos.h"

ClienteForm::ClienteForm(QWidget* parent) : QDialog(parent), ui(new Ui::ClienteForm) {
    ui->setupUi(this);
}

ClienteForm::~ClienteForm() {
    delete ui;
}

void ClienteForm::on_btnGuardar_clicked() {
    ClienteRepository* repo = ClienteRepository::getInstance();
    int id = ui->inputId->text().toInt();
    QString nombre = ui->inputNombre->text();
    QString direccion = ui->inputDireccion->text();
    QString telefono = ui->inputTelefono->text();
    QString email = ui->inputEmail->text();
    QString fechaNacimiento = ui->inputFechaNacimiento->text();

    Cliente* nuevoCliente = new Cliente(id, nombre, direccion, telefono, email, fechaNacimiento);
    repo->agregarCliente(nuevoCliente);

    this->accept();
}
