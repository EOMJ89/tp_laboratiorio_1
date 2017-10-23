#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "generic.h"
#include "funciones.h"

#define MOVIES_AM 10

int getOpcionMenu()
{
    int option;

    char mensaje[]="\n1- Agregar pelicula\
        \n2- Borrar pelicula\
        \n3- Modificar pelicula\
        \n4- Generar pagina web\
        \n5- Mostrar todas las peliculas\n\
        \n6- Salir\n";
    getInt(&option, mensaje, 50, -1000, 1000);
    return option;
}

void inicializarEstados(sMovie* movies, int moviesAmount)
{
    int i;

    for(i=0; i<moviesAmount; i++)
    {
        (movies+i)->estado=0;
        (movies+i)->id=-1;
    }
}

int cargarDesdeArchivo(sMovie *x,int moviesAmount)
{
    int flag=0;
    FILE *f;

    f=fopen("bin.dat","rb");
    if(f==NULL)
    {
        f=fopen("bin.dat","wb");
        if(f==NULL)
        {
            return 1;
        }
        flag=1;
    }

    if(flag==0)
    {
        fread(x,sizeof(sMovie),moviesAmount,f);
    }
    fclose(f);
    return 0;
}

int guardarEnArchivo(sMovie *x,int moviesAmount)
{
    FILE *f;

    f=fopen("bin.dat","wb");
    if(f==NULL)
    {
        return 1;
    }

    fwrite(x,sizeof(sMovie),moviesAmount,f);

    fclose(f);
    return 0;
}

void mostrarMovie(sMovie* movie)
{
    printf("ID: %d\nTitulo: %s\nGenero: %s\nDuracion: %d\nPuntaje: %d\nDescripcion: %s\nLink Imagen: %s", movie->id,movie->titulo,movie->genero,movie->duracion,movie->puntaje,movie->descripcion,movie->linkImagen);
    printNextLine();
}

int mostrarMovies(sMovie* movies, int moviesAmount)
{
    int i, salida=0;

    for(i=0; i<moviesAmount; i++)
    {
        if((movies+i)->estado)
        {
            mostrarMovie((movies+i));
            printNextLine();
            salida=1;
        }
    }
    return salida;
}

int buscarLibre(sMovie* movies, int moviesAmount)
{
    int id=-1;
    int i;
    for(i=0; i<moviesAmount; i++)
    {
        if((movies+i)->estado==0)
        {
            id=i;
            break;
        }
    }
    return id;
}

int agregarPelicula(sMovie* movies, int moviesAmount)
{
    int idMovie, i, nValido;
    int id;
    int repite=0;

    /*Busca el primer indice libre*/
    idMovie=buscarLibre(movies, moviesAmount);

    if(idMovie!=-1)//En caso de hallar lugar disponible
    {
        printf("Alta de Pelicula:\n");
        printNextLine();

        do
        {
            nValido=getInt(&id, "Ingrese id: ", 50, 0, 10000);
            printNextLine();
        }
        while(nValido!=1);

        /*Busca si no hay otra pelicula con dicho id*/
        for(i=0; i<moviesAmount; i++)
        {
            if(id==(movies+i)->id)
            {
                repite=1;//Hay otra pelicula con el mismo id
                break;
            }
        }
        if(!repite)//Entras si repite==0
        {
            (movies+idMovie)->id=id;

            getStringAlphaNumeric((movies+idMovie)->titulo, "Ingrese el titulo: ", 75);
            printNextLine();

            getStringAlpha((movies+idMovie)->genero, "Ingrese el genero: ", 20);
            printNextLine();

            do
            {
                nValido=getInt(&(movies+idMovie)->duracion, "Ingrese la duracion en minutos: ", 50, 0, 500);
                printNextLine();
            }
            while(nValido!=1);

            getStringAlphaNumeric((movies+idMovie)->descripcion, "Ingrese la descripcion: ", 1024);
            printNextLine();

            do
            {
                nValido=getInt(&(movies+idMovie)->puntaje, "Ingrese el puntaje: ", 50, 0, 500);
                printNextLine();
            }
            while(nValido!=1);

            getStringLinks((movies+idMovie)->linkImagen, "Ingrese el link de la imagen: ", 250);
            printNextLine();

            (movies+idMovie)->estado=1;

            printf("Creada con exito.\n");
            return 1;
        }
        else
        {
            printf("Error, ya hay una pelicula con ese ID.");
            printNextLine();
        }
    }
    else
    {
        printf("No queda espacio.");
        printNextLine();
    }

    return 0;
}

void mostrarIdT(sMovie* movie)
{
    printf("ID: %d\nTitulo: %s\n", movie->id,movie->titulo);
}

int mostrarIdTitulo(sMovie* movies, int moviesAmount)
{
    int i, salida=0;

    for(i=0; i<moviesAmount; i++)
    {
        if((movies+i)->estado)
        {
            mostrarIdT((movies+i));
            printNextLine();
            salida=1;
        }
    }
    return salida;
}

int borrarPelicula(sMovie* movies, int moviesAmount)
{
    int id, flag=0,i, nValido;
    char opcion;

    mostrarIdTitulo(movies, moviesAmount);

    do
    {
        nValido=getInt(&id, "Ingrese id: ", 50, -1, 500);
        printNextLine();
    }
    while(nValido!=1);

    if(id==-1)
    {
        printf("Accion cancelada.\n");
        return 0;
    }

    for(i=0; i<moviesAmount; i++)
    {
        if(id==(movies+i)->id)
        {
            printf("Datos a eliminar:\n");
            printNextLine();

            mostrarMovie((movies+i));

            printNextLine();
            getStringChar(&opcion,"ID encontrado.\nSeguro desea dar de baja? ");

            if(opcion=='s')
            {
                (movies+i)->estado=0;
                (movies+i)->id=-1;
                printf("El registro ha sido eliminado.");
                printNextLine();
                return 1;
            }
            else
            {
                printf("El registro no ha sido eliminado.");
                printNextLine();
            }
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Pelicula inexistente.");
        printNextLine();
    }

    return 0;
}

int modificarPelicula(sMovie* movies, int moviesAmount)
{
    int id, flag=0,i,nValido,opcionCambio;
    char continuar;

    mostrarIdTitulo(movies, moviesAmount);

    do
    {
        nValido=getInt(&id, "Ingrese ID de pelicula a modificar: ", 50, -1, 500);
        printNextLine();
    }
    while(nValido!=1);
    if(id==-1)
    {
        printf("Accion cancelada.\n");
        return 0;
    }
    for(i=0; i<moviesAmount; i++)
    {
        if(id==(movies+i)->id)
        {
            printf("Datos encontrados:");
            printNextLine();

            do
            {
                cleanScreen();
                mostrarMovie((movies+i));

                do
                {
                    printNextLine();
                    nValido=getInt(&opcionCambio, "Que desea cambiar?\n1- Titulo\n2- Descripcion\n3- Genero\n4- Duracion\n5- Puntaje\n6- Link de imagen\n7.-Cancelar/Salir\n\nIngrese: ",50,-1000,1000);
                }
                while(nValido!=1);

                modificarOpciones(movies+i,opcionCambio, &continuar);
            }
            while(continuar!='n');

            flag=1;
            return 1;
        }
    }
    if(flag==0)
    {
        printf("Pelicula inexistente.");
        printNextLine();
    }
    return 0;
}

void modificarOpciones(sMovie* movies,int cambio, char* continuar)
{
    int auxDuracion, auxPuntaje, nValido;
    char rta;
    char auxTitulo[20];
    char auxDescripcion[1024];
    char auxGenero[20];
    char auxLink[250];

    switch(cambio)
    {
    //Cambiar Titulo
    case 1:
        getStringAlphaNumeric(auxTitulo, "Ingrese el nuevo titulo: ", 75);
        printNextLine();

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            strcpy(movies->titulo, auxTitulo);
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Cambiar Descripcion
    case 2:
        getStringAlphaNumeric(auxDescripcion, "Ingrese la nueva descripcion: ", 1024);
        printNextLine();

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            strcpy(movies->descripcion, auxDescripcion);
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Cambiar genero
    case 3:
        getStringAlpha(auxGenero, "Ingrese el nuevo genero: ", 20);
        printNextLine();

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            strcpy(movies->genero, auxGenero);
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Cambiar duracion
    case 4:
        do
        {
            nValido=getInt(&auxDuracion, "Ingrese la nueva duracion en minutos: ", 50, 0, 500);
            printNextLine();
        }
        while(nValido!=1);

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            movies->duracion=auxDuracion;
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Cambiar puntaje
    case 5:
        do
        {
            nValido=getInt(&auxPuntaje, "Ingrese la nuevo puntaje: ", 50, 0, 500);
            printNextLine();
        }
        while(nValido!=1);

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            movies->puntaje=auxPuntaje;
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Cambiar link de imagen
    case 6:
        getStringLinks(auxLink, "Ingrese el nuevo link de imagen: ", 250);
        printNextLine();

        getStringChar(&rta, "Desea cambiar los datos? ");
        if(rta=='s')
        {
            strcpy(movies->linkImagen, auxLink);
            printf("\nDatos cambiados exitosamente.\n");
            break;
        }
        else
        {
            printf("\nAccion cancelada por el usuario.\n");
            break;
        }
    //Salir de la modificacion
    case 7:
        *continuar='n';
        break;
    default:
        printf("Incorrecto.\n");
    }
}

void generarPagina(sMovie* movies, int moviesAmount)
{
    int i;
    FILE *htmlMovies;
    htmlMovies=fopen("exit_doc/index.html","w");
    if(htmlMovies==NULL)
    {
        printf("No se pudo abrir el archivo.\n");
    }
    else
    {
        fprintf(htmlMovies,"<!DOCTYPE html>\n<html lang='en'>\n<head>\n<meta charset='utf-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n<meta name='viewport' content='width=device-width, initial-scale=1'>\n<title>Lista peliculas</title>\n<link href='css/bootstrap.min.css' rel='stylesheet'>\n<link href='css/custom.css' rel='stylesheet'>\n</head>\n");
        fprintf(htmlMovies,"<body>\n<div class='container'>\n<div class='row'>\n");

        for(i=0; i<moviesAmount; i++)
        {
            if((movies+i)->estado==1)
            {
                //Comienza el for
                fprintf(htmlMovies,"<!-- Repetir esto para cada pelicula -->\n<article class='col-md-4 article-intro'>\n<a href='#'>\n<img class='img-responsive img-rounded' src='");
                fprintf(htmlMovies,(movies+i)->linkImagen);
                //Imagen
                fprintf(htmlMovies,"' alt=''>\n</a>\n<h3>\n<a href='#'>");
                //Titulo
                fprintf(htmlMovies,(movies+i)->titulo);
                fprintf(htmlMovies,"</a>\n</h3>\n<ul>\n<li>");
                 //Genero
                fprintf(htmlMovies,"Genre: ");
                fprintf(htmlMovies,(movies+i)->genero);
                //Puntaje
                fprintf(htmlMovies,"</li>\n<li>");
                fprintf(htmlMovies,"Score: ");
                fprintf(htmlMovies,"%d",(movies+i)->puntaje);
                //Duracion
                fprintf(htmlMovies,"</li>\n<li>");
                fprintf(htmlMovies,"Duration: ");
                fprintf(htmlMovies,"%d",(movies+i)->duracion);
                fprintf(htmlMovies," minutes");
                //Descripcion
                fprintf(htmlMovies,"</li>\n</ul>\n<p>");
                fprintf(htmlMovies,"Description: ");
                fprintf(htmlMovies,(movies+i)->descripcion);

                fprintf(htmlMovies,"</p>\n</article>\n<!-- Repetir esto para cada pelicula -->");
                //Termina el for
            }
        }
    }

    fclose(htmlMovies);
    printf("Listado creado con exito\n");
}
