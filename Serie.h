//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
// En esta actividad aprendía a combinar los conceptos de herencia y composición
// en este caso la base padre es la de Video y la hija es la de serie.
// Es muy padre y impresionante como podemos juntar todos los temas en uno solo.

#ifndef SERIE_H
#define SERIE_H

#include <stdio.h>
#include "Video.h"
#include "Episodio.h"

//HERENCIA DE VIDEO
class Serie : public Video
{
public:
    //Constructor default
    Serie();
    // Constructor con parametros
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);
    //Metodos set
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    //Metodos get
    Episodio getEpisodio(int posicion);
    int getCantidad();

    double calculaPromedio();

    //OVERRIDING REESCRIBIR EL METODO DE LA CLASE BASE
    string str();
    void agregaEpisodio(Episodio episodio);

    void calculaDuracion();

    string getTipo(){
        return "Serie";
    }


private:

    int cantidad;
    // COMPOSICIÓN11
    Episodio episodios[5];
};

#endif // SERIE_H
