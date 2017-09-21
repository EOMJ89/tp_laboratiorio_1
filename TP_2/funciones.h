#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
}ePersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param tamanio del array.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(ePersona lista[], int tam, int aComparar);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);

/** \brief Obtiene un entero positivo.
 *
 * \param Mensaje de error
 * \return entero positivo para opcion
 *
 */
int obtenerOpcion(char mensajeError[]);

/** \brief Valida un numero ingresado por parametro.
 *
 * \param Numero a validar en string
 * \return Devuelve un valor 1 si es valido, 0 si no lo es.
 *
 */
int validarNumero(char number[]);

/** \brief Valida el rango de un numero
 *
 * \param el dni a validar, en cadena
 * \param maximo del rango
 * \param minimo del rango
 * \return 1 si esta dentro, 0 si no lo esta
 *
 */
int convertirValidarRango(char dni[], int max, int min);

/** \brief Obtiene los datos de una persona y los da en alta
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void altaPersonas(ePersona lista[], int tam);

/** \brief Valida el rango de un numero
 *
 * \param el nombre a validar, en cadena
 * \return 1 si es valido, 0 si no lo es
 *
 */
int validarNombre(char nombre[50]);

/** \brief Obtiene un numero de dni, mayor a 10 millones.
 *
 * \param Mensaje de error
 * \return Devuelve un entero mayor a 10 millones
 *
 */
int obtenerDni(char mensajeError[]);

/** \brief Obtiene un numero de edad.
 *
 * \param Mensaje de error
 * \return Devuelve un entero mayor 0 y menor a 120
 *
 */
int obtenerEdad(char mensajeError[]);

/** \brief Elimina los datos de una persona.
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void eliminarPersona(ePersona lista[], int tam);

/** \brief Ordena los los datos de una persona en relacion al nombre
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void ordenarPersonas(ePersona lista[], int tam);

/** \brief Muestra la lista de personas
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void mostrarPersonas(ePersona lista[], int tam);

/** \brief Muestra una sola persona
 *
 * \param Variable ePersona
 * \param El tamaño del array
 * \return
 *
 */
void mostrar(ePersona persona);

/** \brief Imprime el grafico de personas
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void imprimirGrafico(ePersona lista[], int tam);

/** \brief Valida el rango de un numero
 *
 * \param la lista de personas, en array
 * \param tamanio del array
 * \return
 *
 */
void inicializarEstados(ePersona lista[], int tam);

#endif // FUNCIONES_H_INCLUDED
