#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion;
    double primerOperando;
    double segundoOperando;
    int primerOperandoFlag=0;
    int segundoOperandoFlag=0;


    while(seguir=='s')
    {
        system("cls");
        titulo(primerOperando, segundoOperando);
        /* Controla que los operandos se impriman si es que estan ingresados
        dentro del programa. */
        if(chequearOperandoInicializado(primerOperandoFlag)==1)
        {
            printf("1- Ingresar 1er operando (A=%.2f)\n", primerOperando);
        }
        else
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        if(chequearOperandoInicializado(segundoOperandoFlag)==1)
        {
            printf("2- Ingresar 2do operando (B=%.2f)\n", segundoOperando);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        //Obtiene opcion ingresada por usuario
        opcion=obtenerOpcion("Opcion incorrecta.\n\n");

        switch(opcion)
        {
        case 1://Obtener  primer operando
            system("cls");
            titulo(primerOperando, segundoOperando);
            primerOperando=obtenerNumero("Ingrese el 1\247 operando: ", "Error, reingrese el 1\247 operando: ");
            printf("El 1\247 operando es: %f\n\n", primerOperando);
            primerOperandoFlag=1;
            system("pause");
            break;
        case 2://Obtener segundo operando
            system("cls");
            titulo(primerOperando, segundoOperando);
            segundoOperando=obtenerNumero("Ingrese el 2\247 operando: ", "Error, reingrese el 2\247 operando: ");
            printf("El 2\247 operando es: %f\n\n", segundoOperando);
            segundoOperandoFlag=1;
            system("pause");
            break;
        case 3://Realizar suma
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1 || chequearOperandoInicializado(segundoOperandoFlag)!=1)
            {
                printf("Error. Falta un Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            sumar(primerOperando, segundoOperando);
            system("pause");
            break;
        case 4://Realizar resta
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1 || chequearOperandoInicializado(segundoOperandoFlag)!=1)
            {
                printf("Error. Falta un Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            restar(primerOperando, segundoOperando);
            system("pause");
            break;
        case 5://Realizar division
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1 || chequearOperandoInicializado(segundoOperandoFlag)!=1)
            {
                printf("Error. Falta un Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            dividir(primerOperando, segundoOperando);
            system("pause");
            break;
        case 6://Realizar producto
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1 || chequearOperandoInicializado(segundoOperandoFlag)!=1)
            {
                printf("Error. Falta un Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            multiplicar(primerOperando, segundoOperando);
            system("pause");
            break;
        case 7://Obtener factorial del primer operando
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1)
            {
                printf("Error. Falta el Primer Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            factorial(primerOperando);
            system("pause");
            break;
        case 8://Todas las operaciones (solo funciona con ambos operandos ingresados
            system("cls");
            if(chequearOperandoInicializado(primerOperandoFlag)!=1 || chequearOperandoInicializado(segundoOperandoFlag)!=1)
            {
                printf("Error. Falta un Operando.\n");
                system("pause");
                break;
            }
            titulo(primerOperando, segundoOperando);
            sumar(primerOperando, segundoOperando);
            restar(primerOperando, segundoOperando);
            dividir(primerOperando, segundoOperando);
            multiplicar(primerOperando, segundoOperando);
            factorial(primerOperando);
            system("pause");
            break;
        case 9://Salir del programa
            system("cls");
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n\n");
            seguir = 's';
            break;
        }
    }
    return 0;
}


