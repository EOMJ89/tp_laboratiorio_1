#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "generic.h"


void cleanScreen()
{
    system("cls");
}

void pauseSystem()
{
    system("pause");
}

void printNextLine()
{
    printf("\n");
}

void getString(char*dato, char*msj, int len)
{
    char buffer[1024];
    int lengthBuffer;

    do
    {
        printf("%s",msj);
        fflush(stdin);
        gets(buffer);
        lengthBuffer=strlen(buffer);
    }
    while(lengthBuffer>len);

    strcpy(dato,buffer);
}

void getStringFloat(char*dato, char*msj, int len)
{
    int i, contMenos, contPunto, lengthDato, datoValido;

    do
    {
        datoValido=0;
        getString(dato, msj, len);
        lengthDato=strlen(dato);

        contMenos=0;
        contPunto=0;

        for(i=0; i<lengthDato; i++)
        {
            if((*(dato+i) < '0' || *(dato+i) > '9') && (*(dato+i) != '-') && (*(dato+i) != '.'))
            {
                printf("Invalido.\n");
                datoValido=1;
                break;
            }
            if(*(dato+i) == '.')
            {
                contPunto++;
            }
            if(*(dato+i) == '-')
            {
                contMenos++;
            }
        }
        if(lengthDato==0)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
        if((contMenos==1 && *(dato+0)!='-') || contMenos>1 || contPunto>1)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
    }
    while(datoValido!=0);
}

int getFloat(float* flotante, char*msj, int len, int rangoMin, int rangoMax)
{
    char dato[len];
    int validNumber=1;

    getStringFloat(dato,msj,len);

    *flotante= atof(dato);

    if(*flotante<rangoMin || *flotante>rangoMax)
    {
        printf("Numero fuera de rango, reingrese.\n");
        validNumber=0;
    }

    return validNumber;
}

void getStringInt(char*dato, char*msj, int len)
{
    int i, contMenos, lengthDato, datoValido;

    do
    {
        datoValido=0;
        getString(dato, msj, len);
        lengthDato=strlen(dato);
        contMenos=0;

        for(i=0; i<lengthDato; i++)
        {
            if((*(dato+i) < '0' || *(dato+i) > '9') && (*(dato+i) != '-'))
            {
                printf("Invalido.\n");
                datoValido=1;
                break;
            }
            if(*(dato+i) == '-')
            {
                contMenos++;
            }
        }
        if(lengthDato==0)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
        if((contMenos==1 && *(dato+0)!='-') || contMenos>1)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
    }
    while(datoValido!=0);
}

int getInt(int* entero, char*msj, int len, int rangoMin, int rangoMax)
{
    char dato[len];
    int validNumber=1;

    getStringInt(dato,msj,len);

    *entero= atoi(dato);

    if(*entero<rangoMin || *entero>rangoMax)
    {
        printf("Numero fuera de rango, reingrese.\n");
        validNumber=0;
    }

    return validNumber;
}

void getStringAlphaNumeric(char*dato, char*msj, int len)
{
    int i, lengthDato, datoValido;

    do
    {
        datoValido=0;
        getString(dato, msj, len);
        lengthDato=strlen(dato);

        for(i=0; i<lengthDato; i++)
        {
            if((*(dato+i) < 'a' || *(dato+i) > 'z') && (*(dato+i) < 'A' || *(dato+i) > 'Z') && (*(dato+i) < '0' || *(dato+i) > '9') && (*(dato+i) != '.') && (*(dato+i) != ' '))
            {
                printf("Invalido.\n");
                datoValido=1;
                break;
            }
        }
        if(lengthDato==0)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
    }
    while(datoValido!=0);
}

void getStringAlpha(char*dato, char*msj, int len)
{
    int i, lengthDato, datoValido;

    do
    {
        datoValido=0;
        getString(dato, msj, len);
        lengthDato=strlen(dato);

        for(i=0; i<lengthDato; i++)
        {
            if((*(dato+i) < 'a' || *(dato+i) > 'z') && (*(dato+i) < 'A' || *(dato+i) > 'Z') && (*(dato+i) != ' '))
            {
                printf("Invalido.\n");
                datoValido=1;
                break;
            }
        }

        if(lengthDato==0)
        {
            printf("Invalido.\n");
            datoValido=1;
        }
    }
    while(datoValido!=0);
}

void getStringChar(char*charIngresed, char*msj)
{
    char dato[5];
    getString(dato,msj,5);

    *charIngresed=dato[0];
}
