//Diego Garc�a Gonz�lez
//A01198976
//ITC
//09/06/24
// En esta clase me sirvió mucho el conocimiento de arreglos mas que nada para los apuntadores
// Que forman parte del tema de polimorfismo y pudimos implementarlo al proyecto de manera eficiente.
// Aprendí a leer un archivo excel de datos para que mi programa los agarre y los use.

#include "Polimorfismo.h"

//Constructor Default
Polimorfismo::Polimorfismo()
{
    // Inicializar arreglo de punteros con punteros nulos
    for (int index = 0; index < MAX_VIDEOS; index++)
    {
        arrPtrVideos[index] = nullptr;
    }

    // Inicializar cantidad de videos

    cantidad = 0;
}
//Metodos set
void Polimorfismo::setPtrVideo(int index, Video* video)
{
    if (index >= 0 && index < MAX_VIDEOS)
    {
        arrPtrVideos[index] = video;
    }
}

void Polimorfismo::setCantidad(int _cantidad)
{
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS)
    {
        cantidad = _cantidad;
    }
}
//Metodos get
Video* Polimorfismo::getPtrVideo(int index)
{
    if (index >= 0 && index < MAX_VIDEOS)
    {
        return arrPtrVideos[index];
    }
    return nullptr;
}

int Polimorfismo::getCantidad()
{
    return cantidad;
}

void Polimorfismo::reporteCalificacion(double _calificacion)
{

    int total = 0;
    for (int index = 0; index < cantidad; index++)
    {
        if (arrPtrVideos[index]->getCalificacion() == _calificacion)
        {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

void Polimorfismo::reporteGenero(string _genero)
{
    int total = 0;
    for (int index = 0; index < cantidad; index++)
    {
        if (arrPtrVideos[index]->getGenero() == _genero)
        {
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl;
}

void Polimorfismo::reportePeliculas()
{
    int totalPeliculas = 0;
    for (int index = 0; index < cantidad; index++)
    {
        if (arrPtrVideos[index]->getTipo() == "Pelicula")
        {
            cout << arrPtrVideos[index]->str() << endl;
            totalPeliculas++;
        }
    }
    if (totalPeliculas > 0)
    {
        cout << "Total Peliculas = " << totalPeliculas << endl;
    }
    else
    {
        cout << "No peliculas" << endl;
    }
}

void Polimorfismo::reporteSeries()
{
    int totalSeries = 0;
    for (int index = 0; index < cantidad; index++)
    {
        if (arrPtrVideos[index]->getTipo() == "Serie")
        {
            cout << arrPtrVideos[index]->str() << endl;
            totalSeries++;
        }
    }
    if (totalSeries > 0)
    {
        cout << "Total Series = " << totalSeries << endl;
    }
    else
    {
        cout << "No series" << endl;
    }
}

void Polimorfismo::reporteInventario()
{
    int totalPeliculas = 0;
    int totalSeries = 0;

    for (int index = 0; index < cantidad; index++)
    {
        cout << arrPtrVideos[index]->str() << endl;

        if (arrPtrVideos[index]->getTipo() == "Pelicula")
        {
            totalPeliculas++;
        }
        else if (arrPtrVideos[index]->getTipo() == "Serie")
        {
            totalSeries++;
        }
    }

    cout << "Peliculas = " << totalPeliculas << endl;
    cout << "Series = " << totalSeries << endl;
}


void Polimorfismo::leerArchivo(string nombre )
{
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    ifstream entrada;
    string row[7];         // row - arreglo de 7 elementos de strings, para almacenar los datos de la línea del archivo ya separados
    string line, word;     // line- almacena la línea leída, y word la palabra que se saca de line
    int cantidadPeliculas = 0;     //contador de peliculas y de series, inicialmente son 0
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);     // Abrir archivo de entrada

    while ( getline(entrada, line) )       // lee una línea del archivo y la almacena en line
    {
        stringstream s(line);       // usado para separar las palabras split()
        iR = 0;     // Cada vez que inicia una nueva línea inicializar iR = 0

        // Ciclo que extrae caracteres de s y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ','))
        {
            // añade word al arreglo row e incrementa iR p/la proxima palabra
            row[iR++] = word;
        }

        // Determinar si la línea es P-Pelicula, S-Serie, E-Episodio
        if (row[0] == "P")
        {
            // se crea un apuntador usando el operador new con el constructor con parámetros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            // cout << "Pelicula" << arrPeliculas[cantidadPeliculas]->str() << endl;
            cantidadPeliculas++; //inc la cantidad de peliculas
        }
        else if (row[0] == "S")
        {
            arrPtrSeries[cantidadSeries] = new Serie( row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            // cout << "Serie" << arrSeries[cantidadSeries]->str() << endl;
            cantidadSeries++;
        }
        else if (row[0] == "E")
        {
            // Calcular a qué Serie le pertenece el episodio?
            index = stoi(row[1]) - 500;
            // Se agrega el episodio usando el método agregaEpisodio
            // Se crea el apuntador y se convierte a objeto usando el operador de indireccion
            arrPtrSeries[index]->agregaEpisodio(Episodio( row[2], stoi(row[3]), stoi(row[4])));
            //cout << "Episodio" << arrSeries[index]->str() << endl;
        }
    }

    //  calculaDuracion
    for (int index = 0; index < cantidadSeries; index++)
    {
        arrPtrSeries[index]->calculaDuracion();
    }

    // fuera del ciclo
// ya se termino de leer todo el archivo ahora se guardan los
// todos los apuntadores de Película y Serie en el arrPtrVideo
// copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video calculando su calificaciónPromedio
// ya que tiene todos los episodios

    for(int index = 0; index < cantidadSeries; index++)
    {
        promedio = arrPtrSeries[index]->calculaPromedio(); // calcula la calificacion de la Serie
        arrPtrSeries[index]->setCalificacion(promedio); // cambia la calificacion de la Serie
        // añade el calcular la duración de la serie
        arrPtrSeries[index]->calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

// copiar todos los apuntadores del arreglo de Películas al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++)
    {
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /* Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base)
      - se da el POLIMORFISMO - SUPER SUPER SUPER !!,
      se ejecuta el método str() que corresponde al tipo del apuntador almacenado,
      no el correspondiente al tipo del arreglo.
      Favor de comentar el siguiente código para el Avance2
    */

    for(int index = 0; index < cantidad; index++)
    {
        // cout << index << " " << arrPtrVideos[index]->str() << endl;
    }

    entrada.close(); // cerrar el archivo

}

void Serie::calculaDuracion()
{
    int suma = 0;
    for (int index = 0; index < cantidad; index++)
    {
        suma += episodios[index].getTemporada();
    }
    duracion = suma;
}
