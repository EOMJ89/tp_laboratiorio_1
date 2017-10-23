#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int id;
    char titulo[75];
    char genero[20];
    int duracion;
    char descripcion[1024];
    int puntaje;
    char linkImagen[250];
    int estado;
} sMovie;

/** \brief Obtiene una opcion del menu
 *
 * \return Entero para opción de menu
 *
 */
int getOpcionMenu();

/** \brief Inicializa los estados e IDs de las peliculas
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 * \return
 *
 */
void inicializarEstados(sMovie* movies, int moviesAmount);

/** \brief Carga los datos de un archivo binario
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 * \return 0 si se ha cargado de forma exitosa, 1 si ha habido error
 *
 */
int cargarDesdeArchivo(sMovie *x,int moviesAmount);

/** \brief Guarda los datos de un archivo binario
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 * \return 0 si se ha guardado de forma exitosa, 1 si ha habido error
 *
 */
int guardarEnArchivo(sMovie *x,int moviesAmount);

/** \brief Busca un lugar libre en el array de peliculas
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 * \return Entero con la posición libre
 *
 */
int buscarLibre(sMovie* movies, int moviesAmount);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(sMovie* movies, int moviesAmount);

/** \brief Muestra una sola peliculas
 *
 * \param Puntero a peliculas
 * \return
 *
 */
void mostrarMovie(sMovie* movie);

/** \brief Muestra las peliculas en el array
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 *  @return retorna 1 o 0 de acuerdo a si ha mostrado una pelicula o no
 *
 */
int mostrarMovies(sMovie* movies, int moviesAmount);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(sMovie* movies, int moviesAmount);

/** \brief Modifica las opciones de las peliculas
 *
 * \param Puntero a peliculas
 * \param Entero con la opción de dato a ser cambiado
 * \param Char con la elección para continuar
 * \return
 *
 */
void modificarOpciones(sMovie* movies,int cambio, char* continuar);

/** \brief Permite la modificación de los datos de una pelicula
 *
 * \param Puntero a peliculas
 * \param Cantidad maxima de peliculas
 * \return Entero -1 por si se ha modificado
 *                -0 si no se ha modificado
 *
 */
int modificarPelicula(sMovie* movies, int moviesAmount);

/**
 *  @brief Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(sMovie* movies, int moviesAmount);

#endif // FUNCIONES_H_INCLUDED
