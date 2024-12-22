#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QMainWindow *VentanaPrincipal;
    QTableWidget *tablaClientes;
    QLineEdit *lineEditNombre;
    QLineEdit *lineEditDireccion;
    QLineEdit *lineEditTelefono;
    QLineEdit *lineEditCorreo;
    QLineEdit *lineEditEdad;  // Nuevo QLineEdit para la edad
    QPushButton *btnAgregarCliente;
    QPushButton *btnModificarCliente;
    QPushButton *btnEliminarCliente;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout1;
    QHBoxLayout *horizontalLayout2;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QString::fromUtf8("VentanaPrincipal"));
        VentanaPrincipal->resize(600, 400);

        // Crear los widgets
        tablaClientes = new QTableWidget(VentanaPrincipal);
        tablaClientes->setObjectName(QString::fromUtf8("tablaClientes"));
        tablaClientes->setColumnCount(5); // Se incrementa la cantidad de columnas
        tablaClientes->setHorizontalHeaderLabels({"Nombre", "Dirección", "Teléfono", "Correo Electrónico", "Edad"}); // Se agrega "Edad"

        lineEditNombre = new QLineEdit(VentanaPrincipal);
        lineEditNombre->setObjectName(QString::fromUtf8("lineEditNombre"));
        lineEditDireccion = new QLineEdit(VentanaPrincipal);
        lineEditDireccion->setObjectName(QString::fromUtf8("lineEditDireccion"));
        lineEditTelefono = new QLineEdit(VentanaPrincipal);
        lineEditTelefono->setObjectName(QString::fromUtf8("lineEditTelefono"));
        lineEditCorreo = new QLineEdit(VentanaPrincipal);
        lineEditCorreo->setObjectName(QString::fromUtf8("lineEditCorreo"));
        lineEditEdad = new QLineEdit(VentanaPrincipal);  // Crear el QLineEdit para la edad
        lineEditEdad->setObjectName(QString::fromUtf8("lineEditEdad"));

        btnAgregarCliente = new QPushButton(VentanaPrincipal);
        btnAgregarCliente->setObjectName(QString::fromUtf8("btnAgregarCliente"));
        btnAgregarCliente->setText("Agregar Cliente");

        btnModificarCliente = new QPushButton(VentanaPrincipal);
        btnModificarCliente->setObjectName(QString::fromUtf8("btnModificarCliente"));
        btnModificarCliente->setText("Modificar Cliente");

        btnEliminarCliente = new QPushButton(VentanaPrincipal);
        btnEliminarCliente->setObjectName(QString::fromUtf8("btnEliminarCliente"));
        btnEliminarCliente->setText("Eliminar Cliente");

        // Layouts
        verticalLayout = new QVBoxLayout();
        horizontalLayout1 = new QHBoxLayout();
        horizontalLayout2 = new QHBoxLayout();

        // Agregar widgets al layout
        horizontalLayout1->addWidget(new QLabel("Nombre:"));
        horizontalLayout1->addWidget(lineEditNombre);
        horizontalLayout1->addWidget(new QLabel("Dirección:"));
        horizontalLayout1->addWidget(lineEditDireccion);

        horizontalLayout2->addWidget(new QLabel("Teléfono:"));
        horizontalLayout2->addWidget(lineEditTelefono);
        horizontalLayout2->addWidget(new QLabel("Correo:"));
        horizontalLayout2->addWidget(lineEditCorreo);
        horizontalLayout2->addWidget(new QLabel("Edad:")); // Agregar etiqueta para la edad
        horizontalLayout2->addWidget(lineEditEdad); // Agregar QLineEdit para la edad

        verticalLayout->addLayout(horizontalLayout1);
        verticalLayout->addLayout(horizontalLayout2);
        verticalLayout->addWidget(btnAgregarCliente);
        verticalLayout->addWidget(btnModificarCliente);
        verticalLayout->addWidget(btnEliminarCliente);
        verticalLayout->addWidget(tablaClientes);

        // Asignar el layout al widget central
        QWidget *centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setLayout(verticalLayout);
        VentanaPrincipal->setCentralWidget(centralWidget);
    }
};

namespace Ui {
class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
