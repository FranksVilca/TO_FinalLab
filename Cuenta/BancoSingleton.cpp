#include "BancoSingleton.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

BancoSingleton* BancoSingleton::instancia = nullptr;

BancoSingleton* BancoSingleton::obtenerInstancia() {
    if (instancia == nullptr) {
        instancia = new BancoSingleton();
    }
    return instancia;
}

int BancoSingleton::generarIdCuenta() {
    static int idCuenta = 1000;
    return idCuenta++;
}

void BancoSingleton::crearCuenta(Cuenta* cuenta) {
    cuentas.append(cuenta);
}

void BancoSingleton::eliminarCuenta(int idCuenta) {
    for (int i = 0; i < cuentas.size(); ++i) {
        if (cuentas[i]->id == idCuenta) {
            cuentas.removeAt(i);
            break;
        }
    }
}

QList<Cuenta*> BancoSingleton::obtenerCuentas() const {
    return cuentas;
}


void BancoSingleton::guardarCuentasEnCSV(const QString &rutaArchivo) {
    QFile archivo(rutaArchivo);

    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "No se pudo abrir el archivo para guardar las cuentas.";
        return;
    }

    QTextStream salida(&archivo);

    for (Cuenta *cuenta : cuentas) {
        salida << cuenta->id << ","
               << cuenta->clienteId << ","
               << cuenta->saldo << ","
               << cuenta->tasaInteres << ","
               << cuenta->tipo << "\n";
    }

    archivo.close();
}


