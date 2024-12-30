//Diego Garc�a Gonz�lez
//A01198976
//ITC
//Cpp Video1
//09/06/24
// Esta clase me ayudó a entender el concepto de herencia en este caso
// la clase video será mi clase padre o base y podré crear otras clases cómo derivadas o hijas
// Cómo lo son las clases de serie y pelicula.

#ifndef VIDEO_H
#define VIDEO_H

#include <string>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

//Clase de nombre "VIDEO"

class Video
{
public:
    //Metodo constructor default
    Video();
    //Metodo constructor con parametros
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacionPromedio);
    //Metodos set
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Metodos get1
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Metodo str
    virtual string str();
    virtual string getTipo() const;

    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Video& video);


protected:
    //Variables privadas
    string iD, titulo, genero;
    int duracion;
    double calificacion;
};

#endif // EPISODIO_H
