#include <funciones.h>
#include <iostream>

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



