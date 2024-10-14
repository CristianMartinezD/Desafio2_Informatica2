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
    cantidaDeSurtidores = _cantidaDeSurtidores;
    cout<<"\nCantidad de surtidores: "<<_cantidaDeSurtidores<<endl;
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

unsigned int *Gasolinera::retornarTanque()
{
    return tanque;
}

string Gasolinera::getNombre()
{
    return nombre;
}

unsigned short Gasolinera::getcantidaDeSurtidores()
{
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


Gasolinera::~Gasolinera()
{
    if (liberarTanque == true){
        delete [] tanque;
        cout<<"\nTanque Liberado\n";
        system("pause");
    }
    cout<<"\nLlamando al destructor de la gasolinera\n";
}
