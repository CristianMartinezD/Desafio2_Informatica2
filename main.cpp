#include <iostream>
#include <termax.h>
#include <funciones.h>

using namespace std;

void menuDeGasolineras(TerMax& gasolineras);

int main() {
    TerMax gasolinerasDelPais;
    string region;
    do {
        cout << "\n---- Bienvenido a la red nacional de combustibles TerMax ----\n";

        cout << "\nEn que region del pais te encuentras?";
        cout << "\n1. Norte";
        cout << "\n2. Centro";
        cout << "\n3. Sur";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >>  region;

        if(region != "1" && region != "2" && region != "3") {
            system("cls");
            cout <<"\nOPCION INVALIDA, INTENTALO NUEVAMENTE.\n";
        }

    } while( region != "1" && region != "2" && region != "3");

    unsigned short int opcion;
    do{
        system("cls");
        cout << "1. Agregar Estacion de Servicio\n";
        cout << "2. Eliminar Estacion de Servicio\n";
        cout << "3. Calcular Ventas Totales por Categoria\n";
        cout << "4. Fijar Precios del Combustible\n";
        cout << "5. Verificar Fugas de Combustible\n";
        cout << "6. Simular Venta de Combustible\n";
        cout << "7. Mostrar Gasolineras\n";
        cout << "8. Salir\n";
        cout << "Seleccione una opcion: ";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, 3 o 0): "; cin >> opcion;
        switch(opcion) {
        case 1: {gasolinerasDelPais.agregarGasolinera(); break;}
        case 7: {gasolinerasDelPais.mostrarGasolineras(); break;}
        case 8: break;
        default:
            cout << "Opcion invalida, intente nuevamente.\n";
        }
    }while (opcion != 8);

    return 0;
}
