#ifndef SURTIDOR_H
#define SURTIDOR_H
#include <string>
using namespace std;

class surtidor
{
private:
    unsigned int* tanque;
    string codigoDeLsurtidor, modelo, registroDeVentas;
    unsigned int ventasR = 0, ventasE = 0, ventasP = 0, saldoVentasR = 0, saldoVentasE = 0, saldoVentasP = 0;
public:
    surtidor();

    surtidor(unsigned int* DireccionTanque);

    void simularVenta();
};

#endif // SURTIDOR_H
