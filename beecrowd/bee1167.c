#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{struct no *hr, *anthr; char nome[30]; int num;}Node;
typedef struct{Node *inicio, *fim; int num;}node;

//quando o valor que consta na ficha é par, a contagem é feita no sentido horário 
//quando o valor que consta na ficha é ímpar, a contagem é feita no sentido anti-horário

void iniciar(node*);
void adicionar(node*, char *, int);
void juntar(node*);
void vencedor(node*, int);

int main(){
	char nome[30];
	int n, num;
    node p;
	
	while(scanf("%d", &n) && n){
		iniciar(&p);
		for(int i=0; i<n; i++){
			scanf("%s %d", nome, &num);
			adicionar(&p, nome, num);
		}
		juntar(&p);
		vencedor(&p, n);	
		printf("Vencedor(a): %s\n", p.inicio->nome);
	}
	return 0;
}

//funcoes
void iniciar(node *ptr){
	ptr->inicio = NULL;
	ptr->fim = NULL;
}
void adicionar(node *ptr, char nome[], int num){
	Node *aux = (Node *)malloc(sizeof(Node));
	aux->num = num;
	strcpy(aux->nome, nome);
	if(ptr->inicio == NULL){
		aux->hr = NULL;
		ptr->inicio = aux;
		ptr->num = num;
	}else{
		aux->hr = ptr->fim;
		ptr->fim->anthr = aux;
	}
	ptr->fim = aux;
}
void juntar(node *ptr){
	ptr->inicio->hr = ptr->fim;
	ptr->fim->anthr = ptr->inicio;
}
void vencedor(node *ptr, int n){
	Node *aux = ptr->inicio; 
	int i, num;
	for(i=0, n-=1; i<n; i++){
		num = aux->num;
		if(num%2)
			for(int j=0; j<num; j++)
				aux = aux->anthr;			
		else
			for(int j=0; j<num; j++)
				aux = aux->hr;		
		aux->hr->anthr = aux->anthr;
		aux->anthr->hr = aux->hr;				
	}
	ptr->inicio = aux->anthr;
}
