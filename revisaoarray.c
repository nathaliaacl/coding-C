#include <stdio.h>
#include <stdlib.h>
int main (){
    //AULA 99 - como criar um vetor em C 
    int vetor[10]; 
    int vetor2[]={1,2,3,4,5};
    int vetor3[5]={4,3,5}; //preenche o resto das posicoes com zero
    //a prioridade é o valor definido dentro dos cochetes

    //AULA 100 - como imprimir o conteúdo de um vetor
    printf("%d", vetor2[2]); //vai imprimir o n° 3

    for (int i=0; i<5; i++)
        printf("%d", vetor2[i]);


    //AULA 101 - como preencher um vetor com valores do teclado
    int vetor4[10];
    for (int i=0; i<10; i++){
        scanf("%d ", &vetor4[i]);
        printf("\n");
    }

    //AULA 102 - como alterar o conteúdo de um vetor
}

