#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int retorno=-1;
    if (path!=NULL && pArrayListEmployee!= NULL){
        //aca dentro abro el archivo y llamo a la funcion parser para cargar los datos al array
        pFile=fopen(path,"r");
        if (pFile==NULL){
            printf("El archivo no puede ser abierto");
            retorno=-1;
            return retorno;
        }
        else {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* ruta del archivo de texto
 * \param pArrayListEmployee LinkedList* puntero del array lista de empleados
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    if (path!=NULL && pArrayListEmployee!= NULL){
    if((pFile=fopen(path,"rb"))==NULL){
        if((pFile=fopen(path,"wb"))==NULL){
                printf("\nEl archivo %s no puede ser abierto",path);
                retorno=-1;
            }
        else{
            //creo el archivo
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno=1;
            }
        }
    }
    else{
        retorno=-1;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 * \param pArrayListEmployee LinkedList* puntero del array lista de empleados
 * \return int devuelve un entero
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *arrAux = ll_get(pArrayListEmployee,pArrayListEmployee->size);
    char nombre[50];
    int sueldo,horasTrabajadas;
    utn_getStringAvanzado(nombre,"Ingrese nombre: ","ERROR! El apellido debe ser solo letras\n",50,2);
    utn_getEntero(&horasTrabajadas,"Ingrese las horas trabajadas: ","ERROR! Las horas deben ser mayor a 0",0,500,2);
    utn_getEntero(&sueldo,"Ingrese sueldo: ","ERROR! El sueldo debe ser mayor a 0",0,500000,2);
    Employee *employee = employee_newParametros(arrAux->id+1,nombre,horasTrabajadas,sueldo);
    ll_add(pArrayListEmployee, employee);
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

