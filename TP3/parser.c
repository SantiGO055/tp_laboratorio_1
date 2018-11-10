#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r,i=0;
    char var1[50],var3[50],var2[50],var4[50];
    int retorno=-1;
    //Employee* auxStruct;
    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

    do{
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4){
            //llamo a addemployee
            Employee* auxStruct=employee_newParametros(var1,var2,var3,var4);
            if(auxStruct!=NULL)
            ll_add(pArrayListEmployee,auxStruct);
            //printf("id: %d nombre: %s horastrabajadas: %d sueldo: %d",auxStruct->id,auxStruct->nombre,
         //          auxStruct->horasTrabajadas,auxStruct->sueldo);
            retorno=1;
        }
        else{
            retorno=-1;
            }
    }while(!feof(pFile));

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    do {
        Employee *employee = employee_new();
        if(fread(employee, sizeof(Employee), 1, pFile) == 1){
            ll_add(pArrayListEmployee, employee);
            printf("%d %s %d %d\n", employee_getId(employee), employee_getNombre(employee), employee_getHorasTrabajadas(employee),
               employee_getSueldo(employee));
        }
    } while (!feof(pFile));
    return 1;
}
