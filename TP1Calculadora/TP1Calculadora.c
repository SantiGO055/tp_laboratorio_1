/* ******************************TP1 Calculadora *****************************
**
**                              Gonzalez Santiago
**
******************************************************************************/

float suma(float nro1, float nro2){
float resultado;
resultado=nro1+nro2;
return resultado;
}

float resta(float nro1, float nro2){
float resultado;
resultado=nro1-nro2;
return resultado;
}

float division(float nro1, float nro2){
float resultado;
resultado=nro1/nro2;
return resultado;
}

float multiplicacion(float nro1, float nro2){
float resultado;
resultado=nro1*nro2;
return resultado;
}

int fact(int nro){
int i, fact=1;
    if(nro<0){
        fact=0;
    }
        for(i=1; i<=nro; i++){
                fact=fact*i;
        }
return fact;
}
