//
//  main.cpp
//  Tarea3 y Actividad Presencial 23/05/24
//
//  Created by Ma. Guadalupe Roque Díaz de León on 23/05/24.
//

// Clases Base - Video - con método virtual str() para Poliformismo
// Clases Derivadas - Pelicula, Serie
// Clase usada para composición - Episodio
// Arreglo de apuntadores


//Diego Garcia Gonz�lez
//A01198976
//ITC

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"

#include <string>
using namespace std;


int main() {
    // Declaracion de objetos
    Polimorfismo neflix;

    int opcion;

    // leer la opcion
    cin >> opcion;

    switch (opcion){

        case 1:
           neflix.leerArchivo("C:\\Users\\diego\\OneDrive\\Datos adjuntos\\Documentos\\GitHub\\Proyecto_2\\Inventario1.csv");
           break;

        case 2:
          neflix.leerArchivo("C:\\Users\\diego\\OneDrive\\Datos adjuntos\\Documentos\\GitHub\\Proyecto_2\\Inventario2.csv");
          break;

    default:
          cout << "incorrecta" ;
    }

    return 0;
}
