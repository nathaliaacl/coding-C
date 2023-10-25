#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    int TAM, K, N;
    char C;
    int cont;
    int n;
    
    scanf("%d %d %c", &N, &K, &C);
    
    cont = C; //para n?o confundir com o valor de C
    n = 0;
    TAM = (N*2)-1;
    int matriz[TAM][TAM];
    
    if (K == 1){ //bordas
        for(int x; x<N; x++){
            if(cont<123){
                for(int i=n;i<TAM-n;i++){
                    matriz[n][i] = cont;
                }
                
                for(int i=n+1;i<TAM-(n);i++){
                    matriz[i][TAM-(n+1)] = cont;
                }
        
                for(int i=TAM-(n+2);i>n-1;i--){
                    matriz[TAM-(n+1)][i] = cont;
                }   
        
                for(int i=TAM-(n+2);i>n;i--){
                    matriz[i][n] = cont;
                }
                
                cont++;
                n++;
            }
            else{
                cont = 122-26+1;
                for(int i=n;i<TAM-n;i++){
                    matriz[n][i] = cont;
                }
                
                for(int i=n+1;i<TAM-(n);i++){
                    matriz[i][TAM-(n+1)] = cont;
                }
        
                for(int i=TAM-(n+2);i>n-1;i--){
                    matriz[TAM-(n+1)][i] = cont;
                }   
        
                for(int i=TAM-(n+2);i>n;i--){
                    matriz[i][n] = cont;
                }
                cont++;
                n++;
            }
        }
    }
        else if(K==-1){ //centro
        cont = cont + (N-1);
        if(cont>122){ //referencia da tabela ascii
            cont = cont - 26;
        }
        for(int x; x<N; x++){
            if(cont>96){
                for(int i=n;i<TAM-n;i++){
                    matriz[n][i] = cont;
                }
                
                for(int i=n+1;i<TAM-(n);i++){
                    matriz[i][TAM-(n+1)] = cont;
                }
        
                for(int i=TAM-(n+2);i>n-1;i--){
                    matriz[TAM-(n+1)][i] = cont;
                }   
        
                for(int i=TAM-(n+2);i>n;i--){
                    matriz[i][n] = cont;
                }
                cont--;
                n++;
            }
            else{
                cont = cont + 26;
                for(int i=n;i<TAM-n;i++){
                    matriz[n][i] = cont;
                }
                
                for(int i=n+1;i<TAM-(n);i++){
                    matriz[i][TAM-(n+1)] = cont;
                }
        
                for(int i=TAM-(n+2);i>n-1;i--){
                    matriz[TAM-(n+1)][i] = cont;
                }   
        
                for(int i=TAM-(n+2);i>n;i--){
                    matriz[i][n] = cont;
                }
                cont--;
                n++;
            }
        }
    }//printar a lista
    for(int i=0; i<TAM; i++){
        for(int j=0; j<TAM; j++){
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }
}