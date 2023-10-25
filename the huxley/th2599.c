#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LIN 12
#define COL 8

int main(void) {
    
    float valor_min = 1.0;
    char mes[15];
    char posicao[10];
    char dia[15];
    int i,j;
    float matriz [12][8];
    
    for (i=0; i<12; i++){ 
        for (j=0; j<8; j++){
            scanf("%f", &matriz[i][j]);
            if (matriz[i][j] < valor_min){
                valor_min=matriz[i][j];
        
                switch (i){
                    case 0:
                        strcpy(mes, "Janeiro");
                        break;
                    case 1:
                        strcpy(mes, "Fevereiro");
                        break;
                    case 2:
                        strcpy(mes, "Marco");
                        break;
                    case 3:
                        strcpy(mes, "Abril");
                        break;
                    case 4:
                        strcpy(mes, "Maio");
                        break;
                    case 5:
                        strcpy(mes, "Junho");
                        break;
                    case 6:
                        strcpy(mes, "Julho");
                        break;
                    case 7:
                        strcpy(mes, "Agosto");
                        break;
                    case 8:
                        strcpy(mes, "Setembro");
                        break;
                    case 9:
                        strcpy(mes, "Outubro");
                        break;
                    case 10:
                        strcpy(mes, "Novembro");
                        break;
                    case 11:
                        strcpy(mes, "Dezembro");
                    break;
                }
                
                if (j==0 || j==1){
                    strcpy(posicao,"Primeiro");
                }
                else if (j==2 || j==3){
                    strcpy(posicao,"Segundo");
                }
                else if (j==4 || j==5){
                    strcpy(posicao,"Terceiro");
                }
                else if (j==6 || j==7){
                    strcpy(posicao,"Quarto");
                }
                if (j==0 || j%2==0){
                    strcpy(dia,"Sabado");
                } 
                else{
                    strcpy(dia,"Domingo");
                }
            
            }    
        }     
    }  
    
    if  (valor_min > 0.5){
        
        printf("Proximo ano eu tento denovo...");
    }else{        
        printf ("O melhor dia e no %s %s de %s",posicao,dia,mes);
    }
    return 0;

}    
