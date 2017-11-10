#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Muestra los datos de los empleados
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return void
 *
 */
void showEmployees(ArrayList* this);

/** \brief Obtiene los datos necesarios para dar de alta un empleado (id, nombre y apellido)
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return void*
 *
 */
void* obtenerDatos(ArrayList* this);

/** \brief Añade un emplado al arrayList y muestra su posicion.
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si no hay error pero no se puede añadir y 1 si ok
 *
 */
int addEmployee(ArrayList* this);

/** \brief Elimina un empleado del arrayList
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si no hay error pero no se puede eliminar y 1 si ok
 *
 */
int deleteEmployee(ArrayList* this);

/** \brief Crea una sublista con elementos especificos del arrayList
 *
 * \param this ArrayList* Puntero a Arraylist
 * \param min int Punto inicial de la nueva lista
 * \param max int Punto final de la nueva lista
 * \return int -1 Si error en los punteros, 0 si ok
 *
 */
int showFT(ArrayList* this, int min, int max);

/** \brief Obtiene los rangos para la funcion de sublista
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si ok
 *
 */
int showFromTo(ArrayList* this);

/** \brief Compara los nombres de dos Empleados
 *
 * \param a Employee* Puntero a primer empleado
 * \param b Employee* Puntero a segundo empleado
 * \return int -1 Si es menor, 0 si son iguales, 1 si es mayor
 *
 */
int sortName(Employee* a, Employee* b);

/** \brief Obtiene el index del empleado a eliminar y mostrar.
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si ok
 *
 */
int popAndShow(ArrayList* this);

/** \brief Elimina y muestra el empleado eliminado mediante un nuevo puntero.
 *
 * \param this ArrayList* Puntero a ArrayList
 * \param index int Index del elemento a eliminar
 * \return int -1 Si error en los punteros, 0 si ok
 *
 */
int popAndShowIndex(ArrayList* this,int index);

/** \brief Reemplaza un elemento en el index especificado
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si no hay error pero no se puede reemplazar y 1 si ok
 *
 */
int replaceElement(ArrayList* this);

/** \brief Añade un elemento en el index especificado sin perder elementos anteriores
 *
 * \param this ArrayList* Puntero a Arraylist
 * \return int -1 Si error en los punteros, 0 si no hay error pero no se puede añadir y 1 si ok
 *
 */
int pushElement(ArrayList* this);


#endif // FUNCIONES_H_INCLUDED
