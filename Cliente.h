//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_CLIENTE_H
#define PROYECTO_FFFFF_CLIENTE_H
#include <iostream>
#include "Cuenta.h"
#include <vector>

using namespace std;

class Cliente{
private:
    string DNI;
    string nombreCompleto;
    string fechaNacimiento;
    vector <Cuenta*> cuentas;
public:
    Cliente(string _dni, string _nombreCompleto, string _fechaNacimiento){  // para ahorrar memoria usamos la referencia, ya que ya se creó ese array de string
        DNI = _dni;
        nombreCompleto = _nombreCompleto;
        fechaNacimiento=_fechaNacimiento;
    }
    void setDni(string _dni) { // setter de DNI
        DNI = _dni;
    }
    string getDni() {  // getter de DNI
        return DNI;
    }
    void setnombreCompleto( string _nombreCompleto) { // setter de nombreCompleto
        nombreCompleto = _nombreCompleto;
    }
    string getnombreCompleto(){ // get de nombreCompleto
        return nombreCompleto;
    }
    void setfechaNacimiento(string _fechaNacimiento) { // setter de fechaNacimiento
        fechaNacimiento = _fechaNacimiento;
    }
    string getfechaNacimiento(){ // getter de fechaNacimiento
        return fechaNacimiento;
    }

    void addCuenta(Cuenta* cuenta)
    {
        cuentas.push_back(cuenta);
    }

    const vector<Cuenta *> &getCuentas() const {
        return cuentas;
    }
};

ostream& operator<<(ostream& os, Cliente* cliente)
{
    os << "¡Usuario encontrado!" << endl;
    os<<"DNI: "<<cliente->getDni()<< endl;
    os<<"Nombre Completo: "<< cliente->getnombreCompleto()<< endl;
    os<<"Fecha de nacimiento: "<<cliente->getfechaNacimiento()<< endl;
    return os;
}


#endif //PROYECTO_FFFFF_CLIENTE_H




