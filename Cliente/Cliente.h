#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class Cliente {
public:
    Cliente(int id, QString nombre, QString direccion, QString telefono, QString email, int edad);
    int getId() const;
    QString getNombre() const;
    QString getDireccion() const;
    QString getTelefono() const;
    QString getEmail() const;
    int getEdad() const;

    void setNombre(const QString& nombre);
    void setDireccion(const QString& direccion);
    void setTelefono(const QString& telefono);
    void setEmail(const QString& email);
    void setEdad(const int& edad);

private:
    int id;
    QString nombre;
    QString direccion;
    QString telefono;
    QString email;
    int edad;
};

#endif // CLIENTE_H
