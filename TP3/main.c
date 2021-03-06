#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option,i=0;
    Employee* e;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option=printMenu(option);
        switch(option)
        {
            case 1:
                system("cls");
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                system("cls");
                controller_loadFromBinary("data-binary", listaEmpleados);
                break;
            case 3:
                system("cls");
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                system("cls");
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                system("cls");
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                system("cls");
                do{
                    employee_print(ll_get(listaEmpleados,i));
                    i++;
                }while(i<=10);
                break;
            case 7:
                system("cls");
                controller_loadFromBinary("data-binary", listaEmpleados);
                break;
            case 8:
                system("cls");
                controller_saveAsText("path",listaEmpleados);
                break;
            case 9:
                system("cls");
                controller_saveAsBinary("path",listaEmpleados);
                break;
        }

    }while(option != 10);
    return 0;
}
