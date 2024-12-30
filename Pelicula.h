//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
//Cpp Pelicula 1
// La clase de pelicula me sirvio para aprender a hacer una clase derivada usando el concepto de herencia.
// En este caso mi clase de Pelicula es la clase hija de la clase Video que es la padre.
// Aprendí a usar los atributos de la clase padre aparte agregando el atributo propio de esta clase que son los oscares.

#ifndef PELICULA_H
#define PELICULA_H

#include <stdio.h>
#include <string>
#include <iostream>
#include "Video.h"

class Pelicula : public Video
{
public:

    //Metodos Constructores
    Pelicula();
    Pelicula(string iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Metodos get y set
    void setOscares(int _oscares);
    int getOscares();

    // Metodo string
    string str();

    string getTipo() const;
    // Sobrecarga del operador <<
    friend ostream& operator <<(ostream& os, const Pelicula& pelicula);


private:

    int oscares;
};

#endif // PELICULA_H
