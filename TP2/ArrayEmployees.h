#define ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int idEmpleado;
    int isEmpty;
}Employee;


int initEmployee(Employee list[], int tam);
static int getNextId();
int searchFree(Employee list[], int tam);
int addEmployee(Employee* array, int tam);
int findEmployeeById(Employee list[], int tam, int id);
int printEmployees(Employee list[], int tam);
int modifyEmployee(Employee list[], int tam, int reintentos);
int removeEmployee(Employee* array, int tam, int reintentos);
int sortEmployeePorApellidoSector(Employee *array, int tam, int orden);
int compareApellidoSector(Employee* arrayUno, Employee* arrayDos);
int informacionEmployees(Employee *array, int tam);
int ingresoManual(Employee* array, int tam, char *nombre, char *apellido, float salario, int sector);

