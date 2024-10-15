#include "funciones.h"
#include <iostream>
#include "gasolinera.h"


/* MENU PARA GESTIONAR ESTACIONES DE SERVICIO*/

unsigned short MenuDeEstaciones(TerMax &gasolinerasDelPais){

    unsigned short int opcion = 12;
    do{
        system("cls");
        cout << "\n---- MENU PARA GESTIONAR ESTACIONES ----\n";
        cout << "1. Agregar/Eliminar un Surtidor de una E/S\n";
        cout << "2. Activar/Desactivar un Surtidor de una E/S\n";
        cout << "3. Consultar el historico de transacciones de cada Surtidor de la E/S\n";
        cout << "4. Reportar la cantidad de litros vendida segun cada categoria de combustible\n";
        cout << "5. Simular Venta de Combustible\n";
        cout << "6. Asignar capacidad del tanque con valor aleatorio entre 100 y 200 Lt\n";
        cout << "7. Detectar fugas de combustible en alguna estacion de la red nacional\n";
        cout << "8. Volver al menu de la red nacional\n";
        cout << "9. Salir\n";
        cout<<"\nIngresa una de las anteriores opciones (1, 2, 3, 4, 5, 6, 7, o 8): "; cin >> opcion;
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
            case 4: {
                string region;
                cout << "\nDe cual region es la estacion a la cual consultaras el combustible que ha vendido?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {reportarLitrosVendidos(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {reportarLitrosVendidos(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {reportarLitrosVendidos(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 5: {
                string region;
                cout<<"\nEn que region te encuentras?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {venderGasolina(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {venderGasolina(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {venderGasolina(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 6: {
                string region;
                cout<<"\nEn que region se encuentra la gasalinera a la que modificaras su tanque?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {AsignarCapacidadDelTanque(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {AsignarCapacidadDelTanque(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {AsignarCapacidadDelTanque(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 7: {
                string region;
                cout<<"\nEn que region se encuentra la gasalinera a la cual queremos consultar si presenta alguna fuga?";
                cout << "\n1. norte\n2. centro\n3. sur";
                cout<<"\nIngresa una de las anteriores opciones (1, 2, o 3): "; cin >> region;
                unsigned int tamanoArreglo = gasolinerasDelPais.getSizeArreglo(region);

                if (region == "1" || region == "norte") {detectarFugas(gasolinerasDelPais.getArregloDeGasolineras("norte"), "norte", tamanoArreglo); break;}
                else if (region == "2" || region == "centro") {detectarFugas(gasolinerasDelPais.getArregloDeGasolineras("centro"), "centro", tamanoArreglo); break;}
                else if (region == "3" || region == "sur") {detectarFugas(gasolinerasDelPais.getArregloDeGasolineras("sur"), "sur", tamanoArreglo); break;}
                else {cout << "REGION INVALIDA.\n"; break;}
            }
            case 8: return 0;
            case 9: return 7;
            default:
                cout << "Opcion invalida, intente nuevamente.\n";
        }
    }while (opcion != 8);
    return 0;
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
    int num;
    cout <<"\nCual es su cedula: "; cin >> ccDelCliente;
    do{
        cout <<"\nQue categoria de combustible va a comprar: ";
        cout <<"\n1. Regular\n2. EcoExtra\n3. Premium";
        cout <<"\nIngresa (1, 2, o 3): "; cin >> categoria;
        cout <<"\nCuantos litros deseas comprar: "; cin >> num;
        cantidad_comprada = num;
        cout <<"\nCual sera el metodo de pago?";
        cout <<"\n1. Efectivo\n2. TCredito\n3. TDebito";
        cout <<"\nIngresa (1, 2, o 3): "; cin >> metodoDePago;

        if ((categoria != "1" && categoria != "2" && categoria != "3") ||
            (metodoDePago != "1" && metodoDePago != "2" && metodoDePago != "3") ||  num < 1){
            cout <<"\nUPS! PARECE QUE NO INGRESASTE UN DATO CORRECTO, VUELVE A INTENTARLO";
        }
    }while((categoria != "1" && categoria != "2" && categoria != "3") ||
             (metodoDePago != "1" && metodoDePago != "2" && metodoDePago != "3") ||  num < 1);
}



Gasolinera *eliminarEstacionDeUnaRegion(Gasolinera *ArregloDEgasolineras, unsigned int &capacidad, unsigned int &sigtPosicion, string region)
{
    system("cls");
    cout<<"\nBuscando estaciones sin surtidores activos en la region "<<region<<"...\n";
    string respuesta;
    for (unsigned short i = 0; i < sigtPosicion; ++i) {
        if (ArregloDEgasolineras[i].getTanque()[0] == 0 &&
            ArregloDEgasolineras[i].getTanque()[1] == 0 &&
            ArregloDEgasolineras[i].getTanque()[2] == 0){
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
    cout<<"\nNO HAY ESTACIONES PARA ELIMINAR EN LA REGION "<<region<<endl<<endl;
    system("pause");
    system("cls");

    return ArregloDEgasolineras;
}

unsigned long int calcularVentas(Gasolinera* ArregloDEgasolineras, unsigned int& sigtPosicion, string region)
{
    unsigned long int TotalRegion = 0;
    cout<<"\nLAS VENTAS EN LA REGION "<<region<<" SON:\n";

    for (unsigned int i = 0; i < sigtPosicion; ++i){//Iteramos sobre todas las gasolineras.
        cout<<ArregloDEgasolineras[i].getNombre()<<".";
        unsigned int Regular = 0;
        unsigned int EcoExtra = 0;
        unsigned int Premium = 0;
        for (unsigned short j = 0; j < ArregloDEgasolineras[i].getcantidaDeSurtidores(); ++j) {
            Regular += ArregloDEgasolineras[i].getSurtidores()[j].getSaldoVentas("Regular");
            EcoExtra += ArregloDEgasolineras[i].getSurtidores()[j].getSaldoVentas("EcoExtra");
            Premium += ArregloDEgasolineras[i].getSurtidores()[j].getSaldoVentas("Premium");
        }
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
            ArregloDeGasolineras[opcion].getcantidaDeSurtidores("+");
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
            if (ArregloDeGasolineras[opcion].getSurtidores()[i].VerEstadoDelSurtidor()) cout<<" --> Activo";
            else cout<<" --> Desactivado";
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
            if (ArregloDeGasolineras[opcion].getSurtidores()[i].VerEstadoDelSurtidor()) cout<<" --> Activo";
            else cout<<" --> Desactivado";
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
        cout << "\nIngresa el numero de la gasolinera a la cual le quieres consultar su historico de transacciones (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;
        if (opcion < 0 || opcion > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (opcion < 0 || opcion > tamanoArreglo-1);

    ArregloDeGasolineras[opcion].historialTransaciones();
}

void reportarLitrosVendidos(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int opcion;
    do{
        cout << "\nIngresa el numero de la gasolinera que quieres ver su cantidad vendida (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;
        if (opcion < 0 || opcion > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (opcion < 0 || opcion > tamanoArreglo-1);

    ArregloDeGasolineras[opcion].imprimirLitrosVendidos();
}

void venderGasolina(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    unsigned int opcion;
    cout<<"\nEN CUAL ESTACION DE LA REGION "<<region<<" QUIERES HACER LA COMPRA?";
    for (unsigned int i = 0; i < tamanoArreglo; ++i) {
        cout<<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    cout<<"\nElige una opcion (0 a "<<tamanoArreglo-1<<"): "; cin>>opcion;

    if(opcion >= 0 && opcion < tamanoArreglo){
        unsigned short cantidadSurtidores = ArregloDeGasolineras[opcion].getcantidaDeSurtidores(), modo;

        cout<<"\nQuieres que esta venta sea automatica o deseas realizarla manualmente?";
        cout<<"\n1. Manualmente\n2. Automatico\nElige 1 o 2: "; cin>>modo;

        system("cls");

        bool SiHaySurtiActivos = true;
        if (modo == 2){
            unsigned short indiceSurtidor = 0 + (rand() % (cantidadSurtidores - 1 ));
            if (!ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].VerEstadoDelSurtidor()){
                SiHaySurtiActivos = false; //Asumimos que no habran surtidores activos
                for (int i = 0; i < cantidadSurtidores; ++i) {
                    if (ArregloDeGasolineras[opcion].getSurtidores()[i].VerEstadoDelSurtidor()){
                        indiceSurtidor = i;
                        SiHaySurtiActivos = true;
                        break;
                    }
                }
            }
            if(SiHaySurtiActivos){
                cout<<"\nINFORMACION DE LA ESTACION DONDE ESTAS COMPRANDO:\n";
                ArregloDeGasolineras[opcion].imprimir();
                system("pause");
                ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].simularVenta(2);
            }
        }
        else{
            SiHaySurtiActivos = false; //Asumimos que no habran surtidores activos

            cout<<"\nLOS SURTIDORES DE ESTA GASALINERA SON:";
            for (int i = 0; i < ArregloDeGasolineras[opcion].getcantidaDeSurtidores(); ++i) {
                cout<<"\n"<<i<<". "<<ArregloDeGasolineras[opcion].getSurtidores()[i].getcodigoDeLsurtidor();
                if (ArregloDeGasolineras[opcion].getSurtidores()[i].VerEstadoDelSurtidor()){
                    cout<<" --> Activo";
                    SiHaySurtiActivos = true;
                }
                else cout<<" --> Desactivado";
            }
            if(SiHaySurtiActivos){
                unsigned short indiceSurtidor;
                cout<<"\nCUAL DE ELLOS DESEAS QUE TE DESPACHE?: "; cin>>indiceSurtidor;
                if (ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].VerEstadoDelSurtidor()){
                    cout<<"\nINFORMACION DE LA ESTACION DONDE ESTAS COMPRANDO:\n";
                    ArregloDeGasolineras[opcion].imprimir();
                    system("pause");
                    ArregloDeGasolineras[opcion].getSurtidores()[indiceSurtidor].simularVenta(1);
                }
                else {
                    cout<<"\nNO ELEGISTE UN SURTIDOR ACTIVO!\nSALIENDO...\n\n";
                    system("pause");
                }
            }
        }

    }
    else{
        cout<<"\nNO INGRESASTE UN INDICE DE LAS ESTACIONES DISPONIBLES!\nSALIENDO...\n\n";
        system("pause");
    }
}

void AsignarCapacidadDelTanque(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int indice;
    do{
        cout << "\nIngresa el numero de la gasolinera a la cual le vamos a cambiar el contenido de su tanque (0 a "<<tamanoArreglo-1<<"): "; cin>>indice;
        if (indice < 0 || indice > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (indice < 0 || indice > tamanoArreglo-1);

    unsigned int nuevaCapacidad = ArregloDeGasolineras[indice].verCapacidadDelTanque(100 + (rand() % (201-100)));

    unsigned int Regular = 20 + (rand() % ((1+nuevaCapacidad/2)-20));
    unsigned int EcoExtra = 20 + (rand() % ((nuevaCapacidad - Regular)-20));
    unsigned int Premium = nuevaCapacidad - (Regular + EcoExtra);

    ArregloDeGasolineras[indice].getTanque()[0] = Regular;
    ArregloDeGasolineras[indice].getTanque()[1] = EcoExtra;
    ArregloDeGasolineras[indice].getTanque()[2] = Premium;

    cout<<"\nLOS NUEVOS DATOS DEL TANQUE DE LA GASOLINERA "<<ArregloDeGasolineras[indice].getNombre()<<" SON:\n";
    cout<<"Nueva capacidad: "<<nuevaCapacidad<<" Lt"<<endl;
    cout<<"Cantidad Regular:  "<<ArregloDeGasolineras[indice].getTanque()[0]<<" Lt disponibles"<<endl;
    cout<<"Cantidad EcoExtra: "<<ArregloDeGasolineras[indice].getTanque()[1]<<" Lt disponibles"<<endl;
    cout<<"Cantidad Premium:  "<<ArregloDeGasolineras[indice].getTanque()[2]<<" Lt disponibles"<<endl<<endl;
    system("pause");
}

void detectarFugas(Gasolinera *ArregloDeGasolineras, string region, unsigned int tamanoArreglo)
{
    system("cls");
    cout << "\nESTA ES LA LISTA DE GASOLINERAS DE LA REGION "<<region<<":";
    for (unsigned int i = 0; i < tamanoArreglo; ++i){
        cout <<"\n"<<i<<". "<<ArregloDeGasolineras[i].getNombre();
    }
    unsigned int indice;
    do{
        cout << "\nIngresa el numero de la gasolinera a la cual miraremos si presenta fugas (0 a "<<tamanoArreglo-1<<"): "; cin>>indice;
        if (indice < 0 || indice > tamanoArreglo-1){
            cout<<"\nEse indice no corresponde a ninguna de las gasolineras que te mostre!";
        }
    }while (indice < 0 || indice > tamanoArreglo-1);

    ArregloDeGasolineras[indice].detectarFugas();
}
