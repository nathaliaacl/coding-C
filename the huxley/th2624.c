#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
    char sinal[3];
    int num;
    scanf(" %d",&num);
    float matA[num][num];
    float matB[num][num];
    float matC[num][num];
    
    for (int i = 0;i<num;i++){
        for (int j = 0;j<num;j++){
            scanf(" %f",&matA[i][j]);
        }
     putchar('\n'); 
    }
    for (int i = 0; i<num;i++){
        for (int j = 0; j<num; j++){
            scanf(" %f",&matB[i][j]);
        }
        putchar('\n');
    }
    scanf("%s",sinal);
    if (sinal[0] == '+'){
        for(int m = 0;m<num;m++){
            for(int o = 0;o<num;o++){
                if(m%2 == 0){
                    matC[m][o] = matA[m][o] + matB[m][o];
                }
                else{
                    matC[m][o] = matA[m][o] - matB[m][o];
                }
                if(o<num-1){
                    printf("%.2f ",(float)matC[m][o]);
                }
                else{
                    printf("%.2f",(float)matC[m][o]);
                }
            }
            putchar('\n');
        }
    }else{
        for(int h = 0; h<num; h++){
            for(int o = 0;o<num;o++){
                if(h%2 == 0){
                    matC[h][o] = matA[h][o] - matB[h][o];
                }else{
                    matC[h][o] = matA[h][o] + matB[h][o];
                }if(o<num-1){
                    printf("%.2f ",(float)matC[h][o]);
                }else{
                    printf("%.2f",(float)matC[h][o]);
                }
            }
        putchar('\n');
        }
    }
    
    
    
	return 0;
}