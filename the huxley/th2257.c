#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void funcao (int a, int b);

int main() {
  int i, j;
  scanf("%d", &i);
  scanf("%d", &j);
  if((i >= 0 && i <= pow(2,30)) && (j >= 0 && j<= 9)){
    funcao(i, j);
  } return 0;
}
void funcao(int x, int y) {
  int digt;
  int resultado = 0;
  while(x > 0) {
    digt = x % 10;
    if (digt == (y+1) || digt == (y-1)) {
      resultado++;
    }
    x = x / 10;
  }
  if (resultado > 0) {
    printf("sim");
  }
  else{
    printf("nao");
  }
}