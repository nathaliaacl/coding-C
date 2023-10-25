#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAM 500

int main(void) {
  int num;
  char string[TAM]; 
  char string2[TAM]; 
  char comp[TAM];
  int a = 0; 
  int b = 0;
  int cont = 0;
  scanf("%d", &num);

  for(int i = 0 ; i <= num ; i++){
    fgets(string, TAM, stdin); 
    strcat(string2, string);
  }

  fgets(comp, TAM, stdin);

  while(comp[a] != '\0'){
    while(string2[b] != '\0'){
      if(comp[a] == string2[b]){
      cont++;
    }
      b++;
    }
    
    printf("%c = %d\n", comp[a], cont);
    cont = 0;
    a++;
    b = 0;
   
  }
  
  return 0;
}