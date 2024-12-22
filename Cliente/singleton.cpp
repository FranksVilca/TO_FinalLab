#include "Singleton.h"
#include <QDebug>

// Inicializamos el puntero estático a nullptr
Singleton* Singleton::instancia = nullptr;

// Método estático para obtener la única instancia
Singleton* Singleton::getInstance() {
    // Si la instancia aún no existe, la creamos
    if (!instancia) {
        instancia = new Singleton();
    }
    return instancia;
}

// Ejemplo de una función de la clase Singleton
void Singleton::mostrarMensaje() {
    qDebug() << "¡Este es un mensaje desde la clase Singleton!";
}
