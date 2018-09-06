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

int fact1(int nro1){
int i, fact=1;
    if(nro1<0){
        fact=0;
    }
        for(i=1; i<=nro1; i++){
                fact=fact*i;
        }
return fact;
}

int fact2(int nro2){
int i, fact=1;
    if(nro2<0){
        fact=0;
    }
        for(i=1; i<=nro2; i++){
                fact=fact*i;
        }

return fact;
}

