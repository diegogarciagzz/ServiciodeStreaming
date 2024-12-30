//Diego Garc�a Gonz�lez
//A01198976
//ITC
//Cpp Video1
//09/06/24
// Esta clase me ayudó a entender el concepto de herencia en este caso
// la clase video será mi clase padre o base y podré crear otras clases cómo derivadas o hijas
// Cómo lo son las clases de serie y pelicula.

#include "Video.h"

using namespace std;

//Metodo constructor default
Video::Video()
{

    iD = "0000";
    titulo = "Diego";
    duracion = 10;
    genero = "Comedia";
    calificacion = 9.7;

}

//Metodo constructor con parametros

Video::Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion)
{

    iD = _iD;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;

}

//Metodos set
void Video::setId(string _iD)
{

    iD = _iD;
}

void Video::setTitulo(string _titulo)
{

    titulo = _titulo;
}

void Video::setDuracion(int _duracion)
{

    duracion = _duracion;
}

void Video::setGenero(string _genero)
{

    genero = _genero;
}

void Video::setCalificacion(double _calificacion)
{

    calificacion = _calificacion;
}

//Metodos get
string Video::getId()
{

    return iD;
}

string Video::getNombre()
{

    return titulo;
}

int Video::getDuracion()
{

    return duracion;
}

string Video::getGenero()
{

    return genero;
}

double Video::getCalificacion()
{

    return calificacion;
}

//Metodo str
string Video::str()
{

    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion);
}

string Video::getTipo() const
{
    return "Video";
}

// Sobrecarga del operador <<
ostream& operator<<(ostream& os, const Video& video)
{
    os << fixed << setprecision(6);
    os << video.iD << "_" << video.titulo << "_" << video.duracion << "_" << video.genero << "_" << video.calificacion;
    return os;
}
