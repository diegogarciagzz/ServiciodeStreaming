//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
//Cpp Episodio 1
//
// Esta clase me sirvió para implementar la sobrecarga del operador "<< "
// pude realizar la sobrecarga y aplicarlo en el main para objetos de la clase episodio.

#include "Episodio.h"

//Constructor normal o default
Episodio::Episodio()
{
    titulo = "";
    temporada = 0;
    calificacion = 0;
}

//Constructor Con Parametros
Episodio::Episodio(string _titulo, int _temporada, int _calificacion)
{

    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;

}

//Metodos sets
void Episodio::setTitulo(string _titulo)
{

    titulo = _titulo;

}
void Episodio::setTemporada(int _temporada)
{

    temporada = _temporada;

}
void Episodio::setCalificacion(int _calificacion)
{

    calificacion = _calificacion;

}

//Metodos get
string Episodio::getTitulo()
{

    return titulo;
}
int Episodio::getTemporada()
{

    return temporada;

}
int Episodio::getCalificacion()
{

    return calificacion;
}

//Metodos string que retorna el contenido final.
string Episodio::str()
{


    return titulo + " " + to_string(temporada) + " " + to_string(calificacion);
}

// Sobrecarga del operador <<
ostream& operator<<(ostream& os, const Episodio& episodio)
{
    os << episodio.titulo << "_" << episodio.temporada << "_" << episodio.calificacion;
    return os;
}
