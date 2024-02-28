//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_TDEBITO_H
#define PROYECTO_FFFFF_TDEBITO_H
#include <iostream>
#include "Tarjeta.h"
using namespace std;

class TDebito: public Tarjeta{ // en esta linea formamos la herencia
private:
    string fechaVencimiento;

public:

    TDebito(string _numero, bool _estado, string _ccv, string _fechaVencimiento) :
            Tarjeta(_numero, _estado, _ccv){
        fechaVencimiento = _fechaVencimiento;
    }

    void setfechaVencimiento(string _fechaVencimiento) { // setter de fecha de vencimiento
        fechaVencimiento = _fechaVencimiento;
    }
    string getfechaVencimiento(){ // getter de fecha de vencimiento
        return fechaVencimiento;
    }
};
#endif //PROYECTO_FFFFF_TDEBITO_H

