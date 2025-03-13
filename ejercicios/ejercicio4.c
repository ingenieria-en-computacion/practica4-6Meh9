#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea un tipo de dato estudiante que guarde el nombre del estudiante max. 40 caracteres y su edad
typedef struct estudiante{
    char neim[40];
    int eig; 
} Estudiante;

int main() {

    int size = 2;
    // Crea un arreglo dinámico usando malloc de tamaño size
    Estudiante *num;
    num = malloc(size * sizeof(Estudiante));

    //Si el arreglo es nulo imprime el mensaje
    if (num == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    char nombre[50];
    int edad;
    num = (int*)calloc(size, sizeof(Estudiante));
 
    printf("Ingrese estudiantes (nombre y edad, ingrese 'fin' para terminar):\n");
    while (1) {
        printf("Nombre: ");
        scanf("%s", nombre);

        if (strcmp(nombre, "fin") == 0) break;

        printf("Edad: ");
        scanf("%d", &edad);



        if (count >= size) {
            size *= 2;
            //Cambia el tamaño del arreglo
            num = realloc(num, size * sizeof(Estudiante));

            //Verifica nuevamente que si apunta a nulo se imprima el error
            if (num == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }
        //copia el nombre leido en el nuevo estudiante y su edad
        strcpy(num[count].neim, nombre);
        num[count].eig = edad;

        count++;
    }

    printf("Lista de estudiantes:\n");
    for (int i = 0; i < count; i++) {
        printf("| %s, %d anios \t |", num[i].neim, num[i].eig);
        
    }

    //libera la memoria
    free (num);
    return 0;
}
