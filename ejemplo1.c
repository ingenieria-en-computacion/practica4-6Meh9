#include <stdio.h>
#include <stdlib.h> //manejo de funciones de memoria dinamica 

int main(){
    int *arreglo, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n"); 
    scanf("%d", &num);
    arreglo = (int*)malloc(num *sizeof(int)); //reserva memoria acorde a lo que iingrese el usuario  
    if(arreglo != NULL){ //verifica si malloc pudo reservar memoria 
        printf("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d, %p", *(arreglo + cont), (arreglo+cont));            
        }
        printf("\t]\n");
        printf("Liberando el espacio reservado\n");
        free(arreglo); //arreglo == NULL libera la memoria, no la borra, ya  que no se usa esa zona de memoria          
    }
    return 0;
}