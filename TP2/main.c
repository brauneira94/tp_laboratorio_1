#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define TAM 1000
int main()
{
    int elegirOpcion;
    int salirMenu = 0;
    int cantEmpleados = 0;
    Employee Employee[TAM];
    initEmployee(Employee, TAM);

    while(salirMenu == 0)
    {
        printf("MENU PRINCIPAL\n\n");
        printf("1. Alta\n"
               "2. Modificar\n"
               "3. Baja\n"
               "4. Informacion\n"
               "5. Salir\n");
        elegirOpcion = 0;
        getEntero(&elegirOpcion, 5, "Seleccione una opcion\n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if(!addEmployee(Employee, TAM))
                {
                    cantEmpleados++;
                }
                else
                {
                    printf("No se pudo dar de alta el empleado\n");
                }
                break;
            case 2:
                if(cantEmpleados != 0 && !modifyEmployee(Employee, TAM, 2))
                {
                    printf("Datos modificados con exito\n");
                }
                else
                {
                    printf("No se pudo modificar el empleado\n");
                }
                break;
            case 3:
                if(cantEmpleados != 0 && !removeEmployee(Employee, TAM, 2))
                {
                    cantEmpleados--;
                }
                else
                {
                    printf("No se pudo dar de baja el empleado\n");
                }
                break;
            case 4:
                if(cantEmpleados != 0)
                {
                    printf( "1. Listado de empleados\n"
                            "2. Informacion de salarios\n"
                            "3. Salir\n");
                    elegirOpcion = 0;
                    getEntero(&elegirOpcion, 5, "Seleccione una opcion\n", "", 0);
                    switch(elegirOpcion)
                    {
                        case 1:
                            sortEmployeePorApellidoSector(Employee, TAM, 0);
                            printEmployees(Employee, TAM);
                            break;
                        case 2:
                            informacionEmployees(Employee, TAM);
                            break;
                        default:
                            printf("Opcion incorrecta\n");
                            break;
                    }
                }
                else
                {
                    printf("No hay empleados cargados en el sistema\n");
                }
                break;
            case 5:
                salirMenu = 1;
                break;
            default:
                printf("Opcion Incorrecta\n");
                break;
        }
        printf("Pulse intro para continuar\n");
        fflush(stdin);
        getchar();
    }
}
