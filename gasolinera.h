#ifndef GASOLINERA_H
#define GASOLINERA_H
#include <string>
using namespace std;

class Gasolinera
{
private:
    string nombre, codigo, gerente, region, coordenadas;
    unsigned int tanque[6];
public:
    Gasolinera();
    Gasolinera(string nombre, string _codigo, string _gerente, string _region, string _coordenadas, unsigned int _tanque[6]);
    void imprimir();
    unsigned int* retornarTanque();
};

#endif // GASOLINERA_H
