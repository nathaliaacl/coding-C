#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Node{
	int valor;
	struct Node *prox;   }; 

    int lista(struct Node *head);
    void enfileirar(struct Node **head, struct Node **tail, int var);
    void desenfileirar(struct Node **head, struct Node **tail);
    void printar(struct Node *head);


int main(void) {
    
    char op[50];
    int valor;
    int contparada;
    struct Node *head = NULL;
	struct Node *tail = NULL;
	contparada = 0;

  while(contparada == 0) {
    scanf("%s",op);
  
    if(strcmp("Enfileirar", op) == 0){
      scanf("%d",&valor);
      enfileirar(&head,&tail,valor);
    } else if(strcmp("Desenfileirar", op) == 0) {
      desenfileirar(&head, &tail);
    } else if(strcmp("Imprimir", op) == 0) {
      printar(head);
    } else if(strcmp("Finalizar", op) == 0) {
      contparada = 1;
    }

    }
  
  return 0;
}

int lista(struct Node *head){  
	return head == NULL;
}


void enfileirar(struct Node **head, struct Node **tail, int var){

	struct Node *novo = (struct Node *)malloc(sizeof(struct Node));
	
	novo->valor =var;
	novo->prox = NULL;
  
  if (lista(*head)){ 
    
	*head = novo;
    *tail = novo;
    
	} else {
		
	  (*tail)->prox = novo; 
	  *tail = novo; 
	}
}


void desenfileirar(struct Node **head, struct Node **tail){
	struct Node *temp;
	int aux;
  
    temp = *head;
    aux = (*head)->valor;
    *head = (*head)->prox;
  
	if ((*head) == NULL){
		*tail = NULL;
	}
	  free(temp);  
}


void printar(struct Node *head){ 
	
  struct Node *aux = head;
  
  printf("\n");
  
	while(aux !=NULL){
	    if(aux->prox == NULL){
	        printf("%d", aux->valor);
	    } else {
	        printf("%d ", aux->valor);
	    }
  aux= aux->prox;
	}	
}