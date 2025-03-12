#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    printf("%p \n", arreglo); //el apuntador no apunta a nulo, ya tiene un valor cargado 
//calloc si garantiza que a cada dato se asigne un cero, malloc no 
    arreglo = (int*)calloc(num , sizeof(int)); //calloc recibe dos argumentos, no uno. num de elementos y tamaño de tipo de elementos a reservar. devuelve aoubtador de tipo void 
    if(arreglo != NULL){ //verifica que haya regresado algo 
        printf
        ("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d, %p", *(arreglo + cont), (arreglo+cont));            
        }
        printf("\t]\n");
        printf("Liberando el espacio reservado\n");
        free(arreglo);        
    }
    return 0;
}
