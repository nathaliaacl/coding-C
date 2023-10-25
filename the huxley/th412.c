#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define v1 0.8
#define v2 0.2

typedef struct atualizacao{
    int id;
    char frase[500];
    double temp;
}at;

typedef struct amg{
    int id;
    double prox;
}friend;

typedef struct Node{
    struct Node *next;
    double conta;
    at valor;
    friend p;
}Node;

void imprimir(Node *head, int num);
void ordenar(Node **head, at valor, friend p);

int main(void) {
    Node *head = NULL;
    int feed, qamigos;
    int atualzs;
    int i, j;
    scanf("%d", &feed);
    scanf("%d", &qamigos);
    friend amg[qamigos];
    
    for(i=0; i<qamigos; i++) {
        scanf("%d%lf", &amg[i].id, &amg[i].prox);
    }

    scanf("%d", &atualzs);
    at post[atualzs];

    for(i=0; i<atualzs; i++) {
        scanf("%d%lf", &post[i].id, &post[i].temp);
        fgets(post[i].frase, 500, stdin); //recebe do teclado
    }

    if(qamigos >= atualzs) {
        for(i=0; i<qamigos; i++) {
            for(j=0; j<atualzs; j++) {
                if(post[j].id==amg[i].id) {
                    ordenar(&head, post[j], amg[i]);
                }
                else{
                    continue;
                }
            }
        }
    }
    else{
        for(i=0; i<atualzs; i++) {
            for(j=0; j<qamigos; j++) {
                if(post[i].id==amg[j].id) {
                    ordenar(&head, post[i], amg[j]);
                }
            }
        }
    }
    imprimir(head, feed);
    return 0;
}

void imprimir(Node *head, int num) {
    int cont=0;
    Node *aux = head;
    while(aux!=NULL && cont < num) {
        printf("%d%s",aux->valor.id, aux->valor.frase);
        aux = aux->next;
        cont++;
    }
}

void ordenar(Node **head, at valor, friend p) {
    Node *new=(Node *)malloc(sizeof(Node));
    new->valor = valor;
    new->p = p;
    new->next = NULL;
    new->conta = (new->p.prox * v1) + (new->valor.temp * v2);
    if(*head == NULL) {
        *head = new;
    }
    else {
        Node *aux = *head;
        if(aux->conta < new->conta) {
            new->next = (*head);
            *head = new;
        }
        else{
            while(aux->next != NULL && new->conta < aux->next->conta) {
                aux = aux->next;
            }
            if(aux->next==NULL && new->conta < aux->conta) {
                new->next = NULL;
                aux->next = new;
            }
            else{
                new->next = aux->next;
                aux->next = new;
            }
            } 
        }
}
