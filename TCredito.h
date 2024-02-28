//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_TCREDITO_H
#define PROYECTO_FFFFF_TCREDITO_H
#include "Tarjeta.h"
#include <iostream>
using namespace std;

class TCredito : public Tarjeta { // en esta linea de codigo estamos formando la herencia
private:
    double interes;
    double limiteMonto;
    string fechaCorte;
    string fechaPago;

public:
    TCredito( string _numero, bool _estado, string _ccv, double _interes, double _limiteMonto,
              string _fechaCorte, string _fechaPago) : Tarjeta(_numero, _estado, _ccv){
        interes= _interes;
        limiteMonto = _limiteMonto;
        fechaCorte = _fechaCorte;
        fechaPago = _fechaPago;
    }

    void setinteres(double _interes) { // setter de interes
        interes = _interes;
    }
    double getinteres() { // getter de interes
        return interes;
    }

    void setlimiteMonto(double _limiteMonto) { // setter de limite de monto
        limiteMonto = _limiteMonto;
    }

    double getlimiteMonto() { // getter de limite monto
        return limiteMonto;
    }

    void setfechaCorte( string _fechaCorte) { // setter de fecha corte
        fechaCorte = _fechaCorte;
    }
    string getfechaCorte(){ // getter de fecha corte
        return fechaCorte;
    }

    void setfechaPago(string _fechaPago) { // setter fecha pago
        fechaPago = _fechaPago;
    }

    string getfechaPago(){ // getter fecha pago
        return fechaPago;
    }

};
#endif //PROYECTO_FFFFF_TCREDITO_H

