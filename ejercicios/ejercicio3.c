#include <stdio.h>
#include <stdlib.h>

int main() {
    int size ; // Asigna un número pequeño
    size = 3;
    int *arr ; // reserva memoria con malloc
    arr = (int*)malloc(size *sizeof(int));

    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese números (ingrese -1 para terminar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) //rompe el ciclo
        break;

        if (count >= size) {
            size *= 2;
            arr ; //utiliza realloc para cambiar el tamaño del arreglo
            arr = (int*)realloc(arr, sizeof(int));
            if (arr == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        arr[count++] = num;
    }

    printf("La lista ingresada es: [\t");
    for (int i = 0; i < count; i++) {
        //Imprime la lista
        printf("%d \t", arr[i]);
    }
    printf("] \n");

    //libera la memoria
    free (arr); 
    return 0;
}
