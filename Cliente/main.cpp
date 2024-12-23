#include <QApplication>
#include "VentanaPrincipal.h"
#include "BaseDeDatos.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Cargar la base de datos desde el archivo CSV
    BaseDeDatos::getInstance()->cargarClientes("C:/Users/USER/OneDrive/Escritorio/TO_Lab09/csvRepo/clientes.csv");

    // Crear e iniciar la ventana principal
    VentanaPrincipal ventana;
    ventana.show();

    return app.exec();
}
