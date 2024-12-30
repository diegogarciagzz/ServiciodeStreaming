//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
// En esta actividad aprendía a combinar los conceptos de herencia y composición
// en este caso la base padre es la de Video y la hija es la de serie.
// Es muy padre y impresionante como podemos juntar todos los temas en uno solo.

#include "Serie.h"

Serie::Serie():Video()
{

    cantidad = 0;
}

Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion):Video( _iD, _titulo, _duracion, _genero, _calificacion)
{
    cantidad = 0;
}

//Metodos set
void Serie::setEpisodio(int posicion, Episodio episodio)
{
    //Validar que el episodio exita
    if (posicion >= 0 && posicion < cantidad)
    {
        episodios[posicion] = episodio;
    }

}
void Serie::setCantidad(int _cantidad)
{
    // Validad
    if (_cantidad >= 0 && _cantidad <= 5)
    {

        cantidad = _cantidad;
    }
}

//Metodos get
Episodio Serie::getEpisodio(int posicion)
{
    if (posicion >= 0 && posicion < cantidad)
    {
        return episodios[posicion];
    }
    return Episodio();
}

int Serie::getCantidad()
{
    return cantidad;
}

double Serie::calculaPromedio()
{
    double acum = 0.0;

    for (int index = 0; index < cantidad; index++)
    {

        acum += episodios[index].getCalificacion();
    }

    if (cantidad > 0)
    {
        calificacion =  acum / cantidad;
        return calificacion;
    }

    return 0;
}

//OVERRIDING REESCRIBIR EL METODO DE LA CLASE BASE1
string Serie::str()
{

    string acum = "\n";

    for (int index = 0; index < cantidad; index++)
    {
        acum += episodios[index].str() + "\n";

    }
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(cantidad) + acum;

}
void Serie::agregaEpisodio(Episodio episodio)
{
    //Validar que haya espacio1
    if (cantidad < 5)
    {

        episodios[cantidad++] = episodio;

    }
}
