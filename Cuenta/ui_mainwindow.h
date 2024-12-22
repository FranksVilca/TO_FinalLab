#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDate>
#include "Cuenta.h"
#include "Cliente.h"
QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QMainWindow *MainWindow;
    QTableWidget *tableWidgetCuentas;  // Nombre corregido
    QComboBox *comboBoxClientes;
    QComboBox *comboBoxTipoCuenta;
    QPushButton *buttonCrear;   // Nombre corregido
    QPushButton *buttonEditar;  // Nombre corregido
    QPushButton *buttonEliminar; // Nombre corregido
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout1;
    QHBoxLayout *horizontalLayout2;
    QHBoxLayout *horizontalLayout3;  // Nuevo layout para el saldo
    QLineEdit *lineEditID;
    QLineEdit *lineEditSaldo;  // Nuevo QLineEdit para el saldo

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);

        // Crear los widgets
        tableWidgetCuentas = new QTableWidget(MainWindow);
        tableWidgetCuentas->setObjectName(QString::fromUtf8("tableWidgetCuentas"));
        tableWidgetCuentas->setColumnCount(7); // 7 columnas (ID, Cliente, Tipo de Cuenta, Saldo, Tasa de Interés, Fecha de Creación)
        tableWidgetCuentas->setHorizontalHeaderLabels({"ID", "Cliente", "Tipo de Cuenta", "Saldo", "Tasa de Interés", "Fecha de Creación"});

        comboBoxClientes = new QComboBox(MainWindow);
        comboBoxClientes->setObjectName(QString::fromUtf8("comboBoxClientes"));

        comboBoxTipoCuenta = new QComboBox(MainWindow);
        comboBoxTipoCuenta->setObjectName(QString::fromUtf8("comboBoxTipoCuenta"));
        comboBoxTipoCuenta->addItem("Ahorro");
        comboBoxTipoCuenta->addItem("Joven");
        comboBoxTipoCuenta->addItem("Plus");
        comboBoxTipoCuenta->addItem("Empresarial");
        comboBoxTipoCuenta->addItem("Tarjeta de Crédito");

        buttonCrear = new QPushButton(MainWindow);   // Nombre corregido
        buttonCrear->setObjectName(QString::fromUtf8("buttonCrear"));
        buttonCrear->setText("Crear Cuenta");

        buttonEditar = new QPushButton(MainWindow);  // Nombre corregido
        buttonEditar->setObjectName(QString::fromUtf8("buttonEditar"));
        buttonEditar->setText("Modificar Cuenta");

        buttonEliminar = new QPushButton(MainWindow); // Nombre corregido
        buttonEliminar->setObjectName(QString::fromUtf8("buttonEliminar"));
        buttonEliminar->setText("Eliminar Cuenta");

        // Crear un campo para mostrar el ID único de la cuenta
        lineEditID = new QLineEdit(MainWindow);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));
        lineEditID->setReadOnly(true);  // ID no editable

        // Crear un campo para ingresar el saldo
        lineEditSaldo = new QLineEdit(MainWindow);
        lineEditSaldo->setObjectName(QString::fromUtf8("lineEditSaldo"));
        lineEditSaldo->setPlaceholderText("Saldo inicial");

        // Layouts
        verticalLayout = new QVBoxLayout();
        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout2 = new QHBoxLayout();
        horizontalLayout3 = new QHBoxLayout();  // Layout para el saldo

        // Agregar widgets al layout
        horizontalLayout1->addWidget(new QLabel("Cliente:"));
        horizontalLayout1->addWidget(comboBoxClientes);
        horizontalLayout1->addWidget(new QLabel("Tipo de Cuenta:"));
        horizontalLayout1->addWidget(comboBoxTipoCuenta);

        horizontalLayout2->addWidget(new QLabel("ID Cuenta:"));
        horizontalLayout2->addWidget(lineEditID);

        horizontalLayout3->addWidget(new QLabel("Saldo Inicial:"));
        horizontalLayout3->addWidget(lineEditSaldo);

        verticalLayout->addLayout(horizontalLayout1);
        verticalLayout->addLayout(horizontalLayout2);
        verticalLayout->addLayout(horizontalLayout3);
        verticalLayout->addWidget(buttonCrear);
        verticalLayout->addWidget(buttonEditar);
        verticalLayout->addWidget(buttonEliminar);
        verticalLayout->addWidget(tableWidgetCuentas);

        // Asignar el layout al widget central
        QWidget *centralWidget = new QWidget(MainWindow);
        centralWidget->setLayout(verticalLayout);
        MainWindow->setCentralWidget(centralWidget);
    }
};

namespace Ui {
class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
