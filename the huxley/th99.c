#include <stdio.h>
#include <string.h>
#include <math.h>

struct Type {
  int id;
  float temp;
  char fumc; };

int main(){
  int test;
  scanf("%i", &test);

  for (int i = 0; i < test; i++) {
    printf("TESTE %i\n", i + 1);

    struct Type sprinkler[15];
    float temptotal = 0;
    int quant;
    float avgtemp;
    
    scanf("%d\n", &quant);
    float qmedia = quant;
    
    for (int i = 1; i <= quant; i++) {
      scanf("%d %f %c", &sprinkler[i].id, &sprinkler[i].temp, &sprinkler[i].fumc);
      temptotal = temptotal + sprinkler[i].temp;
    }
    

    avgtemp = (temptotal)/qmedia;
    
    
    for (int j = 1; j <= quant; j++){
      if (sprinkler[j].fumc == 'S' || (sprinkler[j].temp > avgtemp * 1.15)){
        printf("%i\n", sprinkler[j].id);
      }
    }
  }

  return 0;
}