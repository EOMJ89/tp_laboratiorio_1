#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic.h"
#include "funciones.h"

#define MOVIES_AM 20

int main()
{
    sMovie allMovies[MOVIES_AM];
    char seguir='s';
    char guardar;
    int opcion;
    inicializarEstados(allMovies, MOVIES_AM);

    if(cargarDesdeArchivo(allMovies, MOVIES_AM))
    {
        printf("No se pudo abrir el fichero.\n");
    }
    else
    {
        printf("Datos cargados.\n");
    }
    system("pause");

    do
    {
        cleanScreen();
        opcion=0;
        opcion=getOpcionMenu();

        switch(opcion)
        {
        case 1:
            cleanScreen();
            agregarPelicula(allMovies, MOVIES_AM);
            pauseSystem();
            break;
        case 2:
            cleanScreen();
            borrarPelicula(allMovies, MOVIES_AM);
            pauseSystem();
            break;
        case 3:
            cleanScreen();
            modificarPelicula(allMovies, MOVIES_AM);
            pauseSystem();
            break;
        case 4:
            cleanScreen();
            generarPagina(allMovies, MOVIES_AM);
            pauseSystem();
            break;
        case 5:
            cleanScreen();
            if(!(mostrarMovies(allMovies, MOVIES_AM)))
            {
                printf("\nNo hay nada que mostrar.\n");
            }
            pauseSystem();
            break;
        case 6:
            getStringChar(&guardar,"\nGuardar cambios?\nS- Si\nN- No\nC-Cancelar: ");

            if(guardar == 's')
            {
                if(guardarEnArchivo(allMovies, MOVIES_AM))
                {
                    printf("\nError, no se ha podido abrir el archivo.\n");
                }
                else
                {
                    printf("\nLa informacion ha sido guardada exitosamente.\n");
                }
            }
            else
            {
                if(guardar=='c')
                {
                    printf("\nSalida cancelada.\n");
                    pauseSystem();
                    break;
                }
            }
            seguir = 'n';
            break;
        default:
            printf("\nIncorrecto.\n");
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
