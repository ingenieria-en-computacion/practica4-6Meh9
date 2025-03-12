#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct estudiante{
    char name[40];
    int age; 
} Estudiante;

int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    int *num;
    num = malloc(sizeof(size));


    //Si el arreglo es nulo imprime el mensaje
    if (num == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
 
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);
        Estudiante est;
        est.name[count] = nombre;
        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);
        //Estudiante anios;
        est.age = edad;

        num = (int*)calloc(num, sizeof(int));

        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            num = (int*)realloc(num, 5*sizeof(int));

            //Verifica nuevamente que si apunta a nulo se imprima el error
            if (num == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        est.name[count] = nombre;
        est.age = edad;
        
        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("| %s, %d años \t |", est.name[i], est.age);
        
    }

    //libera la memoria
    free (num);
    return 0;
}
