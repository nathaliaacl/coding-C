#include <stdio.h>
#include <stdlib.h>
int main (){
    //AULA 106
    int matriz1[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //AULA 107 - percorrer e imprimir uma matriz
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            printf("%d ", matriz1[i][j]);
        }
        printf("\n");
    }
    //AULA 108 - como ler uma matriz pelo teclado
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            scanf("%d", &matriz1[i][j]);
        }
        printf("\n");
    }
    //AULA 142 - matriz de strings 
    char nomes[5][25]; 
        //5 indica o n° de linhas
        //25 é o valor máximo de caracteres por linha
    for (int l=0; l<5; l++){
        printf("digite o nome: %d", l);
        scanf("%25[^\n]", nomes[l]); //indica para ler tudo ate que o enter seja pressionado
        scanf("%c"); //remocao do buffer do teclado
    }
    //fazer um for para printar
}