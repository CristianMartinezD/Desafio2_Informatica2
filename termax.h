#ifndef TERMAX_H
#define TERMAX_H
#include <string>
#include "gasolinera.h"
using namespace std;

class TerMax
{
private:
    unsigned int capacidadN = 7, capacidadC = 7, capacidadS = 7;
    Gasolinera* ArregloDEgasolinerasN = new Gasolinera[capacidadN];
    Gasolinera* ArregloDEgasolinerasC = new Gasolinera[capacidadC];
    Gasolinera* ArregloDEgasolinerasS = new Gasolinera[capacidadS];
    string region;
    unsigned int siguientePosicionN, siguientePosicionC, siguientePosicionS;
    void redimensionar(string R,unsigned int& capacidad);
public:
    TerMax();

    void gasolinerasDelNorte();

    void gasolinerasDelCentro();

    void gasolinerasDelSur();

    void agregarGasolinera();

    void rellenarTanque(unsigned int tanque[], bool fijaPrecio = false);

    void mostrarGasolineras();

    Gasolinera* getArregloDeGasolineras(string R);
    Gasolinera* getArregloDeGasolinerasC();
    Gasolinera* getArregloDeGasolinerasS();


    ~TerMax(){delete[] ArregloDEgasolinerasN; delete[] ArregloDEgasolinerasC; delete[] ArregloDEgasolinerasS;}
};

#endif // TERMAX_H
