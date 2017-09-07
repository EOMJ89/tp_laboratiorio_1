#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

int chequearOperandoInicializado(int aux)
{
    if(aux==1)
    {
        return 1;
    }

    return 0;
}

int obtenerOpcion(char mensajeError[])
{
    char opcion[10];
    int opcionValida=0;
    int num;

    fflush(stdin);
    gets(opcion);
    //Envia a validar
    opcionValida=validarNumero(opcion);

    while(opcionValida==0)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(opcion);
        opcionValida=validarNumero(opcion);
    }

    num=atoi(opcion);
    return num;
}

void titulo()
{
    printf("______________________________\n\n      Calculadora V1\n______________________________\n\n");
}

double obtenerNumero(char mensaje[], char mensajeError[])
{
    char number[21];
    int numeroValido=0;
    double num;

    printf("%s", mensaje);
    fflush(stdin);
    gets(number);
    //Envia a validar
    numeroValido=validarNumero(number);

    while(numeroValido==0)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(number);
        numeroValido=validarNumero(number);
    }

    num=atof(number);

    return num;
}

int validarNumero(char number[])
{
    int i;
    int contPuntos=0;
    int contMenos=0;

    for(i=0; i<strlen(number); i++)
    {
        if(!(number[i]>=45 && number[i]<=57 && number[i]!=47))
        {

            return 0;
        }

        //Busca existencias de '-' y '.'
        if (number[i]==45)
        {
            contPuntos++;
        }
        if (number[i]==46)
        {
            contMenos++;
        }
        //Si encuentra mas de un '-' o '.'
        if(contPuntos>1 || contMenos>1)
        {
            return 0;
        }
        if(strlen(number)==1)
        {
            if(contPuntos==1 || contMenos==1)
            {
                return 0;
            }
        }
        //Si hay un '-' o '.' pero solo la cadena solo tiene 2 caracteres
        if(strlen(number)==2 && contPuntos==1 && contMenos==1)
        {
            return 0;
        }

    }

    return 1;
}

void sumar(float numA, float numB)
{
    float resultado = numA+numB;

    printf("El resultado de la suma es entre %.5f y %.5f es : %.5f\n\n",numA, numB, resultado);
}

void restar(float numA, float numB)
{
    float resultado = numA-numB;

    printf("El resultado de la resta entre %.5f y %.5f es : %.5f\n\n",numA, numB, resultado);
}

void multiplicar(float numA, float numB)
{
    float resultado = numA*numB;

    printf("El resultado de la multiplicacion entre %.5f y %.5f es : %.5f\n\n",numA, numB, resultado);
}

int dividir(float numA, float numB)
{
    double resultado = numA/numB;

    if(numB==0)
    {
        printf("El divisor es 0, imposible realizar la operacion.\n\n");
        return 0;
    }
    else
    {
        printf("El resultado de la division entre %.5f y %.5f es : %.5f\n\n",numA, numB, resultado);
        return 1;
    }
}

void factorial(double num)
{
    unsigned long long int fact=1;
    int i;

    if(validarParaFactorial(num)==1)
    {
        for(i=1; i<=num; i++)
        {
            fact= i*fact;
        }
        printf("El factorial de %.0f es igual a : %llu\n\n",num, fact);
    }
    else
    {
        printf("Error. Ingrese un numero entero positivo menor a 20.\n\n");
    }
}

int validarParaFactorial(float num)
{
    if(!((num-(int)num)==0) || (int)num<0 || (int)num>20)
    {
        return 0;
    }

    return 1;
}
