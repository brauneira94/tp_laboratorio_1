#include <stdio.h>
#include <stdlib.h>
#include <neira.h>


int main()

{

    int opcion;
    int op1=0,op2=0,suma,resta,division,multiplicacion,factorizaciona,factorizacionb;




    do
    {
        printf("\n\nCALCULADORA\n\n");
        printf("Menu de opciones\n\n");
        printf("1.Ingresar 1er operando (A=%d)\n",op1);
        printf("2.Ingresar 2do operando (B=%d)\n",op2);
        printf("3.Calcular todas las operaciones \n");
        printf("4.Informar resultados \n");
        printf("5.Salir\n\n");
        scanf("%d",&opcion);

        switch(opcion)

        {
        case 1:
            printf("\n Ingrese primer operando:");
            scanf ("%d",&op1);
            break;
        case 2:
            printf("\n Ingrese segundo operando:");
            scanf ("%d",&op2);
            break;
        case 3:
            suma = sumar (op1,op2);
            resta = restar (op1,op2);
            division = dividir (op1,op2);
            multiplicacion = multiplicar (op1,op2);
            factorizaciona = factorizar (op1);
            factorizacionb = factorizar (op2);
            break;

        case 4:
            printf("\n El resultado de %d+%d es: %d\n",op1,op2,suma);
            printf("\n El resultado de %d-%d es: %d\n",op1,op2,resta);
            if (op2 != 0)
            {
                printf("\n El resultado de %d/%d es: %d\n",op1,op2,division);
            }
            else
            {
                printf("\n No es posible dividir por cero\n");
            }
            printf("\n El resultado de %d*%d es: %d\n",op1,op2,multiplicacion);
            printf("\n El factorial de %d es: %d y el factorial de %d es: %d\n",op1,factorizaciona,op2,factorizacionb);
            break;






        }




    }
    while  (opcion !=5);

    return 0;
}
