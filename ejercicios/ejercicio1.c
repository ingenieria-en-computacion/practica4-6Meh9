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
    printf("Ingrese %d valores:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Ingrese el valor #%d: ", i+1);
        scanf ("%d", &*(arr+i));
    }

    printf("El arreglo es: \n");
    for (int i = 0; i < n; i++) {
        printf("\t%d, %p \n", *(arr + i), (arr + i));
    }
    printf("\n");

    printf("Liberando el espacio reservado\n");
    free(arr);
    return 0;
}
