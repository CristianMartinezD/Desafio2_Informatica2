#include "funciones.h"
#include <iostream>
#include "gasolinera.h"


/* MENU PARA GESTIONAR ESTACIONES DE SERVICIO*/

void MenuDeEstaciones(TerMax &gasolinerasDelPais){

    unsigned short int opcion = 12;
    do{
        //system("cls");
        cout << "\n---- MENU PARA GESTIONAR ESTACIONES ----\n";
        cout << "1. Agregar/Eliminar un Surtidor de una E/S\n";
        cout << "2. Activar/Desactivar un Surtidor de una E/S\n";
        cout << "3. Consultar el historico de transacciones de cada Surtidor de la E/S\n";
        cout << "4. Reportar la cantidad de litros vendida segun cada categoria de combustible\n";
        cout << "5. Simular Venta de Combustible\n";
        cout << "6. Asignar capacidad del tanque con valor aleatorio entre 100 y 200 Lt\n";
        cout << "7. Salir\n";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, 3, 4, 5, 6, o 7): "; cin >> opcion;
        switch(opcion) {
            case 1: {
                string region;
                cout << "\nDe cual region es la estacion a la cual le agregaras/quitaras un surtidor?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {agregarYQitarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {agregarYQitarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {agregarYQitarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }

            case 2: {
                string region;
                cout << "\nDe cual region es la estacion a la cual le activaras/desactivaras un surtidor?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {activarYDesactivarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {activarYDesactivarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {activarYDesactivarSurtidor(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 3: {
                string region;
                cout << "\nDe cual region es la estacion a la cual le quieres consultar su historico de transacciones?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {verHistoricoDeVentaDeUnaEstacion(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {verHistoricoDeVentaDeUnaEstacion(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {verHistoricoDeVentaDeUnaEstacion(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 4: {gasolinerasDelPais.mostrarGasolineras(); break;}
            case 5: {gasolinerasDelPais.cambiarPrecio(); break;}
            case 6: {gasolinerasDelPais.venderGasolina(); break;}
            case 7: break;
            default:
                cout << "Opcion invalida, intente nuevamente.\n";
        }
    }while (opcion != 7);
}















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

    for (unsigned int i = 0; i < sigtPosicion; ++i){//Iteramos sobre todoas las gasolineras.
        cout<<ArregloDEgasolineras[i].getNombre()<<".";
        unsigned int Regular = ArregloDEgasolineras[i].getSurtidores()->getVentas("Regular");
        unsigned int EcoExtra = ArregloDEgasolineras[i].getSurtidores()->getVentas("EcoExtra");
        unsigned int Premium = ArregloDEgasolineras[i].getSurtidores()->getVentas("Premium");
        cout<<"\nRegular:  $ "<<Regular;
        cout<<"\nEcoExtra: $ "<<EcoExtra;
        cout<<"\nPremium:  $ "<<Premium;
        cout<<"\nTotal:    $ "<<Regular + EcoExtra + Premium<<endl<<endl;
        TotalRegion += ArregloDEgasolineras[i].actualizarTotalVentas(); // Se retorna totalVentas de la gasolinera en la posicion i
    }

    return TotalRegion;
}



void agregarYQitarSurtidor(Gasolinera* ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int opcion;
    do{
        cout << "\nIngresa el numero de la gasolinera donde quieres agregar/quitar el surtidor (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;
        if (opcion < 0 || opcion > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (opcion < 0 || opcion > tamanoArreglo-1);

    string accion;
    cout<<"\nQUIERES AGREGAR O QUITAR UN SURTIDOR?";
    cout << "\n1. Agregar\n2. Quitar";
    cout<<"\nIngresa una de las anteriores opciones (1 o 2): "; cin >> accion;

    if (accion == "1" || accion == "Agregar"){
        // AQUI OBTENGO UN SURTIDOR DE LA GASOLINERA EN LA POSICION opcion.
        unsigned short stposicion = ArregloDeGasolineras[opcion].getcantidaDeSurtidores();


        //En la siguiente posicion del arreglo de surtidores meto un nuevo surtidor.
        //Este nuevo surtidor será creado llamando al constructor de copia de la clase surtidor.
        if (stposicion < 12){
            ArregloDeGasolineras[opcion].getSurtidores()[stposicion] = surtidor(ArregloDeGasolineras[opcion].getSurtidores()[0]);
            cout<<"\nSURTIDOR AGREGADO EXITOSAMENTE!\n";
            ArregloDeGasolineras[opcion].getSurtidores()[stposicion].imprimirAtributosDelSurtidor();
            system("pause");
            system("cls");
        }
        else {
            cout << "\nEn esta gasolinera no se puede agregar mas surtidores ya que tiene el tope maximo de surtidores que puede tener\n";
            system("pause");
            system("cls");
        }
    }
    else if (accion == "2" || accion == "Quitar"){
        unsigned int indiceQuitar;
        cout<<"\nLOS SURTIDORES DE ESTA GASALINERA SON:";
        for (int i = 0; i < ArregloDeGasolineras[opcion].getcantidaDeSurtidores(); ++i) {
            cout<<"\n"<<i<<". "<<ArregloDeGasolineras[opcion].getSurtidores()[i].getcodigoDeLsurtidor();
        }
        do{
            cout<<"\nDE LOS SURTIDORES ANTERIORES INGRESA EL INDICE DEL QUE QUIERES QUITAR: "; cin>>indiceQuitar;
            if (indiceQuitar < 0 || indiceQuitar >= ArregloDeGasolineras[opcion].getcantidaDeSurtidores()){
                cout<<"\nEse indice no es valido.";
            }
        }while(indiceQuitar < 0 || indiceQuitar >= ArregloDeGasolineras[opcion].getcantidaDeSurtidores());
        ArregloDeGasolineras[opcion].actualizarTotalVentas(); // Para que el saldo vendido por este surtidor se agregue al saldo acumulado de toda la gasolinera
        ArregloDeGasolineras[opcion].getSurtidores()[indiceQuitar].~surtidor();

        // ahora corremos los surtidores que estan a la derecha del surtidor quitado una posicion a la izquierda.
        for (int i = indiceQuitar; i < ArregloDeGasolineras[opcion].getcantidaDeSurtidores(); ++i) {
            ArregloDeGasolineras[opcion].getSurtidores()[i] = ArregloDeGasolineras[opcion].getSurtidores()[i+1];
        }
        ArregloDeGasolineras[opcion].getcantidaDeSurtidores("-");

        cout<<"\nSURTIDOR QUITADO EXITOSAMENTE!";
        cout<<"\nAHORA QUEDARON LOS SIGUIENTES SURTIDORES EN ESTA GASOLINERA:";
        for (int i = 0; i < ArregloDeGasolineras[opcion].getcantidaDeSurtidores(); ++i) {
            cout<<"\n"<<i<<". "<<ArregloDeGasolineras[opcion].getSurtidores()[i].getcodigoDeLsurtidor();
        }
        cout<<endl;
        system("pause");
        system("cls");
    }
    else {cout<<"\nACCION NO VALIDA, VOLVIENDO AL MENU..."; system("pause");}
}




void activarYDesactivarSurtidor(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int opcion;
    do{
        cout << "\nIngresa el numero de la gasolinera donde quieres activar/desactivar el surtidor (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;
        if (opcion < 0 || opcion > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (opcion < 0 || opcion > tamanoArreglo-1);

    string accion;
    cout<<"\nQUIERES ACTIVAR O DESACTIVAR UN SURTIDOR?";
    cout << "\n1. Activar\n2. Desactivar";
    cout<<"\nIngresa una de las anteriores opciones (1 o 2): "; cin >> accion;

    if (accion == "1") accion = "Activar";
    else if (accion == "2") accion = "Desactivar";

    if (accion == "Activar" || accion == "Desactivar"){

        unsigned int indiceSurtidor;
        cout<<"\nLOS SURTIDORES DE ESTA GASALINERA SON:";
        for (int i = 0; i < ArregloDeGasolineras[opcion].getcantidaDeSurtidores(); ++i) {
            cout<<"\n"<<i<<". "<<ArregloDeGasolineras[opcion].getSurtidores()[i].getcodigoDeLsurtidor();
            if (ArregloDeGasolineras[opcion].getSurtidores()[i].VerEstadoDelSurtidor()) cout<<" --> Activo";
            else cout<<" --> Desactivado";
        }
        do{
            cout<<"\nDE LOS SURTIDORES ANTERIORES INGRESA EL INDICE DEL QUE QUIERES "<<accion<<": "; cin>>indiceSurtidor;
            if (indiceSurtidor < 0 || indiceSurtidor >= ArregloDeGasolineras[opcion].getcantidaDeSurtidores()){
                cout<<"\nEse indice no es valido.";
            }
        }while(indiceSurtidor < 0 || indiceSurtidor >= ArregloDeGasolineras[opcion].getcantidaDeSurtidores());

        if(accion == "Activar") ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].CambiarEstadoDelSurtidor(true);
        else ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].CambiarEstadoDelSurtidor(false);

        if(accion == "Activar") cout<<"\nSURTIDOR ACTIVADO EXITOSAMENTE!";
        else cout<<"\nSURTIDOR DESACTIVADO EXITOSAMENTE!";
        cout<<endl;
        system("pause");
        system("cls");
    }
    else {cout<<"\nACCION NO VALIDA, VOLVIENDO AL MENU..."; system("pause");}
}

void verHistoricoDeVentaDeUnaEstacion(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int opcion;
    do{
        cout << "\nIngresa el numero de la gasolinera a la cuual le quieres consultar su historico de transacciones (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;
        if (opcion < 0 || opcion > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (opcion < 0 || opcion > tamanoArreglo-1);

    ArregloDeGasolineras[opcion].historialTransaciones();
}
