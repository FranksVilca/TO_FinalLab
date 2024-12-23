#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <QString>

class Transaccion {
public:
    Transaccion(const QString& idCliente, const QString& idCuenta, const QString& tipoOperacion,
                const QString& monto, const QString& fecha, const QString& descripcion);

    // Getters
    QString getIdCliente() const { return m_idCliente; }
    QString getIdCuenta() const { return m_idCuenta; }
    QString getTipoOperacion() const { return m_tipoOperacion; }
    QString getMonto() const { return m_monto; }
    QString getFecha() const { return m_fecha; }
    QString getDescripcion() const { return m_descripcion; }

private:
    QString m_idCliente;
    QString m_idCuenta;
    QString m_tipoOperacion;
    QString m_monto;
    QString m_fecha;
    QString m_descripcion;
};

#endif // TRANSACCION_H
