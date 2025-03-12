#include <stdio.h>
#include <stdlib.h>

int main(){ //los apuntadores inician guardando basura (vease el ejemplo 2)
    int *arreglo=NULL, *arreglo2=NULL, num, cont; //una buena practica es asignar un nulo al apuntadores desde que son declarados  
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    arreglo = (int*)malloc(num *sizeof(int)); //reserva memoria acorde al dato que ingrese el usuario 
    if(arreglo != NULL){        
        for(cont =0; cont <num; cont++){
            printf("Ingresa el elemento %d del conjunto\n", cont+1);
            scanf("%d", (arreglo+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d", *(arreglo + cont));            
        }
        printf("\t]\n");

        printf("Aumentando el espacio reservado al doble\n");
        num *=2; //crece el arreglo al doble 
        arreglo2 = (int*)realloc(arreglo, num*sizeof(int)); //modifica el tamaño de una zona de memoria ya reservada, recibe el apuntador de la zona de memoria a modificar, luego el nuevo tamaño, si es que cabe, en caso de que no mueve todo el bloque de memoria hasta una zona valida
        if(arreglo2 != NULL){ 
            arreglo = arreglo2;       
            for(; cont <num; cont++){ //agrega los elementos que hacoan falta agregar en el arreglo 
                printf("Ingresa el elemento %d del conjunto\n", cont+1);
                scanf("%d", (arreglo2+cont));
            }
            printf("Vector reservado:\n\t[");
            for(cont =0; cont <num; cont++){
                printf("\t%d", *(arreglo2 + cont));            
            }
            printf("\t]\n");    
            arreglo2 = (int*)realloc(arreglo, 5*sizeof(int)); //ahora disminuira el tamaño del arreglo 
            printf("Vector reservado:\n\t[");
            for(cont =0; cont <5; cont++){ //si la disminucion es mayor al numero de elementos que tiene el arreglo devuelve error de segmentacion o valores direfrentes a los declarados 
                printf("\t%d", *(arreglo2 + cont));            
            }
            printf("\t]\n");  

        }
        printf("Liberando el espacio reservado\n");

        free(arreglo);        
        arreglo = arreglo2 = NULL; //garantiza que el codigo este de forma correwcta 
    }
    return 0;
}
