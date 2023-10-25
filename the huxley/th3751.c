#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define maxcaract 200 //maximo de caracteres falado pela questao

struct dicionario{
    char words[maxcaract];
};

//declaracao
char* minusculo(char *palavra);
char* maiusculo(char *palavra);
char* remover(char *palavra);

int main(void){
    struct dicionario palavras[10000];
    char tmp[maxcaract], aux[maxcaract];
    char *ptr; 
    int TAM=0;
    int cont1=0, cont2=0;
    
    do{
        scanf("%s", tmp);
        if(strcmp(tmp, "-1")!= 0){ //zero indica igualdade 
            remover(tmp);
            ptr = strtok(tmp, " "); //divisao em strings menores
            
            while(ptr != NULL){
                strcat (palavras[TAM].words, ptr);
                ptr = strtok(NULL, " ");
                maiusculo (palavras[TAM].words);
                TAM++;
            }
        }else
            break;
            
    }while(strcmp(palavras[TAM-1].words, "-1") != 0);
  
  for(int i=1; i<=TAM-1; i++){
     for(int j=TAM-1; j>=i; j--){
        if(strcmp(palavras[j].words, palavras[j-1].words) < 0){
         
          strcpy(aux, palavras[j].words);
          strcpy(palavras[j].words, palavras[j-1].words);
          strcpy(palavras[j-1].words, aux);
        }
     }
   }

    for(int i=0; i<TAM; i++){
        for(int j=0; j<=TAM; j++){
            if(strcmp(palavras[i].words, palavras[j].words)==0){
                cont1++;
                if(cont1>1)
                    strcat(palavras[j].words, "nada");
            }
            if(palavras[i].words[j]>= 97)
                cont2++;
        }
        if(cont2 == 0){
            minusculo (palavras[i].words);
            printf("%s %d\n", palavras[i].words, cont1);
        }
        cont1 = 0;
        cont2 = 0;
    }
  
  return 0;
}

char* maiusculo(char *palavra){ //questao dos maiusculos
    int tamanho;
    tamanho = strlen(palavra);
    for(int i=0; i<(tamanho); i++){
    if(palavra[i] >= 90)
        palavra[i] = palavra[i] - 32;
    }
}

char* minusculo(char *palavra){ //questao dos minusculos
    int tamanho;
    tamanho = strlen(palavra);
    for(int i=0; i<(tamanho); i++){
    if(palavra[i] <= 90)
        palavra[i] = palavra[i] + 32;
    }
}

char* remover(char *palavra){ 
    int caract=0;
    while(palavra[caract]!='\0'){
        //caracteres especiais listados
        if(palavra[caract]=='.'||palavra[caract]=='"'||palavra[caract]==
        '('||palavra[caract]=='*'||palavra[caract]=='$'||palavra[caract]=='#'||palavra[caract]==':'){
            palavra[caract]=' ';
        }
    caract++;
    }
    return palavra;
}