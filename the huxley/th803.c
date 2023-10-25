#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define TAM 200
int main(void){
  int cont_a = 0;
  int cont_e = 0;
  int cont_i = 0;
  int cont_o = 0;
  int cont_u = 0;
  char frase[TAM];
  int len, i;
  fgets(frase, TAM, stdin); 
  len=strlen(frase);
  for (int i=0; i<len; i++){
    if(tolower(frase[i]) == 'a'){
      cont_a++;
    }if(tolower(frase[i]) == 'e'){
      cont_e++;
    }if(tolower(frase[i]) == 'i'){
      cont_i++;
    }if(tolower(frase[i]) == 'o'){
      cont_o++;
    }if(tolower(frase[i]) == 'u'){
      cont_u++;
    }
  }
  printf("a %d\n", cont_a);
  printf("e %d\n", cont_e);
  printf("i %d\n", cont_i);
  printf("o %d\n", cont_o);
  printf("u %d\n", cont_u);
}