// Cada estudiante debe trabajar en el ejemplo de estructura de la clase anterior (alumno) y
// debe crear un programa que permita al usuario el ingreso y presentación de datos de n alumnos.
// funciones:
// gets();
// puts();
// fflush();
//Coloco la biblioteca
#include <stdio.h>
// Defino un limite 
#define MAX_ALUMNOS 1000
//Ingreso una estructura de alumnos 
struct Alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};
//Coloco la funciones que creo se pueden utilizar
void obtenerDatosAlumno(struct Alumno *alumno);
void mostrarDatosAlumno(const struct Alumno *alumno);

int main()
{
    int n = 0;
    struct Alumno alumnos[MAX_ALUMNOS];
    int opcion;
//Coloco el menu 
    do
    {
        // Menú
        printf("\n---- Menú ----\n");
        printf("1. Ingresar más alumnos\n");
        printf("2. Mostrar datos de los alumnos\n");
        printf("3. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            // Ingresar más alumnos
            if (n < MAX_ALUMNOS)
            {
                printf("\nIngresar datos del nuevo alumno:\n");
                obtenerDatosAlumno(&alumnos[n]);
                n++;
            }
            else
            {
                printf("No se pueden agregar más alumnos. Límite alcanzado.\n");
            }
            break;

        case 2:
            // Mostrar datos de los alumnos
            printf("\n\tDatos de los alumnos:\n");
            for (int i = 0; i < n; i++)
            {
                printf("\n \t Alumno %d:\n", i + 1);
                mostrarDatosAlumno(&alumnos[i]);
            }
            break;

        case 3:
            // Salir del programa
            break;

        default:
            printf("Opción no válida. Intente de nuevo.\n");
        }

    } while (opcion != 3);

    return 0;
}
//Defino las funciones y las operaciones que se van a realizar
void obtenerDatosAlumno(struct Alumno *alumno)
{
    printf("Matrícula del estudiante: ");
    scanf("%d", &alumno->matricula);

    while (getchar() != '\n');

    printf("Nombre del estudiante: ");
    fgets(alumno->nombre, sizeof(alumno->nombre), stdin);
    printf("Dirección del estudiante: ");
    fgets(alumno->direccion, sizeof(alumno->direccion), stdin);
    printf("Carrera: ");
    fgets(alumno->carrera, sizeof(alumno->carrera), stdin);
    printf("Promedio: ");
    scanf("%f", &alumno->promedio);
}

void mostrarDatosAlumno(const struct Alumno *alumno)
{
    printf("Matrícula del estudiante: %d\n", alumno->matricula);
    printf("Nombre del estudiante: %s", alumno->nombre);
    printf("Dirección del estudiante: %s", alumno->direccion);
    printf("Carrera: %s", alumno->carrera);
    printf("Promedio: %.2f\n", alumno->promedio);
}
