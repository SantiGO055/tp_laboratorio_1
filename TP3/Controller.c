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
    if (path!=NULL && pArrayListEmployee!= NULL&&pFile!=NULL){
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    Employee* employee;
    char nombre[50];
    int sueldo,horasTrabajadas,retorno=-1,i;
    utn_getStringAvanzado(nombre,"Ingrese nombre: \n","ERROR! El apellido debe ser solo letras\n",50,2);
    utn_getEntero(&horasTrabajadas,"Ingrese las horas trabajadas: \n","ERROR! Las horas deben ser mayor a 0",0,500,2);
    utn_getEntero(&sueldo,"Ingrese sueldo: \n","ERROR! El sueldo debe ser mayor a 0",0,500000,2);
    for(i=0;i<ll_len(pArrayListEmployee);i++){
        auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
        auxEmployee->id=employee_setId(auxEmployee,auxEmployee->id);
        employee = employee_newParametros(auxEmployee->id+1,nombre,horasTrabajadas,sueldo);
    }

    if (employee!=NULL){
        ll_add(pArrayListEmployee, employee);
        retorno=0;
    }
    return retorno;
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
    char nombre[50];
    int idAux,sueldoAux,horasTrabajadasAux,retorno=-1,i,index;
    Employee* employeeAux=employee_new();
    if (pArrayListEmployee!=NULL&&employeeAux!=NULL){
        employee_print(pArrayListEmployee);
        utn_getEntero(&idAux,"Ingrese ID del empleado que desea modificar: ","ERROR! El id debe ser entre 1 y 1000",1,ll_len(pArrayListEmployee),2);
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            employeeAux=(Employee*)ll_get(pArrayListEmployee,i);
            if(idAux==employee_getId(employeeAux)){
                index=ll_indexOf(pArrayListEmployee,employeeAux);
                printf("ID: %d\n",idAux);
                utn_getStringAvanzado(nombre,"Ingrese el nombre del empleado a editar: \n","ERROR! El nombre deben ser solo letras",50,2);
                utn_getEntero(&horasTrabajadasAux,"Ingrese las horas trabajadas: \n","ERROR! Las horas deben ser mayor a 0",0,500,2);
                utn_getEntero(&sueldoAux,"Ingrese sueldo: \n","ERROR! El sueldo debe ser mayor a 0",0,500000,2);
                employee_setNombre(employeeAux,nombre);
                employee_setHorasTrabajadas(employeeAux,horasTrabajadasAux);
                employee_setSueldo(employeeAux,sueldoAux);
                ll_set(pArrayListEmployee,index,employeeAux);
                retorno=1;
            }
        }
    }
    return retorno;
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
    char nombre[50];
    int idAux,idAuxRemove,retorno=-1,i;
    Employee* employeeAux=employee_new();
    if (pArrayListEmployee!=NULL&&employeeAux!=NULL){
        employee_print(pArrayListEmployee);
        utn_getEntero(&idAux,"Ingrese ID del empleado que desea eliminar: \n","ERROR! El id debe ser entre 1 y 1000",1,ll_len(pArrayListEmployee),2);
        for(i=0;i<ll_len(pArrayListEmployee);i++){
            employeeAux=(Employee*)ll_get(pArrayListEmployee,i);
            if(idAux==employee_getId(employeeAux)){
                ll_remove(pArrayListEmployee,i);
                retorno=1;
                break;
            }
            else{
                printf("No se encontro el ID ingresado");
            }
        }
    }
    else{
        system("cls");
        printf("ERROR! Volver a intentar");
    }
    return retorno;
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
    int retorno=-1;
    if(ll_len(pArrayListEmployee)!=0&&pArrayListEmployee!=NULL){
        employee_printList(pArrayListEmployee);
        retorno=1;
    }
    else
        retorno=-1;
    return retorno;
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
    FILE* pFile;
    pFile = fopen(path, "w");
    int retorno=-1,i;
    Employee* auxEmp;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL){
        fprintf(pFile,"%s,%s,%s,%s\n","id","nombre","horasTrabajadas","sueldo");
        for(i=0; i<ll_len(pArrayListEmployee);i++){
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(pFile,"%d,%s,%d,%d\n",auxEmp->id,auxEmp->nombre,auxEmp->horasTrabajadas,auxEmp->sueldo);
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
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
    int retorno=-1,i;
    FILE* pFile;
    pFile = fopen(path, "wb");
    Employee* auxEmp;
    if(path!=NULL&&pFile!=NULL&&pArrayListEmployee!=NULL){
        for(i=0; i<ll_len(pArrayListEmployee);i++){
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(auxEmp, sizeof(Employee), 1, pFile);
        }
        if(i==ll_len(pArrayListEmployee)){
            retorno=1;
        }
    }
    fclose(pFile);
    return retorno;
}

