#include "transaccion.h"

Transaccion::Transaccion(const QString& idCliente, const QString& idCuenta, const QString& tipoOperacion,
                         const QString& monto, const QString& fecha, const QString& descripcion)
    : m_idCliente(idCliente)
    , m_idCuenta(idCuenta)
    , m_tipoOperacion(tipoOperacion)
    , m_monto(monto)
    , m_fecha(fecha)
    , m_descripcion(descripcion)
{
}
