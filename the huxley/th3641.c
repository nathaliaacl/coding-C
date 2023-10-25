#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
  int n;
  char nome[100];
  struct Node *prox, *ant, *aux;
}Node;

typedef struct lista{
  Node *head;
  Node *tail;
}lista;

//declaracao
void imprimir(lista *l);
void adicionar(char *nomes, lista *l, int n);

int main(void) {
  lista *list = (lista *)malloc(sizeof(lista));
  int i;

  if (list != NULL){ 
    Node *head = NULL;
    Node *tail = NULL;
    int qnt, num;
    char nomes[500];
    scanf("%d", &qnt);
    
    for (i = 0; i < qnt; i++){
      scanf("%s", nomes);
      scanf("%d", &num);
      adicionar(nomes, list, num);
    }
  }
    imprimir(list);
    return 0;
}

//funcoes 
void adicionar(char *nomes, lista *l, int n){
  Node *novo = (Node *)malloc(sizeof(Node));
  strcpy(novo->nome, nomes);
  novo->n = n;
  novo->prox = NULL;
  
  if (l->head == NULL){
    l->head = novo;
    l->tail= novo;
  } else{
    
    if(l->head->n %2 == 1){
    novo->prox = l->head;
    l->head = novo;
    }else{
      Node *ant = l->head;
      Node *aux = ant->prox;

      while( aux != NULL && aux->n%2 ==0){
        ant = ant->prox;
        aux = aux->prox;
      }
      if(novo->n % 2 == 0){
        ant->prox = novo;
        novo->prox = aux;
      }
        else{
        while(aux != NULL){
          ant = ant->prox;
          aux = aux->prox;
          }
        ant->prox = novo;
        novo->prox = aux;
        }
      }
  }
}

void imprimir(lista *l){
  Node *novo = l->head;
  if (novo != NULL){
      while(novo != NULL){
      if(novo->prox == NULL){
        printf("%s\n", novo->nome);  
      }
      else{
       printf("%s\n", novo->nome);
      }
      novo = novo->prox;
    }
  }
}