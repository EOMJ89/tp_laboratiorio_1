#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"
#define TAM 20


int main()
{
    char seguir='s';
    int opcion;
    ePersona listaDePersonas[TAM];
    inicializarEstados(listaDePersonas, TAM);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        opcion=obtenerOpcion("\nIngrese la opcion deseada: ", "Opcion Incorrecta.");

        switch(opcion)
        {
        case 1:
            system("cls");
            altaPersonas(listaDePersonas, TAM, "Ingrese el nombre: ", "Nombre invalido.\n");
            system("pause");
            break;
        case 2:
            system("cls");
            eliminarPersona(listaDePersonas, TAM);
            system("pause");
            break;
        case 3:
            system("cls");
            ordenarPersonas(listaDePersonas, TAM);
            mostrarPersonas(listaDePersonas,TAM);
            system("pause");
            break;
        case 4:
            system("cls");
            imprimirGrafico(listaDePersonas, TAM);
            system("pause");
            break;
        case 5:
            seguir = 'n';
            printf("Gracias por usar.\n");
            system("pause");
            break;
        default:
            printf("Opcion incorrecta.\n");
            system("pause");
        }
    }

    return 0;
}
