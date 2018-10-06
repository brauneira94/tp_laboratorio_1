#include <stdio.h>
#include <stdlib.h>
#include <neira.h>


/** \brief La funcion recibe dos valores, realiza la operacion de suma y devuelve el resultado
*   \param Primer valor a ingresar
*   \param Segundo valor a ingresar
*   \return Resultado de la suma de ambos valores ingresados
*
*/

int sumar (int op1, int op2)
{
    int suma=0;
    suma=op1+op2;
    return suma;
}


/** \brief La funcion recibe dos valores, realiza la operacion de resta y devuelve el resultado
*   \param Primer valor a ingresar
*   \param Segundo valor a ingresar
*   \return Resultado de la resta de ambos valores ingresados
*
*/

int restar (int op1, int op2)
{
    int resta=0;
    resta=op1-op2;
    return resta;
}


/** \brief La funcion recibe dos valores, realiza la operacion de division y devuelve el resultado
*   \param Primer valor a ingresar
*   \param Segundo valor a ingresar
*   \return Resultado de la division de ambos valores ingresados
*
*/

int dividir (int op1, int op2)
{
    int cociente=0;
    if (op2==0)
    {

        return 0;
    }
    cociente=op1/op2;
    return cociente;
}


/** \brief La funcion recibe dos valores, realiza la multiplicaion y devuelve el resultado
*   \param Primer valor a ingresar
*   \param Segundo valor a ingresar
*   \return Resultado de la multiplicacion de los valores ingresados
*
*/

int multiplicar (int op1, int op2)
{
    int producto=0;
    producto=op1*op2;
    return producto;
}


/** \brief La funcion recibe un valor, realiza la factorizacion y devuelve el resultado
*   \param Valor a ingresar
*   \return Resultado de la factorizacion del valor ingresado
*
*/

int factorizar (int op1)
{
    int i=0;
    int factorizar=1;
    for (i=op1; i>0; i--)
    {
        factorizar=factorizar*i;


    }
    return factorizar;

}
