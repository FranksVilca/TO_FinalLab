#ifndef CLIENTEMANAGER_H
#define CLIENTEMANAGER_H

#include "Cliente.h"
#include <QList>

class ClienteManager {
private:
    static ClienteManager* instancia;
    QList<Cliente> listaClientes;

    ClienteManager() {}

public:
    static ClienteManager* obtenerInstancia() {
        if (!instancia) {
            instancia = new ClienteManager();
        }
        return instancia;
    }

    void cargarClientes(const QString& archivo) {
        listaClientes = Cliente::cargarClientesDesdeCSV(archivo);
    }

    QList<Cliente> obtenerClientes() const {
        return listaClientes;
    }
};

#endif // CLIENTEMANAGER_H
