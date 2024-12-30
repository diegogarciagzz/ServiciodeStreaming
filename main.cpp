//
//  main.cpp
//  Tarea3 y Actividad Presencial 23/05/24
/*
Nombre: Diego García
Matricula:A01198976
Carrera: ITC
Fecha:1 JUNIO

- ¿Qué aprendí en el desarrollo de la clase Polimorfismo?
Gracias a este proyecto aprendí a usar el polimorfismo aplicado a la herencia ussando clases bases y clases derivadas, ademas
incluí aspectos cómo la composicion para usar atributos de otra clase.
*/

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"

#include <string>
using namespace std;

void polimorfismo(Polimorfismo inventario)
{
    // Declaración de variables locales
    int opcion;
    double calificacion;
    string genero;

    cin >> opcion;

    switch (opcion)
    {
    case 1:
        cin >> calificacion;
        inventario.reporteCalificacion(calificacion);
        break;

    case 2:
        cin >> genero;
        inventario.reporteGenero(genero);
        break;

    case 3:
        inventario.reporteInventario();
        break;

    case 4:
        inventario.reportePeliculas();
        break;

    case 5:
        inventario.reporteSeries();
        break;

    default:
        cout << "Error\n";
        break;
    }
}

int main() {

    Video viernes("100", "Computer", 100, "Ing.", 100);
    Episodio episodio("ExitoDTB", 100, 100);
    Pelicula pelicula("007", "Xochitl", 2024, "PANPRI", 100, 100);

    // Pruebas de la sobrecarga del operador <<
    cout << viernes << endl; // sobrecarga del operador <<
    cout << viernes.str() << endl;
    cout << pelicula << endl; // sobrecarga del operador <<
    cout << pelicula.str() << endl;
    cout << episodio << endl; // sobrecarga del operador <<
    cout << episodio.str() << endl;

    return 0;
}
