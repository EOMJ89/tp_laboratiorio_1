#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Revisa si los operandos estan ingresados
 *
 * \param La variable flag a comparar
 * \return Si regresa 1: El operando esta ingresado.
 *         Si regresa 0: El operando aun no esta ingresao.
 */
int chequearOperandoInicializado(int aux);

/** \brief Obtiene un numero entero del 1 al 9
 *
 * \param Mensaje de error
 * \return Regresa el numero entero
 *
 */
int obtenerOpcion(char mensajeError[]);

/** \brief Imprime un mensaje por pantalla con los operandos actuales
 *
 * \param A, double
 * \param B, double
 * \return Mensaje impreso
 *
 */
void titulo();

/** \brief Obtiene un numero flotante, haya sido ingresado con o sin coma
 *
 * \param Mensaje para ingresar
 * \param Mensaje de error
 * \return Regresa el numero flotante.
 *
 */
double obtenerNumero(char mensaje[], char mensajeError[]);

/** \brief Valida un numero y lo convierte a flotante, tenga o no una coma
 *
 * \param Ingresa numeros en forma de cadena
 * \return Regresa un valor de validacion: 1.- Si se admite
 *                                         0.- Si se pide reingreso
 */
int validarNumero( char number[]);

/** \brief Suma dos variables
 *
 * \param Primer sumando de la operacion
 * \param Segundo sumando de la operacion
 * \return Resultado de la suma
 *
 */
void sumar(float numA, float numB);

/** \brief Resta dos variables
 *
 * \param El minuendo de la resta
 * \param El sustraendo de la resta
 * \return Diferencia resultante
 *
 */
void restar(float numA, float numB);

/** \brief Multiplica dos variables
 *
 * \param Primer multiplicando
 * \param Segundo multiplicando
 * \return Producto de la multiplicacion
 *
 */
void multiplicar(float numA, float numB);

/** \brief Divide dos variables
 *
 * \param Divisor
 * \param Dividiendo
 * \return Cociente y resto de la division (impreso)
 *
 */
int dividir(float numA, float numB);

/** \brief Calcula el factorial de un numero
 *
 * \param Numero a calcular factorial
 * \return No devuelve nada
 *
 */
void factorial(double numA);

/** \brief Valida un valor para permitir calcular el factorial con requisito de
 *      ser entero mayor a 0 y menor o igual a 12.
 *
 * \param Flotante y/o entero a verificar
 * \return Valor 1 si es permitido
 *         Valor 0 si no es permitido
 */
int validarParaFactorial(float numA);

#endif // FUNCIONES_H_INCLUDED
