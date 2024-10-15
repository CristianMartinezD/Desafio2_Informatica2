#include "gasolinera.h"
#include <iostream>
using namespace std;

Gasolinera::Gasolinera() {}

Gasolinera::Gasolinera(string _nombre, string _codigo, string _gerente, string _region, string _coordenadas, unsigned int _tanque[6], unsigned short _cantidaDeSurtidores)
{
    nombre = _nombre;
    codigo = _codigo;
    gerente = _gerente;
    region = _region;
    coordenadas = _coordenadas;
    tanque[0] = _tanque[0];
    tanque[1] = _tanque[1];
    tanque[2] = _tanque[2];
    tanque[3] = _tanque[3];
    tanque[4] = _tanque[4];
    tanque[5] = _tanque[5];
    capacidadDelTanque = tanque[0] + tanque[1] + tanque[2];
    TotalR = tanque[0]; TotalE = tanque[1]; TotalP = tanque[2];

    cantidaDeSurtidores = _cantidaDeSurtidores;

    for (int i = 0; i < cantidaDeSurtidores; ++i) {
        surtidores[i] = surtidor(tanque, surtidores, cantidaDeSurtidores);
    }
}

void Gasolinera::imprimir()
{
    cout<<"Nombre: "<<nombre<<"\nCodigo: "<<codigo<<"\nGerente: "<<gerente<<"\nRegion: "<<region;
    cout<<"\nCoordenadas: "<<coordenadas<<"\nRegular: "<<tanque[0]<<" Lt\nEcoExtra: "<<tanque[1]<<" Lt\nPremium: "<<tanque[2]<<" Lt";
    cout<<"\nPecios HOY:\n Regular: "<<tanque[3]<<" COP/Lt, EcoExtra: "<<tanque[4]<<" COP/Lt, Premium: "<<tanque[5]<<" COP/Lt\n\n";
}

unsigned int *Gasolinera::getTanque()
{
    return tanque;
}

string Gasolinera::getNombre()
{
    return nombre;
}

unsigned short Gasolinera::getcantidaDeSurtidores(string modificar)
{
    if (modificar == "+") ++cantidaDeSurtidores;
    if (modificar == "-") --cantidaDeSurtidores;
    return cantidaDeSurtidores;
}


surtidor *Gasolinera::getSurtidores()
{
    return surtidores;
}


void Gasolinera::liberarElTanque()
{
    liberarTanque = true;
}

unsigned long Gasolinera::actualizarTotalVentas()
{
    for (int i = 0; i < cantidaDeSurtidores; ++i){
        totalSaldoVentas += surtidores[i].getSaldoVentas("Todas");
    }
    return totalSaldoVentas;
}

void Gasolinera::historialTransaciones()
{
    string ventasDeEstaEstacion = "";
    for (int i = 0; i < cantidaDeSurtidores; ++i) {
        if (surtidores[i].getRegistroDeVentas() != "") ventasDeEstaEstacion += surtidores[i].getRegistroDeVentas() + "\n";
    }
    cout<<"\nEL HISTORIAL DE TRANSACCIONES DE LA ESTACION "<<nombre<<" ES:\n";
    if (ventasDeEstaEstacion != "") cout<<ventasDeEstaEstacion<<endl;
    else cout<<"\n  EN ESTA ESTACION NO SE HA VENDIDO NADA TODAVIA! :(\n\n";
    system("pause");
    system("cls");
}

unsigned int Gasolinera::imprimirLitrosVendidos(bool imprimir)
{
    unsigned int TotalVentasR = 0, TotalVentasE = 0, TotalVentasP = 0;
    string ventasDeEstaEstacion = "";
    for (int i = 0; i < cantidaDeSurtidores; ++i) {
        TotalVentasR += surtidores[i].getCantidadVentas("Regular");
        TotalVentasE += surtidores[i].getCantidadVentas("EcoExtra");
        TotalVentasP += surtidores[i].getCantidadVentas("Premium");
    }
    if(imprimir == true){
        cout<<"\nEN LA ESTACION "<<nombre<<" SE HA VENDIDO LA SIGUIENTE CANTIDAD DE COMBUSTIBLE:";
        cout<<"\nRegular:  "<<TotalVentasR;
        cout<<"\nEcoExtra: "<<TotalVentasE;
        cout<<"\nPremium:  "<<TotalVentasP<<endl;
        system("pause");
        system("cls");
    }
    return (TotalVentasR + TotalVentasE + TotalVentasP);
}

unsigned int Gasolinera::verCapacidadDelTanque(unsigned int nuevoValor)
{
    if(nuevoValor != 0) capacidadDelTanque = nuevoValor;
    return capacidadDelTanque;
}

void Gasolinera::detectarFugas()
{
    unsigned int TotalVentasR = 0, TotalVentasE = 0, TotalVentasP = 0;
    for (int i = 0; i < cantidaDeSurtidores; ++i) {
        TotalVentasR += surtidores[i].getCantidadVentas("Regular");
        TotalVentasE += surtidores[i].getCantidadVentas("EcoExtra");
        TotalVentasP += surtidores[i].getCantidadVentas("Premium");
    }

    cout<<"\nDETALLES SOBRE EL COMBUSTIBLE EN ESTA GASOLINERA, "<<nombre<<":\n";
    cout<<"\n Capacidad Total de Regular:......................... "<<TotalR<<" Litros";
    cout<<"\n Regular Vendido + Regular en tanque:..... "<<TotalVentasR<<" + "<<tanque[0]<<": "<<TotalVentasR + tanque[0]<<" Litros";
    cout<<"\n\n Capacidad Total de EcoExtra:........................ "<<TotalE<<" Litros";
    cout<<"\n EcoExtra Vendido + EcoExtra en tanque:... "<<TotalVentasE<<" + "<<tanque[1]<<": "<<TotalVentasE + tanque[1]<<" Litros";
    cout<<"\n\n Capacidad Total de Premium:......................... "<<TotalP<<" Litros";
    cout<<"\n Premium Vendido + Premium en tanque:...... "<<TotalVentasP<<" + "<<tanque[3]<<": "<<TotalVentasP + tanque[2]<<" Litros";

    if ((TotalVentasR + tanque[0]) < 0.95*TotalR) cout<<"\n\nLA GASOLINERA "<<nombre<<" ESTA PRESENTANDO UNA FUGA POR EL COMPARTIMENTO DEL COMBUSTIBLE REGULAR!";
    else if ((TotalVentasE + tanque[1]) < 0.95*TotalE) cout<<"\n\nLA GASOLINERA "<<nombre<<" ESTA PRESENTANDO UNA FUGA POR EL COMPARTIMENTO DEL COMBUSTIBLE EcoExtra!";
    else if ((TotalVentasP + tanque[2]) < 0.95*TotalP) cout<<"\n\nLA GASOLINERA "<<nombre<<" ESTA PRESENTANDO UNA FUGA POR EL COMPARTIMENTO DEL COMBUSTIBLE Premium!";
    else cout<<"\n\nLA GASOLINERA "<<nombre<<" NO TIENE NINGUNA FUGA DE COMBUSTIBLE!\n\n";
    system("pause");

}


Gasolinera::~Gasolinera()
{
    if (liberarTanque == true){
        delete [] tanque;
    }
}
