#ifndef TERMAX_H
#define TERMAX_H
#include <string>
#include "gasolinera.h"
using namespace std;

class TerMax
{
private:
    Gasolinera* ArregloDEgasolineras = new Gasolinera[7];
    string region;
    unsigned int siguientePosicion;
public:
    TerMax(string _region);

    void gasolinerasDelNorte();

    void gasolinerasDelCentro();

    void gasolinerasDelSur();

    void agregarGasolinera();


    ~TerMax(){delete[] ArregloDEgasolineras;}
};

#endif // TERMAX_H
