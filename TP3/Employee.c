#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

Employee* employee_new(){

    Employee* this = malloc(sizeof(Employee));
    return this;
}
Employee* employee_newParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr){
    Employee* e=employee_new();
    if(e!=NULL && idStr!=NULL && nombre!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL){
        employee_setId(e, idStr);
        employee_setNombre(e, nombre);
        employee_setHorasTrabajadas(e,horasTrabajadasStr);
        employee_setSueldo(e,sueldoStr);


    }

    return e;
}

int employee_setId(Employee* this,char* id){
    id=atoi(id);
    if(id>0)
        return this->id = id;
}

int employee_getId(Employee* this){
    return this->id;
}

void employee_setNombre(Employee* this,char* nombre){
    if(nombre[0] != '\0')
        strncpy(this->nombre, nombre, sizeof(this->nombre));
}
char* employee_getNombre(Employee* this){
    return this->nombre;
}
int employee_setHorasTrabajadas(Employee* this,char* horasTrabajadas){
    horasTrabajadas = atoi(horasTrabajadas);
    if(horasTrabajadas>0)
        return this->horasTrabajadas = horasTrabajadas;
}
int employee_getHorasTrabajadas(Employee* this){
    return this->horasTrabajadas;
}
int employee_setSueldo(Employee* this,char* sueldo){
    sueldo = atoi(sueldo);
    if(sueldo>0)
       return this->sueldo = sueldo;
}
int employee_getSueldo(Employee* this){
    return this->sueldo;
}
void employee_print(Employee* employee){
    printf("-----------------------------------------------------\n");
    printf("ID      : %d\n", employee->id);
    printf("Nombre  : %s\n", employee->nombre);
    printf("Salario : %d\n", employee->sueldo);
    printf("Horas Trabajadas : %d\n", employee->horasTrabajadas);
    printf("-----------------------------------------------------\n");
}
int printMenu(int option){
    printf("");
    utn_getEntero(&option,"\t\t\tMenu\n\tIngrese opcion\n"
                  "*******************************************************************************\n"
                  "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
                  "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                  "3. Alta de empleado\n"
                  "4. Modificar datos de empleado\n"
                  "5. Baja de empleado\n"
                  "6. Listar empleados\n"
                  "7. Ordenar empleados\n"
                  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
                  "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                  "10. Salir\n"
                  "*******************************************************************************\n"
                  ,"Opcion incorrecta",
                  0,10,2);
    return option;
}
