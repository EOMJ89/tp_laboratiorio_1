#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "../inc/ArrayList.h"
#include "Employee.h"
#include "generic.h"
#include "funciones.h"

int main()
{
    FILE* fEmployee=NULL;
    ArrayList* lista =al_newArrayList();
    ArrayList* duplicateList =al_newArrayList();
    char mensaje[]="\nMenu:\
    \n1. Parse del archivo data.csv\
    \n2. Listar Empleados\
    \n3. Ordenar por nombre\
    \n4. Agregar un elemento\
    \n5. Elimina un elemento\
    \n6. Listar Empleados (Desde/Hasta)\
    \n7. Eliminar un empleado y mostrarlo.\
    \n8. Reemplaza un elemento en posicion elegida.\
    \n9. Añade un elemento en posicion elegida.\
    \n10. Reiniciar lista.\
    \n11. Duplicar lista.\
    \n12. Comparar lista.\
    \n13. Salir.\n\
    \nIngrese: ";
    char seguir='s';
    int opcion, auxExtra;

    do
    {
        cleanScreen();
        opcion=0;
        getInt(&opcion, mensaje, 50, -1000, 1000);

        switch(opcion)
        {
        case 1:
            printf("Carga los datos de archivo.\n");
            parserEmployee(fEmployee, lista);
            printf("\nDatos Cargados.\n");
            pauseSystem();
            break;
        case 2:
            printf("Muestra los datos.\n");
            showEmployees(lista);
            pauseSystem();
            break;
        case 3:
            printf("Ordenar por nombre.\n");
            lista->sort(lista,sortName,1);
            pauseSystem();
            break;
        case 4:
            printf("Agregar un elemento.\n");
            addEmployee(lista);
            pauseSystem();
            break;
        case 5:
            printf("Elimina un elemento.\n");
            deleteEmployee(lista);
            pauseSystem();
            break;
        case 6:
            printf("Listar (Desde/Hasta).\n");
            showFromTo(lista);
            pauseSystem();
            break;
        case 7:
            printf("Elimina un emplado y lo muestra.\n");
            popAndShow(lista);
            pauseSystem();
            break;
        case 8:
            printf("Reemplaza un elemento.\n");
            replaceElement(lista);
            pauseSystem();
            break;
        case 9:
            printf("Añade un elemento en posicion elegida.\n");
            pushElement(lista);
            pauseSystem();
            break;
        case 10:
            printf("Reiniciar lista.\n");
            lista->clear(lista);
            pauseSystem();
            break;
        case 11:
            printf("Duplicar lista.\n");
            duplicateList= duplicateList->clone(lista);
            pauseSystem();
            break;
        case 12:
            printf("Compara listas.\n");
            if(duplicateList->isEmpty(duplicateList)==0)
            {
                auxExtra=duplicateList->containsAll(lista, duplicateList);
                if(auxExtra==1)
                {
                    printf("Contiene todos los elementos.\n");
                }
                else
                {
                    if(auxExtra==0)
                    {
                        printf("NO contiene todos los elementos.\n");
                    }
                }
            }
            else
            {
                printf("La lista 2 no esta cargada, seleccione opcion 11 primero.\n");
            }
            pauseSystem();
            break;
        case 13:
            seguir='n';
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
