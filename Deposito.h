
#ifndef deposito1
#define deposito1
#include "Cuenta.h"
#include <string>
class Deposito
{
    private:
    std::string nombreCuentaEmision;
    std::string nombreCuentaLlegada;
    tipoCuenta tipoDeCuenta;
    double monto;
    std::string fecha;
    
    public:
    Deposito(std::string _nombreCuentaEmision,std::string _nombreCuentaLlegada,
    double _monto,std::string _fecha,tipoCuenta _tipoCuenta):
    nombreCuentaEmision(_nombreCuentaEmision),
    nombreCuentaLlegada(_nombreCuentaLlegada),
    monto(_monto),
    fecha(_fecha)
    {
        tipoDeCuenta = _tipoCuenta;
    };

    double getMonto()
    {
        return monto;
    }

    std::string getFecha()
    {
        return fecha;
    }

    std::string getNombreCuentaEmision()
    {
        return nombreCuentaEmision;
    }

    std::string getNombreCuentaLlegada()
    {
        return nombreCuentaLlegada;
    }

    void setMonto(double _newMonto)
    {
        monto = _newMonto;
    }

    void setFecha(std::string _newFecha)
    {
        fecha = _newFecha;
    }

    void setCuentaEmision(std::string _newCuentaEmision)
    {
        nombreCuentaEmision = _newCuentaEmision;
    }
    void setCuentaLlegada(std::string _newCuentaLlegada)
    {
        nombreCuentaLlegada = _newCuentaLlegada;
    }

};

#endif