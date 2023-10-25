#include <stdio.h>
#include <math.h>
int raizes(float A, float B, float C);

int main(void)
{
    float A, B, C;
    float *ptrA;
    ptrA = &A;
    float *ptrB;
    ptrB = &B;
    scanf("%f %f %f", &A, &B, &C);
    raizes(A, B, C);
    
}
int raizes(float A, float B, float C){
    float soma, sub, delta;
    float real, imag;
    
    delta = (B * B) - (4*A*C);
    
    if (A != 0){
        if (delta < 0){
            printf("0");
        }
        else if(delta == 0){
            soma = -B/(2*A);
            printf("%.2f\n", soma);
            printf("1");
        }else{
            soma = (-B + sqrt(delta))/(2*A);
            sub = (-B - sqrt(delta))/(2*A);
            printf("%.2f %.2f\n", soma, sub);
            printf("2");
            
        }
        
    }else{
        printf("0");}
    
}