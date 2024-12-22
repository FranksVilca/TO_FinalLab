#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include "Cliente.h"
#include <vector>
#include <QString>

class BaseDeDatos {
public:
    static BaseDeDatos* getInstance();
    void cargarClientes(const QString& archivoCSV);
    void agregarCliente(Cliente* cliente);
    void modificarCliente(int id, Cliente* clienteModificado);
    void eliminarCliente(int id);
    std::vector<Cliente*> obtenerClientes() const;

private:
    BaseDeDatos() = default;
    static BaseDeDatos* instancia;
    std::vector<Cliente*> clientes;
};

#endif // BASEDEDATOS_H
