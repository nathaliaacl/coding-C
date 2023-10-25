#include <stdio.h>
#include <stdlib.h>

void imprimirString(char str[]);

//função que retorna o tamanho de uma string
int minhaStrLen(char str[]){
    int tam = 0;

    while(str[tam]!= '\0'){
        tam ++;
    }
    return tam;
}

int main(){
    char vet[20]={"Ola"};
    printf("%d\n", minhaStrLen(vet));
    imprimirString(vet);
    return 0;
}

//PROCEDIMENTOS NÃO TEM RETONOS E SÃO INDICADOS PELA VOID
void imprimirString(char str[]){
    int i = 0;

    while(str[i]!= '\0'){
        printf("%c", str[i]);
        i++;
    } printf("\n");
}