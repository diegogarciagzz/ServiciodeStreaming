//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
// Episodio 1
//
// Esta clase me sirvió para implementar la sobrecarga del operador "<< "
// pude realizar la sobrecarga y aplicarlo en el main para objetos de la clase episodio.

#ifndef EPISODIO_H
#define EPISODIO_H

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

//Clasde de nombre "Episodio"

class Episodio
{
public:
    //Metodo constructor default
    Episodio();
    //Metodo constructor con parametros
    Episodio(string _titulo, int _temporada, int _calificacion);
    //Metodos set
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    //Metodos get
    string getTitulo();
    int getTemporada();
    int getCalificacion();
    //Metodo str
    string str();
    // Sobrecarga del operador <<
    friend ostream& operator<<(ostream& os, const Episodio& episodio);


private:
    //Variables privadas1
    string titulo;
    int temporada, calificacion;
};

#endif // EPISODIO_H
