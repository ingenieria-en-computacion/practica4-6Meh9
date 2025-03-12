#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n;
    printf("Ingrese el número de filas: ");
    scanf("%d", &m);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &n);

    int *matrix = (int *)calloc(m * n, sizeof(int));
    if (matrix == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        
    }

    printf("Matriz inicializada con ceros:\n");
    for (int i = 0; i < m; i++) {
        printf ("| %d |\t");
        for (int j = 0; j < n-1; j++) {
            printf ("| %d |\t");
        }
        printf("\n");
    }

    printf("Ingrese las coordenadas (fila, columna) y el valor para modificar (ej. 1 2 5):\n");
    int row, col, value;
    //lee los varlores solicitados
    scanf("%d %d %d", &row, &col, &value);

    matrix[(row-1) * n + (col)] = value;

    printf("Matriz actualizada:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == row-1 && j == col-1)
            printf("| %d |\t", value);
            else 
            printf("| %d |\t ");
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}
