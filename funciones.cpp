#include "funciones.h"
#include <iostream>
#include "gasolinera.h"

string validarCategoria()
{
    string categoria;
    do {
        cout << "\nIngreasa la categoria?";
        cout << "\n1. Regular";
        cout << "\n2. EcoExtra";
        cout << "\n3. Premium";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >>  categoria;

        if(categoria != "1" && categoria != "2" && categoria != "3") {
            system("cls");
            cout <<"\nOPCION INVALIDA, INTENTALO NUEVAMENTE.\n";
        }

    } while( categoria != "1" && categoria != "2" && categoria != "3");


    if (categoria == "1") categoria = "Regular";
    if (categoria == "2") categoria = "EcoExtra";
    if (categoria == "3") categoria = "Premium";
    return categoria;
}


void pedir_datos_del_client(string &ccDelCliente, unsigned int &cantidad_comprada, string &metodoDePago, string &categoria)
{
    cout <<"\nCual es su cedula: "; cin >> ccDelCliente;
    cout <<"\nQue categoria de combustible va a comprar: ";
    cout <<"\n1. Regular\n2. EcoExtra\n3. Premium";
    cout <<"\nIngresa (1, 2, o 3): "; cin >> categoria;
    cout <<"\nCuantos litros deseas comprar: "; cin >> cantidad_comprada;
    cout <<"\nCual sera el metodo de pago?";
    cout <<"\n1. Efectivo\n2. TCredito\n3. TDebito";
    cout <<"\nIngresa (1, 2, o 3): "; cin >> metodoDePago;
}



Gasolinera *eliminarEstacionDeUnaRegion(Gasolinera *ArregloDEgasolineras, unsigned int &capacidad, unsigned int &sigtPosicion, string region)
{
    system("cls");
    string respuesta;
    for (unsigned short i = 0; i < sigtPosicion; ++i) {
        if (ArregloDEgasolineras[i].retornarTanque()[0] == 0 &&
            ArregloDEgasolineras[i].retornarTanque()[1] == 0 &&
            ArregloDEgasolineras[i].retornarTanque()[2] == 0){
            cout<<"\nEn la region "<<region<<" la estacion '"<<ArregloDEgasolineras[i].getNombre()<<"' no tiene surtidores disponibles.";
            cout<<"\nDeseas eliminarla?\n1. si\n2. no\nResponde ingresando 1 o 2: ";
            cin >> respuesta;
            if (respuesta == "1" || respuesta == "si"){
                Gasolinera* nuevoArreglo = new Gasolinera[capacidad];
                for (unsigned int j = 0, k = 0; j < sigtPosicion; ++j) {
                    if (j != i) {
                       nuevoArreglo[k] = ArregloDEgasolineras[j]; //Copiamos
                         k++;
                    }
                }
                // Libero la memoria del arreglo original
                delete[] ArregloDEgasolineras;

                ArregloDEgasolineras = nuevoArreglo; // Asigno el nuevo arreglo al puntero ArregloDEgasolinerasN

                --sigtPosicion;
                cout<<"\nESTACION ELIMINADA!\n";
                system("pause");
                system("cls");
                return  ArregloDEgasolineras;
            }
            else {cout<<"\nOK, ESA ESTACION SEGUIRA EXISTIENDO...\n"; return ArregloDEgasolineras;}
        }
    }
    cout<<"\nNO HAY ESTACIONES PARA ELIMINAR EN LA REGION "<<region<<endl;
    system("pause");
    system("cls");

    return ArregloDEgasolineras;
}

unsigned long int calcularVentas(Gasolinera* ArregloDEgasolineras, unsigned int& sigtPosicion, string region)
{
    unsigned long int TotalRegion = 0;
    cout<<"\nLAS VENTAS EN LA REGION "<<region<<" SON:\n";
    for (unsigned int i = 0; i < sigtPosicion; ++i){
        cout<<ArregloDEgasolineras[i].getNombre()<<".";
        unsigned int Regular = ArregloDEgasolineras[i].getSurtidores()->getVentas("Regular");
        unsigned int EcoExtra = ArregloDEgasolineras[i].getSurtidores()->getVentas("EcoExtra");
        unsigned int Premium = ArregloDEgasolineras[i].getSurtidores()->getVentas("Premium");
        cout<<"\nRegular:  $ "<<Regular;
        cout<<"\nEcoExtra: $ "<<EcoExtra;
        cout<<"\nPremium:  $ "<<Premium;
        cout<<"\nTotal:    $ "<<Regular + EcoExtra + Premium<<endl<<endl;
        TotalRegion += Regular + EcoExtra + Premium;
    }

    return TotalRegion;
}
