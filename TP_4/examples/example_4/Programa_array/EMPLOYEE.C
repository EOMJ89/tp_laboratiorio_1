#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"
#include "Employee.h"


int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    return 0;
}


void employee_print(Employee* this)
{
    printf("ID: %-10dName: %-15sLast Name: %-15sisEmpty: %d\n", this->id, this->name, this->lastName, this->isEmpty);
}

Employee* employee_new(void)
{
    Employee* returnAux = NULL;

    returnAux=(Employee*)malloc(sizeof(Employee));
    if(returnAux!=NULL)
    {
        returnAux->id=-1;
        strcpy(returnAux->name,"");
        strcpy(returnAux->lastName,"");
        returnAux->isEmpty=0;
    }
    return returnAux;
}

Employee* employee_new_Parameters(int id,char* name, char* lastName, int isEmpty)
{
    Employee* returnAux = NULL;

    returnAux=employee_new();
    if(returnAux!=NULL)
    {
        returnAux->id=id;
        strcpy(returnAux->name,name);
        strcpy(returnAux->lastName,lastName);
        returnAux->isEmpty=isEmpty;
    }

    return returnAux;
}

void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        this->id=-1;
        strcpy(this->name,"");
        strcpy(this->lastName,"");
        this->isEmpty=0;
    }
}

int employee_setId(Employee* this, int id)
{

    return 0;

}

int employee_getId(Employee* this)
{
    if(this!=NULL)
    {
        return this->id;
    }

    return 0;
}
