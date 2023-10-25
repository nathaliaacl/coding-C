#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

struct qNode{
    char id;
	int prioridade; 
	struct qNode *prox;   };

    void add(struct qNode **head, struct qNode **tail, char c, long int var);
    void imprimir(struct qNode *head, struct qNode *tail);
    int run(struct qNode **head, struct qNode **tail);

int main(){
    
    char i;
	char vet[100];
	long int x;
	struct qNode *head = NULL;
	struct qNode *tail = NULL;
	
	do{
		scanf("%s", vet); getchar();
		if(strcmp(vet, "ADD")==0){
			scanf("%c %d", &i, &x); getchar();
			add(&head,&tail, i, x);
			
		}else if(strcmp(vet, "RUN")==0){
				run(&head,&tail);
		}else if(strcmp(vet, "PRT")==0){
		    prt(head, tail);
		}
	}while(strcmp(vet, "EXT")!=0);
	
	return 0;

} 

    void add(struct qNode **head, struct qNode **tail, char c, long int var){
	struct qNode *novo = (struct qNode *)malloc(sizeof(struct qNode));
	
	if(novo != NULL){ 
	    novo->id = c;
		novo->prioridade =var;
		novo->prox = NULL;
		
		if ((*head) == NULL){ 
			*head = novo;
			*tail = novo;
			novo->prox = NULL;
		}else{
		    if((*head)!=NULL && (*head)->prioridade < var){
		        novo->prox = *head;
		        *head = novo;
		    }else{
		        struct qNode *temp = *head;
		        struct qNode *aux = temp->prox;
		        while(aux!=NULL && aux->prioridade >var){
		            temp = temp->prox;
		            aux = aux->prox;
		        }
		        if(aux==NULL){
		            (*tail)->prox = novo;
		            (*tail) = novo;
		            novo->prox = NULL;
		        }else{
		            temp->prox = novo;
		            novo->prox = aux;
		        }
		    }
		}
	}
	printf("Process [%c|%d] enqueued!\n", novo->id, novo->prioridade);

}

void prt(struct qNode *head, struct qNode *tail){ 
	
	if(head != NULL){
		struct qNode *aux = head;
		while(aux !=NULL){
		    if(aux != tail){
			printf("[%c|%d] => ", aux->id, aux->prioridade);
			aux= aux->prox;
		    }else{
		        printf("[%c|%d]", aux->id, aux->prioridade);
		        aux= aux->prox;
		    }
		}		
		printf("\n");
	}else{
	    printf("Empty process queue!\n");
	}

}

int run(struct qNode **head, struct qNode **tail){
	struct qNode *temp;
	int aux;
  
    if((*head)==NULL){
        printf("Empty process queue!\n");
    }else{
        printf("Process [%c|%d] dequeued!\n", (*head)->id, (*head)->prioridade);
        temp = *head;
	    aux = (*head)->prioridade;
	    *head = (*head)->prox;
	    if ((*head) == NULL){ 
		    *tail = NULL;
	    }
	    free(temp);
    }
    return aux; 
}