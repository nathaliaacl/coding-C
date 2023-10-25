#include <stdio.h>
#include <stdlib.h>

int consumoMedio(int distancia, double combustivel){
    return distancia/combustivel;
}
 
int main() {
    
    int distancia; 
    double combustivel, resp; 
    scanf("%d\n%lf", &distancia, &combustivel);
    resp = consumoMedio(distancia, combustivel);
    printf("%.3lf km/l\n", resp);
    
    return 0;
}