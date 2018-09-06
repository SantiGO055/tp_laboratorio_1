#ifndef TP1CALCULADORA_H_INCLUDED
#define TP1CALCULADORA_H_INCLUDED

/* ******************************TP1 Calculadora *****************************
**
**                              Gonzalez Santiago
**
******************************************************************************/


/*
* \brief Suma dos numeros
* \param nro1 El primer numero a sumar
* \param nro2 El segundo numero a sumar
* \return Devuelve el valor con el resultado de sumar el primer numero con el segundo numero (nro1 + nro2)
*/
float suma(float, float);

/*
* \brief Resta dos numeros
* \param nro1 El primer numero a restar
* \param nro2 El segundo numero a restar
* \return Devuelve el valor con el resultado de restar el primer numero con el segundo numero (nro1 - nro2)
*/
float resta(float, float);

/*
* \brief Divide dos numeros
* \param nro1 El dividendo
* \param nro2 El divisor
* \return Devuelve el valor con el resultado de dividir el dividendo por el divisor (nro1 / nro2)
*/
float division(float,float);

/*
* \brief Multiplica dos numeros
* \param nro1 El primer numero a multiplicar
* \param nro2 El segundo numero a multiplicar
* \return Devuelve el valor con el resultado de multiplicar el primer numero por el segundo numero (nro1 * nro2)
*/
float multiplicacion(float, float);

/*
* \brief Calcula el factorial del primer numero mediante un bucle for
* \param nro1 El numero a calcular el factorial
* \return Devuelve el valor de la operacion factorial realizada
*/
int fact1(int);

/*
* \brief Calcula el factorial del segundo numero mediante un bucle for
* \param nro2 El numero a calcular el factorial
* \return Devuelve el valor de la operacion factorial realizada
*/
int fact2(int);
#endif //TP1CALCULADORA_H_INCLUDED
