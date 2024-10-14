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
    bool EstadoDelSurtidor;
    surtidor* DireccionDeSurtidores;
    unsigned short cantidaDeSurtidores;
public:
    surtidor();

    surtidor(unsigned int* DireccionTanque, surtidor* _DireccionDeSurtidores, unsigned short _cantidaDeSurtidores);

    surtidor(const surtidor &Acopiar);

    void simularVenta();
    void CambiarEstadoDelSurtidor(bool estado);
    bool VerEstadoDelSurtidor();
    unsigned int getVentas(string categoria);
    unsigned int* getTanque();

    void imprimirAtributosDelSurtidor();

    ~surtidor();
};

#endif // SURTIDOR_H
