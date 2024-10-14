#ifndef GASOLINERA_H
#define GASOLINERA_H
#include <string>
#include "surtidor.h"
using namespace std;

class Gasolinera
{
private:
    surtidor surtidores [12];
    unsigned short cantidaDeSurtidores;

    string nombre, codigo, gerente, region, coordenadas;
    unsigned int* tanque = new unsigned int [6];
    bool liberarTanque = false;
public:
    Gasolinera();
    Gasolinera(string nombre, string _codigo, string _gerente, string _region, string _coordenadas, unsigned int _tanque[6], unsigned short _cantidaDeSurtidores);
    void imprimir();
    unsigned int* retornarTanque();
    string getNombre();
    unsigned short getcantidaDeSurtidores();
    void liberarElTanque();

    surtidor* getSurtidores();
    ~Gasolinera();
};

#endif // GASOLINERA_H
