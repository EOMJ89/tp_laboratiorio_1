#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"
#include "Employee.h"

int parserEmployee(FILE* pFile, ArrayList* pArrayListEmployee)
{
    char id[50], firstName[100], lastName[100],isEmpty[50];
    int auxId;
    Employee* e;

    pFile = fopen ("data.csv", "r");
    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, firstName, lastName, isEmpty);

    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, firstName, lastName, isEmpty);
        auxId=atoi(id);

        if(strcmp(isEmpty,"true"))
        {
            e = employee_new_Parameters(auxId, firstName, lastName, 1);
        }
        else
        {
            e = employee_new_Parameters(auxId, firstName, lastName, 0);
        }

        pArrayListEmployee->add(pArrayListEmployee, e);
    }

    return 0;
}
