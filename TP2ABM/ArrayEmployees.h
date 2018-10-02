#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
/* ********************************** TP2 ABM ********************************
**
**                              Gonzalez Santiago
**
******************************************************************************/
typedef struct{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}employee;

int initEmployee(employee*,int);
int getFreeSpace(employee*,int);
int addEmployee(employee*,int,char*,char*,float,int,int);
int findEmployeeById(employee*,int,int id);
int removeEmployee(employee*,int,int);
int sortEmployee(employee*,int,char*,char*,int);
int printEmployee(employee*,int);
int firstEmployee(int);
void modifyEmployee(employee*,int,char*,char*,float,int,int,int);
int averageSalary(employee*,int);
float totalSalary(employee*,int);
int excSalary(employee*,int);
int esLetra(char* input);
void utn_getString(char*,char*);
int utn_getStringAvanzado(char*,char*,char*,int, int);
int utn_getEntero(int*,char*,char*,int, int,int);
int utn_getFlotante( float*,char*,char*,int,int,int);

#endif // ARRAYEMPLOYEES_H_INCLUDED
