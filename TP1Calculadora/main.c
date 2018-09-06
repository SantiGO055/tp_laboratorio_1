#include <stdio.h>
#include <stdlib.h>
#include "TP1Calculadora.h"

/* ******************************TP1 Calculadora *****************************
**
**                              Gonzalez Santiago
**
******************************************************************************/
int main()
{
int opcion,operacionFact1,operacionFact2;
float op1=0,op2=0, operacionSuma, operacionResta, operacionMult, operacionDiv;
    do{
        if(opcion!=4){          //Valida si la opcion es distinto de 4 limpia la pantalla
            system("cls");
        }
        printf("Menu");
        printf("\n\n1. Ingresar 1er operando(A=%.0f)",op1);
        printf("\n2. Ingresar 2do operando(B=%.0f)",op2);
        printf("\n3. Calcular todas las operaciones");
        printf("\n4. Mostrar todos los resultados");
        printf("\n5. Salir\n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                system("cls");
                printf("Ingrese 1er operando: ");
                scanf("%f", &op1);
                break;
            case 2:
                system("cls");
                printf("Ingrese 2do operando: ");
                scanf("%f", &op2);
                break;
            case 3:
                operacionSuma=suma(op1, op2);
                operacionResta=resta(op1, op2);
                operacionMult=multiplicacion(op1,op2);
                if(op2!=0){          //Valida si la opcion es distinto de 0, realiza la division
                    operacionDiv=division(op1,op2);
                }
                operacionFact1=fact1(op1);
                operacionFact2=fact2(op2);
                break;
            case 4:
                system("cls");
                printf("El resultado de A+B es: %.0f",operacionSuma);
                printf("\nEl resultado de A-B es: %.0f",operacionResta);
                if (op2==0){          //Valida si la opcion es igual a 0 informa que no es posible dividir por cero
                    printf("\nNo es posible dividir por cero");
                }
                else{          //Si la opcion no es igual a 0 informa el resultado de la division
                printf("\nEl resultado de A/B es: %.2f",operacionDiv);
                }
                printf("\nEl resultado de A*B es: %.0f",operacionMult);
                printf("\nEl factorial de A es: %d",operacionFact1);
                printf("\nEl factorial de B es: %d\n\n",operacionFact2);
                break;
        }
    }while(opcion!=5&&opcion<=5);
    return 0;
}
