#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "termax.h"
using namespace std;

string validarCategoria();
void pedir_datos_del_client(string& ccDelCliente, unsigned int& cantidad_comprada, string& tipoDePago, string& categoria);

Gasolinera* eliminarEstacionDeUnaRegion(Gasolinera* ArregloDEgasolineras, unsigned int& capacidad, unsigned int& sigtPosicion, string region);

unsigned long int calcularVentas(Gasolinera* ArregloDEgasolineras, unsigned int& sigtPosicion, string region);

void MenuDeEstaciones(TerMax &gasolinerasDelPais);

void agregarSurtidor(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);

#endif // FUNCIONES_H
