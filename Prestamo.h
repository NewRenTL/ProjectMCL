//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_PRESTAMO_H
#define PROYECTO_FFFFF_PRESTAMO_H
#include <iostream>
using namespace std;

class Prestamo {
private:
    string fechaPrestamo;
    double monto;
    int numeroCuotas;
    double precioCuota;
    float interes;
    bool estadoPrestamo;

public:

    // en el constructor no ponemos el parámetro para el precio de la cuota porque para eso primero tenemos
    // que saber el monto y el numero de cuotas

    Prestamo(string _fechaPrestamo, double _monto, int _numeroCuotas, float _interes, bool _estadoPrestamo)
    {
        fechaPrestamo = _fechaPrestamo;
        monto = _monto;
        numeroCuotas = _numeroCuotas;
        interes = _interes;
        estadoPrestamo = _estadoPrestamo;
        precioCuota =((((float)(interes)/(100/1.0))*monto) + monto)/(numeroCuotas/1.0); // para que salga decimal siempre dividimos al numerador entre 1.0

    }

    string getfechaPrestamo() {
        return fechaPrestamo;
    }

    void setfechaPrestamo(string _fechaPrestamo) {
        fechaPrestamo = _fechaPrestamo;
    }

    double getmonto() {
        return monto;
    }

    void setmonto(double _monto) {
        monto = _monto;
    }

    int getnumeroCuotas()  {
        return numeroCuotas;
    }

    void setnumeroCuotas(int _numeroCuotas) {
        numeroCuotas = _numeroCuotas;
    }

    double getprecioCuota(){
        return precioCuota;
    }

    void setprecioCuota(double _precioCuota) {
        precioCuota = _precioCuota;
    }

    float getinteres(){
        return interes;
    }

    void setinteres(float _interes) {
        interes = _interes;
    }

    bool getestadoPrestamo(){
        return estadoPrestamo;
    }

    void setestadoPrestamo(bool _estadoPrestamo) {
        estadoPrestamo = _estadoPrestamo;
    }


};


#endif //PROYECTO_FFFFF_PRESTAMO_H
