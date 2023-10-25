#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int vet[500]; 
    int selecionado, menor;
    int len = 0;
    
    while(scanf("%d", &vet[len]) != EOF){
        len++;
    }
    
    for(int i = 0; i< len-1; i++){
        selecionado = vet[i];
        menor = i+1;
        for(int j=i+1; j<len; j++){
            if(vet[menor] > vet[j])
            menor = j;
        }
        if(selecionado >= vet[menor]){
            vet[i] = vet[menor];
            vet[menor] = selecionado;
        }
        printf("\nMenor elemento neste passo: %d\n", vet[i]);
        
            printf("Estado Atual:");
            for (int i = 0; i < len; i++){
                    printf(" %d", vet[i]);
                if(i < len-1){
                    printf(" |");}
            }
    printf("\n");
    }
    printf("\nResultado Final:");
    for (int i = 0; i < len; i++){
        printf(" %d ", vet[i]);
        if( i < len - 1)
            printf("|");
}

    return 0;

}