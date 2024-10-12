#include <iostream>
#include "termax.h"
#include "funciones.h"
#include "surtidor.h"

using namespace std;

void menuDeGasolineras(TerMax& gasolineras);

int main() {
    TerMax gasolinerasDelPais;
    unsigned int Tanque[6] = {10000, 20000, 30000, 5000, 6000, 7000};
    surtidor* surtidores30 = new surtidor[12];

    unsigned short int opcion = 12;
    surtidores30[0] = surtidor(Tanque, surtidores30, opcion);
    do{
        //system("cls");
        cout << "\n---- MENU PARA GESTIONAR LA RED ----\n";
        cout << "1. Agregar Estacion de Servicio\n";
        cout << "2. Eliminar E/S de la red nacional si no tiene surtidores activos\n";
        cout << "3. Calcular Ventas Totales por Categoria en cada E/S del pais\n";
        cout << "4. Fijar Precios del Combustible\n";
        cout << "5. Verificar Fugas de Combustible\n";
        cout << "6. Simular Venta de Combustible\n";
        cout << "7. Mostrar Gasolineras\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, 3 o 0): "; cin >> opcion;
        switch(opcion) {
        case 1: {gasolinerasDelPais.agregarGasolinera(); break;}
        case 2: {gasolinerasDelPais.eliminarEstacion(); break;}
        case 3: {gasolinerasDelPais.ventasTotalesPorCaTDeLasES(); break;}
        case 7: {gasolinerasDelPais.mostrarGasolineras(); break;}
        case 4: {gasolinerasDelPais.cambiarPrecio(); break;}
        case 6: {gasolinerasDelPais.venderGasolina(); break;}
        case 8: break;
        default:
            cout << "Opcion invalida, intente nuevamente.\n";
        }
    }while (opcion != 8);

    delete[] surtidores30;
    return 0;
}
