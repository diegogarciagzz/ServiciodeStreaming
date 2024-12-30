//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
// En esta clase me sirvió mucho el conocimiento de arreglos mas que nada para los apuntadores
// Que forman parte del tema de polimorfismo y pudimos implementarlo al proyecto de manera eficiente.
// Aprendí a leer un archivo excel de datos para que mi programa los agarre y los use.

#ifndef POLIMORFISMO_H
#define POLIMORFISMO_H

#include "Serie.h"
#include "Episodio.h"
#include "Video.h"
#include "Pelicula.h"

using namespace std;
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <iostream>

class Polimorfismo
{
public:
    Polimorfismo();
    void leerArchivo(string _nombre);

    //Metodos sett

    void setPtrVideo(int index, Video* video);
    void setCantidad(int _cantidad);
    Video* getPtrVideo(int index);
    int getCantidad();

    //Otros metodos
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();
    void reporteInventario();


private:
    int cantidad;
    static const int MAX_VIDEOS = 100;
    Video *arrPtrVideos[MAX_VIDEOS];
};

#endif // POLIMORFISMO_H
