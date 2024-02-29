//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_SISTEMABANCO_H
#define PROYECTO_FFFFF_SISTEMABANCO_H

#endif // PROYECTO_FFFFF_SISTEMABANCO_H

// no incluimos tarjeta porque esta dentro de clientes y TCredito y TDebito a están dentro de tarjeta
#include "Cuenta.h"
#include "Prestamo.h"
#include "Cliente.h"
#include <iostream>
#include "TDebito.h"
#include <regex>
using namespace std;

class SistemaBanco
{
private:
    vector<Prestamo *> prestamos;
    vector<Cliente *> clientes;
    vector<Cuenta *> cuentas;
    vector<Tarjeta *> tarjetas;

private: // crearemos metodo de apoyo, porque el metodo de apoyo nos ayuda a optimizar procesos dentro de las funciones publicas
    // o sea el usuario no puede utilizar estos metodos

    int generateRandomNumber(int minValue, int maxValue)
    {
        return minValue + rand() % (maxValue - minValue + 1);
    }

    std::string generateNumberCard()
    {
        std::string newNumber = "";
        for (size_t i = 0; i < 16; i++)
        {
            if (i % 4 == 0 && i != 0)
            {
                newNumber += '-';
            }
            newNumber += std::to_string(generateRandomNumber(0, 9));
        }
        return newNumber;
    }

    std::string generateNumberAccount()
    {
        std::string newNumber = "";
        for (int i = 0; i < 10; i++)
        {
            newNumber += std::to_string(generateRandomNumber(0, 9));
            if (i == 3)
            {
                newNumber += "-";
            }
        }
        return newNumber;
    }

    std::string generateCCV()
    {
        std::string newccv = "";
        for (int i = 0; i < 3; i++)
        {
            newccv += std::to_string(generateRandomNumber(0, 9));
        }
        return newccv;
    }

    int menu()
    {
        int num;
        cout << endl;
        cout << "----------- SERVICIOS -------------" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Cuentas de ahorro" << endl;
        cout << "3. Prestamos de dinero" << endl;
        cout << "4. Salir" << endl;
        cout << "-----------------------" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> num;
        return num;
    }
    void accesoCliente()
    {
        int num;
        cout << "-----------------------" << endl;
        cout << "1.1 Buscar cliente" << endl;
        cout << "1.2 Agregar cliente" << endl;
        cout << "1.3 Eliminar cliente" << endl;
        cout << "1.4 Regresar" << endl;
        cout << "-----------------------" << endl;
        cout << "Ingresa tu opcion: ";
        cin >> num;
        if (num == 1)
        {

            string DNIbuscar;
            cout << "Ingrese el DNI a buscar: ";
            cin >> DNIbuscar;
            bool seencontro = false;

            for (int i = 0; i < clientes.size(); i++) // vector de punteros a clientes
            {
                if (clientes[i]->getDni() == DNIbuscar)

                {
                    cout << clientes[i]; // SOBRECARGA a "<<"
                    seencontro = true;
                    break;
                }
            }

            if (seencontro == false)
            {
                cout << "No se encontro el DNI" << endl;
            }
        }
        else if (num == 2)
        {

            regex isDate("([0-2][0-9]|3[0-1])/(0[1-9]|1[0-2])/([0-9]{4})");

            string nuevoDNI;
            string nuevoNombreCompleto;
            string fechaNacimiento = "";

            cout << "Ingrese su DNI: ";
            cin >> nuevoDNI;
            cin.ignore();

            cout << "Ingresa tu nombre completo: ";
            getline(cin, nuevoNombreCompleto);

            cout << "Ingrese su fecha de nacimiento: ";
            cin >> fechaNacimiento;
            while (regex_match(fechaNacimiento, isDate) == false)
            { // string           //patron
                cout << "Ingrese su fecha de nacimiento: ";
                cin >> fechaNacimiento;
            }

            Cliente *newCliente = new Cliente(nuevoDNI, nuevoNombreCompleto, fechaNacimiento);
            clientes.push_back(newCliente);
            cout << "¡Usuario agregado exitosamente!" << endl
                 << endl;
        }
    }

    void accesoCuentasAhorro()
    {
        std::string existDni;
        std::cout << "Enter a DNI to associate for client:" << std::endl;
        std::cin >> existDni;
        Cliente *saveCliente;
        bool existsDniBool = false;
        for (int i = 0; i < clientes.size(); ++i)
        {
            if (existDni == clientes[i]->getDni())
            {
                saveCliente = clientes[i];
                existsDniBool = true;
            }
        }
        if (existsDniBool == true)
        {
            int number;
            cout << "-----------------------" << endl;
            cout << "1.1 Buscar cuenta de ahorro" << endl;
            cout << "1.2 Crear cuenta de ahorro" << endl;
            cout << "1.3 Cancelar Tarjeta Debito" << endl;
            cout << "1.4 Solicitar Tarjeta Debito" << endl;
            cout << "1.5 Cancelar Cuenta de Ahorro" << endl;
            cout << "1.6 Solicitar todas las cuentas de ahorro" << endl;
            cout << "1.7 Regresar" << endl;
            std::cout << "Ingresar una opcion:";
            cin >> number;
            if (number == 1)
            {
                std::string nrCuenta;
                std::cout << "Ingrese el numero de cuenta:";
                cin >> nrCuenta;
                bool saveClientexist = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); ++i)
                {
                    if (saveCliente->getCuentas()[i]->getNumero() == nrCuenta)
                    {
                        saveClientexist = true;
                        std::cout << saveCliente->getCuentas()[i];
                    }
                }
                if (saveClientexist == false)
                {
                    std::cout << "La cuenta no existe" << endl;
                }
            }
            else if (number == 2)
            {
                std::cout << "Generando Cuenta..." << std::endl;
                std::string newNumberAccount = generateNumberAccount();
                std::string newNumberTarjeta = generateNumberCard();
                std::cout << "Numero de Cuenta:" << newNumberAccount << std::endl;
                std::string newCCV = generateCCV();
                std::cout << "CCV:" << newCCV << std::endl;
                std::string fechaVencimientoNueva = "02/04/2027";
                std::cout << "Vencimiento:" << fechaVencimientoNueva << std::endl;
                Tarjeta *tarjetaDebitoNueva = new TDebito(newNumberTarjeta, true, newCCV, fechaVencimientoNueva);
                tarjetas.push_back(tarjetaDebitoNueva);
                Cuenta *cuentaNueva = new Cuenta(newNumberAccount, cuentaAhorro, tarjetaDebitoNueva);
                saveCliente->addCuenta(cuentaNueva);
                std::cout << "Cuenta Generada!!" << std::endl;
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == cuentaAhorro)
                    {
                        std::cout << "-------------" << std::endl;
                        std::cout << saveCliente->getCuentas()[i]->getTarjeta();
                        std::cout << "-------------" << std::endl;
                    }
                }
                std::string buscarTarjeta;
                std::cout << "Ingrese el numero de tarjeta a cancelar:";
                std::cin >> buscarTarjeta;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == cuentaAhorro && saveCliente->getCuentas()[i]->getTarjeta()->getNumero() == buscarTarjeta)
                    {
                        std::cout << "-------------" << std::endl;
                        std::cout << saveCliente->getCuentas()[i]->getTarjeta();
                        saveCliente->getCuentas()[i]->setestado(false);
                        saveCliente->getCuentas()[i]->setTarjeta(nullptr);
                        std::cout << "-------------" << std::endl;
                        break;
                    }
                }
            }
            else if ()
            {

                std::string numCuentaBuscar;
                std::cout << "Ingresa su numero de cuenta:";
                cin>>numCuentaBuscar;
                bool exito = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaBuscar && saveCliente->getCuentas()[i]->getTarjeta() == nullptr)
                    {
                        std::cout << "Generando Tarjeta..." << std::endl;
                        std::string newNumberTarjeta = generateNumberCard();
                        std::string newCCV = generateCCV();
                        std::cout << "CCV:" << newCCV << std::endl;
                        std::string fechaVencimientoNueva = "02/04/2027";
                        std::cout << "Vencimiento:" << fechaVencimientoNueva << std::endl;
                        Tarjeta *tarjetaDebitoNueva = new TDebito(newNumberTarjeta, true, newCCV, fechaVencimientoNueva);
                        tarjetas.push_back(tarjetaDebitoNueva);
                        saveCliente->getCuentas()[i]->setTarjeta(tarjetaDebitoNueva);
                        std::cout << "Tarjeta Generada!!" << std::endl;
                        exito = true;
                        break;
                    }
                }
                if(exito == false)
                {
                    std::cout<<"Numero de cuenta no encontrado o cuenta con tarjeta ya existente"<<std::endl;
                }
            }
        }
        else
        {
            std::cout << "No se encontro el DNI" << std::endl;
        }
    }

public:
    // creamos constructor vacio;
    SistemaBanco(){};

    void iniciarSistema()
    {

        int opcion = 0;
        while (opcion != 4)
        {
            opcion = menu();
            switch (opcion)
            {
            case 1:
                accesoCliente();
                break;
            case 2:
                accesoCliente();
                break;
            case 3:
                accesoCliente();
                break;
            }
        }
        cout << "Gracias por su visita. Tenga un buen dia. " << endl;
    }
};
