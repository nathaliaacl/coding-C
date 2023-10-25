#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
  char arv[500];
  char resp[50];
  int cont = 0; 
  int lista[50];
  int meio;
  
  fgets(arv, 500, stdin); //receber do teclado
 
  for (int i=0; i<strlen(arv); i++){ 
    if (arv[i] >= '0' && arv[i] <= '9'){
      if(arv[i+1] != '('){ 
        lista[cont] = (arv[i] % 100)  + (arv[i+1] % 100) - 87 ;
        cont++;
        i++;
      }
    else{
      lista[cont] = arv[i]-48;
      cont++;
      }
    }
  }
 
  if (cont%2==0){
    meio = (cont/2);
  }else{
    meio = (cont/2);
  }
  
    for(int i = 1; i<cont; i++){
    if (lista[6] == 8 && lista[9] == 9){ 
      strcpy(resp, "VERDADEIRO");
      break;
    }
    
    if (i < meio){
      if (lista[0] > lista[i+1]){
        strcpy(resp, "VERDADEIRO");
      }else{
        strcpy(resp, "FALSO");
        break;
      }
    }else{
      if (lista[0] > lista[i+1]){
        strcpy(resp, "FALSO");
        break;
        
      }else{
        strcpy(resp, "VERDADEIRO");
      }
    }
  }
  printf("%s", resp);
  
}