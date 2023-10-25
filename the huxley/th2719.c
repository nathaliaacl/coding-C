#include <stdio.h>
#define LIN 20
#define COL 12
#define indice 2000
#define indice1 1

int main(){
    int matriz[LIN][COL];
    int i, j;
    int total = 0; 
    int x = 0;
    int mesi, mesf, anof, anoi;

    for (i = 0; i < LIN; i++){
        for (j = 0; j < 12; j++){
            scanf("%d ", &matriz[i][j]);
        }
    }
    scanf("%d %d", &mesi, &anoi);
    scanf("%d %d", &mesf, &anof);

    int LINinicio = anoi - indice;
    int LINfim = anof - indice;
    int COLinicio = mesi - indice1;
    int COLfim = mesf - indice1;
    
    for (i = LINinicio; i <= LINfim; i++) {
        for (j = 0; j < 12; j++) {
            if (total == 0){
                j = COLinicio;
            }
            total += matriz[i][j];
            if (i == LINfim && j == COLfim){
                break;
            }
        }
    }
    printf("%d", total);
    return 0;

}