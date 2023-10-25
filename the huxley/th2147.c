#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define array 100

typedef struct node Node;
int vazio(Node *head);
int tam(Node *head);
int ordenar(Node **head, char p[array]); //distancia
int desordenar(Node **head);
void orgn1(char aux[array]);
void orgn2(char aux[array]);

struct node{
    char prato[array];
	Node *ruhead;
	Node *a2head;
	Node *prox;
};

int main(void){
  	Node *ruhead = NULL;
  	Node *a2head = NULL;
  	
  	int tamRu, tamA2;
  	char ruInfo[array], a2Info[array];  //informacoes
  	char p[array], info[array]; 
  	char ruprato[array], a2prato[array], ent[array];
  	
  	fgets(ruInfo, 100, stdin); //receber do teclado
  	fgets(a2Info, 100, stdin); //receber do teclado
  	strcpy(ruprato, ruInfo);
  	strcpy(a2prato, a2Info);
  	orgn2(a2prato);
  	orgn2(ruprato);
	
  	while(1){
        if(fgets(ent, 100, stdin) == NULL){
            break;
        }
        strcpy(p, ent);
        strcpy(info, ent);
        orgn1(p);
        orgn2(info);
        
        tamRu = tam(ruhead);
        tamA2 = tam(a2head);
        strcpy(ent, p);
        
		if (strcmp(p, "SAIU") == 0){
		    tamA2=tam(a2head);
			tamRu=tam(ruhead);
            strcpy(ent, info);
            if(((tamRu==0 && ent[0]==82) || tamA2==0 && ent[0]==65) ){ 
            	printf("Nao ha mais ninguem para comer aqui\n");
            }
            else if(ent[0]==65){ 
                printf("%s almocou na Area 2 e esta voltando pra aula\n", a2head->prato);
            	desordenar(&a2head);
            }
            else if(ent[0]==82){ 
            	printf("%s almocou no RU e esta voltando pra aula\n", ruhead->prato);
            	desordenar(&ruhead);
            }
            tamRu = tam(ruhead);
          	tamA2 = tam(a2head);
		}
        else{
            if(tamA2 == 0 && tamRu == 0 && strcmp(a2prato, ruprato) == 0){
				ordenar(&a2head, p);
				printf("%s foi para a fila da Area 2\n", p);
			}
			else if(strcmp(info, a2prato)==0){
				ordenar(&a2head, p);
				printf("%s foi para a fila da Area 2\n", p);
			}
			else if(strcmp(info, ruprato) == 0){
				ordenar(&ruhead, p);
				printf("%s foi para a fila do RU\n", p);
			}
			else{
				char *i = NULL;
				i = strchr(p,'\n');
				if(i!=NULL){
					*i = '\0';
				}
				tamA2 = tam(a2head);
				tamRu = tam(ruhead);
				if(tamRu == tamA2){
					ordenar(&a2head, p);
					printf("%s foi para a fila da Area 2\n", p);
				}
				else if(tamRu > tamA2){
					ordenar(&a2head, p);
					printf("%s foi para a fila da Area 2\n", p);
				}
				else{
					ordenar(&ruhead, p);
					printf("%s foi para a fila do RU\n", p);
				}
			}
    	}
	}
}

int vazio(Node *head){
	return head == NULL;
}

int tam(Node *head){ 
    int count = 0; 
    Node* temp = head;
    while(temp != NULL){
        count++;
        temp = temp->prox;
    }
    return count;
}

int ordenar(Node **head, char p[array]){ 
    Node *novo;
    novo = (Node*)malloc(sizeof(Node));

    if(!novo){         
        return 1;
	}
    strcpy(novo->prato, p);
    novo->prox = NULL;
    if(vazio(*head)){
        *head = novo;
        return 0;
    }
    Node *aux;
    aux = *head;
    while (aux->prox != NULL){
    	aux = aux->prox;
    }    
    aux->prox = novo;
    return 0;
}

int desordenar(Node **head){
    Node *novo;
    novo = *head;
    *head=(*head)->prox;
    free(novo);
}

void orgn1(char aux[array]){
    char* def = strtok(aux, ":");
    if(def != NULL){
    	strcpy(aux, def);
    }
}

void orgn2(char aux[array]){
    char* def = strtok(aux, ":");
    while ((def != NULL)){
		def = strtok(NULL, ":");
        if(def!=NULL){
            strcpy(aux, def);
        }
    }
}
