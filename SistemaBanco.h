//
// Created by lenovo on 27/02/2024.
//

#ifndef PROYECTO_FFFFF_SISTEMABANCO_H
#define PROYECTO_FFFFF_SISTEMABANCO_H

// no incluimos tarjeta porque esta dentro de clientes y TCredito y TDebito a están dentro de tarjeta
#include "Cuenta.h"
#include "Prestamo.h"
#include "Cliente.h"
#include <iostream>
#include "TDebito.h"
#include "TCredito.h"
#include "util.h"
#include <regex>
using namespace std;

class SistemaBanco
{
private:
    vector<Prestamo *> prestamos;
    vector<Cliente *> clientes;
    vector<Cuenta *> cuentas;
    vector<Tarjeta *> tarjetas;
    vector<Deposito *> depositos;

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
        cout << "3. Cuentas de credito" << endl;
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
        cout << "1.4 Listar servicios de cliente" << endl;
        cout << "1.5 Regresar" << endl;
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
            cout << "1.7 Realizar un deposito" << endl;
            cout << "1.8 Regresar" << endl;
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
                    if (saveCliente->getCuentas()[i]->getNumero() == nrCuenta && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
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
                Cuenta *cuentaNueva = new Cuenta(newNumberAccount, tipoCuenta::cuentaAhorro, tarjetaDebitoNueva);
                saveCliente->addCuenta(cuentaNueva);
                std::cout << "Cuenta Generada!!" << std::endl;
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
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
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getTarjeta()->getNumero() == buscarTarjeta)
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
            else if (number == 4)
            {

                std::string numCuentaBuscar;
                std::cout << "Ingresa su numero de cuenta:";
                cin >> numCuentaBuscar;
                bool exito = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaBuscar && saveCliente->getCuentas()[i]->getTarjeta() == nullptr)
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
                if (exito == false)
                {
                    std::cout << "Numero de cuenta no encontrado o cuenta con tarjeta ya existente" << std::endl;
                }
            }
            else if (number == 5)
            {
                std::string numeroCuentaBuscar;
                std::cout << "Ingresa el numero de cuenta de ahorro:";
                std::cin >> numeroCuentaBuscar;
                bool encontradoCuenta = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getNumero() == numeroCuentaBuscar && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
                    {
                        // Desactivamos la cuenta
                        saveCliente->getCuentas()[i]->setestado(false);
                        // Desactivamos las tarjetas asociadas a la cuenta
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            saveCliente->getCuentas()[i]->getTarjeta()->setEstado(false);
                        }
                        encontradoCuenta = true;
                        break;
                    }
                }
                if(encontradoCuenta == false)
                {
                    cout<<"No se encontro la cuenta de ahorro"<<endl;
                }
            }
            else if (number == 6)
            {
                // Listar cuentas de ahorro
                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
                    {
                        std::cout << "---------------------" << std::endl;
                        std::cout << cuentas[i] << std::endl;
                        std::cout << "---------------------" << std::endl;
                    }
                }
            }
            else if (number == 7)
            {
                double monto_a_Depositar;
                cout << "Cual es el monto a depositar:";
                cin >> monto_a_Depositar;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
                    {
                        std::cout << "------------------" << endl;
                        std::cout << cuentas[i] << endl;
                        std::cout << "------------------" << endl;
                    }
                }
                // Cuenta del cliente que elegira para depositar
                std::string numCuentaElegida;
                std::cout << "Ingrese su numero cuenta que elegira para depositar";
                cin >> numCuentaElegida;
                bool cuentaClienteeligdaexiste = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaElegida)
                    {
                        if (saveCliente->getCuentas()[i]->getmonto() < monto_a_Depositar)
                        {
                            std::cout << "La cantidad de dinero en la cuenta no es suficiente" << endl;
                        }
                        if (saveCliente->getCuentas()[i]->getmonto() >= monto_a_Depositar)
                        {
                            // Si tiene suficiente dinero
                            std::string numCuentaADepositar;
                            std::cout << "Ingrese el numero de cuenta que desea depositar:";
                            cin >> numCuentaADepositar;
                            bool cuentaEncontrada = false;
                            for (int i = 0; i < cuentas.size(); i++)
                            {
                                if (cuentas[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && cuentas[i]->getNumero() == numCuentaADepositar)
                                {
                                    std::cout << "Cuenta encontrada con exito!" << endl;

                                    cuentaEncontrada = true;

                                    std::cout << "Depositando dinero..." << endl;
                                    std::string fechaDepositoHoy;
                                    std::cout << "Ingrese la fecha:";
                                    cin >> fechaDepositoHoy;
                                    Deposito *newDeposito = new Deposito(numCuentaElegida, numCuentaADepositar, monto_a_Depositar, fechaDepositoHoy, tipoCuenta::cuentaAhorro);

                                    // Guardo el deposito en ambas cuentas
                                    saveCliente->getCuentas()[i]->addDeposito(newDeposito);
                                    cuentas[i]->addDeposito(newDeposito);
                                    // Guardo el deposito en el banco
                                    depositos.push_back(newDeposito);
                                    // Modifico los monto de ambas cuentas, porque se ha gastado
                                    cuentas[i]->setmonto(cuentas[i]->getmonto() + monto_a_Depositar);
                                    saveCliente->getCuentas()[i]->setmonto(saveCliente->getCuentas()[i]->getmonto() - monto_a_Depositar);
                                    break;
                                }
                            }
                            if (cuentaEncontrada == false)
                            {
                                std::cout << "Ingreso una cuenta ahorro destino inexistente" << endl;
                            }
                        }
                        cuentaClienteeligdaexiste = true;
                        break;
                    }
                }
                if (cuentaClienteeligdaexiste == false)
                {
                    std::cout << "La cuenta de ahorro del cliente ingresada no existe" << endl;
                }
            }
            else if (number == 8)
            {
                std::cout << "Regresando" << endl;
            }
        }
        else
        {
            std::cout << "No se encontro el DNI" << std::endl;
        }
    }

    void accesoCuentasCredito()
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
            cout << "1.1 Buscar cuenta de credito" << endl;
            cout << "1.2 Crear cuenta de credito" << endl;
            cout << "1.3 Cancelar Tarjeta Credito" << endl;
            cout << "1.4 Solicitar Tarjeta Credito" << endl;
            cout << "1.5 Cancelar Cuenta de Credito" << endl;
            cout << "1.6 Solicitar todas las cuentas de credito" << endl;
            cout << "1.7 Regresar" << endl;
            cout << "-----------------------" << endl;
            cin >> number;
            if (number == 1)
            {
                std::string nrCuenta;
                std::cout << "Ingrese el numero de cuenta:";
                cin >> nrCuenta;
                bool saveClientexist = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); ++i)
                {
                    if (saveCliente->getCuentas()[i]->getNumero() == nrCuenta && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        saveClientexist = true;
                        std::cout << saveCliente->getCuentas()[i];
                    }
                    if (saveClientexist == false)
                    {
                        std::cout << "La cuenta no existe" << endl;
                    }
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
                std::string fechaCorte;
                std::cout << "Ingrese fecha de Corte:";
                cin >> fechaCorte;
                std::string fechaPago;
                std::cout << "Ingrese fecha de Pago:";
                cin >> fechaPago;
                double interes = 20;
                std::cout << "Interes:" << interes << "%" << endl;
                double limiteMonto = 20000.0;
                std::cout << "Limite Monto:" << limiteMonto << endl;
                Tarjeta *tarjetaCreditoNueva = new TCredito(newNumberTarjeta, true, newCCV, interes, limiteMonto, fechaCorte, fechaPago);
                tarjetas.push_back(tarjetaCreditoNueva);
                Cuenta *cuentaNueva = new Cuenta(newNumberAccount, tipoCuenta::cuentaCredito, tarjetaCreditoNueva);
                saveCliente->addCuenta(cuentaNueva);
                std::cout << "Cuenta Generada!!" << std::endl;
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
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
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito && saveCliente->getCuentas()[i]->getTarjeta()->getNumero() == buscarTarjeta)
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
            else if (number == 4)
            {
                std::string numCuentaBuscar;
                std::cout << "Ingresa su numero de cuenta:";
                cin >> numCuentaBuscar;
                bool exito = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaBuscar && saveCliente->getCuentas()[i]->getTarjeta() == nullptr)
                    {
                        std::cout << "Generando Tarjeta..." << std::endl;
                        std::string newNumberTarjeta = generateNumberCard();
                        std::string newCCV = generateCCV();
                        std::cout << "CCV:" << newCCV << std::endl;
                        std::string fechaCorte;
                        std::cout << "Ingrese fecha de Corte:";
                        cin >> fechaCorte;
                        std::string fechaPago;
                        std::cout << "Ingrese fecha de Pago:";
                        cin >> fechaPago;
                        double interes = 20;
                        std::cout << "Interes:" << interes << "%" << endl;
                        double limiteMonto = 20000.0;
                        std::cout << "Limite Monto:" << limiteMonto << endl;
                        Tarjeta *tarjetaCreditoNueva = new TCredito(newNumberTarjeta, true, newCCV, interes, limiteMonto, fechaCorte, fechaPago);
                        tarjetas.push_back(tarjetaCreditoNueva);
                        saveCliente->getCuentas()[i]->setTarjeta(tarjetaCreditoNueva);
                        std::cout << "Tarjeta Generada!!" << std::endl;
                        exito = true;
                        break;
                    }
                }
                if (exito == false)
                {
                    std::cout << "Numero de cuenta no encontrado o cuenta con tarjeta ya existente" << std::endl;
                }
            }
            else if (number == 5)
            {
                std::string numeroCuentaBuscar;
                std::cout << "Ingresa el numero de cuenta de credito:";
                std::cin >> numeroCuentaBuscar;
                bool encontradoCuenta = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getNumero() == numeroCuentaBuscar && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        // Desactivamos la cuenta
                        saveCliente->getCuentas()[i]->setestado(false);
                        // Desactivamos las tarjetas asociadas a la cuenta
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            saveCliente->getCuentas()[i]->getTarjeta()->setEstado(false);
                        }
                        encontradoCuenta = true;
                        break;
                    }
                }
                if(encontradoCuenta == false)
                {
                    cout<<"No se encontro la cuenta de credito"<<endl;
                }
            }
            else if (number == 6)
            {
                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "---------------------" << std::endl;
                        std::cout << cuentas[i] << std::endl;
                        std::cout << "---------------------" << std::endl;
                    }
                }
            }
            else if(number == 7)
            {
                cout<<"Regresando"<<endl;
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
                accesoCuentasAhorro();
                break;
            case 3:
                accesoCuentasCredito();
                break;
            }
        }
        cout << "Gracias por su visita. Tenga un buen dia. " << endl;
    }
};
#endif // PROYECTO_FFFFF_SISTEMABANCO_H