#include "BaseDeDatos.h"
#include <QFile>
#include <QTextStream>

BaseDeDatos* BaseDeDatos::instancia = nullptr;

BaseDeDatos* BaseDeDatos::getInstance() {
    if (!instancia) {
        instancia = new BaseDeDatos();
    }
    return instancia;
}

void BaseDeDatos::cargarClientes(const QString& archivoCSV) {
    QFile file(archivoCSV);
    if (!file.open(QIODevice::ReadOnly)) return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringList data = in.readLine().split(",");
        if (data.size() == 6) {
            Cliente* cliente = new Cliente(data[0].toInt(), data[1], data[2], data[3], data[4], data[5].toInt());
            clientes.push_back(cliente);
        }
    }
    file.close();
}

void BaseDeDatos::agregarCliente(Cliente* cliente) {
    clientes.push_back(cliente);
}

void BaseDeDatos::modificarCliente(int id, Cliente* clienteModificado) {
    for (auto& cliente : clientes) {
        if (cliente->getId() == id) {
            *cliente = *clienteModificado;
            break;
        }
    }
}

void BaseDeDatos::eliminarCliente(int id) {
    clientes.erase(std::remove_if(clientes.begin(), clientes.end(),
                                  [id](Cliente* cliente) { return cliente->getId() == id; }),
                   clientes.end());
}

std::vector<Cliente*> BaseDeDatos::obtenerClientes() const {
    return clientes;
}
