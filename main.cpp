#include <iostream>
#include "termax.h"
#include "funciones.h"

using namespace std;

int main() {
    TerMax gasolinerasDelPais;

    unsigned short opcion = 12;
    do{
        system("cls");
        cout << "\n---- MENU PARA GESTIONAR LA RED ----\n";
        cout << "1. Agregar Estacion de Servicio\n";
        cout << "2. Eliminar E/S de la red nacional si no tiene surtidores activos\n";
        cout << "3. Calcular Ventas Totales por Categoria en cada E/S del pais\n";
        cout << "4. Fijar Precios del Combustible\n";
        cout << "5. Verificar Fugas de Combustible\n";
        cout << "6. Simular Venta de Combustible\n";
        cout << "7. Mostrar Gasolineras\n";
        cout << "8. Entrar al menu de estaciones\n";
        cout << "9. Salir\n";
        cout << "Seleccione una opcion (1, 2, 3 o 0): "; cin >> opcion;
        switch(opcion) {
            case 1: {gasolinerasDelPais.agregarGasolinera(); break;}
            case 2: {gasolinerasDelPais.eliminarEstacion(); break;}
            case 3: {gasolinerasDelPais.ventasTotalesPorCaTDeLasES(); break;}
            case 4: gasolinerasDelPais.cambiarPrecio(); break;
            //case 5: {}
            case 7: {gasolinerasDelPais.mostrarGasolineras(); break;}
            case 8: {opcion = MenuDeEstaciones(gasolinerasDelPais); break;}
            case 9: break;
            default: {cout << "Opcion invalida, intente nuevamente.\n"; break;}
        }
    }while (opcion != 9);

    return 0;
}
