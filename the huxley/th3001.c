#include <stdio.h>

int main(){
   int n;
   
do{
       scanf("%d", &n);
       int matz[n][n];
       int at = n;
       int i, j;
       printf("\n");
       
       for (i = 0; i < n; i++){
           for (j = 0; j < n; j++){
               if (at == 1){
                printf("1");}
                else{
                    
                    if ((i <= 0 || i >= at - 1) || (j <= 0 || j >= at - 1)){
                        printf("1 ");
                    }
                    else if ((i <= 1 || i >= at - 2) || (j <= 1 || j >= at - 2)){
                        printf("2 ");
                    }
                    else if ((i <= 2 || i >= at - 3) || (j <= 2 || j >= at - 3)){
                        printf("3 ");
                    }
                    else if ((i <= 3 || i >= at - 4) || (j <= 3 || j >= at - 4)){
                        printf("4 ");
                    }
                    else if ((i <= 4 || i >= at - 5) || (j <= 4 || j >= at - 5)){
                        printf("5 ");
                    }
                    else if ((i <= 5 || i >= at - 6) || (j <= 5 || j >= at - 6)){
                        printf("6 ");
                    }
                }
               
           }printf("\n");
       }
       
}while(n!=0);
printf("Fim");
    return 0;
}