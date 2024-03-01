//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_CUENTA_H
#define PROYECTO_FFFFF_CUENTA_H
#include <iostream>
#include "Tarjeta.h"
#include <vector>
#include "util.h"
#include "Deposito.h"
#include "Prestamo.h"
using namespace std;


class Cuenta{
private:
    string numero;
    double monto;
    bool estado;
    tipoCuenta tipocuenta;
    std::vector<Deposito*>depositos;
    std::vector<Prestamo*>prestamos;
    Tarjeta *tarjeta; //puntero a una tarjeta

public:

    Cuenta(string _numero,enum::tipoCuenta _tipoCuenta,Tarjeta *tarjeta1){
        numero = _numero;
        monto = 2000;
        tipocuenta = _tipoCuenta;
        tarjeta = tarjeta1;
        estado = true; // se crea una tarjeta, su estado es activo
    }

    // numero no va a cambia, tampoco el tipo de cuenta
    // no hay setter ni getter para estos

    void setmonto(double _monto) {
        monto = _monto;
    }

    void setestado(bool _estado) {
        estado = _estado;
    }

    double getmonto() {
        return monto;
    }

    bool getestado() {
        return estado;
    }

    const string &getNumero() const {
        return numero;
    }

    enum::tipoCuenta getTipoCuenta() const {
        return tipocuenta;
    }

    Tarjeta* getTarjeta()
    {
        return tarjeta;
    }

    void setTarjeta(Tarjeta* pointer)
    {
        tarjeta = pointer;
    }
    void addDeposito(Deposito* deposito)
    {
        depositos.push_back(deposito);
    }

    void addPrestamo(Prestamo* prestamo)
    {
        if(tipocuenta == tipoCuenta::cuentaCredito)
        {
            prestamos.push_back(prestamo);
        }
    }

    vector<Deposito*> getDepositos()
    {
        return depositos;
    }

    vector<Prestamo*> getPrestamos()
    {
        return prestamos;
    }



};

ostream& operator<<(ostream& os, Cuenta* cuenta)
{
    os<<"Numero Cuenta:"<<cuenta->getNumero()<<endl;
    os<<"Estado:"<<(cuenta->getestado()?"Activa":"Inactiva")<<endl;
    os<<"Monto:"<<"S/"<<cuenta->getmonto()<<endl;
    return os;
}

#endif //PROYECTO_FFFFF_CUENTA_H
