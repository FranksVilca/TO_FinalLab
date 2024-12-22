#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton {
public:
    // Método para obtener la instancia única de la clase
    static Singleton* getInstance();

    // Ejemplo de una función de la clase Singleton
    void mostrarMensaje();

private:
    // Constructor privado para evitar instanciación externa
    Singleton() = default;

    // Puntero estático a la única instancia de la clase
    static Singleton* instancia;
};

#endif // SINGLETON_H
