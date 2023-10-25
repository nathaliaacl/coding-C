#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int vet[20] = {999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,999,};
    int tam = 0;
    int i, l;
    
    for (i = 0; i < 20; i++){
        scanf("%d", &vet[i]);}
    for (i = 0; i < 20; i++){
        if (vet[i] != 999){
            tam++;
        }
    }
    int vet2[tam];
    for (i = 0; i < tam; i++){
        vet2[i] = vet[i];
    }
    
    for (l = 0; l < tam; l++){
        int chave = vet[l];
        int j = l;
        if (j>0){
        printf("\nChave: %d\n", vet[l]);
        printf("Estado Atual:");
        for (i = 0; i < tam; i++){
        printf(" %d", vet[i]);
        if(i < tam-1)
        printf(" |");
        }
        
        printf("\n");
            }
        
        while((vet[j] < vet[j-1]) && j > 0){
            int aux = vet[j-1];
            vet[j-1] = vet[j];
            vet[j] = aux;
            --j;
           
            for(i = 0; i < tam; i++){
                printf("%d", vet[i]);
                if (i < tam -1)
                printf(" | ");
            }
            printf("\n");
        }
    }
    
    printf("\nResultado Final:");
    for (i = 0; i < tam; i++){
        printf(" %d ", vet[i]);
        if( i < tam - 1)
            printf("|");
        
    }
    return 0;
}