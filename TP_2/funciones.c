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
        if(!(number[i]>=48 && number[i]<=57))
        {
            return 0;
        }
    }

    return 1;
}

int obtenerOpcion(char mensajeError[])
{
    char opcion[5];
    int opcionValida=0;
    int auxInt;

    //Obtiene el char
    fflush(stdin);
    gets(opcion);
    opcionValida=validarNumero(opcion);

    while(opcionValida==0)
    {
        //Reobtiene el char en caso de error
        printf("%s", mensajeError);
        fflush(stdin);
        gets(opcion);
        opcionValida=validarNumero(opcion);
    }

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

int obtenerEspacioLibre(ePersona lista[], int tam, int aComparar)
{
        if(lista[aComparar].estado==0)
        {
            //Devuelve el indice disponible
            return 1;
        }

    //Devuelve un ilogico.
    return 0;
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
            break;
        }
    }

    return 1;
}

int obtenerDni(char mensajeError[])
{
    char dni[21];
    int numeroValido=0;
    long int auxInt;

    fflush(stdin);
    gets(dni);
    //Obtiene las validaciones de numero y de rango
    if(validarNumero(dni)==1 && convertirValidarRango(dni, 99999999, 10000000)==1)
    {
        numeroValido=1;
    }

    while(numeroValido==0)
    {
        printf("%s", mensajeError);
        fflush(stdin);
        gets(dni);
        //Reobtiene las validaciones de numero y de rango
        if(validarNumero(dni)==1 && convertirValidarRango(dni, 99999999, 10000000)==1)
        {
            numeroValido=1;
        }
    }

    auxInt=atoi(dni);
    return auxInt;
}

int convertirValidarRango(char dni[], int max, int min)
{
    long int auxInt=atoi(dni);

    //Valida que el dni esta en rango
    if(auxInt<min || auxInt>max)
    {
        return 0;
    }

    return 1;
}

int obtenerEdad(char mensajeError[])
{
    char edad[5];
    int edadValida=0;
    int auxInt;

    //Obtiene la edad y valida
    fflush(stdin);
    gets(edad);
    if(validarNumero(edad)==1 && convertirValidarRango(edad, 120, 1)==1)
    {
        edadValida=1;
    }

    while(edadValida==0)
    {
        //Reobtiene la edad y valida nuevamente
        printf("%s", mensajeError);
        fflush(stdin);
        gets(edad);
        if(validarNumero(edad)==1 && convertirValidarRango(edad, 120, 1)==1)
        {
            edadValida=1;
        }
    }

    auxInt=atoi(edad);
    return auxInt;
}

void altaPersonas(ePersona lista[], int tam)
{
    int i;
    int flag=0;
    int nombreValido=1;

    for(i=0; i<tam; i++)
    {
        if(obtenerEspacioLibre(lista, tam, i)== 1)
        {
            flag = 1;
            lista[i].estado=1;
            printf("Ingrese dni: ");
            lista[i].dni = obtenerDni("Dni invalido. Reingrese: ");
            //Obtiene el nombre
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(lista[i].nombre);
            nombreValido= validarNombre(lista[i].nombre);

            while(nombreValido==0)
            {
                //Reobtiene el nombre en caso de error
                printf("Error, reingrese: ");
                fflush(stdin);
                gets(lista[i].nombre);
                nombreValido=validarNombre(lista[i].nombre);
            }

            printf("Ingrese edad: ");
            lista[i].edad=obtenerEdad("Edad incorrecta, reingrese: ");

            break;
        }
    }
    if(flag==0)
    {
        printf ("No hay mas espacio.\n");
    }
}

void eliminarPersona(ePersona lista[], int tam)
{
    int auxInt;
    int i;
    char rta;
    int flag = 0;

    //Obtiene el numero de dni
    printf("Ingrese el Dni: ");
    auxInt=obtenerDni("Numero invalido: ");

    for(i=0; i<tam; i++)
    {
        if(lista[i].dni==auxInt && lista[i].estado==1)//Lo encontro y esta en alta
        {
            flag = 1;
            mostrar(lista[i]);

            printf("Desea eliminar estos datos? ");
            rta = getche();
            rta = tolower(rta);
            if(rta=='s')
            {
                lista[i].estado=0;
                printf("\nDatos eliminados por el usuario.\n");
            }
            else
            {
                printf("\nAccion cancelada por el usuario.\n");
            }
            break;
        }
    }

    //Avisa que no hay una persona en alta con ese dni
    if(flag == 0)
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

void mostrar(ePersona persona)
{
    printf("\n%d--%s--%d\n", persona.dni, persona.nombre, persona.edad);
}

void imprimirGrafico(ePersona lista[], int tam)
{
    int contMenores=0, contMedios=0, contMayores=0, contPersonas=0;
    int i;

    //Obtiene la cantidad de personas y la cantidad de cada una perteneciente a los grupos
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
    if(contMenores==0 && contMedios==0 && contMayores==0)
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
