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

    void simularVenta(unsigned short modo, string cambiarDia);
    void CambiarEstadoDelSurtidor(bool estado);
    bool VerEstadoDelSurtidor();
    unsigned int getSaldoVentas(string categoria);
    unsigned int getCantidadVentas(string categoria);
    unsigned int* getTanque();
    string getcodigoDeLsurtidor();
    string getRegistroDeVentas();


    void imprimirAtributosDelSurtidor();

    ~surtidor();
};

#endif // SURTIDOR_H
