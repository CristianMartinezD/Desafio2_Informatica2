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
    unsigned long int totalSaldoVentas = 0;
    unsigned long int loQueQuedaEnElTanque = 0;
    unsigned int capacidadDelTanque; float TotalR, TotalE, TotalP;

    string nombre, codigo, gerente, region, coordenadas;
    unsigned int* tanque = new unsigned int [6];
    bool liberarTanque = false;
public:
    Gasolinera();
    Gasolinera(string nombre, string _codigo, string _gerente, string _region, string _coordenadas, unsigned int _tanque[6], unsigned short _cantidaDeSurtidores);
    void imprimir();
    unsigned int* getTanque();
    string getNombre();
    unsigned short getcantidaDeSurtidores(string modificar = "NO");
    void liberarElTanque();
    unsigned long int actualizarTotalVentas();
    void historialTransaciones();
    unsigned int imprimirLitrosVendidos(bool imprimir = true);
    unsigned int verCapacidadDelTanque(unsigned int nuevoValor = 0);
    void detectarFugas();

    surtidor* getSurtidores();
    ~Gasolinera();
};

#endif // GASOLINERA_H
