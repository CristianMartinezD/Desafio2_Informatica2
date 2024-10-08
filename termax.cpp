#include "termax.h"

TerMax::TerMax(string _region) {
    region = _region;

    /* NORTE */
    if (region == "norte"){
        siguientePosicion = 4;
        gasolinerasDelNorte();
    }

    /* CENTRO */
    if (region == "centro"){
        siguientePosicion = 5;
        gasolinerasDelCentro();
    }

    /* SUR */
    if (region == "sur"){
        siguientePosicion = 3;
        gasolinerasDelSur();
    }
}


void TerMax::gasolinerasDelNorte(){
    ArregloDEgasolineras[0] = Gasolinera(/*Aquí van los atributos de la primera gasolinera */);
    ArregloDEgasolineras[1] = Gasolinera(/*Aquí van los atributos de la segunda gasolinera */);
    ArregloDEgasolineras[2] = Gasolinera(/*Aquí van los atributos de la tercera gasolinera */);
    ArregloDEgasolineras[3] = Gasolinera(/*Aquí van los atributos de la cuarta gasolinera */);
}

void TerMax::gasolinerasDelCentro()
{
    ArregloDEgasolineras[0] = Gasolinera(/*Aquí van los atributos de la primera gasolinera */);
    ArregloDEgasolineras[1] = Gasolinera(/*Aquí van los atributos de la segunda gasolinera */);
    ArregloDEgasolineras[2] = Gasolinera(/*Aquí van los atributos de la tercera gasolinera */);
    ArregloDEgasolineras[3] = Gasolinera(/*Aquí van los atributos de la cuarta gasolinera */);
    ArregloDEgasolineras[4] = Gasolinera(/*Aquí van los atributos de la quinta gasolinera */);
}

void TerMax::gasolinerasDelSur()
{
    ArregloDEgasolineras[0] = Gasolinera(/*Aquí van los atributos de la primera gasolinera */);
    ArregloDEgasolineras[1] = Gasolinera(/*Aquí van los atributos de la segunda gasolinera */);
    ArregloDEgasolineras[2] = Gasolinera(/*Aquí van los atributos de la tercera gasolinera */);
}

void TerMax::agregarGasolinera()
{
    /* AQUI PEDIMOS LOS ATRIBUTOS */
    /* Luego verifico si siguientePosicion == Capacidad de ArregloDEgasolineras, y de ser así redimenciono */
    ArregloDEgasolineras[siguientePosicion] = Gasolinera(/*Aquí van los atributos de la gasolinera que se va agregar */);
    siguientePosicion += 1;
}
