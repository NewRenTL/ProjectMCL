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

    std::string generateId()
    {
        std::string nuevoId = "";
        for (int i = 0; i < 10; i++)
        {
            if (i < 5)
            {
                nuevoId += generateRandomNumber(65, 90);
            }
            else
            {
                nuevoId += to_string(generateRandomNumber(0, 9));
            }
        }

        return nuevoId;
    }

    int menu()
    {
        int num;
        cout << endl;
        cout << "----------- SERVICIOS -------------" << endl;
        cout << "1. Clientes" << endl;
        cout << "2. Cuentas de ahorro" << endl;
        cout << "3. Cuentas de credito" << endl;
        cout << "4. Prestamos de dinero" << endl;
        cout << "5. Salir" << endl;
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
        cout << "1.3 Regresar" << endl;
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
        std::cout << "Ingresa el DNI del cliente:" << std::endl;
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
                        break;
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
                cuentas.push_back(cuentaNueva);
                saveCliente->addCuenta(cuentaNueva);
                std::cout << "Cuenta Debito Generada!!" << std::endl;
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    // No diferenciara entre Activadas o desactivadas
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
                    {
                        std::cout << "Numero de Cuenta:" << saveCliente->getCuentas()[i]->getNumero() << endl;
                        std::cout << "-------------" << std::endl;
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            std::cout << saveCliente->getCuentas()[i]->getTarjeta();
                        }
                        else
                        {
                            std::cout << "La tarjeta fue Cancelada" << endl;
                        }
                        std::cout << "-------------" << std::endl;
                    }
                }

                std::string buscarTarjeta;
                std::cout << "Ingrese el numero de tarjeta a cancelar:";
                std::cin >> buscarTarjeta;
                // Busca el numero de tarjeta en las cuentas del cliente
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    // Se asegure que busque en las cuentas de ahorro
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getTarjeta()->getNumero() == buscarTarjeta)
                    {
                        // Falta añadir una condición para verificar si la tarjeta esta activa o esta eliminada

                        // Una vez la cuentra cancela la tarjeta pero no la elimina, pero deja espacio para otra tarjeta
                        std::cout << "-------------" << std::endl;
                        std::string numeroTarjetaCancelar = saveCliente->getCuentas()[i]->getTarjeta()->getNumero();
                        std::cout << "Numero de tarjeta a cancelar:" << numeroTarjetaCancelar << endl;
                        saveCliente->getCuentas()[i]->getTarjeta()->setEstado(false);
                        saveCliente->getCuentas()[i]->setTarjeta(nullptr);
                        std::cout << "La tarjeta " << numeroTarjetaCancelar << " fue cancelada" << endl;
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
                    // Verificamos que la cuenta sea de Ahorro, el numero de cuenta coincida y que la tarjeta no exista
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaBuscar && saveCliente->getCuentas()[i]->getTarjeta() == nullptr)
                    {
                        std::cout << "Generando Tarjeta..." << std::endl;
                        std::string newNumberTarjeta = generateNumberCard();
                        std::cout << "Numero de Tarjeta:" << newNumberTarjeta << endl;
                        std::string newCCV = generateCCV();
                        std::cout << "CCV:" << newCCV << std::endl;
                        std::string fechaVencimientoNueva = "02/04/2027";
                        std::cout << "Vencimiento:" << fechaVencimientoNueva << std::endl;
                        Tarjeta *tarjetaDebitoNueva = new TDebito(newNumberTarjeta, true, newCCV, fechaVencimientoNueva);
                        tarjetas.push_back(tarjetaDebitoNueva);
                        saveCliente->getCuentas()[i]->setTarjeta(tarjetaDebitoNueva);
                        std::cout << "Tarjeta Credito Generada!!" << std::endl;
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
                        // Desactivamos las tarjeta asociada a la cuenta
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            saveCliente->getCuentas()[i]->getTarjeta()->setEstado(false);
                        }
                        std::cout << "Las cuenta " << saveCliente->getCuentas()[i]->getNumero() << " fue cancelada" << endl;

                        encontradoCuenta = true;
                        break;
                    }
                }
                if (encontradoCuenta == false)
                {
                    cout << "No se encontro la cuenta de ahorro" << endl;
                }
            }
            else if (number == 6)
            {
                // Listar cuentas de ahorro
                for (int i = 0; i < cuentas.size(); i++)
                {
                    // No diferenciara en cuentas activadas o desactivadas
                    if (cuentas[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro)
                    {
                        std::cout << "---------------------" << std::endl;
                        std::cout << cuentas[i] << std::endl;
                        // Por suerte no imprimira la tarjeta, asegurandonos
                        // que no ocurra un error si la tarjeta no existe en la cuenta
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
                        // Te mostrare todas las cuenta de ahorro activas
                        if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getestado() == true)
                        {
                            std::cout << "------------------" << endl;
                            std::cout << saveCliente->getCuentas()[i] << endl;
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
                        // Verificaremos que el tipo de cuenta sea ahorro, el mismo numero y este activa
                        if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaAhorro && saveCliente->getCuentas()[i]->getNumero() == numCuentaElegida && saveCliente->getCuentas()[i]->getestado() == true)
                        {
                            // Verificaremos si hay suficiente dinero para el deposito
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
                                for (int j = 0; j < cuentas.size(); j++)
                                {
                                    // Buscamos la cuenta a depositar,tipoAhorro,mismo numero y este activa
                                    if (cuentas[j]->getTipoCuenta() == tipoCuenta::cuentaAhorro 
                                    && cuentas[j]->getNumero() == numCuentaADepositar 
                                    && cuentas[j]->getestado() == true)
                                    {
                                        std::cout << "Cuenta encontrada con exito!" << endl;

                                        // Comprobacion que encontramos una cuenta
                                        cuentaEncontrada = true;

                                        std::cout << "Depositando dinero..." << endl;
                                        std::string fechaDepositoHoy;
                                        std::cout << "Ingrese la fecha:";
                                        cin >> fechaDepositoHoy;

                                        Deposito *newDeposito = new Deposito(numCuentaElegida, numCuentaADepositar, monto_a_Depositar, fechaDepositoHoy, tipoCuenta::cuentaAhorro);

                                        // Guardo el deposito en ambas cuentas
                                        std::cout<<"Guardando Deposito"<<endl;
                                        saveCliente->getCuentas()[i]->addDeposito(newDeposito);
                                        cuentas[j]->addDeposito(newDeposito);
                                        // Guardo el deposito en el banco
                                        depositos.push_back(newDeposito);
                                        // Modifico los monto de ambas cuentas, porque se ha gastado
                                        cuentas[j]->setmonto(cuentas[j]->getmonto() + monto_a_Depositar);
                                        std::cout<<"Cuenta destino monto:"<<cuentas[i]->getmonto()<<endl;
                                        saveCliente->getCuentas()[i]->setmonto(saveCliente->getCuentas()[i]->getmonto() - monto_a_Depositar);
                                        cout<<"Cuenta de emision monto:"<<saveCliente->getCuentas()[i]->getmonto()<<endl;
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
        std::cout << "Ingresa el Dni del Cliente:";
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
            cout << "3.1 Buscar cuenta de credito" << endl;
            cout << "3.2 Crear cuenta de credito" << endl;
            cout << "3.3 Cancelar Tarjeta Credito" << endl;
            cout << "3.4 Solicitar Tarjeta Credito" << endl;
            cout << "3.5 Cancelar Cuenta de Credito" << endl;
            cout << "3.6 Solicitar todas las cuentas de credito" << endl;
            cout << "3.7 Regresar" << endl;
            cout << "-----------------------" << endl;
            cout << "Ingresa la opcion que deseas:";
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
                std::cout << "Numero de Cuenta:" << newNumberAccount << std::endl;
                std::string newNumberTarjeta = generateNumberCard();
                std::cout << "Numero de tarjeta:" << newNumberTarjeta << endl;
                std::string newCCV = generateCCV();
                std::cout << "CCV:" << newCCV << std::endl;
                std::string fechaCorte;
                std::cout << "Ingrese fecha de Corte:";
                cin >> fechaCorte;
                std::string fechaPago;
                std::cout << "Ingrese fecha de Pago:";
                cin >> fechaPago;
                // Interes por defecto del 20%
                double interes = 20;
                std::cout << "Interes:" << interes << "%" << endl;
                double limiteMonto = 20000.0;
                // Monto por defecto maxixmo de 20000.0
                std::cout << "Limite Monto:" << limiteMonto << endl;

                Tarjeta *tarjetaCreditoNueva = new TCredito(newNumberTarjeta, true, newCCV, interes, limiteMonto, fechaCorte, fechaPago);
                tarjetas.push_back(tarjetaCreditoNueva);

                Cuenta *cuentaNueva = new Cuenta(newNumberAccount, tipoCuenta::cuentaCredito, tarjetaCreditoNueva);
                cuentas.push_back(cuentaNueva);
                saveCliente->addCuenta(cuentaNueva);

                std::cout << "Cuenta Credito Generada!!" << std::endl;
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "-------------" << std::endl;
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            std::cout << saveCliente->getCuentas()[i]->getTarjeta();
                        }
                        else
                        {
                            std::cout << "La tarjeta fue Cancelada" << endl;
                        }

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
                        std::string numeroTarjetaCancelar = saveCliente->getCuentas()[i]->getTarjeta()->getNumero();

                        std::cout << "Numero de tarjeta a cancelar:" << numeroTarjetaCancelar << endl;
                        saveCliente->getCuentas()[i]->setestado(false);
                        saveCliente->getCuentas()[i]->setTarjeta(nullptr);
                        std::cout << "La tarjeta " << numeroTarjetaCancelar << " fue cancelada" << endl;
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
                        std::cout << "Numero de tarjeta:" << newNumberTarjeta << endl;
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
                        // Creamos la tarjeta de Credito
                        Tarjeta *tarjetaCreditoNueva = new TCredito(newNumberTarjeta, true, newCCV, interes, limiteMonto, fechaCorte, fechaPago);

                        // Agregar a tarjetas del banco
                        tarjetas.push_back(tarjetaCreditoNueva);

                        saveCliente->getCuentas()[i]->setTarjeta(tarjetaCreditoNueva);

                        std::cout << "Tarjeta Credito Generada!!" << std::endl;
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
                        // Desactivamos las tarjeta asociada a la cuenta
                        if (saveCliente->getCuentas()[i]->getTarjeta() != nullptr)
                        {
                            saveCliente->getCuentas()[i]->getTarjeta()->setEstado(false);
                        }
                        encontradoCuenta = true;
                        break;
                    }
                }
                if (encontradoCuenta == false)
                {
                    cout << "No se encontro la cuenta de credito" << endl;
                }
            }
            else if (number == 6)
            {
                std::cout << "Lista de cuentas:" << endl;
                for (int i = 0; i < cuentas.size(); i++)
                {
                    if (cuentas[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "---------------------" << std::endl;
                        std::cout << cuentas[i] << std::endl;
                        // Por suerte no imprimira la tarjeta, asegurandonos
                        // que no ocurra un error si la tarjeta no existe en la cuenta
                        std::cout << "---------------------" << std::endl;
                    }
                }
            }
            else if (number == 7)
            {
                cout << "Regresando" << endl;
            }
        }
        else
        {
            std::cout << "No se encontro el DNI" << std::endl;
        }
    }

    void accesoPrestamos()
    {
        std::string existDni;
        std::cout << "Ingresa el Dni del Cliente:";
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
            cout << "4.1 Crear un Prestamo" << endl;
            cout << "4.2 Cancelar Prestamo" << endl;
            cout << "4.3 Visualizar Prestamos" << endl;
            cout << "4.4 Regresar" << endl;
            cout << "-----------------------" << endl;
            cout<<"Ingrese la opcion que desee:";
            cin >> number;
            if (number == 1)
            {
                std::cout << "Lista de Cuentas Credito del cliente:" << endl;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "-------------" << std::endl;
                        std::cout << saveCliente->getCuentas()[i];
                        std::cout << "-------------" << std::endl;
                    }
                }

                // Busquemos la cuenta
                std::string nrCuenta;
                std::cout << "Ingrese el numero de cuenta:";
                cin >> nrCuenta;
                bool saveClientexist = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); ++i)
                {
                    if (saveCliente->getCuentas()[i]->getNumero() == nrCuenta && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        cout << "Cuenta Credito Encontrada!!" << endl;
                        saveClientexist = true;
                        cout << saveCliente->getCuentas()[i];
                        cout << "Agregando Prestamo..." << endl;

                        string fechaPrestamo;
                        cout << "Ingrese fecha del prestamo:";
                        cin >> fechaPrestamo;
                        double monto;
                        cout << "Ingresa monto del prestamo:";
                        cin >> monto;
                        int numerocuotas;
                        cout << "Ingreso el numero de cuotas:";
                        cin >> numerocuotas;
                        // El interes debe ser el mismo de la cuenta de credito
                        float interes = 20;
                        cout << "Interes:" << interes << "%" << endl;
                        string idgeneradoPrestamo = generateId();
                        Prestamo *nuevoPrestamo = new Prestamo(idgeneradoPrestamo, fechaPrestamo, monto, numerocuotas, interes, true);
                        // Guardamos en la cuenta el prestamo
                        saveCliente->getCuentas()[i]->addPrestamo(nuevoPrestamo);
                        // Sumamos el monto prestado + el monto de la cuenta inicial
                        saveCliente->getCuentas()[i]->setmonto(saveCliente->getCuentas()[i]->getmonto() + nuevoPrestamo->getmonto());
                        // Guardamos en el banco el prestamo
                        prestamos.push_back(nuevoPrestamo);
                        cout << "Prestamo generado con el ID:" << idgeneradoPrestamo << endl;
                        break;
                    }
                }
                if (saveClientexist == false)
                {
                    std::cout << "La cuenta credito no existe" << endl;
                }
            }
            else if (number == 2)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getestado() == true && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "Numero de Cuenta Credito:" << saveCliente->getCuentas()[i]->getNumero() << endl;
                    }
                }

                string buscarNumCredito;
                cout << "Ingresa un numero de cuenta credito:";
                cin >> buscarNumCredito;
                bool existeCuentaCredito = false;
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getestado() == true && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito && saveCliente->getCuentas()[i]->getNumero() == buscarNumCredito)
                    {
                        existeCuentaCredito = true;
                        std::cout << "Numero de Cuenta Credito:" << saveCliente->getCuentas()[i]->getNumero() << endl;
                        vector<Prestamo *> capturarPrestamos = saveCliente->getCuentas()[i]->getPrestamos();
                        for (int j = 0; j < capturarPrestamos.size(); j++)
                        {

                            if (capturarPrestamos[j]->getestadoPrestamo() == true)
                            {
                                cout << "------------------------" << endl;
                                cout << "ID Prestamo:" << capturarPrestamos[j]->getId() << endl;
                                cout << "Estado:" << (capturarPrestamos[j]->getestadoPrestamo() ? "Activo" : "Inactivo");
                                cout << "------------------------" << endl;
                            }
                        }

                        string idPrestamoCancelar;
                        cout << "Ingrese el ID del prestamo a cancelar:";
                        cin >> idPrestamoCancelar;
                        bool existIdPrestamo = false;
                        for (int i = 0; i < capturarPrestamos.size(); i++)
                        {
                            if (capturarPrestamos[i]->getId() == idPrestamoCancelar && capturarPrestamos[i]->getestadoPrestamo() == true)
                            {
                                existIdPrestamo = true;
                                capturarPrestamos[i]->setestadoPrestamo(false);
                                std::cout << "Prestamo Id:" << capturarPrestamos[i]->getId() << endl;
                                std::cout << "Estado:" << (capturarPrestamos[i]->getestadoPrestamo() ? "Activo" : "Inactivo");
                                break;
                            }
                            if (capturarPrestamos[i]->getId() == idPrestamoCancelar && capturarPrestamos[i]->getestadoPrestamo() == false)
                            {
                                existIdPrestamo = true;
                                std::cout << "Prestamo Id:" << capturarPrestamos[i]->getId() << endl;
                                std::cout << "Estado:" << (capturarPrestamos[i]->getestadoPrestamo() ? "Activo" : "Inactivo");
                                break;
                            }
                        }
                        if (existIdPrestamo == false)
                        {
                            std::cout << "No se encontro el prestamo por el ID" << endl;
                        }
                    }
                }
                if (existeCuentaCredito == false)
                {
                    cout << "No se encontro la cuenta credito" << endl;
                }
            }
            else if (number == 3)
            {
                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getestado() == true && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito)
                    {
                        std::cout << "Numero de Cuenta:" << saveCliente->getCuentas()[i]->getNumero() << endl;
                    }
                }
                string buscarNumCredito;
                cout << "Ingresa un numero de cuenta credito:";
                cin >> buscarNumCredito;
                bool existeCuentaCredito = false;

                for (int i = 0; i < saveCliente->getCuentas().size(); i++)
                {
                    if (saveCliente->getCuentas()[i]->getestado() == true && saveCliente->getCuentas()[i]->getTipoCuenta() == tipoCuenta::cuentaCredito && saveCliente->getCuentas()[i]->getNumero() == buscarNumCredito)
                    {
                        existeCuentaCredito = true;
                        std::cout << "Numero de Cuenta:" << saveCliente->getCuentas()[i]->getNumero() <<"  Monto:"<<saveCliente->getCuentas()[i]->getmonto()<<" Estado:"<<(saveCliente->getCuentas()[i]->getestado()?"Activa":"Inactiva")<<endl;
                        vector<Prestamo*> capturarPrestamos = saveCliente->getCuentas()[i]->getPrestamos();
                        for (int j = 0; j < capturarPrestamos.size(); j++)
                        {
                            cout << "------------------------" << endl;
                            cout << "Fecha        "<<"Monto     "<<"Nro  "<<"Cuota   "<<"Interes    "<<"Estado  "<<endl;
                            cout<< capturarPrestamos[j]->getfechaPrestamo()
                            <<"   "<<capturarPrestamos[j]->getmonto()
                            <<"     "<<capturarPrestamos[j]->getnumeroCuotas()
                            <<"    "<<capturarPrestamos[j]->getprecioCuota()
                            <<"      "<<capturarPrestamos[j]->getinteres()
                            <<"        "<<(capturarPrestamos[j]->getestadoPrestamo()?"Activo":"Inactivo")<<endl;
                            //cout << "ID Prestamo:" << capturarPrestamos[j]->getId() << endl;
                            //cout << "Estado:" << (capturarPrestamos[j]->getestadoPrestamo() ? "Activo" : "Inactivo")<<endl;
                            cout << "------------------------" << endl;
                        }
                        break;
                    }
                }
                if (existeCuentaCredito == false)
                {
                    cout << "No se encontro la cuenta credito" << endl;
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
        while (opcion != 5)
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
            case 4:
                accesoPrestamos();
                break;
            }
        }
        cout << "Gracias por su visita. Tenga un buen dia. " << endl;
    }
};
#endif // PROYECTO_FFFFF_SISTEMABANCO_H