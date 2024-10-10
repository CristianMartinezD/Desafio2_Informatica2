#ifndef TERMAX_H
#define TERMAX_H
#include <string>
#include "gasolinera.h"
using namespace std;

class TerMax
{
private:
    unsigned int capacidadN = 7, capacidadC = 7, capacidadS = 7, precioRN = 0, precioRC = 0, precioRS = 0, precioEN = 0, precioEC, precioES = 0, precioPN = 0, precioPC = 0, precioPS = 0;
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
    void cambiarPrecio();

    void mostrarGasolineras();

    Gasolinera* getArregloDeGasolineras(string R);
    Gasolinera* getArregloDeGasolinerasC();
    Gasolinera* getArregloDeGasolinerasS();
    int validarRegion();


    ~TerMax(){delete[] ArregloDEgasolinerasN; delete[] ArregloDEgasolinerasC; delete[] ArregloDEgasolinerasS;}
};

#endif // TERMAX_H
