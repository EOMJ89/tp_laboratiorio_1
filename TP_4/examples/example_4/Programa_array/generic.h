#ifndef GENERIC_H_INCLUDED
#define GENERIC_H_INCLUDED

/** \brief Limpia la pantalla
 *
 * \return
 *
 */
void cleanScreen();

/** \brief Pausa el sistema
 *
 * \return
 *
 */
void pauseSystem();

/** \brief Baja a la siguiente linea
 *
 * \return void
 *
 */
void printNextLine();

/** \brief Obtiene una cadena sin validar
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \return
 *
 */
void getString(char*, char*, int );

/** \brief Obtiene una cadena y la valida para ser un numero flotante.
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \return
 *
 */
void getStringFloat(char*, char*, int);

/** \brief Obtiene un flotante ya validado en un rango determinado por el usuario
 *
 * \param Variable en la que se almacenara el flotante, el parametro es un puntero
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \param Rango minimo del numero
 * \param Rango maximo del numero
 * \return Entero que corrobora la validacion: 1.- Valido 0.- Invalido
 *
 */
int getFloat(float*, char*, int, int, int);

/** \brief Obtiene una cadena y la valida para ser un numero entero.
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \return
 *
 */
 void getStringInt(char*, char*, int);

 /** \brief Obtiene un entero ya validado en un rango determinado por el usuario
 *
 * \param Variable en la que se almacenara el entero, el parametro es un puntero
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \param Rango minimo del numero
 * \param Rango maximo del numero
 * \return Entero que corrobora la validacion: 1.- Valido 0.- Invalido
 *
 */
int getInt(int*, char*, int, int, int);

/** \brief Obtiene una cadena alfanumerica validada.
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \return
 *
 */
 void getStringAlphaNumeric(char*, char*, int);

 /** \brief Obtiene una cadena de letras validada, admite espacios.
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso.
 * \param Longitud maxima de la cadena
 * \return
 *
 */
void getStringAlpha(char*, char*, int);

/** \brief Obtiene un caracter
 *
 * \param Puntero con variable a modificar
 * \param Mensaje de ingreso
 * \return
 *
 */
void getStringChar(char*, char*);

#endif // GENERIC_H_INCLUDED
