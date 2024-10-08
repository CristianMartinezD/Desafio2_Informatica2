#include <iostream>
#include <termax.h>

using namespace std;

void menuDeGasolineras(TerMax& gasolineras);

int main() {

    int opcion;
    do {
        cout << "\n---- Bienvenido a la red nacional de combustibles TerMax ----\n";

        cout << "\nEn que region del pais te encuentras?";
        cout << "\n1. Norte";
        cout << "\n2. Centro";
        cout << "\n3. Sur";
        cout << "\n0. Salir";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, 3 o 0): "; cin >> opcion;

        switch(opcion) {
        case 1: {TerMax gasolineras("norte"); menuDeGasolineras(gasolineras); break;}
        case 2: {TerMax gasolineras("centro"); menuDeGasolineras(gasolineras); break;}
        case 3: {TerMax gasolineras("sur"); menuDeGasolineras(gasolineras); break;}
        case 0: break;
        default:
            cout << "Opcion invalida, intente nuevamente.\n";
        }
    } while(opcion != 0);

    return 0;
}




void menuDeGasolineras(TerMax& gasolineras){
    unsigned short int opcion;
    do{
    cout << "1. Agregar Estacion de Servicio\n";
    cout << "2. Eliminar Estacion de Servicio\n";
    cout << "3. Calcular Ventas Totales por Categoria\n";
    cout << "4. Fijar Precios del Combustible\n";
    cout << "5. Verificar Fugas de Combustible\n";
    cout << "6. Simular Venta de Combustible\n";
    cout << "7. Mostrar Estaciones de Servicio\n";
    cout << "8. Salir\n";
    cout << "Seleccione una opcion: ";
    cout<<"\nIngresa una de las anteriores opciones (1, 2, 3 o 0): "; cin >> opcion;
    switch(opcion) {
    case 1: {gasolineras.agregarGasolinera(); break;}
    case 8: break;
    default:
        cout << "Opcion invalida, intente nuevamente.\n";
    }
    }while (opcion != 8);













}
