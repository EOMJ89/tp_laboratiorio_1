#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "../inc/ArrayList.h"
#include "Employee.h"
#include "generic.h"
#include "funciones.h"

void showEmployees(ArrayList* this)
{
    int i;
    Employee* e;

    if(this!=NULL)
    {
        for(i=0; i<this->len(this); i++)
        {
            if(!(i%250) && (i>1))
            {
                system("pause");
                printf("\n");
            }
            e=(Employee*)this->get(this,i);
            employee_print(e);
        }
    }
}

void* obtenerDatos(ArrayList* this)
{
    char firstName[100], lastName[100];
    int  id, nValido;
    Employee* employee1;

    if(this!=NULL)
    {
        do
        {
            nValido=getInt(&id, "Ingrese el id: ", 50, 0, (this->len(this)+100));
            printNextLine();
        }
        while(nValido!=1);

        getStringAlpha(firstName, "Ingrese el nombre: ", 100);
        printNextLine();

        getStringAlpha(lastName, "Ingrese el apellido: ", 100);
        printNextLine();

        employee1 = employee_new_Parameters(id,firstName,lastName,1);
    }

    return employee1;
}

int addEmployee(ArrayList* this)
{
    int returnAux=-1, index;
    Employee* employee1;

    if(this!=NULL)
    {
        employee1=obtenerDatos(this);
        if(employee1!=NULL)
        {
            this->add(this,employee1);
            returnAux=1;
        }
        returnAux=0;

        index=this->indexOf(this,employee1);
        printf("Indice del nuevo elemento: %d\n", index);
    }

    return returnAux;
}

int deleteEmployee(ArrayList* this)
{
    int i, id, nValido, returnAux=-1;
    Employee* e;

    if(this!=NULL)
    {
        do
        {
            nValido=getInt(&id, "Ingrese el id: ", 50, 0, (this->len(this)));
            printNextLine();
        }
        while(nValido!=1);

        for(i=0; i<this->len(this); i++)
        {
            e=(Employee*)this->get(this,i);

            employee_getId(e);
            if(employee_getId(e)==id)
            {
                printf("Entra a borrar.\n");
                pauseSystem();
                this->remove(this,i);
                returnAux=1;
            }
        }

        returnAux=0;
    }
    return returnAux;
}

int showFT(ArrayList* this, int min, int max)
{
    int i, returnAux=-1;
    ArrayList* auxList;

    if(this!=NULL)
    {
        for(i=min; i<max; i++)
        {
            auxList=this->subList(this, min, max);
            showEmployees(auxList);
        }
        returnAux=0;
        auxList->deleteArrayList(auxList);
    }

    return returnAux;
}

int showFromTo(ArrayList* this)
{
    int min, max, nValido, returnAux=-1;

    if(this!=NULL)
    {
        do
        {
            nValido=getInt(&min, "Ingrese minimo del intervalo: ", 50, 0, this->len(this));
            printNextLine();
        }
        while(nValido!=1);

        do
        {
            nValido=getInt(&max, "Ingrese el maximo del intervalo: ", 50, 0, this->len(this));
            printNextLine();
        }
        while(nValido!=1);

        returnAux=showFT(this, min, max);
    }
    return returnAux;
}

int sortName(Employee* a, Employee* b)
{
    int returnAux;

    if(a!=NULL && b!=NULL)
    {
        returnAux=strcmp(a->name,b->name);
    }
    return returnAux;
}

int popAndShow(ArrayList* this)
{
    int returnAux=-1, nValido, index;

    if(this!=NULL)
    {
        do
        {
            nValido=getInt(&index, "Ingrese el index: ", 50, 0, (this->len(this)+100));
            printNextLine();
        }
        while(nValido!=1);

        popAndShowIndex(this, index);
    }

    return returnAux;
}

int popAndShowIndex(ArrayList* this,int index)
{
    void* auxEm=NULL;
    int returnAux=-1;

    if(this!=NULL && index>=0 && index<this->size)
    {
        auxEm = this->pop(this,1);
        employee_print(auxEm);
        returnAux=0;
    }

    return returnAux;
}

int replaceElement(ArrayList* this)
{
    int returnAux=-1, index, nValido;
    Employee* employee1;

    if(this!=NULL)
    {
        employee1=obtenerDatos(this);

        do
        {
            nValido=getInt(&index, "Ingrese el index a reemplazar: ", 50, 0, (this->len(this)+100));
            printNextLine();
        }
        while(nValido!=1);


        if(employee1!=NULL)
        {
            this->set(this,index,employee1);
            returnAux=1;
        }
        returnAux=0;
    }

    return returnAux;
}

int pushElement(ArrayList* this)
{
    int returnAux=-1, index, nValido;
    Employee* employee1;

    if(this!=NULL)
    {
        employee1=obtenerDatos(this);

        do
        {
            nValido=getInt(&index, "Ingrese el index a reemplazar: ", 50, 0, (this->len(this)+100));
            printNextLine();
        }
        while(nValido!=1);


        if(employee1!=NULL)
        {
            this->push(this,index,employee1);
            returnAux=1;
        }
        returnAux=0;
    }

    return returnAux;
}
