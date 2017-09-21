#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

int validarNumero(char number[])
{
    int i;

    for(i=0; i<strlen(number); i++)
    {
        if(number[i]<48 || number[i]>57)
        {
            return 0;
        }
    }

    return 1;
}

int obtenerOpcion(char mensaje[], char mensajeError[])
{
    char opcion[5];
    int opcionValida=-1;
    int auxInt;

    do
    {
        if(opcionValida==0)
        {
            printf("%s", mensajeError);
        }

        //Reobtiene el char en caso de error
        printf("%s", mensaje);
        fflush(stdin);
        gets(opcion);

        opcionValida=validarNumero(opcion);
    }while(opcionValida==0);

    auxInt=atoi(opcion);
    return auxInt;
}

void inicializarEstados(ePersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        lista[i].estado=0;
    }
}

int obtenerEspacioLibre(ePersona lista[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==0)
        {
            return i;
        }
    }

    return -1;
}

int validarNombre(char nombre[50])
{
    int i;

    //Valida que no haya caracteres fuera de las letras ordinarias('A' a 'Z' y 'a' a 'z')
    for(i=0; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>64 && nombre[i]<=122  && nombre[i]!=91 && nombre[i]!=92 && nombre[i]!=93 && nombre[i]!=94 && nombre[i]!=95 && nombre[i]!=96 && nombre[i]!=32))
        {
            return 0;
        }
    }
    return 1;
}

int convertirValidarRango(int numero, int numMin, int numMax)
{
    //Valida que el numero esta en rango
    if(numero<numMin || numero>numMax)
    {
        return 0;
    }

    return 1;
}

int obtenerNumero(char mensaje[], char mensajeError[], int numMin, int numMax)
{
    char numero[21];
    int numeroValido=1;
    long int auxInt;

    do
    {
        if (numeroValido==0)
        {
            printf("%s", mensajeError);
        }

        printf("%s", mensaje);
        fflush(stdin);
        gets(numero);

        auxInt=atoi(numero);

        if(validarNumero(numero)==1 && convertirValidarRango(auxInt, numMin, numMax)==1)
        {
            numeroValido=1;
        }
        else
        {
            if(validarNumero(numero)==0 || convertirValidarRango(auxInt, numMin, numMax)==0)
            {
                numeroValido=0;
            }
        }
    }while(numeroValido==0);

    return auxInt;
}

void altaPersonas(ePersona lista[], int tam, char mensajeNombre[], char mensajeErrorNombre[])
{
    int i;
    int nombreValido=-1;

    for(i=0; i<tam; i++)
    {
        if(obtenerEspacioLibre(lista, tam)!= -1)
        {
            lista[i].estado=1;
            lista[i].dni = obtenerNumero("Ingrese el dni: ", "Invalido.\n",9999999, 99999999);

            do
            {
                //Reobtiene el nombre en caso de error
                if(nombreValido==0)
                {
                    printf("%s", mensajeErrorNombre);
                }
                printf("%s", mensajeNombre);
                fflush(stdin);
                gets(lista[i].nombre);
                nombreValido=validarNombre(lista[i].nombre);
            }while(nombreValido==0);

            lista[i].edad=obtenerNumero("Ingrese la edad: ", "Edad invalida.\n",1, 120);
            break;
        }
    }
    if(obtenerEspacioLibre(lista, tam)== -1)
    {
        printf ("No hay mas espacio.\n");
    }
}

int buscarPorDni(ePersona lista[], int tam)
{
    int i;
    long int auxInt;
    auxInt = obtenerNumero("Ingrese el dni: ", "Invalido.\n",9999999, 99999999);

    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==auxInt && lista[i].estado==1)
        {
            return i;
        }
    }

    return -1;
}

void eliminarPersona(ePersona lista[], int tam)
{
    char rta;
    int auxPersonaInt=buscarPorDni(lista, tam);

    if(auxPersonaInt!=1)
    {
        mostrar(lista[auxPersonaInt]);

        printf("Desea eliminar estos datos? ");
        rta = getche();
        rta = tolower(rta);
        if(rta=='s')
        {
            lista[auxPersonaInt].estado=0;
            printf("\nDatos eliminados por el usuario.\n");
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
        }
    }

    //Avisa que no hay una persona en alta con ese dni
    if(auxPersonaInt == -1)
    {
    printf("Dni inexistente.\n");
    }
}

void ordenarPersonas(ePersona lista[], int tam)
{
    int i, j;
    ePersona auxPersona;

    for(i=0; i<tam-1; i++)
    {
        if(lista[i].estado==1)
        {
            for(j=i+1; j<tam; j++)
            {
                if(lista[j].estado==1)
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
                    {
                        //Ordena segun la comparacion
                        auxPersona=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxPersona;
                    }
                }
            }
        }
    }
}

void mostrar(ePersona persona)
{
    printf("\n%d--%s--%d\n", persona.dni, persona.nombre, persona.edad);
}

void mostrarPersonas(ePersona lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {
            mostrar(lista[i]);
        }

    }
}

void imprimirGrafico(ePersona lista[], int tam)
{
    int contMenores=0, contMedios=0, contMayores=0, contPersonas=0;
    int i;

    //Obtiene la cantidad de personas y la cantidad perteneciente a los grupos
    for(i=0; i<tam; i++)
    {
        if(lista[i].edad>18 && lista[i].edad<=35)
        {
            if(lista[i].estado==1)
            {
                contPersonas++;
                contMedios++;
            }
        }
        else
        {
            if(lista[i].edad<=18)
            {
                if(lista[i].estado==1)
                {
                    contPersonas++;
                    contMenores++;
                }
            }
            else
            {
                if(lista[i].estado==1)
                {
                    contPersonas++;
                    contMayores++;
                }
            }
        }
    }

    //Sale de la funcion si no hay datos en alta
    if(contPersonas==0)
    {
        printf("No hay datos.\n");
        return;
    }

    int valores[]= {contMenores, contMedios, contMayores};
    int j, max=0; //i es utilizado para el for que calcula el valor maximo y el primer for de impresion. j calcula donde posicionar los astericsos.

    //Calcula el valor maximo de los tres
    for(i=0; i<3; i++)
    {
        if(valores[i]>max)
        {
            max=valores[i];
        }
    }

    //Calcula los renglones donde se imprimiran los asteriscos
    for(i=max; i>0; i--)
    {
        //Calcula la impresion de asteriscos por renglon
        for(j=0; j<3; j++)
        {
            if(valores[j]>=i)
            {
                printf(" *   ");
            }
            else
            {
                printf("     ");
            }
        }
        printf("\n");
    }
    printf("<18 19-35 >35\n\nCantidad de personas ingresadas: %d\n", contPersonas);
}
