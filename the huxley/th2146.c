#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define slots 10 //definido pelo problema
#define array 50

struct vendingmachine {
    int slot;
    int disp;
    char produto[array];
    struct vendingmachine *prox;
};

struct vendingmachine *head = NULL;
struct vendingmachine *tail = NULL;
//declaracoes
int inserir(char *prodt, int Slot, int slot_);
double comprar(char *prodt, double spreco[]);

int main(void) {
        int Slot = 0;
        int i;
        char cprod[array];
        char compras[array][array];
        double slotspreco[slots];

        for (i = 0; i < slots; i++) {
            while (1) {
                scanf("%s", cprod);
                Slot = inserir(cprod, i, Slot);

                if (getchar() == '\n'){
                    break; 
                } 
                else if (ungetc(getchar(), stdin) == '\n'){
                    break;  
                } 
                }
        } tail-> disp = 1;

        for (i = 0; i < slots; i++){
            scanf("%lf", &slotspreco[i]);
        }
        
        double preco = 0;
        for (i = 0; scanf("%s", compras[i]) != EOF; i++)
                preco += comprar(compras[i], slotspreco);
        printf("Compras realizadas com sucesso. Voce gastou R$%.2lf.", preco);
}

//declaracoes
int inserir(char *prodt, int slot_, int Slot) {
        struct vendingmachine *novo = malloc(sizeof(struct vendingmachine));

        strcpy(novo->produto, prodt);
        novo->slot = slot_;
        novo->disp = 0;

        novo->prox = NULL;
        if (head == NULL) {
                head = novo;
                tail = novo;
        } else {
            if (Slot != slot_){
              tail->disp = 1;  
            }
            tail->prox = novo;
            tail = tail->prox;
        }
        return slot_;
}

double comprar(char *prod, double spreco[]) {
        if (head == NULL) { //verificar a alocacao de memoria
                printf("Nao temos %s disponivel no momento.\n", prod);
                return 0;
        }

        struct vendingmachine *c = head;
        struct vendingmachine *prev = NULL;
        double x = 0;

        while (c->disp==0 || strcmp(c->produto, prod)) {
                if (c->prox == NULL) { //produto em falta
                    printf("Nao temos %s disponivel no momento.\n", prod); 
                    return 0;
                } else 
                    prev = c;
                    c = c->prox;
        }
        if (c->slot == 5) {
            printf("Opa, um item 0800!\n"); //item 35 declarado pelo problema
        } else {
            x += spreco[c->slot];
        }
        if (c == head) {
                head = head->prox;
        } else {
                prev->disp = 1;
                prev->prox = c->prox;
        }
        return x;
}
