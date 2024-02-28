//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_TARJETA_H
#define PROYECTO_FFFFF_TARJETA_H


#include <iostream>
using namespace std;

class Tarjeta{

protected: // lo ponemos de forma protegida para que las clases hijas puedan acceder a los atributos y métodos de la clase padre

    string numero;
    bool estado; // activa o inactiva
    string ccv;

public:

    Tarjeta(string _numero, bool _estado, string _ccv){
        numero = _numero;
        estado= _estado;
        ccv = _ccv;
    }

    void setNumero(string _numero) {
        numero = _numero;
    }
    string getNumero(){
        return numero;
    }

    void setEstado(bool _estado) {
        estado = _estado;
    }
    bool getEstado() {
        return estado;
    }

    string getccv() {
        return ccv;
    }
    void setccv(string _ccv) {
        ccv = _ccv;
    }
};

ostream& operator<<(ostream& os, Tarjeta* tarjeta)
{
    os<<"Numero Tarjeta:"<<tarjeta->getNumero()<<endl;
    os<<"CCV:"<<tarjeta->getccv()<<endl;
    os<<"Activa:"<<tarjeta->getEstado()<<endl;
    return os;
}

#endif //PROYECTO_FFFFF_TARJETA_H

