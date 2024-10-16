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
    codigoDeLsurtidor = "C" + to_string(40102 + (rand() % (50102 - 40102)));
    modelo = "surti" + to_string(1 + (rand() % (5)));
    if (tanque[0] == 0 && tanque[1] == 0 && tanque[2] == 0) EstadoDelSurtidor = false;
    else EstadoDelSurtidor = true;
}

surtidor::surtidor(const surtidor &Acopiar)
{
    tanque = Acopiar.tanque;
    codigoDeLsurtidor = "C" + to_string(40102 + (rand() % (50102 - 40102)));
    modelo = "surti" + to_string(1 + (rand() % (5)));
    DireccionDeSurtidores = Acopiar.DireccionDeSurtidores;
    cantidaDeSurtidores = Acopiar.cantidaDeSurtidores + 1;
    if (tanque[0] == 0 && tanque[1] == 0 && tanque[2] == 0) EstadoDelSurtidor = false;
    else EstadoDelSurtidor = true;
}

void surtidor::simularVenta(unsigned short modo, string cambiarDia)
{
    system("cls");
    bool ventaExitosa = true; unsigned int cantidad_comprada, costoT = 0;
    string  ccDelCliente, mensajeExplicion, metodoDePago, categoria, costoL = "0";

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

    string fechaYhora;
    if (cambiarDia == "si") fechaYhora = obtenerTiempo(true);
    else fechaYhora = obtenerTiempo();
    
    string EstaVenta = "\n  Surtidor que realizo la venta: " + codigoDeLsurtidor + "\n  Cliente: " + ccDelCliente + "\n  Categoria: " + categoria + "\n  Metodo De Pago: " + metodoDePago + "\n  Cantidad: " + to_string(cantidad_comprada) + " Lt\n  Costo Total: " + to_string(costoT) + " COP (" + costoL + "/Lt)";
    
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
    registroDeVentas += "\n  FECHA Y HORA: "+fechaYhora + EstaVenta + "\n";
    
    system("pause");
    system("cls");
    // Meto todo en el registroDeVentas
}

void surtidor::CambiarEstadoDelSurtidor(bool estado)
{
    EstadoDelSurtidor = estado;
}

bool surtidor::VerEstadoDelSurtidor()
{
    return EstadoDelSurtidor;
}

unsigned int surtidor::getSaldoVentas(string categoria)
{
    if (categoria == "Regular") return saldoVentasR;
    else if (categoria == "EcoExtra") return saldoVentasE;
    else if (categoria == "Premium") return saldoVentasP;
    else if (categoria == "Todas") return saldoVentasR + saldoVentasE + saldoVentasP;
    else return 0;
}

unsigned int surtidor::getCantidadVentas(string categoria)
{
    if (categoria == "Regular") return cantidadVentasR;
    else if (categoria == "EcoExtra") return cantidadVentasE;
    else if (categoria == "Premium") return cantidadVentasP;
    else if (categoria == "Todas") return cantidadVentasR + cantidadVentasE + cantidadVentasP;
    else return 0;
}

unsigned int *surtidor::getTanque()
{
    return tanque;
}

string surtidor::getcodigoDeLsurtidor()
{
    return codigoDeLsurtidor;
}

string surtidor::getRegistroDeVentas()
{
    return registroDeVentas;
}

void surtidor::imprimirAtributosDelSurtidor()
{
    cout <<"\nINFORMACION DEL SURTIDOR:";
    cout <<"\nCodigo: "<<codigoDeLsurtidor;
    cout <<"\nModelo: "<<modelo;
    if (EstadoDelSurtidor) cout <<"\nEstado: Activo";
    else cout <<"\nEstado: Desactivado";
    cout <<"\nEl tanque al que esta conectado este surtidor cuenta con:";
    cout<<"\nRegular: "<<tanque[0]<<" Lt";
    cout<<"\nRegular: "<<tanque[1]<<" Lt";
    cout<<"\nRegular: "<<tanque[2]<<" Lt"<<endl;
}

surtidor::~surtidor(){}
