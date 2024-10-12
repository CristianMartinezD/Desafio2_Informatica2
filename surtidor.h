#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <string>
using namespace std;

class surtidor
{
private:
    unsigned int* tanque;
    string codigoDeLsurtidor, modelo, registroDeVentas = "";
    unsigned int cantidadVentasR = 0, cantidadVentasE = 0, cantidadVentasP = 0, saldoVentasR = 0, saldoVentasE = 0, saldoVentasP = 0;
    bool surtidorActivo;
    surtidor* DireccionDeSurtidores;
    unsigned short cantidaDeSurtidores;
public:
    surtidor();

    surtidor(unsigned int* DireccionTanque, surtidor* _DireccionDeSurtidores, unsigned short _cantidaDeSurtidores);

    void simularVenta();
    void CambiarEstadoDelSurtidor(bool estado);
    unsigned int getVentas(string categoria);
    unsigned int* getTanque();

    ~surtidor();
};

#endif // SURTIDOR_H
