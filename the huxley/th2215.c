#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define num 10

typedef struct Node{
  int item;
  struct Node *prox;
}Node;

Node* criar() {
	return NULL;
}

Node* add(Node *head, int item){
  Node *novo = (Node*)malloc(sizeof(Node));
	novo->item = item;
	novo ->prox = head;
	return novo;
}

Node* rzero(Node *head){
  Node *tempo = head;
    while (head->item == 0){
      tempo = head;
      head = head->prox;
      free(tempo);
  }
  return head;
} 


void soma(Node *num1, Node *num2);
void imprimir(Node *head);

int main(void) {
	Node *lA = criar();
	Node *lB = criar();
	Node *lC = criar();
	
	int valor;
	char pchar;
	
	while(scanf("%d%c", &valor, &pchar)) {
		lA = add(lA,valor);
		if(pchar == '\n') {
		    break;
		}
	} getchar();

	while(scanf("%d%c", &valor, &pchar)) {
		lB = add(lB,valor);
		if(pchar == '\n') {
		    break;
		}
	} getchar();
    
    if(lA == NULL && lB == NULL) {
        printf("Lista vazia!\n");
    } else if(lA == NULL) {
    	while(lB != NULL) {
    		lC = add(lC, lB->item);
    		lB = lB->prox;
    	} imprimir(lC);
    }
    else if(lB == NULL) {
    	while(lA != NULL) {
    		lC = add(lC, lA->item);
    		lA = lA->prox;
    	} imprimir(lC);
    } else {
    	soma(lA, lB);
    }
	return 0;
}

void soma(Node *num1, Node *num2){
	int resto = 0; 
	int soma = 0;
	Node *resultado = NULL;

	while(1) {
		if((num1 != NULL) && (num2 != NULL)) {
			if((num1->item + num2->item + resto) >= num) {
				soma = ((num1->item + num2->item + resto) %num);
				resultado = add(resultado, soma);
				resto = 1;
				num1 = num1->prox;
				num2 = num2->prox;	
			}
			else {
				soma = (num1->item + num2->item);
				resultado = add(resultado, soma + resto);
				resto = 0;
				num1 = num1->prox;
				num2 = num2->prox;
			}
			
		} else if(num1 == NULL) {
			if(num2->item + resto >= num) {
				soma = ((num2->item + resto) %num);
				resultado = add(resultado, soma);
				resto = 1;
				num2 = num2->prox;
			} else {
				resultado = add(resultado, num2->item + resto);
				resto = 0;
				num2 = num2->prox;
			}	
		} else if(num2 == NULL) {
			if(num1->item + resto >= num) {
				soma = ((num1->item + resto) %num);
				resultado = add(resultado, soma);
				resto = 1;
				num1 = num1->prox;	
			} else {
				resultado = add(resultado, num1->item + resto);
				resto = 0;
				num1 = num1->prox;
			}	
		}
		if((num1 == NULL) && (num2 == NULL)) {
			if(resto != 0) {
				resultado = add(resultado, resto);
				break;
			} else {
				break;
			}	
		}
	}
	resultado = rzero(resultado);
	imprimir(resultado);
}

void imprimir(Node *head){
  while(head != NULL){
    printf("%d ", head->item);
    head = head->prox;
  }printf("\n");
}