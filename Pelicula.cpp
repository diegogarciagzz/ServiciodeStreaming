//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
//Cpp Pelicula 1
// La clase de pelicula me sirvio para aprender a hacer una clase derivada usando el concepto de herencia.
// En este caso mi clase de Pelicula es la clase hija de la clase Video que es la padre.
// Aprendí a usar los atributos de la clase padre aparte agregando el atributo propio de esta clase que son los oscares.

#include "Pelicula.h"

//Metodos Constructor default
Pelicula::Pelicula(): Video()
{
    oscares = 100;
}

//Metodos Constructor con Paramteros
Pelicula::Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion)
{
    oscares = _oscares;
}

// Metodos get y set1
void Pelicula::setOscares(int _oscares)
{
    oscares = _oscares;
}

int Pelicula::getOscares()
{
    return oscares;
}

// Metodo string
string Pelicula::str()
{
    return iD + " " + titulo + " " + to_string(duracion) + " " + genero + " " + to_string(calificacion) + " " + to_string(oscares);
}

// Metodo para obtener el tipo de Video
string Pelicula::getTipo() const
{
    return "Pelicula";
}

// Sobrecarga del operador <<
ostream& operator <<(ostream& os, const Pelicula& pelicula)
{
    os << pelicula.iD << "_" << pelicula.titulo << "_" << pelicula.duracion << "_" << pelicula.genero << "_" << pelicula.calificacion << "_" << pelicula.oscares;
    return os;
}
