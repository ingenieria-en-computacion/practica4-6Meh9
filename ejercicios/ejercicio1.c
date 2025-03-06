#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int *arr;
    arr = (int*)malloc(n *sizeof(int));
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1; 
    }

    printf("Ingrese %d valores:\t[\n", n);
    for (int i = 0; i < n; i++) {
        
        printf("\t%d, %p", *(arr + i), (arr + i));
    }
    printf("\t]\n");

    printf("Liberando el espacio reservado\n");
    free(arr);

    /*printf("El arreglo es: ");
    for (int i = 0; i < n; i++) {
        
    }
    printf("\n");*/

    
    return 0;
}
