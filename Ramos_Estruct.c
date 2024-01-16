// Cada estudiante debe trabajar en el ejemplo de estructura de la clase anterior (alumno) y
// debe crear un programa que permita al usuario el ingreso y presentación de datos de n alumnos.
// funciones:
// gets();
// puts();
// fflush();
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Alumno
struct Alumno
{
    int matricula;
    char nombre[50];
    char direccion[50];
    char carrera[50];
    float promedio;
};

// Funciones
void opcion1();
void opcion2();
void opcion3();
void ingresarDatosAlumno(struct Alumno *alumno);
void mostrarDatosAlumno(const struct Alumno *alumno);

int main()
{
    int opcion;

    do
    {
        // Mostrar el menú
        printf("\nMenú:\n");
        printf("1. Ingresar datos de alumnos\n");
        printf("2. Mostrar datos de alumnos\n");
        printf("3. Salir\n");

        // Solicitar al usuario que ingrese una opción
        printf("Ingrese el número de la opción deseada: ");
        scanf("%d", &opcion);

        // Ejecutar la opción seleccionada
        switch (opcion)
        {
        case 1:
            opcion1();
            break;
        case 2:
            opcion2();
            break;
        case 3:
            printf("Gracias por utilizar el programa.\n");
            break;
        default:
            printf("Opción no válida. Por favor, ingrese un número válido.\n");
        }
    } while (opcion != 3);

    return 0;
}

void opcion1()
{
    printf("Has seleccionado la Opción 1.\n");
    int n;

    // Solicitar al usuario el número de alumnos
    printf("Ingrese el número de alumnos: ");
    scanf("%d", &n);

    // Limpia la variable de entrada
    fflush(stdin);
    // Ingresar datos para cada alumno
    for (int i = 0; i < n; ++i)
    {
        printf("\nIngrese los datos para el alumno %d:\n", i + 1);
        ingresarDatosAlumno(&alumnos[i]);
    }

    // Mostrar datos de todos los alumnos
    printf("\nDatos de todos los alumnos:\n");
    for (int i = 0; i < n; ++i)
    {
        printf("\nDatos del alumno %d:\n", i + 1);
        mostrarDatosAlumno(&alumnos[i]);
    }

    // Liberar la memoria asignada al array de alumnos
    free(alumnos);

