#ifndef FUNCIONES_H
#define FUNCIONES_H
#include "termax.h"
using namespace std;

string validarCategoria();
void pedir_datos_del_client(string& ccDelCliente, unsigned int& cantidad_comprada, string& tipoDePago, string& categoria);

Gasolinera* eliminarEstacionDeUnaRegion(Gasolinera* ArregloDEgasolineras, unsigned int& capacidad, unsigned int& sigtPosicion, string region);

unsigned long int calcularVentas(Gasolinera* ArregloDEgasolineras, unsigned int& sigtPosicion, string region);

unsigned short MenuDeEstaciones(TerMax &gasolinerasDelPais);

void agregarYQitarSurtidor(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
void activarYDesactivarSurtidor(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
void verHistoricoDeVentaDeUnaEstacion(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
void reportarLitrosVendidos(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
void venderGasolina(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo, string cambiarDia = "no");
void AsignarCapacidadDelTanque(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
void detectarFugas(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo);
string obtenerTiempo(bool cambiarDia = false);


#endif // FUNCIONES_H
