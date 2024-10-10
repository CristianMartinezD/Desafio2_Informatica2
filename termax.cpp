#include <termax.h>
#include <gasolinera.h>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include <funciones.h>
#include <iostream>

using namespace std;

TerMax::TerMax()
{
    gasolinerasDelNorte();  siguientePosicionN = 4;
    gasolinerasDelCentro(); siguientePosicionC = 5;
    gasolinerasDelSur();    siguientePosicionS = 3;
}


void TerMax::gasolinerasDelNorte()
{
    unsigned int tanque1[6] = {0,0,0,precioRN,precioEN,precioPN}, tanque2[6], tanque3[6], tanque4[6];
    srand(time(0));
    rellenarTanque(tanque1,true); rellenarTanque(tanque2); rellenarTanque(tanque3); rellenarTanque(tanque4);
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) { // Para que todas las bombas del norte tengan los mismos precios
            tanque2[j] = tanque1[j];
            tanque3[j] = tanque1[j];
            tanque4[j] = tanque1[j];
        }
    }

    ArregloDEgasolinerasN[0] = Gasolinera("bomba1N","12345N","Pedro1N", "norte","35.7749°N,74.0060°W", tanque1);
    ArregloDEgasolinerasN[1] = Gasolinera("bomba2N","12346N","Pedro2N", "norte","36.7749°N,74.0060°W", tanque2);
    ArregloDEgasolinerasN[2] = Gasolinera("bomba3N","12347N","Pedro3N", "norte","37.7749°N,74.0060°W", tanque3);
    ArregloDEgasolinerasN[3] = Gasolinera("bomba4N","12348N","Pedro4N", "norte","38.7749°N,74.0060°W", tanque4);
}

void TerMax::gasolinerasDelCentro()
{
    unsigned int tanque1[6], tanque2[6], tanque3[6], tanque4[6], tanque5[6];
    rellenarTanque(tanque1,true); rellenarTanque(tanque2); rellenarTanque(tanque3); rellenarTanque(tanque4); rellenarTanque(tanque5);
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) { // Para que todas las bombas del centro tengan los mismos precios
            tanque2[j] = tanque1[j];
            tanque3[j] = tanque1[j];
            tanque4[j] = tanque1[j];
            tanque5[j] = tanque1[j];
        }
    }

    ArregloDEgasolinerasC[0] = Gasolinera("bomba1C","12345C","Pedro1C", "centro","01.7749°N,74.0060°W", tanque1);
    ArregloDEgasolinerasC[1] = Gasolinera("bomba2C","12346C","Pedro2C", "centro","02.7749°N,74.0060°W", tanque2);
    ArregloDEgasolinerasC[2] = Gasolinera("bomba3C","12347C","Pedro3C", "centro","03.7749°N,74.0060°W", tanque3);
    ArregloDEgasolinerasC[3] = Gasolinera("bomba4C","12348C","Pedro4C", "centro","04.7749°N,74.0060°W", tanque4);
    ArregloDEgasolinerasC[4] = Gasolinera("bomba5C","12349C","Pedro5C", "centro","05.7749°N,74.0060°W", tanque5);
}

void TerMax::gasolinerasDelSur()
{
    unsigned int tanque1[6], tanque2[6], tanque3[6];
    rellenarTanque(tanque1,true); rellenarTanque(tanque2); rellenarTanque(tanque3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 6; ++j) { // Para que todas las bombas del sur tengan los mismos precios
            tanque2[j] = tanque1[j];
            tanque3[j] = tanque1[j];
        }
    }

    ArregloDEgasolinerasS[0] = Gasolinera("bomba1S","12345S","Pedro1S", "sur","91.7749°N,74.0060°W", tanque1);
    ArregloDEgasolinerasS[1] = Gasolinera("bomba2S","12346S","Pedro2S", "sur","92.7749°N,74.0060°W", tanque2);
    ArregloDEgasolinerasS[2] = Gasolinera("bomba3S","12347S","Pedro3S", "sur","93.7749°N,74.0060°W", tanque3);
}

void TerMax::rellenarTanque(unsigned int tanque[], bool fijaPrecio)
{
    for (size_t i = 0; i < 3; ++i){
        unsigned int min = 20000, max = 50000;
        unsigned int cantidadDeCombustible = min + (rand() % (max - min + 1)); // Cantidad de combustible (Regular, EcoExtra y Premium)
        tanque[i] = cantidadDeCombustible;
    }

    for (size_t i = 3; i < 6; ++i){
        unsigned int min = 3700, max = 4200;
        unsigned int precio = min + (rand() % (max - min + 1)); // Precio de combustible (Regular, EcoExtra y Premium)
        tanque[i] = precio;
    }

    // Ordenamos los elementos de menor a mayor (burbuja simplificada)
    if(fijaPrecio == true){
        for (int i = 3; i < 6; ++i) {
            for (int j = 3; j < 6 - (i - 3) - 1; ++j) {
                if (tanque[j] > tanque[j + 1]) {
                    int temp = tanque[j];
                    tanque[j] = tanque[j + 1];
                    tanque[j + 1] = temp;
                }
            }
        }
    }
}

void TerMax::cambiarPrecio()
{
    unsigned int nuevo_precio, tamano; Gasolinera *ArregloDEgasolineras;
    int region = validarRegion();

    switch (region) {
        case 1: {
            ArregloDEgasolineras = ArregloDEgasolinerasN;
            tamano = siguientePosicionN;
            break;
        }
        case 2: {
            ArregloDEgasolineras = ArregloDEgasolinerasC;
            tamano = siguientePosicionC;
            break;
        }
        case 3: {
            ArregloDEgasolineras = ArregloDEgasolinerasS;
            tamano = siguientePosicionS;
            break;
        }
    }

    string respuesta;
    cout<<"\nVAS A CAMBIAR EL PRECIO DEL COMBUSTIBLE Regular? (si, no): "; cin >> respuesta;
    if (respuesta == "si" || respuesta == "Si" || respuesta == "SI"){
        cout<<"\nINGRESA EL NUEVO PRECIO: "; cin >> nuevo_precio;
        for (unsigned int i = 0; i < tamano; ++i) {
            ArregloDEgasolineras[i].retornarTanque()[3] = nuevo_precio;
        }
    }

    cout<<"\nVAS A CAMBIAR EL PRECIO DEL COMBUSTIBLE EcoExtra? (si, no): "; cin >> respuesta;
    if (respuesta == "si" || respuesta == "Si" || respuesta == "SI"){
        cout<<"\nINGRESA EL NUEVO PRECIO: "; cin >> nuevo_precio;
        for (unsigned int i = 0; i < tamano; ++i) {
            ArregloDEgasolineras[i].retornarTanque()[4] = nuevo_precio;
        }
    }

    cout<<"\nVAS A CAMBIAR EL PRECIO DEL COMBUSTIBLE Premium? (si, no): "; cin >> respuesta;
    if (respuesta == "si" || respuesta == "Si" || respuesta == "SI"){
        cout<<"\nINGRESA EL NUEVO PRECIO: "; cin >> nuevo_precio;
        for (unsigned int i = 0; i < tamano; ++i) {
            ArregloDEgasolineras[i].retornarTanque()[5] = nuevo_precio;
        }
    }

    cout <<"\n\nHAS CAMBIADO EXITOSAMENTE EL PRECIO DE LA GASOLINA EN ESTA REGION!\n\n";
    system("pause");
}

void TerMax::mostrarGasolineras()
{
    system("cls");
    cout<<"\n\n---- GASOLINERAS DEL NORTE ---- "<<endl;
    for (size_t i = 0; i < siguientePosicionN; ++i) {
        ArregloDEgasolinerasN[i].imprimir();
    }
    cout<<"\n\n---- GASOLINERAS DEL CENTRO ---- "<<endl;
    for (size_t i = 0; i < siguientePosicionC; ++i) {
        ArregloDEgasolinerasC[i].imprimir();
    }
    cout<<"\n\n---- GASOLINERAS DEL SUR ---- "<<endl;
    for (size_t i = 0; i < siguientePosicionS; ++i) {
        ArregloDEgasolinerasS[i].imprimir();
    }
    system("pause");
}

Gasolinera *TerMax::getArregloDeGasolineras(string R)
{
    Gasolinera* DireccioDelArreglo;
    if (R == "norte") DireccioDelArreglo = ArregloDEgasolinerasN;
    else if (R == "centro") DireccioDelArreglo = ArregloDEgasolinerasC;
    else if (R == "norte") DireccioDelArreglo = ArregloDEgasolinerasS;
    else DireccioDelArreglo = nullptr;
    return DireccioDelArreglo;
}

Gasolinera *TerMax::getArregloDeGasolinerasC()
{
    return ArregloDEgasolinerasC;
}

Gasolinera *TerMax::getArregloDeGasolinerasS()
{
    return ArregloDEgasolinerasS;
}



void TerMax::agregarGasolinera()
{
    system ("cls");
    string region;
    do {
        cout << "\n---- VAMOS AGREGAR UNA ESTACION DE SERVICIOS ----\n";

        cout << "\nEn cual region del pais vas agregar la estacion?";
        cout << "\n1. Norte";
        cout << "\n2. Centro";
        cout << "\n3. Sur";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >>  region;

        if(region != "1" && region != "2" && region != "3") {
            system("cls");
            cout <<"\nOPCION INVALIDA, INTENTALO NUEVAMENTE.\n";
        }

    } while( region != "1" && region != "2" && region != "3");


    unsigned int* tanqueExistente = nullptr;
    if (region == "1"){
        if (siguientePosicionN == capacidadN){redimensionar("norte",capacidadN);}
        tanqueExistente = ArregloDEgasolinerasN[0].retornarTanque(); region = "norte";
    }
    else if (region == "2"){
        if (siguientePosicionC == capacidadC){redimensionar("centro",capacidadC);}
        tanqueExistente = ArregloDEgasolinerasC[0].retornarTanque(); region = "centro";
    }
    else {
        if (siguientePosicionS == capacidadS){redimensionar("sur",capacidadS);}
        tanqueExistente = ArregloDEgasolinerasS[0].retornarTanque(); region = "sur";
    }

    cout<<"\nINGRESA LOS ATRIBUTOS DE LA NUEVA GASOLINERA.\n";
    string nom, cod, ger, coord; unsigned int tanqueNuevo[6];

    cout<<"Nombre: "; cin>>nom;
    cout<<"Codigo: "; cin>>cod;
    cout<<"Gerente: "; cin>>ger;
    cout<<"Coordenadas: "; cin>>coord;
    cout<<"Combustible Regular (en Lt): "; cin>>tanqueNuevo[0];
    cout<<"Combustible EcoExtra (en Lt): "; cin>>tanqueNuevo[1];
    cout<<"Combustible Premium (en Lt): "; cin>>tanqueNuevo[2];
    cout<<"\nEl precio del combustible en esta region el dia de hoy es:";

    cout<<"\nRegular: "<< tanqueExistente[3]<<" COP /Lt";
    cout<<"\nEcoExtra: "<< tanqueExistente[4]<<" COP /Lt";
    cout<<"\nPremium: "<< tanqueExistente[5]<<" COP /Lt";
    tanqueNuevo[3] = tanqueExistente[3];
    tanqueNuevo[4] = tanqueExistente[4];
    tanqueNuevo[5] = tanqueExistente[5];

    cout<<"\nTu nueva gasolinera se acogio a los precios de esta region.\n";

    if (region == "norte"){
        ArregloDEgasolinerasN[siguientePosicionN] = Gasolinera(nom, cod, ger, region, coord, tanqueNuevo);
        siguientePosicionN += 1;
    }
    else if (region == "centro"){
        ArregloDEgasolinerasC[siguientePosicionC] = Gasolinera(nom, cod, ger, region, coord, tanqueNuevo);
        siguientePosicionC += 1;
    }
    else {
        ArregloDEgasolinerasS[siguientePosicionS] = Gasolinera(nom, cod, ger, region, coord, tanqueNuevo);
        siguientePosicionS += 1;
    }

    cout<<"\nLA NUEVA ESTACION DE COMBUSTIBLE HA SIDO AGREAGADA EXITOSAMENTE!\n\n";
    system("pause");
}



void TerMax::redimensionar(string R,unsigned int& capacidad)
{
    if (R == "norte"){
        capacidad *= 2;
        Gasolinera* nuevoArray = new Gasolinera[capacidad]; // Creamos un nuevo arreglo con la nueva capacidad

        // Copiamos las cuentas del arreglo original al nuevo
        for (unsigned int i = 0; i < capacidad/2; i++) {
            nuevoArray[i] = ArregloDEgasolinerasN[i];
        }

        delete[] ArregloDEgasolinerasN;  // Liberamos la memoria del arreglo anterior
        ArregloDEgasolinerasN = nuevoArray; // Asignamos la dirección de memoria del nuevo arreglo al puntero cuentas
    }

    else if (R == "centro"){
        capacidad *= 2;
        Gasolinera* nuevoArray = new Gasolinera[capacidad]; // Lo mismo

        // Lo mismo
        for (unsigned int i = 0; i < capacidad/2; i++) {
            nuevoArray[i] = ArregloDEgasolinerasC[i];
        }

        delete[] ArregloDEgasolinerasC;  // Lo mismo
        ArregloDEgasolinerasC = nuevoArray; // Lo mismo
    }


    else {
        capacidad *= 2;
        Gasolinera* nuevoArray = new Gasolinera[capacidad]; // Lo mismo

        // Lo mismo
        for (unsigned int i = 0; i < capacidad/2; i++) {
            nuevoArray[i] = ArregloDEgasolinerasS[i];
        }

        delete[] ArregloDEgasolinerasS;  // Lo mismo
        ArregloDEgasolinerasS = nuevoArray; // Lo mismo
    }
}



int TerMax::validarRegion()
{
    string region;
    do {
        cout << "\nEn cual region del pais vas a realizar esta operacion?";
        cout << "\n1. Norte";
        cout << "\n2. Centro";
        cout << "\n3. Sur";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >>  region;

        if(region != "1" && region != "2" && region != "3") {
            system("cls");
            cout <<"\nOPCION INVALIDA, INTENTALO NUEVAMENTE.\n";
        }

    } while( region != "1" && region != "2" && region != "3");

    int REGION;
    if (region == "1")REGION = 1;
    if (region == "2")REGION = 2;
    if (region == "3")REGION = 3;
    return REGION;
}
