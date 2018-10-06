#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"

/**
* \brief  Esta funcion inicializa un array de tipo employee, recorriendo el array y poniendo cada isEmpty en 1
* \param  list employee es el array que se recorre
* \param  tam es el limite de empleados
* \return Rotorna 1 si se realizo de manera correcta, de lo contrario devolvera 0
*/
int initEmployee(Employee list[], int tam)
{
    int retorno = -1;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}


/**
* \brief  Se utiliza esta funcion para obtener un nuevo id
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

/**
* \brief Se obtiene el primer lugar libre de un array de tipo employee, recorre el array hasta encontrar un isEmpty en 1
* \param list es el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \return devuelve el id de la posicion libre.
*/


int searchFree(Employee list[], int tam)
{
    int id = -1;

    for(int i=0; i < tam; i++)
    {

        if( list[i].isEmpty == 1)
        {
            id = i;
            break;
        }
    }
    return id;
}

/**
* \brief Se utiliza esta funcion para dar de alta un empleado generando un id de manera automatica y el usuario introduce el resto de datos.
* \param Array es el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/

int addEmployee(Employee* array, int tam)
{
    int retorno = -1;
    int indice;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    indice = searchFree(array,tam);
    if( array != NULL && tam > 0 && indice >= 0 &&
        indice < tam && array[indice].isEmpty &&
        !getNombre( nombre, 51,"Nombre empleado: \n",
                        "nombre invalido\nTiene que comenzar con mayuscula y el resto con minuscula \n",2) &&
        !getNombre( apellido, 51,"Apellido empleado?\n",
                        "apellido invalido\nTiene que comenzar con mayuscula y el resto con minuscula\n",2) &&
        !getFloatPositivo(&salario, 10,"Salario empleado: \n","salario invalido\n",2) &&
        !getEnteroSoloNumeros(&sector, 4, "Sector empleado: \n", "sector invalido", 2))
    {
        strncpy(array[indice].nombre, nombre,51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].isEmpty = 0;
        array[indice].idEmpleado = getNextId();
        retorno = 0;
    }
    return retorno;
}


/**
* \brief Se utiliza para encontrar un empleado a través de un id
* \param list es el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \param id es con lo que se compara cada dato del array
* \return retorna la direccion de la struct del empleado donde se encontro el id, si no el retorno es NULL.
*/


int findEmployeeById(Employee list[], int tam, int id)
{
    Employee* retorno = NULL;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            if(!list[i].isEmpty && list[i].idEmpleado == id)
            {
                retorno = &list[i];
                break;
            }
        }
    }
    return retorno;

}



/**
* \brief Con esta funcion para mostrar todos los datos de los empleados del array
* \param list es el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/


int printEmployees(Employee list[], int tam)
{
    int retorno = -1;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i=0;i<tam;i++)
        {
            if(!list[i].isEmpty)
            {
                printf("\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\nID: %d\n\n",
                list[i].nombre, list[i].apellido, list[i].salario, list[i].sector, list[i].idEmpleado);
            }
        }
        retorno = 0;
    }
    return retorno;
}



/**
* \brief Se utiliza esta funcion para modificar un empleado,el usuario elige por medio del menu
* \param list es el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \param reintentos son veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int modifyEmployee(Employee list[], int tam, int reintentos)
{
    int retorno = -1;
    Employee *empleadoModificado = NULL;
    int elegirOpcion = 0;
    int id;
    int i;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    if(list != NULL && tam > 0 && reintentos >= 0)
    {
        printEmployees(list, tam);
        for(i=0; i <= reintentos; i++)
        {
            if( !getEntero(&id, tam, "Introduzca el id que desea modificar: \n", "", 0) &&
                findEmployeeById(list, tam, id) != NULL)
            {
                empleadoModificado = findEmployeeById(list, tam, id);
                break;
            }
            else
            {
                printf("Id invalido\n");
            }
        }
    }
    if(empleadoModificado != NULL)
    {
        printf("1. Modificar nombre\n"
               "2. Modificar apellido\n"
               "3. Modificar salario\n"
               "4. Modificar sueldo\n"
               "5. Modificar todos los datos\n");
        getEnteroSoloNumeros(&elegirOpcion, 5, "Seleccione opcion: \n", "", 0);
        switch(elegirOpcion)
        {
            case 1:
                if( !getNombre(nombre, 51,"Nombre empleado: \n",
                    "nombre invalido\nTiene que comenzar con mayusculas y el resto en minuscula\n",2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    retorno = 0;
                }
                break;
            case 2:
                if( !getNombre( apellido, 51,"Apellido empleado: \n",
                    "apellido invalido\nTiene que comenzar con mayusculas y el resto en minuscula\n",2))
                {
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    retorno = 0;
                }
                break;
            case 3:
                if(!getFloatPositivo(&salario, 10,"Salario empleado: \n","salario invalido\n",2))
                {
                    empleadoModificado->salario = salario;
                    retorno = 0;
                }
                break;
            case 4:
                if(!getEnteroSoloNumeros(&sector, 4, "Sector empleado: \n", "sector invalido", 2))
                {
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            case 5:
                if( !getNombre( nombre, 51,"Nombre empleado: \n",
                    "nombre invalido\nTiene que comenzar con mayusculas y el resto en minuscula\n",2) &&
                    !getNombre( apellido, 51,"Apellido empleado: \n",
                    "apellido invalido\nTiene que comenzar con mayusculas y el resto en minuscula\n",2) &&
                    !getFloatPositivo(&salario, 10,"Salario empleado: \n","salario invalido\n",2) &&
                    !getEnteroSoloNumeros(&sector, 4, "Sector empleado: \n", "sector invalido", 2))
                {
                    strncpy(empleadoModificado->nombre, nombre, 51);
                    strncpy(empleadoModificado->apellido, apellido, 51);
                    empleadoModificado->salario = salario;
                    empleadoModificado->sector = sector;
                    retorno = 0;
                }
                break;
            default:
                printf("Opcion incorrecta\n");
                break;
        }
    }
    return retorno;
}


/**
* \brief  Se utiliza esta funcion para dar de baja un empleado
* \param  el array es lo que se recorre
* \param  tam es el limite de empleados que puede guardar el array
* \param  reintentos son las veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/

int removeEmployee(Employee* array, int tam, int reintentos)
{
    int retorno = -1;
    Employee *modifyEmployee;
    char confirmarBaja[10];
    int id;
    int i;
    if(array != NULL && tam > 0 && reintentos >= 0)
    {
        printEmployees(array, tam);
        for(i=0; i<= reintentos; i++)
        {
            if( !getEntero(&id, tam, "Introduzca el id que desea dar de baja\n", "", 0) &&
                findEmployeeById(array, tam, id) != NULL)
            {
                modifyEmployee = findEmployeeById(array, tam, id);
                printf("Se borrara el siguiente empleado\n");
                printEmployees(modifyEmployee, 1);
                if( !getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                    strcmp(confirmarBaja, "1") == 0)
                {
                    modifyEmployee->isEmpty = 1;
                    retorno = 0;
                }
                break;
            }
            else
            {
                printf("Id incorrecto\n");
            }
        }
    }
    return retorno;
}


/**
* \brief ordena un array de empleados por insercion, primero por apellido y en caso de coincidir, por sector
* \param array se recorre
* \param tam es el limite de empleados que puede guardar el array
* \param el orden debe ser 0 si es ascendente o 1 descendente
* \return El retorno es 0 si se realizo el ordenamiento, si no el retorno es -1.
*/
int sortEmployeePorApellidoSector(Employee *array, int tam, int orden)
{
    Employee auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && tam > 0 && (orden == 0 || orden == 1))
    {
        for(i=1; i < tam; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            if(orden == 0)
            {
                while ((j >= 0) && !compareApellidoSector(&array[j], &auxiliar))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
            if(orden == 1)
            {
                while ((j >= 0) && !compareApellidoSector(&auxiliar, &array[j]))
                {
                    array[j + 1] = array[j];
                    j--;
                }
                array[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}


/**
* \brief compara a los empleados por su apellido y luego por sector
* \param arrayUno es el primer empleado que se va a comparar
* \param arrayDos es el segundo empleado que se va a comparar
* \return si el primero es mayor devuelve 0, si no -1
*/
int compareApellidoSector(Employee* arrayUno, Employee* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL)
    {
        if( strcmp(arrayUno->apellido, arrayDos->apellido) > 0 ||
            (strcmp(arrayUno->apellido, arrayDos->apellido) == 0 && arrayUno->sector > arrayDos->sector))
        {
            retorno = 0;
        }
    }
    return retorno;
}

/**
* \brief Calcula el total de los salarios, el promedio y la cantidad de empleados que superan el promedio.
* \param el array se recorre
* \param tam es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostro la informacion, si no el retorno es -1.
*/

int informacionEmployees(Employee *array, int tam)
{
    int retorno=-1;
    int i;
    float totalSalary = 0;
    int totalEmployees = 0;
    float promSalary;
    int cantSalarySobreProm = 0;
    if(array != NULL && tam > 0)
    {
        for(i=0; i < tam; i++)
        {
            if(array[i].isEmpty == 0)
            {
                totalSalary += array[i].salario;
                totalEmployees++;
            }
        }
        promSalary = totalSalary/totalEmployees;
        for(i=0; i < tam; i++)
        {
            if(array[i].isEmpty == 0 && array[i].salario > promSalary)
            {
                cantSalarySobreProm++;
            }
        }
        printf("El total de los salarios es: %.2f\n", totalSalary);
        printf("El promedio de los salarios es: %.2f\n", promSalary);
        printf("La cantidad de salarios que superan el promedio es: %d\n", cantSalarySobreProm);
        retorno = 0;
    }
    return retorno;
}


/**
* \brief Se utiliza esta funcion para cargar los datos de un empleado del array, el id se genera de manera automatica
* \param el array que se recorre
* \param tam es el limite de empleados que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, de lo contrario es -1.
*/
int ingresoManual(Employee* array, int tam, char *nombre, char *apellido, float salario, int sector)
{
    int retorno = -1;
    int indice;
    indice = searchFree(array,tam);
    if( array != NULL && tam > 0 && nombre != NULL &&
        apellido != NULL && salario > 0 && sector > 0)
    {
        strncpy(array[indice].nombre, nombre, 51);
        strncpy(array[indice].apellido, apellido, 51);
        array[indice].salario = salario;
        array[indice].sector = sector;
        array[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
