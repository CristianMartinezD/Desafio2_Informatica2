#include "surtidor.h"
#include <iostream>
#include <chrono>   // Para chrono::milliseconds
#include <thread>   // Para this_thread::sleep_for
#include "funciones.h"
using namespace std;

surtidor::surtidor()
{
    
}

surtidor::surtidor(unsigned int* DireccionTanque, surtidor *_DireccionDeSurtidores, unsigned short _cantidaDeSurtidores) {
    tanque = DireccionTanque;
    DireccionDeSurtidores = _DireccionDeSurtidores;
    cantidaDeSurtidores = _cantidaDeSurtidores;
    if (tanque[0] == 0 && tanque[1] == 0 && tanque[2] == 0) surtidorActivo = false;
    else surtidorActivo = true;
}

void surtidor::simularVenta()
{
    system("cls");
    bool ventaExitosa = true; unsigned int cantidad_comprada, costoT = 0, modo;
    string  ccDelCliente, mensajeExplicion, metodoDePago, categoria, costoL = "0";

    cout<<"\nQuieres digitar la informacion del cliente, o deseas que sea generada automaticamente?";
    cout<<"\n1. Yo la digito\n2. Automatico\nElige 1 o 2: "; cin>>modo;
    if (modo == 1) pedir_datos_del_client(ccDelCliente, cantidad_comprada, metodoDePago, categoria);
    else {
    ccDelCliente = to_string(1010250435 + (rand() % (1010264538 - 1010250435)));
    cantidad_comprada = 3 + (rand() % (21 - 3));
    metodoDePago = to_string(1 + (rand() % (3)));
    categoria = to_string(1 + (rand() % (3)));
    }

    if (metodoDePago == "1") {
        metodoDePago = "Efectivo";
    }
    else if (metodoDePago == "2") {
        metodoDePago = "TCredito";
    }
    else {
        metodoDePago = "TDebito";
    }
    
    
    if (categoria == "1") {
        categoria = "Regular";
        if (cantidad_comprada <= tanque[0] && tanque[0] > 0){
            tanque[0] = tanque[0] - cantidad_comprada;
            cantidadVentasR += cantidad_comprada;
            costoL = to_string(tanque[3]);
            costoT = cantidad_comprada * tanque[3];
            saldoVentasR += costoT;
            cout<<"El precio del Regular es: "<<tanque[3]<<endl;
        }
        else if(cantidad_comprada > tanque[0] && tanque[0] > 0){
            cantidad_comprada = tanque[0];
            tanque[0] = 0;
            cantidadVentasR += cantidad_comprada;
            costoL = to_string(tanque[3]);
            costoT = cantidad_comprada * tanque[3];
            saldoVentasR += costoT;
        }
        else {
            mensajeExplicion = "\nLO SENTIMOS, SE AGOTO EL COMBUSTIBLE Regular!";
            ventaExitosa = false;
        }
        
    }
    if (categoria == "2") {
        categoria = "EcoExtra";
        if (cantidad_comprada <= tanque[1] && tanque[1] > 0){
            tanque[1] = tanque[1] - cantidad_comprada;
            cantidadVentasE += cantidad_comprada;
            costoL = to_string(tanque[4]);
            costoT = cantidad_comprada * tanque[4];
            saldoVentasE += costoT;
        }
        else if(cantidad_comprada > tanque[1] && tanque[1] > 0){
            cantidad_comprada = tanque[1];
            tanque[1] = 0;
            cantidadVentasE += cantidad_comprada;
            costoL = to_string(tanque[4]);
            costoT = cantidad_comprada * tanque[4];
            saldoVentasE += costoT;
        }
        else {
            mensajeExplicion = "\nLO SENTIMOS, SE AGOTO EL COMBUSTIBLE EcoExtra!";
            ventaExitosa = false;
        }
    }
    if (categoria == "3") {
        categoria = "Premium";
        if (cantidad_comprada <= tanque[2] && tanque[2] > 0){
            tanque[2] = tanque[2] - cantidad_comprada;
            cantidadVentasP += cantidad_comprada;
            costoL = to_string(tanque[5]);
            costoT = cantidad_comprada * tanque[5];
            saldoVentasP += costoT;
        }
        else if(cantidad_comprada > tanque[2] && tanque[2] > 0){
            cantidad_comprada = tanque[2];
            tanque[2] = 0;
            cantidadVentasP += cantidad_comprada;
            costoL = to_string(tanque[5]);
            costoT = cantidad_comprada * tanque[5];
            saldoVentasP += costoT;
        }
        else {
            mensajeExplicion = "\nLO SENTIMOS, SE AGOTO EL COMBUSTIBLE Premium!";
            ventaExitosa = false;
        }
    }


    // Obtenemos la fecha y hora actual
    time_t tiempo_actual = time(nullptr);
    tm* tiempo_local = localtime(&tiempo_actual);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", tiempo_local);
    string fechaYhora = buffer;
    
    string EstaVenta = "\n  Cliente: " + ccDelCliente + "\n  Categoria: " + categoria + "\n  Metodo De Pago: " + metodoDePago + "\n  Cantidad: " + to_string(cantidad_comprada) + " Lt\n  Costo Total: " + to_string(costoT) + " COP (" + costoL + "/Lt Hoy)";
    
    cout << "\nFECHA Y HORA: "+fechaYhora<<"\n\n      RESUMEN DE LA VENTA:";
    // DECORACION
    for (char c : EstaVenta) {
        cout << c << flush;  // Imprime un carácter y fuerza el vaciado del buffer
        this_thread::sleep_for(chrono::milliseconds(20));  // Espera 100 mileSegundos
    }

    if (ventaExitosa) cout << "\n\nVENTA REALIZADA EXITOSAMENTE!\n\n";
    else {
        cout << mensajeExplicion << "\n\nLA VENTA NO SE PUDO REALIZAR\n\n";

        if (tanque[0] == 0 && tanque[1] == 0 && tanque[2] == 0){
            for (unsigned short i = 0; i < cantidaDeSurtidores; ++i){
                DireccionDeSurtidores[i].CambiarEstadoDelSurtidor(false);
            }
            cout << "\n\nEL TANQUE DE ESTA GASOLINERA HA QUEDADO VACIO, POR LO CUAL TODOS LOS SURTIDORES HAN SIDO DESACTIVADOS!\n\n";
        }
    }
    
    system("pause");
    system("cls");
    // Meto todo en el registroDeVentas
}

void surtidor::CambiarEstadoDelSurtidor(bool estado)
{
    surtidorActivo = estado;
}

unsigned int surtidor::getVentas(string categoria)
{
    if (categoria == "Regular") return saldoVentasR;
    else if (categoria == "EcoExtra") return saldoVentasE;
    else if (categoria == "Premium") return saldoVentasP;
    else return 0;
}

unsigned int *surtidor::getTanque()
{
    return tanque;
}

surtidor::~surtidor(){}
