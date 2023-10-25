#include <stdio.h>
#include <string.h>

struct pokemon{
    char nome[50];
    char tipo[10];
    float ataque;
    float defesa;
    float adv;};

int main(){

    struct pokemon inimigo;
    struct pokemon ash[10];
    scanf("%s %s %f %f", &inimigo.nome, &inimigo.tipo, &inimigo.ataque, &inimigo.defesa);
    
    int x, i, j;
    scanf("%d", &x);
    
    for (i = 0; i < x; i++){
        scanf("%s %s %f %f", &ash[i].nome, &ash[i].tipo, &ash[i].ataque, &ash[i].defesa);
    }
    
    for (i = 0; i < x; i++){
        if (strcmp(ash[i].tipo, "grama") == 0 && strcmp(inimigo.tipo, "agua") == 0 ){
            ash[i].ataque = ash[i].ataque * 1.5;
        }
        else if (strcmp(ash[i].tipo, "agua") == 0 && strcmp(inimigo.tipo, "fogo") == 0 ){
            ash[i].ataque = ash[i].ataque * 1.5;
        }
        else if (strcmp(ash[i].tipo, "fogo") == 0 && strcmp(inimigo.tipo, "grama") == 0 ){
            ash[i].ataque = ash[i].ataque * 1.5;
        }
        else if (strcmp(ash[i].tipo, "fogo") == 0 && strcmp(inimigo.tipo, "agua") == 0 ){
            ash[i].ataque = ash[i].ataque * 1;
        }
        else if (strcmp(ash[i].tipo, "grama") == 0 && strcmp(inimigo.tipo, "fogo") == 0 ){
            ash[i].ataque = ash[i].ataque * 1;
        }
        else if (strcmp(ash[i].tipo, "agua") == 0 && strcmp(inimigo.tipo, "grama") == 0 ){
            ash[i].ataque = ash[i].ataque * 1;
        }
    }
    for (i = 0; i < x; i++){
        ash[i].adv = ash[i].ataque - inimigo.defesa;
    }
    for (i = 0; i < x; i++) {
        for (j = 0; j < x; j++) {
            if (ash[i].adv > ash[j].adv) {
                struct pokemon aux = ash[i];
                ash[i] = ash[j];
                ash[j] = aux;
            } else if (ash[i].adv == ash[j].adv) {
                if (strcmp(ash[i].nome, ash[j].nome) < 0) {
                struct pokemon aux = ash[i];
                ash[i] = ash[j];
                ash[j] = aux;
            }
        }
    }
}
  for(i = 0; i < x; i++) {
    printf("%d. %s\n", i+1, ash[i].nome);
  }

}