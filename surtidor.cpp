#include "surtidor.h"
#include "iostream"
using namespace std;

surtidor::surtidor()
{

}

surtidor::surtidor(unsigned int* DireccionTanque) {
    tanque = DireccionTanque;
}

void surtidor::simularVenta()
{
    unsigned int ccDelCliente = 101025045 + (rand() % (101026458 - 101025045));
    unsigned int cantidad_comprada = 3 + (rand() % (21 - 3));
    string tipoDePago = to_string(1 + (rand() % (3)));
    string categoria = to_string(1 + (rand() % (3)));
    int costo = 0;

    if (tipoDePago == "1") {
        tipoDePago = "Efectivo";
    }
    else if (tipoDePago == "2") {
        tipoDePago = "TCrédito";
    }
    else {
        tipoDePago = "TDebito";
    }
    if (categoria == "1") {
        categoria = "Regular";
        ventasR += cantidad_comprada;
    }
    if (categoria == "2") {
        categoria = "EcoExtra";
        if (cantidad_comprada <= tanque[1] && tanque[1] > 0){
            tanque[1] = tanque[1] - cantidad_comprada;
            ventasE += cantidad_comprada;
            costo = cantidad_comprada * tanque[4];
            saldoVentasE += costo;
        }
        else if(cantidad_comprada > tanque[1] && tanque[1] > 0){
            cantidad_comprada = tanque[1];
            tanque[1] = 0;
            ventasE += cantidad_comprada;
            costo = cantidad_comprada * tanque[4];
            saldoVentasE += costo;
        }
        else {
            cout<<"\n   LO SENTIMOS, SE AGOTO EL COMBUSTIBLE EcoExtra!";
        }
    }
    if (categoria == "3") {
        categoria = "Premium";
    }


    // AQUÍ VA LA LOGICA DE LA VENTA, ACTUALIZACIÓN DEL TANQUE Y EL REGISTRO.


    // Obtenemos la fecha y hora actual
    time_t tiempo_actual = time(nullptr);
    tm* tiempo_local = localtime(&tiempo_actual);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", tiempo_local);
    string fechaYhora = buffer;

    // Meto todo en el registroDeVentas
}
