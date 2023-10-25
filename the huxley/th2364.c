#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MIN 10000000 //valor minimo a ser arrecadado 

int funcao(int x, int sum, int M);
int qnt(int M);

int main(void){
    
  int ing;
  int valor_ing;
  scanf("%d", &valor_ing);
  
  ing = qnt(valor_ing);
  printf("%d pessoas precisam assistir ao jogo.", ing);
    
  return 0;
}

//Em que M representa o valor de um ingresso b�sico e x representa a 
//quantidade de pessoas que pagaram ingresso.

int funcao(int x, int sum, int M) {

  if(sum >= MIN){
    return x - 1;
  } else{
    if(x % 2 == 0) { //par 
      return funcao(x + 1, sum + x, M); //recursao
    } else {
      return funcao(x + 1, sum + M, M); //impar
    }
  }
  
}

int qnt(int M){   //passa os argumentos da outra funcao 
  
  return funcao(0, 0, M);

}