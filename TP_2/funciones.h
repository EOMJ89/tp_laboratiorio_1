#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int estado;
} ePersona;

/** \brief Valida un numero ingresado por parametro.
 *
 * \param Numero a validar en string.
 * \return Devuelve un valor 1 si es valido, 0 si no lo es.
 *
 */
int validarNumero(char number[]);

/** \brief Obtiene un entero validado.
 *
 * \param Mensaje para ingreso.
 * \param Mensaje de error.
 * \return Entero positivo para opcion.
 *
 */
int obtenerOpcion(char mensaje[], char mensajeError[]);

/** \brief Inicializa todos los estados en 0.
 *
 * \param La lista de personas, en array.
 * \param Tamanio del array.
 * \return
 *
 */
void inicializarEstados(ePersona lista[], int tam);

/** @brief Obtiene el primer indice libre del array.
 *
 * @param Lista el array se pasa como parametro.
 * @param Tamanio del array.
 * @return El primer indice disponible o un ilogico.
 *
 */
int obtenerEspacioLibre(ePersona lista[], int tam);

/** \brief Valida una palabra sin caracteres especiales.
 *
 * \param La palabra a validar, en string.
 * \return 1 si es valido, 0 si no lo es.
 *
 */
int validarNombre(char nombre[50]);

/** \brief Obtiene un numero positivo, validado en un rango especifico.
 *
 * \param Mensaje de ingreso.
 * \param Mensaje de error.
 * \param Rango minimo.
 * \param Rango maximo.
 * \return Devuelve un entero dentro del rango.
 *
 */
int obtenerNumero(char mensaje[], char mensajeError[], int numMin, int numMax);

/** \brief Valida el rango de un numero.
 *
 * \param El numero a validar.
 * \param Maximo del rango.
 * \param Minimo del rango.
 * \return 1 si esta dentro, 0 si no lo esta.
 *
 */
int convertirValidarRango(int numero, int numMin, int numMax);

/** \brief Obtiene los datos de una persona y los da en alta.
 *
 * \param La lista de personas.
 * \param El tamaño del array.
 * \param Mensaje de ingreso.
 * \param Mensaje de error.
 * \return
 *
 */
void altaPersonas(ePersona lista[], int tam, char mensajeNombre[], char mensajeErrorNombre[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni);

/** \brief Elimina los datos de una persona al darlos de baja.
 *
 * \param La lista de personas.
 * \param El tamaño del array.
 * \return
 *
 */
void eliminarPersona(ePersona lista[], int tam);

/** \brief Ordena los los datos de una persona en relacion al nombre.
 *
 * \param La lista de personas.
 * \param El tamaño del array.
 * \return
 *
 */
void ordenarPersonas(ePersona lista[], int tam);

/** \brief Muestra una sola persona.
 *
 * \param Variable ePersona.
 * \param El tamaño del array.
 * \return
 *
 */
void mostrar(ePersona persona);

/** \brief Muestra la lista de personas completa.
 *
 * \param La lista de personas.
 * \param El tamaño del array.
 * \return
 *
 */
void mostrarPersonas(ePersona lista[], int tam);

/** \brief Imprime el grafico de personas
 *
 * \param La lista de personas
 * \param El tamaño del array
 * \return
 *
 */
void imprimirGrafico(ePersona lista[], int tam);
#endif // FUNCIONES_H_INCLUDED
